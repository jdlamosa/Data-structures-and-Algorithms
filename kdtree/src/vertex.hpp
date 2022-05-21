#include <iostream>

template <class T>
class Vertex {
  private:  
  T px;
  T py;
  
  public:
    Vertex() {
      T px = (T) 0;
      T py = (T) 0;
    }
    ~Vertex() {
      px = (T) 0;      
      px = (T) 0;
    }
    void insert(T x1, T y1) { px = x1; py = y1; }
    
    T          getX()            { return px;   }
    T          getY()            { return py;   }
    
    
    void print() {
      std::cout << "(" << px << ", " << py << ")";
    }
};
