/**
    @file MedirTempos.h
    @author Jessica Domingues Lamosa
*/

#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class MedirTempos {
  private: 
    vector<float> tempo;
    vector<string> marcador;
    
    // Chama tempo do sistema em segundos
    float wall_time() {
      struct timeval tv;
      struct timezone tz;
      static long t0     = 0;
      static long t0usec = 0;
      
      gettimeofday(&tv, &tz);
      if (t0 == 0) {
        t0=tv.tv_sec;
        t0usec=tv.tv_usec;
      }
      return (tv.tv_sec-t0 + (tv.tv_usec-t0usec)/1000000.0);
    } // fim wall_time
    
    // Metodo de conversao de numeros em string
    string convertFtoS(float a) {
      stringstream ss;
      ss << a;
      return ss.str();
    } // fim convert
    
    string geraTempos() {
      string saida="";
      vector<bool> control;
      control.resize(marcador.size(), false);
      
      saida = "Tempos:\n"; 
      for(int i=0; i<marcador.size(); i++) {
        if(control[i] == false) {
          control[i] = true;
          for(int j=i+1; j<marcador.size(); j++) {
            if(marcador[i].compare(marcador[j]) == 0) {
              saida += marcador[i] + ":\t" + convertFtoS(tempo[j] - tempo[i]) + " s\n";
              control[j] = true;
              break; // sai do loop j, pois labels foram iguais
            } // fim if
          } // fim for j
        } // fim if
      } // fim for i
      return saida;
    } // fim geraTempos
    
  public: 
    MedirTempos() {
      tempo.clear();
      marcador.clear();
    } // fim construtor
    
    ~MedirTempos() {
      tempo.clear();
      marcador.clear();
    } // fim destrutor
  
    void time(string marc) {
      marcador.push_back(marc);
      tempo.push_back(wall_time());
    } // fim metodo time
    
    // Gera tabela de tempos
    void tabelaTempos() {
      cout << geraTempos();
    }
    
    void tabelaTempos(string saida) {
      ofstream out;
        out.open(saida.c_str());
        out << geraTempos();
      out.close();
    }
    
};
