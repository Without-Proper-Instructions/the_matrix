#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define THE_MATRIX "/matrix"

int main(int argc, char **argv)
{
  chdir(THE_MATRIX);
  chroot(THE_MATRIX);
  chdir("/");

  execvp(argv[1], &argv[2]);
  
  return 0;
}
