/**
 * t7test.c
 * Sample test program for Task 7
 *
 * To compile with your implementation:
 * gcc t7test.c editor2.c -o t7test
 *
 * If successful, executable file t7test should have been
 * created.
 */

#include <stdio.h>
#include "editor2.h"

#define TEST_STRING \
  "Alice opened the door and\n"\
  "found that it led into a small passage,\n"\
  "not much larger than a rat-hole: she\n"\
  "knelt down and looked along the \n"\
  "passage into the loveliest garden you ever saw.\n\n"

int main(void)
{
  char buffer[] = TEST_STRING;

  printf("Buffer contents: %s", buffer);
  int r = editor_count_lines(buffer, sizeof(buffer));
  printf("Output of editor_count_lines()  : %d\n", r);
  printf("Actual number of lines in buffer: 6\n");

  return 0;
}

// int editor_count_lines(const char *ptr,int sizeofb){
// //ptr=buffer;
// int count = 0;
// for(int i=0;i < sizeofb ;i++){
//   if(ptr[i] == '\n'){
//     count++;
//   }
// }
// return count;
// }
