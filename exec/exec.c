#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before exec\n");
    execl("/usr/bin/pwd","/usr/bin/pwd", NULL);
    printf("After exec\n");
    return 0;
}
