#ifndef _LINUX_STAT_H
#define _LINUX_STAT_H

#include <linux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define S_IFMT  00170000	/* type of file */
#define S_IFSOCK 0140000	/* named socket */
#define S_IFLNK	 0120000	/* symbolic link */
#define S_IFREG  0100000	/* regular */
#define S_IFBLK  0060000	/* block special */
#define S_IFDIR  0040000	/* directory */
#define S_IFCHR  0020000	/* character special */
#define S_IFIFO  0010000	/* fifo */
#define S_ISUID  0004000	/* set user id on execution */
#define S_ISGID  0002000	/* set group id on execution */
#define S_ISVTX  0001000	/* save swapped text even after use */

#define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)

#define S_IRWXU 00700		/* rwx for owner */
#define S_IRUSR 00400		/* read permission for owner */
#define S_IWUSR 00200		/* write permission for owner */
#define S_IXUSR 00100		/* execute/search permission for owner */

#define S_IRWXG 00070		/* rwx for group */
#define S_IRGRP 00040		/* read permission for group */
#define S_IWGRP 00020		/* write permission for group */
#define S_IXGRP 00010		/* execute/search permission for group */

#define S_IRWXO 00007		/* rwx for other */
#define S_IROTH 00004		/* read permission for other */
#define S_IWOTH 00002		/* read permission for other */
#define S_IXOTH 00001		/* execute/search permission for other */

struct stat {
	unsigned short st_dev;
	unsigned short __pad1;
	unsigned long st_ino;
	unsigned short st_mode;
	unsigned short st_nlink;
	unsigned short st_uid;
	unsigned short st_gid;
	unsigned short st_rdev;
	unsigned short __pad2;
	loff_t  st_size;
	unsigned long  st_blksize;
	unsigned long  st_blocks;
	unsigned long  st_atime;
	unsigned long  __unused1;
	unsigned long  st_mtime;
	unsigned long  __unused2;
	unsigned long  st_ctime;
	unsigned long  __unused3;
	unsigned long  __unused4;
	unsigned long  __unused5;
};

#ifdef __cplusplus
}
#endif

#endif
