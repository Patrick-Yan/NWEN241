
#include <iostream>
#include "dbms2.hh"
using namespace std;
#include <cstdlib>
#include <cstring>
#include "vdb.hh"
#include <vector>
using namespace dbms2;
//namespace dbms2 {

//std::vector<movie> m;

// VectorDbTable:: VectorDbTable(){
//
//   };
//   VectorDbTable::~VectorDbTable(){
//     m.clear();
//  };

const int VectorDbTable::rows(){
  return m.size();
}
bool VectorDbTable::show(const int num){

  if ((m.size()>0) && ((num) < m.size()) &&( num >= 0)) {
      //moive vm = m[num];
      cout<<m[num].id<<" "<<m[num].title<<" "<<m[num].year<<" "<<m[num].director<<endl;
      return true;
  }
  return false;
}
bool VectorDbTable::add(movie &a){
    m.push_back(a);
    return true;
    //else return false;
}
movie* VectorDbTable::get(const int num){
  if(num<0||num>m.size()){return nullptr;}
  return &m[num];

}

bool VectorDbTable::remove(unsigned long l){
  for(int i = 0;i<m.size();i++){
      if(m[i].id==l){
        m.erase(m.begin()+i);
        return true;
      }
  }
  return false;
}


//}
