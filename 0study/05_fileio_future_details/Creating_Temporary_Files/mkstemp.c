/*              创建临时文件       */
/*    			 mkstemp()         */
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd;
	char template[] = "/tmp/somestringXXXXXX";

	fd = mkstemp(template);
	if(fd == -1)
		errExit("mkstemp");
	printf("Generated filename was: %s\n",template);
	sleep(60);
	unlink(template);

	if(close(fd) == -1)
		errExit("close");
	return 0;
}
