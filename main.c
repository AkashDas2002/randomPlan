#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
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

  //Writing to a file
  printf("\nWriting numbers to file...\n");
  int newFile = open("randomOutput", O_CREAT | O_EXCL | O_WRONLY, 0755);
  if (newFile < 0) {newFile = open("randomOutput", O_WRONLY);}

  int writing = write(newFile, someArray, 10 * sizeof(int));
  if (writing < 0){
    printf("There's an error %d: %s\n", errno, strerror(errno));
    return -1;
  }
  close(newFile);


  return 0;
}
