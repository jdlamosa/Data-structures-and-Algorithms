#include <iostream>
#include <list>
#include "Node.hpp"
#include "vertex.hpp"

template <class T>
class Tree {
  private:
    Node <T> * root;
    
    Node <T> * newNode(T px, T py, int d) {
      Node <T> * nNode = new Node <T> ();
      nNode->setX(px);
      nNode->setY(py);
      nNode->setDepth(d);
      return nNode;
    }
    
    void insert(Node <T> * tmp, T px, T py) {

      if(!find(px, py)){
      int d = tmp->getDepth()+1;
      if(tmp->getDepth()%2 == 0) {
        if(px < tmp->getX()) {
          if(tmp->getEsq() == 0) {
          tmp->setEsq(newNode(px, py, d));
          tmp->getEsq()->setPar(tmp);
          }
          else insert(tmp->getEsq(), px, py);
        } //if px < tmp->X
        else {
          if(tmp->getDir() == 0){
            tmp->setDir(newNode(px, py, d));
            tmp->getDir()->setPar(tmp);
          }
          else insert(tmp->getDir(), px, py);
        }
      }
      else {
        if(py < tmp->getY()) {
            if(tmp->getEsq() == 0) {
            tmp->setEsq(newNode(px, py, d));
            tmp->getEsq()->setPar(tmp);
            }
            else insert(tmp->getEsq(), px, py);
          } //if px < tmp->X
          else {
            if(tmp->getDir() == 0){
              tmp->setDir(newNode(px, py, d));
              tmp->getDir()->setPar(tmp);
            }
            else insert(tmp->getDir(), px, py);
          } 
        }  
      }
    }
    
    void preOrder(Node <T> * tmp) {
      std::cout <<"("<< tmp->getX() << "," << tmp->getY() << ") ";
      if(tmp->getEsq() != 0) preOrder(tmp->getEsq());
      if(tmp->getDir() != 0) preOrder(tmp->getDir());
    }
    
    
    void clear(Node <T> * tmp) {
      if(tmp->getEsq() != 0) clear(tmp->getEsq());
      if(tmp->getDir() != 0) clear(tmp->getDir());
      delete tmp;
      tmp == 0;
    }
    
    Node <T> * findNode(T px) {
      Node <T> * tmp = root;
      while(tmp != 0) {
        if(px == tmp->getX() )     return tmp;
        else if (px < tmp->getX()) tmp = tmp->getEsq();
        else                          tmp = tmp->getDir();
      }
      return 0;
    }
    
    void  findRet(std::list< Node<T> > &vr, Node <T> * tmp, Vertex <T>  v1, Vertex <T>  v3 ) {
      if(tmp) {
        if  (tmp->getX() >= v1.getX() && tmp->getY() >= v1.getY()  
          && tmp->getX() <= v3.getX() && tmp->getY() <= v3.getY()) {
            vr.push_back(*tmp);
        }
        if(tmp->getDepth() == 0){
          if(v1.getX() < tmp->getX()){ findRet(vr, tmp->getEsq(), v1, v3); }
          if(v3.getX() > tmp->getX()){ findRet(vr, tmp->getDir(), v1, v3); }
        }
        else {
          if(v1.getY() < tmp->getY()){ findRet(vr, tmp->getEsq(), v1, v3); }
          if(v3.getY() > tmp->getY()){ findRet(vr, tmp->getDir(), v1, v3); }
        }
      }      
    }
      
    
  public:
    
    Tree() {
      root = 0;
    }
    ~Tree() {
      clear();
    }
    
    // Interface
    void insert(T px, T py) {
      if(root == 0) root = newNode(px, py, 0);
      else {
        insert(root, px, py);
      }
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
    
  
    bool find(T px, T py) {
      Node <T> * tmp = root;
      int d = 0;
      while(tmp != 0) {
        d++;
        if(px == tmp->getX() && py == tmp->getY())     return true;
        else if (d%2!=0) {
          if (px < tmp->getX())    tmp = tmp->getEsq();
          else                     tmp = tmp->getDir();
        }
        else {
          if (py > tmp->getY())    tmp = tmp->getDir();
          else                     tmp = tmp->getEsq();
         }     
      }
      return false;
    }
    
    Node <T> * findNode(T px, T py) {
      Node <T> * tmp = root;
      int d = 0;
      while(tmp != 0) {
        d++;
        if(px == tmp->getX() && py == tmp->getY())     return tmp;
        else if (d%2!=0) {
          if (px < tmp->getX())    tmp = tmp->getEsq();
          else                     tmp = tmp->getDir();
        }
        else {
          if (py > tmp->getY())    tmp = tmp->getDir();
          else                     tmp = tmp->getEsq();
         }     
      }
      return 0;
    }
    
     /* 
      v4 ---------* v3
         -        -
         -        -
         -        -
      v1 *--------- v2
      
      v1 e v3 informados pelo usuario
      
     */
    std::list< Node<T> >  findRet(Vertex <T>  v1,  Vertex <T>  v3) {
      std::list< Node<T> > vr;
      Node <T> * tmp;
      if(root == 0){
        std::cout << "Empty Tree" << std::endl;
        return vr;
      }
      else {
       findRet(vr, root, v1, v3) ;
      }
      return vr;
    }
    
    
    
    void clear() {
      if(root != 0) {
        clear(root);
        root = 0;
      }
    }
    
    inline bool empty() { (root == 0)?true:false;  }
    
    
    
    
};