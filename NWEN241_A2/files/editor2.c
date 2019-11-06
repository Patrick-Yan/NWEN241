

#include <stdio.h>
#include "editor2.h"
#include <string.h>

int editor_count_lines( char *ptr,int sizeofb){

int count = 0;

for(int i=0;i < sizeofb ;i++){
  if(ptr[i] == '\n'){ //if pointer euqal to a newline character
    count++;
  }
}
return count;
}

///////////////////////////////////////////////////////////////////////////
int editor_search_multiple(char *buffer, int size,char *word,int positions[], int max){

int n = 0;
int same = 0;
int count = 0;

for(int i = 0 ; i < size ; i++){
     if(buffer[i]==word[same]){same++;}
     else same = 0;
     if(same==strlen(word)){//if the number of character we judged euqals to the length of word
       count++;
       positions[n]=i-same+1;
       n++;
     }
     if(count==max)break;
}

return count;
}
// //Task1
// 1.float * ptr
// 2.long *ptr(int a , int b){};
// 3.char * ptr(const char *const ptr );
// 4.int *ptr[20];
// 5.Strng myStr[] = {“cyan”,”megenta”,”yellow”,”black”};
// Task2
// 1.1100
// 2.1101
// 3.1101
// 4.66
// 5.C
// Task3
// 1.57 80
//    80 80
// 2. in1 equals to
// Task4
// 1102
// 1102
// 4
// Task5
//      1.printf(“%s”, *strPtr);
//         *strPtr++;
//
