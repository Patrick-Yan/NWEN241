
#include <iostream>
#include "editor2.hh"


using namespace editor2;
int EditorUtilities::countWords(char* buffer,int size){

int count = 0;

 for (int i = 0; i < size; i++){
   //traverse everything in buffer
   if(buffer[i]==' '||buffer[i]=='\t'||buffer[i]=='\n'||buffer[i]=='\v'||buffer[i]=='\f'||buffer[i]=='\r'){
     //if the value of pointer is :  ' ' or '\t' or......
       if(buffer[i-1]!=' '&&buffer[i-1]!='\t'&&buffer[i-1]!='\n'&&buffer[i-1]!='\v'&&buffer[i-1]!='\f'&&buffer[i-1]!='\r'){
         //if the formal character is not:  ' ' and '\t' and.......
            count++;
    }
   }

 }
 return count+1;
}
