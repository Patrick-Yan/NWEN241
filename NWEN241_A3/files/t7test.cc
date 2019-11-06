/**
 * t7test.cc
 * Sample test program for Task 7
 * The test program assumes that you have already implemented the show() and add() functions.
 *
 * To compile with your implementation:
 * g++ t7test.cc dbms.cc -o t7test
 *
 * If successful, executable file t7test should have been
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
    
    cout << "The test program assumes that you have already implemented the show() and add() functions." << endl;
    cout << "Instantiating DbTable..." << endl;
    db = new DbTable();
    
    cout << "Adding 6 entries..." << endl;
    addAlbum1(db);
    addAlbum2(db);

    cout << "Removing entry with id=100 [not in table]..." << endl;
    bool r = db->remove(100);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;
    cout << "Expected    : rowsUsed = 6, rowsTotal = 10" << endl;
    cout << "From DbTable: rowsUsed = " << db->rows() << ", rowsTotal = " << db->allocated() << endl << endl;

    cout << "Removing entry with id=37..." << endl;
    r = db->remove(37);
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl;
    cout << "Expected    : rowsUsed = 5, rowsTotal = 5" << endl;
    cout << "From DbTable: rowsUsed = " << db->rows() << ", rowsTotal = " << db->allocated() << endl << endl;
   
    cout << "Removing entry with id=14..." << endl;
    r = db->remove(14);
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl;
    cout << "Expected    : rowsUsed = 4, rowsTotal = 5" << endl;
    cout << "From DbTable: rowsUsed = " << db->rows() << ", rowsTotal = " << db->allocated() << endl << endl;
 
    
    for(int i=0; i<4; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        bool r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl << endl;
    }   

    cout << "Freeing DbTable..." << endl;
    delete db;
    
    return 0;
}
