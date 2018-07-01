/* This exercise is designed to demonstrate why the atomicity guaranteed by opening
a file with the O_APPEND flag is necessary. Write a program that takes up to three
command-line arguments:
$ atomic_append filename num-bytes [x]
This file should open the specified filename (creating it if necessary) and append
num-bytes bytes to the file by using write() to write a byte at a time. By default, the
program should open the file with the O_APPEND flag, but if a third command-line
argument (x) is supplied, then the O_APPEND flag should be omitted, and instead the
File I/O: Further Details 111
program should perform an lseek(fd, 0, SEEK_END) call before each write(). Run
two instances of this program at the same time without the x argument to write
1 million bytes to the same file:
$ atomic_append f1 1000000 & atomic_append f1 1000000
Repeat the same steps, writing to a different file, but this time specifying the x
argument:
$ atomic_append f2 1000000 x & atomic_append f2 1000000 x
List the sizes of the files f1 and f2 using ls –l and explain the difference. */

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"


int main(int argc, char const *argv[])
{
    int fd;
    size_t num_bytes;
    int isX = 0;
    if(argc != 3 && argc != 4 || strcmp(argv[1],"--help") == 0){
        usageErr("%s filename num-bytes [x]",argv[0]);
    }
    if(argc == 3){
        fd = open(argv[1], O_RDWR | O_APPEND | O_CREAT,S_IRUSR | S_IWUSR);
    }
    if(argc == 4 && strcmp(argv[3],"x") == 0){
        // printf("xxxxxxxxxxxx\n");
        fd = open(argv[1], O_RDWR | O_CREAT,S_IRUSR | S_IWUSR);
        isX = 1;
    }
    num_bytes = getLong(argv[2],GN_ANY_BASE,argv[2]);
    // printf("num_bytes=%ld\n",(long)num_bytes);
    // printf("isX=%d\n",isX);
    for(size_t i=0;i< num_bytes;i++){
        if(isX == 1){
            // printf("test ");
            // printf("\n");
            if(lseek(fd,0,SEEK_END) == -1)
                errExit("lseek");
        }
        if(write(fd,"a",1) == -1)
            errExit("write");
    }
    if(close(fd) == -1)
        errExit("close");

    return 0;
}
