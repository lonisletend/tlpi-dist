#include <stdio.h>
#include "tlpi_hdr.h"


int main(int argc, char const *argv[])
{
    char **p;
    for(p=argv; *p!=NULL; p++)
        // puts(*p);
        printf("%s ",*p);
    printf("\n");
    return 0;
}
