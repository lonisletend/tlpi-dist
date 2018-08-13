#define _GNU_SOURCE
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    struct utsname* uts = (struct utsname*)malloc(sizeof(struct utsname));
    if(uname(uts)==-1){
        printf("uname error");
        exit(EXIT_FAILURE);
    }

    printf("Node name:    %s\n",uts->nodename);
    printf("System name:  %s\n",uts->sysname);

#ifdef _GNU_SOURCE
    printf("Domain name:  %s\n",uts->domainname);
#endif

    return 0;
}
