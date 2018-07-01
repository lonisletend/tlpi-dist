#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	printf("getpid() = %d\n",(int)getpid());
	printf("getppid() = %d\n",(int)getppid());
	return 0;

}y

