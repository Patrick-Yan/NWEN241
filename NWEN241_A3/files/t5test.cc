/**
 * t5test.cc
 * Sample test program for Task 5. 
 * The test program assumes that you have already implemented the add() function.
 *
 * To compile with your implementation:
 * g++ t5test.cc dbms.cc -o t5test
 *
 * If successful, executable file t5test should have been
 * created.
 */

#include <iostream>
#include "dbms.hh"


using namespace std;
using namespace dbms;


struct album defaultAlbums[] = {
    { 10, "The Dark Side of the Moon", 1973, "Pink Floyd" },
    { 14, "Back in Black", 1980, "AC/DC" },
    { 23, "Their Greatest Hits", 1976, "Eagles" }
};


void populateDbTable(DbTable *db)
{
    for(unsigned long i=0; i<sizeof(defaultAlbums)/sizeof(album); i++)
        db->add(defaultAlbums[i]);
}


int main(void)
{
    DbTable *db;
    
    cout << "The test program assumes that you have already implemented the add() function." << endl;
    cout << "Instantiating DbTable..." << endl;
    db = new DbTable();
    
    cout << "Populating DbTable with 3 entries..." << endl << endl;
    populateDbTable(db);

    cout << "Invoking show(4)..." << endl;
    bool r = db->show(4);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl << endl;

    for(int i=0; i<3; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl << endl;
    }
    
    cout << "Freeing DbTable..." << endl;
    delete db;
    
    return 0;
}
