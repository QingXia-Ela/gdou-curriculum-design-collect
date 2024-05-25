// PAGEBREAK!
//  Inode content
//
//  The content (data) associated with each inode is stored
//  in blocks on the disk. The first NDIRECT block numbers
//  are listed in ip->addrs[].  The next NINDIRECT blocks are
//  listed in block ip->addrs[NDIRECT].

// Return the disk block address of the nth block in inode ip.
// If there is no such block, bmap allocates one.
// 已修改的 bmap 函数
static uint
bmap(struct inode *ip, uint bn)
{
  uint addr, *a;
  struct buf *bp;

  if (bn < NDIRECT)
  {
    if ((addr = ip->addrs[bn]) == 0)
      ip->addrs[bn] = addr = balloc(ip->dev);
    return addr;
  }
  bn -= NDIRECT;

  // layer 1
  if (bn < NINDIRECT)
  {
    // Load indirect block, allocating if necessary.
    // alloc if not exist with indirect addr
    if ((addr = ip->addrs[NDIRECT]) == 0)
      ip->addrs[NDIRECT] = addr = /* alloc method */ balloc(ip->dev);
    // disk buf pointer (512 Bytes)
    bp = bread(/* disk device num*/ ip->dev, /* read addr */ addr);
    // data pointer
    a = (uint *)bp->data;
    if ((addr = a[bn]) == 0)
    {
      a[bn] = addr = balloc(ip->dev);
      log_write(bp);
    }
    brelse(bp);
    return addr;
  }

  // 减去第一层间接地址的数量
  bn -= NINDIRECT;

  // layer 2
  if (bn < NINDIRECTLAYER2)
  {
    /**
     * 核心点：一个数字表示双层索引：
     * |---bn---|---l1_index---|---l2_index---|
     * |   00   |      0       |       0      |
     * |   01   |      0       |       1      |
     * |   ..   |     ...      |      ...     |
     * |  127   |      0       |      127     |
     * |  128   |      1       |       0      |
     * |  129   |      1       |       1      |
     * |   ..   |     ...      |      ...     |
     * | 16383  |     127      |      127     | // max layer 2 index
     * | 16384  |         out of range        |
     */
    int l1_index = bn / LAYER2ADDRS;
    int l2_index = bn % LAYER2ADDRS;

    // index 1 alloc
    if ((addr = ip->addrs[NDIRECT + 1]) == 0)
      ip->addrs[NDIRECT + 1] = addr = balloc(ip->dev);

    bp = bread(ip->dev, addr);
    a = (uint *)bp->data;

    // read index 1 addr block
    // if info block not exist, just create
    if ((addr = a[l1_index]) == 0)
    {
      a[l1_index] = balloc(ip->dev);
      addr = a[l1_index];
      // log record
      log_write(bp);
    }
    brelse(bp);

    // read index 2 addr block
    bp = bread(ip->dev, addr);
    a = (uint *)bp->data;

    // zero disk block
    if ((addr = a[l2_index]) == 0)
    {
      a[l2_index] = addr = balloc(ip->dev);
      log_write(bp);
    }
    brelse(bp);

    // disk addr
    return addr;
  }

  // 块号越界
  panic("bmap: out of range");
}

// Truncate inode (discard contents).
// Only called when the inode has no links
// to it (no directory entries referring to it)
// and has no in-memory reference to it (is
// not an open file or current directory).
// 已修改的 itrunc 函数
static void
itrunc(struct inode *ip)
{
  int i, j;
  struct buf *bp;
  uint *a;

  for (i = 0; i < NDIRECT + 1; i++)
  {
    if (ip->addrs[i])
    {
      bfree(ip->dev, ip->addrs[i]);
      ip->addrs[i] = 0;
    }
  }

  // layer 1
  // 与原代码没有区别
  if (ip->addrs[NDIRECT])
  {
    bp = bread(ip->dev, ip->addrs[NDIRECT]);
    a = (uint *)bp->data;
    for (j = 0; j < NINDIRECT; j++)
    {
      if (a[j])
        bfree(ip->dev, a[j]);
    }
    brelse(bp);
    bfree(ip->dev, ip->addrs[NDIRECT]);
    ip->addrs[NDIRECT] = 0;
  }

  // layer 2
  if (ip->addrs[NDIRECT + 1])
  {
    bp = bread(ip->dev, ip->addrs[NDIRECT + 1]);
    a = (uint *)bp->data;
    struct buf *bp2;
    uint *a2;
    int k;

    for (j = 0; j < LAYER2ADDRS; j++)
    {
      // 先找第一层是否存在内容
      if (a[j])
      {
        // 读取第二层，循环释放每个地址指向的文件块
        // 以下代码与之前释放文件块的代码相同
        bp2 = bread(ip->dev, a[j]);
        a2 = (uint *)bp2->data;
        for (k = 0; k < LAYER2ADDRS; k++)
        {
          if (a2[k])
            bfree(ip->dev, a2[k]);
        }
        brelse(bp2);
        bfree(ip->dev, a[j]);
      }
    }

    brelse(bp);
    bfree(ip->dev, ip->addrs[NDIRECT + 1]);
    ip->addrs[NDIRECT + 1] = 0;
  }
  ip->size = 0;
  iupdate(ip);
}
