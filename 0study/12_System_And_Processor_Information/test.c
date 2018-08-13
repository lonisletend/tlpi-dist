#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    char str[100] = "this is an example!";
    // printf("%.*s\n",9,str);
    system("echo test:" "`cat /proc/sys/kernel/pid_max`");
    return 0;
}