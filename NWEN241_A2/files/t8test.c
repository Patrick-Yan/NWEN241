/**
 * t8test.c
 * Sample test program for Task 8
 *
 * To compile with your implementation:
 * gcc t8test.c editor2.c -o t8test
 *
 * If successful, executable file t8test should have been
 * created.
 */
#include <string.h>
#include <stdio.h>
#include "editor2.h"

#define TEST_STRING "The good, the bad and the lucky."

int main(void)
{
  char buffer[] = TEST_STRING;
  int positions[20];
  int *pp = positions;

  printf("Buffer contents: %s", buffer);
  int r = editor_search_multiple(buffer, sizeof(buffer), "the", positions, 20);
  printf("\nOutput of editor_search_multiple(): %d\n", r);
  printf("Positions: { ");
  for(int i=0; i<r; i++) { printf("%d ", *pp); pp++; }
  printf("}\nActual number of occurrences in buffer of 'the': 2\n");
  printf("Positions: { 10 22 }\n");

  return 0;
}
