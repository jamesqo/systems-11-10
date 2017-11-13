#include "parse_args.h"

#include <stdlib.h>
#include <string.h>

char* make_copy(char* str) {
  size_t buf_len = strlen(str) + 1;
  char* new_str = malloc(buf_len);
  strncpy(new_str, str, buf_len);
  return new_str;
}

// Returns the number of substrings the array is split into
size_t replace_spaces_with_nulls(char* str) {
  size_t num_substrings;
  // Note: strsep sets str to NULL once it reaches a NULL
  // that it didn't place there itself.
  for (num_substrings = 0; str; num_substrings++) {
    strsep(&str, " ");
  }
  return num_substrings;
}

char** parse_args(char* line) {
  char* line_copy = make_copy(line);
  size_t num_substrings = replace_spaces_with_nulls(line_copy);
  char** args_buf = malloc(num_substrings + 1);
  args_buf[num_substrings] = NULL;
  
  char* cur_ptr = line_copy;
  size_t i;
  for (i = 0; i < num_substrings; i++) {
    args_buf[i] = cur_ptr;
    cur_ptr = cur_ptr + strlen(cur_ptr) + 1;
  }

  return args_buf;
}
