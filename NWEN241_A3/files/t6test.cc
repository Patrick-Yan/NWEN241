/**
 * t6test.cc
 * Sample test program for Task 6
 * The test program assumes that you have already implemented the show() function.
 *
 * To compile with your implementation:
 * g++ t6test.cc dbms.cc -o t6test
 *
 * If successful, executable file t6test should have been
 * created.
 */

#include <iostream>
#include "dbms.hh"


using namespace std;
using namespace dbms;


struct album albums1[] = {
    { 10, "The Dark Side of the Moon", 1973, "Pink Floyd" },
    { 14, "Back in Black", 1980, "AC/DC" },
    { 23, "Their Greatest Hits", 1976, "Eagles" }
};


struct album albums2[] = {
    { 37, "Falling into You", 1996, "Celine Dion" },
    { 43, "Come Away With Me", 2002, "Norah Jones" },
    { 55, "21", 2001, "Adele" }
};



void addAlbum1(DbTable *db)
{
    for(unsigned long i=0; i<sizeof(albums1)/sizeof(album); i++)
        db->add(albums1[i]);
}


void addAlbum2(DbTable *db)
{
    for(unsigned long i=0; i<sizeof(albums2)/sizeof(album); i++)
        db->add(albums2[i]);
}


int main(void)
{
    DbTable *db;
    
    cout << "The test program assumes that you have already implemented the show() function." << endl;
    cout << "Instantiating DbTable..." << endl;
    db = new DbTable();
    
    cout << "Adding 3 entries..." << endl;
    addAlbum1(db);
    cout << "Expected    : rowsUsed = 3, rowsTotal = 5" << endl;
    cout << "From DbTable: rowsUsed = " << db->rows() << ", rowsTotal = " << db->allocated() << endl << endl;
    for(int i=0; i<3; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        bool r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl << endl;
    }

    cout << "Adding 3 more entries..." << endl;
    addAlbum2(db);
    cout << "Expected    : rowsUsed = 6, rowsTotal = 10" << endl;
    cout << "From DbTable: rowsUsed = " << db->rows() << ", rowsTotal = " << db->allocated() << endl << endl;
    for(int i=3; i<6; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        bool r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl << endl;
    }    

    cout << "Freeing DbTable..." << endl;
    delete db;
    
    return 0;
}
