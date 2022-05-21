/**
    Convex Hull
    @file ConvexHull.hpp
    @author Jessica Domingues Lamosa
*/

#include <list>
#include "edge.hpp"

class ConvexHull {
  private:
    std::list<Vertex>  v;
    std::list<Edge>    e;
    std::list<Edge>    ch;
    
    void createE() {
      if(!v.empty() && v.size() > 1) {
        std::list<Vertex>::iterator it1, it2;
        it1 = v.begin();
        Edge tmp;
        while(it1 != v.end()) {
          it2 = v.begin();
          while(it2 != v.end()) {
            if(it1 != it2) {
              tmp.v1 = *it1;
              tmp.v2 = *it2;
              e.push_back(tmp);
            }
            it2++;
          }
          it1++;
        }
      }
      else {
        std::cerr << "CreateE: vertex list is empty! Egde list not create";
      } 
    }
    
     // cross product
    double cross(Vertex a, Vertex b, Vertex p) {
      return (a.x - p.x)*(b.y - p.y) - (a.y - p.y)*(b.x - p.x);
    }
    
   
    
  public:
    
    ConvexHull() {
      v.clear();
      e.clear();
      ch.clear();
    }
    
    ~ConvexHull() {
      v.clear();
      e.clear();
      ch.clear();
    }
    
    void setV(std::list<Vertex> ver) { 
      v = ver;
    }
    
    void printE(std::list<Edge> edge) {
      if(!edge.empty()) {
        Edge tmp;
        for( std::list<Edge>::iterator it = edge.begin(); it != edge.end(); it++) {
           (*it).print(); std::cout << " ";
        }
        std::cout << std::endl;
      }
    }
    
    void printV(std::list<Edge> vtx) {
      if(!vtx.empty()) {
        Edge tmp;
        for( std::list<Edge>::iterator it = vtx.begin(); it != vtx.end(); it++) {
           (*it).print(); std::cout << " ";
        }
        std::cout << std::endl;
      }
    }
    
    void run() {
      bool flag;
      std::list<Vertex>::iterator v1;
      std::list<Edge>::iterator e1;
      createE();
      e1 = e.begin();  
      while(e1 != e.end()) {
        v1 = v.begin();
        flag = true;
        while(v1 != v.end()) {
          if(!(*e1).inEdge((*v1))) {
            if(cross((*e1).v1,(*e1).v2, (*v1)) > 0) {
              flag = false;
              break;
            }
          }
          v1++;
        }
        if(flag) {
          ch.push_back((*e1));
        }
        e1++;
      }
      printE(ch);
    }
    
   
};
