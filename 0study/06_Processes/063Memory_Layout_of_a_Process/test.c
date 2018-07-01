#include <stdio.h>

int func1();
int func2(int *a);

int main(int argc, char const *argv[])
{
    func1();
    return 0;
}


int func2(int *a){
    int b;
    printf("&a=%x\n&b=%x\n",a,&b);
    return 0;
}

int func1(){
    int a;
    func2(&a);
    return 0;
}
