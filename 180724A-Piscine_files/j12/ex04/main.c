#include<stdio.h>
#include<fcntl.h>
#include<utmp.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
      int fd;
	int br;
      struct utmp cr;
      int reclen = sizeof(struct utmp);

      fd = open("/var/log/wtmp.1", O_RDONLY);
	//fd = open(WTMP_FILE, O_RDONLY);
      if (fd == -1){
        perror("oops");
        exit(1);
      }
      while ((br = read(fd, &cr, reclen)) > 0)
        printf("-- %s\n", cr.ut_user);
	printf("reclen = %d\n", reclen);
	printf("br = %d\n", br);
      close (fd);
      return 0;
}
