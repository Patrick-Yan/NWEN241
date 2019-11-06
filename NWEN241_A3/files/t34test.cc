/**
 * t34test.cc
 * Sample test program for Tasks 3 and 4
 *
 * To compile with your implementation:
 * g++ t34test.cc dbms.cc -o t34test
 *
 * If successful, executable file t34test should have been
 * created.
 */

#include <iostream>
#include "dbms.hh"


using namespace std;
using namespace dbms;

int main(void)
{
    DbTable *db;
    
    cout << "Instantiating DbTable..." << endl;
    db = new DbTable();
    
    cout << "Expected    : rowsUsed = 0, rowsTotal = 5" << endl;
    cout << "From DbTable: rowsUsed = " << db->rows() << ", rowsTotal = " << db->allocated() << endl;

    cout << "Freeing DbTable..." << endl;
    delete db;
    
    return 0;
}
