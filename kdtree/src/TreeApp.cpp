#include "Tree.hpp"

void printV(std::list<Node <int> > node) {
    for( std::list<Node <int> >::iterator it = node.begin(); it != node.end(); it++) {
        (*it).print(); std::cout << " ";
    }
    std::cout << std::endl;
}


int main() {
  Tree <int> t;
  Node <int> *x;
  Vertex <int> v1;
  Vertex <int> v3;
  std::list< Node <int> > vr;


  bool exits;
  
 
  t.insert(7,2);
  
  t.insert(4,7);
  t.insert(5,4); 
  t.insert(9,6);
  t.insert(2,3);
  t.insert(8,1);
  
  /* 
  v4 ---------* v3
      -        -
      -        -
      -        -
  v1 *--------- v2
  */
  
  v1.insert(1, 1);
  v3.insert(10, 10);
   
  std::cout << std::endl;
  t.preOrder();
  std::cout << std::endl;

  exits = t.find(4,7);  
  if(exits){
    x = t.findNode(4,7);
    std::cout<<"(x,y): (" << x->getX() << "," << x->getY() << ")" << std::endl;
  }
  
  
  vr = t.findRet(v1,v3);
  
  std::cout << std::endl;
  printV(vr);
  
  t.clear();
  t.preOrder();
  return 0;
}