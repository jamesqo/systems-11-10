#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parse_args.h"

int main(int argc, char** argv) {
  if (argc == 1) {
    printf("You need to enter an argument!\n");
    exit(1);
  }

  char* line = argv[1];
  char** args = parse_args(line);
  execvp(args[0], args);

  return 0;
}
