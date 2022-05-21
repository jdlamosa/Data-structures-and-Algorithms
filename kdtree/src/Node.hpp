/**
    KD-Tree
    @file Node.hpp
    @author Jessica Domingues Lamosa
*/
#include <iostream>

template <class T> 
class Node {
  private:
    T px;
    T py;
    Node <T> *esq;
    Node <T> *dir;
    Node <T> *par;
    int depth;

  public:
    Node() {
      px    = (T) 0;
      py    = (T) 0;
      esq   = 0;
      dir   = 0;
      par   = 0;
      depth = 0;
    }
    ~Node() {
      px    = (T) 0;
      py    = (T) 0;
      esq   = 0;
      dir   = 0;
      par   = 0;
      depth = 0;
    }
    void       setX(T x)            { px    = x;   }
    void       setY(T y)            { py    = y;   }
    void       setEsq(Node <T> * e) { esq   = e;   }
    void       setDir(Node <T> * d) { dir   = d;   }
    void       setPar(Node <T> * p) { par   = p;   }
    void       setDepth(int d)      { depth = d;   }
    T          getX()               { return px;   }
    T          getY()               { return py;   }
    Node <T> * getEsq()             { return esq;  }
    Node <T> * getDir()             { return dir;  }
    Node <T> * getPar()             { return par;  }
    int        getDepth()           { return depth;}
    
    void print() {
      std::cout << "(" << px << ", " << py << ")";
      
    }
};
