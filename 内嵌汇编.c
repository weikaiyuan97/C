#include<stdio.h>

int main()
{
    unsigned int val1 = 1;
    unsigned int val2 = 2;
    unsigned int val3 = 0;
    printf("val1:%d,val2:%d,val3:%d\n",val1,val2,val3);
    asm volatile(
            "movl $0,%%eax\n\t"/*将eax清零*/
            "addl %1,%%eax\n\t"/*eax+=val1*/
            "addl %2,%%eax\n\t"/*eax+=val2*/
            "movl %%eax,%0\n\t"/*val3=eax*/
            :"=m"(val3)//%0,第一个参数
            :"c"(val1)/*ecx = val1*/,"d"(val2)/*edx = val2*/
            );

    printf("val1:%d,val2:%d,val3:%d\n",val1,val2,val3);
    return 0;
}
