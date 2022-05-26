#include<stdio.h>
#include"header.h"
int main ()
{
  int a,b;
  printf("enter two number\n");
  scanf("%d%d",&a,&b);
  printf("addition is %d\n",add(a,b));
  printf("multiplication is %d\n",mul(a,b));
  printf("division  is %d\n",div(a,b));
  
  return 0;

}