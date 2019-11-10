#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main() {
  int rand = open("/dev/random", O_RDONLY);
  printf("%d\n",rand);
  return 0;
}
