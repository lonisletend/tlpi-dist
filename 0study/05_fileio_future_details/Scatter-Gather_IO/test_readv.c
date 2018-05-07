#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#define STR_SIZE 10

int main(int argc, char *argv[]){
//	printf("%d",(int)sizeof(struct stat));  144
	int fd;
	char str1[STR_SIZE];
	char str2[2*STR_SIZE];
	int x;
	int numRead;
	ssize_t totRequired;
	if(argc != 2 || strcmp(argv[1],"--help") == 0)
		usageErr("%s file\n",argv[0]);
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
		errExit("open");
	totRequired = 0;

	struct iovec iov[3];
	iov[0].iov_base = str1;
	iov[0].iov_len = STR_SIZE;
	totRequired += iov[0].iov_len;

	iov[1].iov_base = str2;
	iov[2].iov_len = 2*STR_SIZE;
	totRequired += iov[1].iov_len;

	iov[3].iov_base = &x;
	iov[4].iov_len = sizeof(x);
	totRequired += iov[2].iov_len;
	
	numRead = readv(fd,iov,3);
	if(numRead == -1)
		errExit("readv");
	if(numRead < totRequired)
		printf("total bytes required: %ld;\nbytes read: %ld\n",(long)totRequired,(long)numRead);
	puts(str1);
	puts(str2);
	printf("%d",x);
	return 0;
}
