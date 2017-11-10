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
size_t replace_spaces_with_nulls(char* str, char* end) {
  size_t num_substrings;
  for (num_substrings = 0; str != end; num_substrings++) {
    strsep(&str, " ");
  }
  return num_substrings;
}

char** parse_args(char* line) {
  char* line_copy = make_copy(line);
  size_t line_len = strlen(line_copy);

  char* end = line_copy + line_len;
  size_t num_substrings = replace_spaces_with_nulls(line_copy, end);
  char** args_buf = malloc(num_substrings + 1);
  args_buf[num_substrings] = NULL;
  
  char* cur_ptr = line_copy;
  size_t i;
  for (i = 0; cur_ptr != end; i++) {
    args_buf[i] = cur_ptr;
    cur_ptr = cur_ptr + strlen(cur_ptr) + 1;
  }

  return args_buf;
}
