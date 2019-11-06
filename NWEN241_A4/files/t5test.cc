/**
 * t5test.cc
 * Sample test program for Task 5
 * This test assumes that you have completed implementation of VectorDbTable in Task 4.
 *
 * To compile with your implementation:
 * g++ t5test.cc dbms2.cc vdb.cc -o t5test
 *
 * If successful, executable file t5test should have been
 * created.
 */

#include <iostream>
#include "vdb.hh"


using namespace std;
using namespace dbms2;


int main(void)
{
    VectorDbTable *db;
    bool r;
    
    cout << "Instantiating VectorDbTable..." << endl;
    db = new VectorDbTable();
       
    cout << "Invoking loadCSV(\"dummy\")..." << endl;
    r = db->loadCSV("dummy");
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;   
    
    cout << "Invoking loadCSV(\"default.csv\")..." << endl;
    r = db->loadCSV("default.csv");
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl;       
    cout << "Expected : rows = 3" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;  
    
    for(int i=0; i<3; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl;
    }
    
    cout << "Freeing VectorDbTable..." << endl;
    delete db;
    
    return 0;
}
