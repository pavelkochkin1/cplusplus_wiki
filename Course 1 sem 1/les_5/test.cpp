#include <stdio.h>
#include <string.h>
int main(void)
{
char *p;
p = strchr ("this is a test", ' ');
printf(p);
return 0;
}