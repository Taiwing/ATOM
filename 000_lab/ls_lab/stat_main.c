//#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    struct stat sb;

   if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

   if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

   printf("File type:                ");

   switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }
	printf("block device: %d\n", S_IFBLK);
	printf("char device: %d\n", S_IFCHR);
	printf("directory: %d\n", S_IFDIR);
	printf("FIFO/pipe: %d\n", S_IFIFO);
	printf("symlink: %d\n", S_IFLNK);
	printf("regular file: %d\n", S_IFREG);
	printf("socket: %d\n", S_IFSOCK);
   printf("I-node number:            %ld\n", (long) sb.st_ino);

   printf("Mode:                     %lo (octal)\n",
            (unsigned long) sb.st_mode);
   if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
		printf("st_rdev:			 %#lx\n", (long) sb.st_rdev);

   printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);
    printf("Ownership:                User=%s   Group=%s\n",
            getpwuid((long) sb.st_uid)->pw_name,
			getgrgid((long) sb.st_gid)->gr_name);

   printf("Preferred I/O block size: %ld bytes\n",
            (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long) sb.st_blocks);

	char *change, *access, *modif, *birth;
   	change = ctime(&sb.st_ctime);
   	access = ctime(&sb.st_atime);
   	modif = ctime(&sb.st_mtime);
   	birth = ctime(&sb.st_birthtime);
	printf("Last status change:       %s", change);
    printf("Last file access:         %s", access);
    printf("Last file modification:   %s", modif);
    printf("File creation:   	%s", birth);
	printf("birthtimensec:		%ld\n", (long int)sb.st_birthtime);
	printf("birthtimensec:		%lld\n", (long long int)sb.st_birthtime);

	printf("\nEXIT: %p\n", stdout);

   exit(EXIT_SUCCESS);
}
