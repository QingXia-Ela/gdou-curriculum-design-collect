#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  int fd;
  char *testfile = "testfile";
  int block_size = 512; // block size define on fs.h BSIZE `512`
  char buffer[block_size];
  memset(buffer, 'A', block_size); // fill

  fd = open(testfile, O_CREATE | O_RDWR);
  if (fd < 0)
  {
    printf(2, "Error: cannot open file %s\n", testfile);
    exit();
  }

  int blocks_written = 0;
  while (write(fd, buffer, block_size) == block_size)
  {
    blocks_written++;

    if (blocks_written % 100 == 0)
    {
      printf(1, "Now write %d blocks\n", blocks_written);
    }
  }

  printf(1, "Maximum blocks in a file: %d\n", blocks_written);

  close(fd);
  exit();
}