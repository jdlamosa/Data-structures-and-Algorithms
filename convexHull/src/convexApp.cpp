/**
    Convex Hull
    @file convexApp.cpp
    @author Jessica Domingues Lamosa
*/

#include "ConvexHull.hpp"
#include "MedirTempos.h"

using namespace std;

int main() {
  MedirTempos t;
  Vertex v;
  list <Vertex> vs;
  t.time("Full Time");
  t.time("insert");
  v.insert(1.0, 1.0);
  vs.push_back(v);
  v.insert(2.0, 2.0);
  vs.push_back(v);
  v.insert(2.0, 4.0);
  vs.push_back(v);
  v.insert(1.0, 3.0);
  vs.push_back(v);
  v.insert(4.0, 9.0);
  vs.push_back(v);
  t.time("insert");
  

  ConvexHull a;
  t.time("setV");
  a.setV(vs);
  t.time("setV");
  t.time("run");
  a.run();
  t.time("run");
  t.time("Full Time");
  t.tabelaTempos();
  
  
  return 0;
}
