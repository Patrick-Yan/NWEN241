
#ifndef __EDITOR2_H__
#define __EDITOR2_H__
#include <string.h>

//#define TEST_STRING

int editor_count_lines(char *ptr,int sizeofb);
int editor_search_multiple(char *buffer, int size, char *word ,int positions[], int max);


#endif
