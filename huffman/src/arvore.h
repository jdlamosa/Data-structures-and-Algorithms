/* 
 * Jéssica Domingues Santos
 * Codificação de Huffman
 */


#include <iostream>
using namespace std;

class NoArvore {
private:
    int valor;
    char letra;
    NoArvore *esq, *dir;
public:

    NoArvore() {
        valor = -1;
        letra = '\0';
        esq = NULL;
        dir = NULL;
    }
    
    NoArvore(int valor, char letra){
        valor = valor;
        letra = letra;
    }
    inline void setValor(int v) { valor = v;} 
    inline void setLetra(char c){ letra = c;}
    inline void setEsq(NoArvore *e) { esq = e;}
    inline void setDir(NoArvore *d) { dir = d;}
    inline int getValor() {return valor;}
    inline char getLetra(){return letra;}
    inline NoArvore *getEsq() {return esq;}
    inline NoArvore *getDir() {return dir;}
    
};
