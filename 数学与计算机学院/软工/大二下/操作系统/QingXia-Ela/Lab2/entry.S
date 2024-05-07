# The xv6 kernel starts executing in this file. This file is linked with
# the kernel C code, so it can refer to kernel symbols such as main().
# The boot block (bootasm.S and bootmain.c) jumps to entry below.
        
# Multiboot header, for multiboot boot loaders like GNU Grub.
# http://www.gnu.org/software/grub/manual/multiboot/multiboot.html
#
# Using GRUB 2, you can boot xv6 from a file stored in a
# Linux file system by copying kernel or kernelmemfs to /boot
# and then adding this menu entry:
#
# menuentry "xv6" {
# 	insmod ext2
# 	set root='(hd0,msdos1)'
# 	set kernel='/boot/kernel'
# 	echo "Loading ${kernel}..."
# 	multiboot ${kernel} ${kernel}
# 	boot
# }

#include "asm.h"
#include "memlayout.h"
#include "mmu.h"
#include "param.h"

# Multiboot header.  Data to direct multiboot loader.
.p2align 2
.text
.globl multiboot_header
multiboot_header:
  #define magic 0x1badb002
  #define flags 0
  .long magic
  .long flags
  .long (-magic-flags)

# By convention, the _start symbol specifies the ELF entry point.
# Since we haven't set up virtual memory yet, our entry point is
# the physical address of 'entry'.
.globl _start
_start = V2P_WO(entry)

# Entering xv6 on boot processor, with paging off.
.globl entry
entry:
  # Turn on page size extension for 4Mbyte pages
  // 注释此处汇编以使用4KB小页表
  //movl    %cr4, %eax
  //orl     $(CR4_PSE), %eax
  //movl    %eax, %cr4
  
  // 实验二任务2汇编代码由此开始
  #初始化页表内容

  // xor self, same as set %esi to 0
  xor %esi, %esi

// loop for init page_table
// %esi will self add
1:
  // eax set to val
  movl %esi, %eax
  // move left << 12, set offset to 0 and PTX from %esi
  // %eax store current PTX addr
  shll $12, %eax
  // set eax flag that phy present and writable
  orl $(PTE_P|PTE_W), %eax
  // macro call, parse page_table start addr to real phy addr, and send value to edi
  movl $(V2P_WO(page_table)), %edi
  // ebx set to loop value
  movl %esi, %ebx
  // move left << 2, because uint array gap is 4 byte (uint) same as *= 4
  shll $2, %ebx
  // move %edi position to current loop page_table
  addl %ebx, %edi
  // move eax value to page_table position that with %edi deref
  movl %eax, (%edi)
  // %esi++
  incl %esi
  // if esi < 1024 (NPTENTRIES), jmp 1:
  cmpl $1024, %esi
  jb 1b

  # 初始化页目录表内容

  // now is jump out
  // split entry and page_table to 2 module
  
  // level 1 ptb
  // set 0
  movl $0, %esi
  // ebx set 0
  movl %esi, %ebx
  shll $2, %ebx
  movl $(V2P_WO(entrypgdir)), %edi
  addl %ebx, %edi
  movl $(V2P_WO(page_table)), (%edi)
  // write flag
  orl $(PTE_P | PTE_W), (%edi)

  // level 2 ptb
  movl $512, %esi
  movl %esi, %ebx
  shll $2, %ebx
  movl $(V2P_WO(entrypgdir)), %edi
  // 512 offset, split to second ptb
  addl %ebx, %edi
  movl $(V2P_WO(page_table)), (%edi)
  // write flag
  orl $(PTE_P | PTE_W), (%edi)
  // 实验二任务2汇编代码到此结束

  movl    $(V2P_WO(entrypgdir)), %eax
  movl    %eax, %cr3
  # Turn on paging.
  movl    %cr0, %eax
  orl     $(CR0_PG|CR0_WP), %eax
  movl    %eax, %cr0

  # Set up the stack pointer.
  movl $(stack + KSTACKSIZE), %esp

  # Jump to main(), and switch to executing at
  # high addresses. The indirect call is needed because
  # the assembler produces a PC-relative instruction
  # for a direct jump.
  mov $main, %eax
  jmp *%eax

.comm stack, KSTACKSIZE
