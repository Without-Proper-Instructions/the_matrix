/*
 * matrix.c - Enter the matrix
 * N. DeMarinis & L. Fogel
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define THE_MATRIX "/matrix"
#define WD_SIZE 2014

int main(int argc, char **argv)
{
  char wd[WD_SIZE];
  int result;

  getcwd(wd, WD_SIZE);

  chdir(THE_MATRIX);
  chroot(THE_MATRIX);
  chdir(wd);

  char* path = argv[0];

  // If the path to exec begins with a ".", exec its basename (search
  // for it in PATH) instead
  if(path[0] == '.')
  {
    path = basename(argv[0]);
  }

  result = execvp(path, &argv[1]);
  printf("Exec result on %s:  %d, %s\n", path, result, strerror(errno));

  return 0;
}
