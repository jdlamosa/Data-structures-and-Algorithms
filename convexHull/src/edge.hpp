/**
    Convex Hull
    @file edge.hpp
    @author Jessica Domingues Lamosa
*/

#include "vertex.hpp"

class Edge {
  public:
    Vertex v1;
    Vertex v2;
    Edge() {
      v1.x = 0.0; v1.y = 0.0;
      v2.x = 0.0; v2.y = 0.0;
    }
    ~Edge() {
      v1.x = 0.0; v1.y = 0.0;
      v2.x = 0.0; v2.y = 0.0;
    }
    void insert(Vertex ver1, Vertex ver2) { v1 = ver1; v2 = ver2; }
    
    void print() {
      std::cout << "["; v1.print(); std::cout << ", "; v2.print(); std::cout << "]";
    }
    
    bool inEdge(Vertex tmp) {
      if(tmp.x == v1.x && tmp.y == v1.y) return true;
      if(tmp.x == v2.x && tmp.y == v2.y) return true;
      return false;
    }
};
