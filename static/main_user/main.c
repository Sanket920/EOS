#include<stdio.h>
#include"header.h"
int main ()
{
  int a,b;
  printf("enter number\n");
  scanf("%d%d",&a,&b);
  printf("addition %d\n",add(a,b));
  printf("multiplication %d\n",mul(a,b));
  printf("division %d\n",div(a,b));
  
  return 0;

}
