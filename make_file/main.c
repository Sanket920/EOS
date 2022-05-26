#include<stdio.h>
#include"main.h"
int main()
{  printf("enter two number: ");
   int a,b;
   scanf("%d%d",&a,&b);

    printf("%d\n",add(a,b));
    printf("%d\n",sub(a,b));
    printf("%d\n",mul(a,b));
    return 0;
}