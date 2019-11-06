#include <iostream>
#include "dbms.hh"

using namespace dbms;
#include <cstdlib>
#include <cstring>
//using namespace dbms;
using namespace std;

DbTable::DbTable(){
   rowsTotal=5;
   rowsUsed=0;
  table = (album *) calloc(rowsTotal, sizeof(album));
}

DbTable::~DbTable(){
  free(table);
}

unsigned int DbTable::rows(){
  return rowsUsed;
}
unsigned int DbTable::allocated(){
  return rowsTotal;
}

bool DbTable::add(album &a){
    if(rowsUsed == rowsTotal-1){
        album* temp = (album*)calloc(rowsTotal+5, sizeof(album));//to temporary hold values by temp pointer

        for (int i=0; i<rowsTotal; i++) {
            temp[i] = table[i];
        }

        free(table);// free the previous table
        table = (album*)calloc(rowsTotal+5, sizeof(album));//then assign a new memory location

        for (int i=0; i<rowsTotal; i++) {
            table[i] = temp[i];// put the values back to table
        }
        free(temp);
        rowsTotal += 5;
    }
    // add the new album to the last
    for (int i = 0; i < rowsTotal; i++) {
        if (table[i].id == 0) {
            table[i] = a;
            rowsUsed++;
            return true;
        }
    }
    return false;
}

bool DbTable::show(unsigned int num){
    if (table[num].id != 0) {
        cout<<table[num].id<<" "<<table[num].title<<" "<<table[num].year<<" "<<table[num].artist<<endl;
        return true;
    }
    return false;
}
