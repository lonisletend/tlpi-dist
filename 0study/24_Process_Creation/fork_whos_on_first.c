#include "tlpi_hdr.h"
#include <sys/wait.h>

int main(int argc, char const* argv[])
{
    int numChildren, j;
    pid_t childPid;

    if (argc > 1 && strcmp(argv[1], "--help") == 0)
        usageErr("%s [numChildren]\n", argv[0]);
    numChildren = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-children") : 1;
    setbuf(stdout, NULL);
    for (j = 0; j < numChildren; j++) {
        switch (childPid = fork()) {
        case -1:
            errExit("fork");
        case 0:
            printf("%d child\n", j);
            _exit(EXIT_SUCCESS);

        default:
            printf("%d parent\n", j);
            // sleep(3);
            wait(NULL);
            break;
        }
    }
    exit(EXIT_SUCCESS);
}
