/*              截断文件           */
/*    truncate()  &  ftruncate()   */
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd;
	fd = open("myfile",O_RDWR);
	if(fd == -1)
		errExit("open");
	if( ftruncate(fd, 20) == -1)
		errExit("ftruncate");
	if(truncate("myfile2",20) == -1)
		errExit("truncate");
	if(truncate("myfile3",60) == -1)
		errExit("truncate2");	


	return 0;
}
