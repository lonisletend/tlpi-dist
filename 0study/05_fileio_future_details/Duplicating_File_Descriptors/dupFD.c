/*  测试文件描述符正副本共享同一打开文件句柄  */
/*    文件句柄所含的文件偏移量和状态标志      */
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd, newfd, offset, newoffset, flags, newflags;
	fd = open("myfile",O_RDWR);   //myfile已经存在
	if(fd == -1)
		errExit("open");
	else
		printf("fd = %d\n",fd);
	newfd = dup(fd);
	if(newfd == -1)
		errExit("dup");
	else
		printf("newfd = %d\n",newfd);
	if(lseek(fd,20,SEEK_SET) == -1)
		errExit("lseek1");
	offset = lseek(fd,0,SEEK_CUR);
	newoffset = lseek(newfd,0,SEEK_CUR);
	if(offset == -1 || newoffset == -1)
		errExit("lseek2");
	else if(offset == newoffset)
		printf("same offset!\n");
	flags = fcntl(fd,F_GETFL);
	newflags = fcntl(newfd,F_GETFL);
	if(flags == -1 || newflags == -1)
		errExit("fcntl");
	else if(flags == newflags)
		printf("same flags!\n");

	return 0;
}
