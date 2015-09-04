#ifndef __FDISK_H__
#define __FDISK_H__

typedef unsigned int uint32;

#include "dfs_shared.h" // This gets us structures and #define's from main filesystem driver

#define FDISK_INODE_BLOCK_START 1 // Starts after super block (which is in file system block 0, physical block 1)
#define FDISK_INODE_NUM_BLOCKS 36 // Number of file system blocks to use for inodes
#define FDISK_NUM_INODES 192  //STUDENT: define this
#define FDISK_FBV_BLOCK_START 37//STUDENT: define this
#define FDISK_BOOT_FILESYSTEM_BLOCKNUM 0 // Where the boot record and superblock reside in the filesystem

#ifndef NULL
#define NULL (void *)0x0
#endif

//STUDENT: define additional parameters here, if any
#define FDISK_DATA_BLOCK_START 45 
#define FDISK_FBV_NUM_BLOCKS 8
#define FDISK_NUM_FBV 1024
#endif
