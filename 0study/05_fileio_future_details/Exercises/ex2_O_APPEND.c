/* 5-2.Write a program that opens an existing file for writing with 
the O_APPEND flag, and then seeks to the beginning of the file
before writing some data. Where does the data appear in the 
file? Why? */

#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"


int main(int argc, char const *argv[])
{
    int fd;
    if (argc != 2 || strcmp(argv[1],"--help")==0) {
        usageErr("%s pathname\n",argv[1]);
    }
    fd = open(argv[1], O_RDWR | O_APPEND);
    
    if (fd == -1)
        errExit("open");
    if (lseek(fd,0,SEEK_SET) == -1)
        errExit("lseek");
    if (write(fd,"test",4) == -1)
        errExit("write");
    if (close(fd) == -1)
        errExit("close");
    return 0;
}
