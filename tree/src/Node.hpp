template <class T> 
class Node {
  private:
    T val;
    Node <T> *esq;
    Node <T> *dir;

  public:
    Node() {
      val = (T) 0;
      esq = 0;
      dir = 0;
    }
    ~Node() {
      val = (T) 0;
      esq = 0;
      dir = 0;
    }
    void       setVal(T v)          { val = v;    }
    void       setEsq(Node <T> * e) { esq = e;    }
    void       setDir(Node <T> * d) { dir = d;    } 
    T          getVal()             { return val; }
    Node <T> * getEsq()             { return esq; }
    Node <T> * getDir()             { return dir; }
};