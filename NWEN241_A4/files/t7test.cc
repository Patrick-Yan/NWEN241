/**
 * t7test.cc
 * Sample test program for Task 7
 *
 * To compile with your implementation:
 * g++ t7test.cc dbms2.cc lldb.cc -o t7test
 *
 * If successful, executable file t7test should have been
 * created.
 */

#include <iostream>
#include "lldb.hh"


using namespace std;
using namespace dbms2;


struct movie movies[] = {
    { 13, "The Shawshank Redemption", 1994, "Frank Darabont" },
    { 25, "The Godfather", 1972, "Francis Ford Coppola" },
    { 31, "The Dark Knight", 2008, "Christopher Nolan" },
    { 40, "The Godfather: Part II", 1974, "Francis Ford Coppola" },
    { 55, "The Lord of the Rings: The Return of the King", 2003, "Peter Jackson" },
    { 72, "Pulp Fiction", 1994, "Quentin Tarantino" }
};


void addMovies(LinkedListDbTable *db)
{
    for(unsigned long i=0; i<sizeof(movies)/sizeof(movie); i++)
        db->add(movies[i]);
}

int main(void)
{
    LinkedListDbTable *db;
    bool r;
    
    cout << "Instantiating LinkedListDbTable..." << endl;
    db = new LinkedListDbTable();
    
    cout << "Adding 6 entries..." << endl;
    addMovies(db);
    cout << "Expected : rows = 6" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;
    
    for(int i=0; i<6; i++) {
        cout << "Invoking show(" << i << ")..." << endl;
        r = db->show(i);
        cout << "Expected return value: 1" << endl;
        cout << "Actual return value  : " << r << endl;
    }
    
    cout << "Invoking show(100)..." << endl;
    r = db->show(100);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;    

    cout << "Invoking remove(100)..." << endl;
    r = db->remove(100);
    cout << "Expected return value: 0" << endl;
    cout << "Actual return value  : " << r << endl;  
    
    cout << "Invoking remove(40)..." << endl;
    r = db->remove(40);
    cout << "Expected return value: 1" << endl;
    cout << "Actual return value  : " << r << endl; 
    cout << "Expected : rows = 5" << endl;
    cout << "Actual   : rows = " << db->rows() << endl;
    
    cout << "Invoking get(40)..." << endl;
    const movie *m1 = db->get(100);
    cout << "Expected return value: 0 (NULL)" << endl;
    cout << "Actual return value  : " << m1 << endl; 
    
    cout << "Invoking get(0)..." << endl;
    const movie *m2 = db->get(0);
    cout << "Expected return value: (not NULL)" << endl;
    cout << "Actual return value  : " << m2 << endl;     
    cout << "Expected m2->id : 13" << endl;
    cout << "Actual m2->id   : " << m2->id << endl;     
    
    cout << "Freeing LinkedListDbTable..." << endl;
    delete db;
    
    return 0;
}
