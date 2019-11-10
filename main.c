#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int random_generator(){
  int rand = open("/dev/random", O_RDONLY);
  int buf;
  read(rand, &buf, sizeof(int));
  close(rand);
  return buf;
}

int main() {
  int index = 0;
  int someArray[10];

  // Populate someArray
  while(index < 10){
    someArray[index] = random_generator();
    index++;
  }

  //Print out elements of someArray
  index = 0;
  while(index < 10){
    printf("random %d: %d\n", index, someArray[index]);
    index++;
  }
  return 0;
}
