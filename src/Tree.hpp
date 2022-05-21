#include <iostream>
#include "Node.hpp"
#include "Queue.hpp"

template <class T>
class Tree {
  private:
    Node <T> * root;
    
    Node <T> * newNode(T val) {
      Node <T> * nNode = new Node <T> ();
      nNode->setVal(val);
      return nNode;
    }
    
    void insert(Node <T> * tmp, T val) {
      if(val < tmp->getVal()) { // <
        if(tmp->getEsq() == 0) tmp->setEsq(newNode(val));
        else                   insert(tmp->getEsq(), val);
      }
      else { // > ou == 
        if(tmp->getDir() == 0) tmp->setDir(newNode(val));
        else                   insert(tmp->getDir(), val);
      }
    }
    
    void preOrder(Node <T> * tmp) {
      std::cout << tmp->getVal() << " ";
      if(tmp->getEsq() != 0) preOrder(tmp->getEsq());
      if(tmp->getDir() != 0) preOrder(tmp->getDir());
    }
    
    void inOrder(Node <T> * tmp) {
      if(tmp->getEsq() != 0) inOrder(tmp->getEsq());
      std::cout << tmp->getVal() << " ";
      if(tmp->getDir() != 0) inOrder(tmp->getDir());
    }
    
    void posOrder(Node <T> * tmp) {
      if(tmp->getEsq() != 0) posOrder(tmp->getEsq());
      if(tmp->getDir() != 0) posOrder(tmp->getDir());
      std::cout << tmp->getVal() << " ";
    }
    
    void levelOrder(Node <T> *tmp) {
      Queue <Node <T> *> q;
      q.insert(tmp);
      while(!q.empty()) {
        Node <T> * first = q.getFirst();
        std::cout << first->getVal() << " ";
        q.remove();
        if(first->getEsq() != 0)
          q.insert(first->getEsq());
        if(first->getDir() != 0)
          q.insert(first->getDir()); 
      }
    }
    
  public:
    
    Tree() {
      root = 0;
    }
    
    // Interface
    void insert(T val) {
      if(root == 0) root = newNode(val);
      else          insert(root, val);
    }
    
    void preOrder() {
      if(root == 0) {
        std::cout << "Empty Tree" << std::endl;
      }
      else {
        preOrder(root);
        std::cout << std::endl;
      }
    }
    
    void inOrder() {
      if(root == 0) {
        std::cout << "Empty Tree" << std::endl;
      }
      else {
        inOrder(root);
        std::cout << std::endl;
      }
    }
    
    void posOrder() {
      if(root == 0) {
        std::cout << "Empty Tree" << std::endl;
      }
      else {
        posOrder(root);
        std::cout << std::endl;
      }
    }
    
    void levelOrder() {
      if(root == 0) {
        std::cout << "Empty Tree" << std::endl;
      }
      else {
        levelOrder(root);
        std::cout << std::endl;
      }
      
    }
    
    bool find(T val) {
      Node <T> * tmp = root;
      while(tmp != 0) {
        if(val == tmp->getVal() )     return true;
        else if (val < tmp->getVal()) tmp = tmp->getEsq();
        else                          tmp = tmp->getDir();
      }
      return false;
    }
};