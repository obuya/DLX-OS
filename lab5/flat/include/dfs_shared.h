#ifndef __DFS_SHARED__
#define __DFS_SHARED__

typedef struct dfs_superblock {
  // STUDENT: put superblock internals here
  int valid;
  int filesys_blocksize;
  int filesys_blocknum;
  int filesys_inodestart;
  int inodenum;
  int filesys_fbvstart;
  int fbvnum;
  int filesys_datastart;
} dfs_superblock;

#define DFS_BLOCKSIZE 512  // Must be an integer multiple of the disk blocksize
#define FILENAME_LENGTH 44 
typedef struct dfs_block {
  char data[DFS_BLOCKSIZE];
} dfs_block;

typedef struct dfs_inode {
  // STUDENT: put inode structure internals here
  // IMPORTANT: sizeof(dfs_inode) MUST return 96 in order to fit in enough
  // inodes in the filesystem (and to make your life easier).  To do this, 
  // adjust the maximumm length of the filename until the size of the overall inode 
  // is 96 bytes.
  int inuse;//1 in use, 0 not in use
  int filesize;
  char filename[FILENAME_LENGTH];
  uint32 direct[10];
  uint32 indirect;
} dfs_inode;

#define DFS_MAX_FILESYSTEM_SIZE 0x1000000  // 16MB
#define DFS_INODE_MAX_NUM 512
#define DFS_FBV_MAX_NUM (DFS_MAX_FILESYSTEM_SIZE)/((DFS_BLOCKSIZE)*32)
#define DFS_FAIL -1
#define DFS_SUCCESS 1



#endif
