#include <cstdio>
#include <cstdlib>
using namespace std;

namespace dbms2{
class LinkedListDbTable : public AbstractDbTable{
private:
  struct node{
  movie m;
  struct node *next;
  };
  Node *head; // this is the private member variable. It is just a pointer to the first Node
public:
  LinkedList();// constructor
  ~LinkedList();// destructor
   const int rows();
   bool show(const int num);
   bool add(movie &a);
   bool remove(unsigned long m);
   movie* get(const int num);

};
}
