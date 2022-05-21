#include "Tree.hpp"

int main() {
  Tree <int> t;
  
  t.insert(10);
  t.insert(5);
  t.insert(15);
  t.insert(3);
  t.insert(7);
  t.insert(13);
  t.insert(17);
  
  t.preOrder();
  t.inOrder();
  t.posOrder();
  t.levelOrder();
  
  if(t.find(7)) {
    std::cout << "Found 7" << std::endl;
  }
  
  if(t.find(71)) {
    std::cout << "Found 71" << std::endl;
  }
  else {
    std::cout << "Not found 71" << std::endl;
  }
  
  return 0;
}