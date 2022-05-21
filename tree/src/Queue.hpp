#include <iostream>

template <class T>
class NodeQ {
  public:
    T val;
    NodeQ <T> *ant;
    NodeQ <T> *prox;
    NodeQ() {
      val  = (T) 0;
      ant  = 0;
      prox = 0;
    }
};

template <class T>
class Queue {
  private:
    NodeQ <T> *front;
    NodeQ <T> *back;
    
    inline NodeQ <T> * newNode(T val) {
      NodeQ <T> * nNode =  new NodeQ <T> ();
      nNode->val = val;
      return nNode;
    }

  public:
    Queue() {
      front = 0;
      back  = 0;
    }
    
    inline T getFirst() {
      return front->val;
    }
    
    void insert(T val) {
      if(front == 0) {
        front = newNode(val);
        back = front;
      }
      else {
        back->prox = newNode(val);
        back->prox->ant = back;
        back = back->prox;
      }
    }
    void remove() {
      if(empty()) {
       std::cerr << "Empty Queue!!" << std::endl;  
      }
      else if(front == back) {
        delete front;
        back = 0;
        front = 0;
      }
      else {
        NodeQ <T> * tmp = front->prox;
        front->prox = 0;
        delete front;
        tmp->ant = 0;
        front = tmp;
      }
    }
    
    inline bool empty() { 
      return (front == 0)?true:false;
    }
};