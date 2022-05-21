#include <iostream>

class Vertex {
  public:
    double x;
    double y;
    Vertex() {
      x = y = 0.0;
    }
    ~Vertex() {
      x = y = 0.0;
    }
    void insert(double x1, double y1) { x = x1; y = y1; }
    
    void print() {
      std::cout << "(" << x << ", " << y << ")";
    }
};
