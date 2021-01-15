#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char pass[80];

void m(void)
{
  printf("%s - %d\n", pass, time(0));
  return;
}

int main(int argc,char **argv)
{
  char *s1;
  char *s2;
  char *s3;
  char *s4;

  FILE *fs;

  s1 = (char *)malloc(8);
  *s1 = 1;
  s2 = (char *)malloc(8);
  s1[1] = s2;

  s3 = (char *)malloc(8);
  *s3 = 2;
  s4 = (char *)malloc(8);
  s3[1] = s4;

  strcpy(s1[1], argv[1]);
  strcpy(s3[1], argv[2]);

  fs = fopen("/home/user/level8/.pass","r");
  fgets(pass, 68, fs);
  puts("~~");
  return 0;
}