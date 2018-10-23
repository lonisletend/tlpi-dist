#include "tlpi_hdr.h"

int main(int argc, char const* argv[])
{
    setbuf(stdout, NULL);
    printf("Hello world\n");
    write(STDOUT_FILENO, "Ciao\n", 5);
    /* fflush(stdout); */ //强制刷新缓冲区
    if (fork() == -1)
        errExit("fork");

    //子进程调用_exit(), 父进程调用exit()
    /* switch(fork()){
    case -1:
        errExit("fork");
    case 0:
        _exit(EXIT_SUCCESS);
    } */

    exit(EXIT_SUCCESS);
}
