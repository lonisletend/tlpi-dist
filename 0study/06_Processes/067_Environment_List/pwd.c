#include <stdio.h>
#include <string.h>
#include <tlpi_hdr.h>

int pwdPatch(char* ex);
int oldpwdPatch(char* ex);
extern char **environ;


int main(int argc, char const *argv[])
{
    char **ep;
    for(ep = environ; *ep != NULL; ep++){
        if(pwdPatch(*ep)){
            printf("当前路径：");
            puts(&((*ep)[4]));
        }
        if(oldpwdPatch(*ep)){
            printf("上一路径：");
            puts(&((*ep)[7]));
        }
    }
    char name[10]="PWD";
    puts(getenv(name));
    
    exit(EXIT_SUCCESS);
}

int pwdPatch(char* ex){
    char a[10]="PWD";
    for(int i=0;i<3;i++){
        if(ex[i] != a[i])
            return 0;
    }
    return 1;
}
int oldpwdPatch(char* ex){
    char a[10]="OLDPWD";
    for(int i=0;i<6;i++){
        if(ex[i] != a[i])
            return 0;
    }
    return 1;
}