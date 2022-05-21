/* 
 * Jéssica Domingues Santos
 * Codificação de Huffman
 */

#include "arvore.h"
#include <string.h>
#include <iomanip>
using namespace std;

class ArvoreBinaria {
private:
    NoArvore *raiz;
    NoArvore **repositorio;

    char *alfabeto;
    int *alfabeto_num;
    int tam;
    int tam_r;
    static int tabela_size;

    string **tabela;

    NoArvore *criaNo(char c, int v) {
        NoArvore *tmp = new NoArvore();
        tmp->setValor(v);
        tmp->setLetra(c);
        return tmp;
    }//fim do criaNo

    void imprimir(NoArvore *tmp,unsigned k=0) {
        cout << tmp->getValor() << " (" << tmp->getLetra() <<")"<< endl;
        if (tmp->getEsq() != NULL) {
                for(unsigned i=0; i<k; i++)
    {
      cout<<" ";
    }//fim do for 
	  cout << "<-- ";
            imprimir(tmp->getEsq(),k+3);
        }
//
        if (tmp->getDir() != NULL) {
	        for(unsigned i=0; i<k; i++)
    {
      cout<<" ";
    }//fim do for
            cout << "--> ";
            imprimir(tmp->getDir(),k+3);
        }
    }//fim do imprimir

public:

    ArvoreBinaria() {
        raiz = NULL;
    }

    void iniciaRepositorio(char alf[], int alf_num[], int tam) {
        alfabeto = alf;
        alfabeto_num = alf_num;
        ArvoreBinaria::tam = tam;
        tam_r = 0;

        tabela = new string*[tam];

        for (int i = 0; i < tam; i++) {
           tabela[i] = new string[2];
        }

        criaNosRepositorio();
    }
    

  /* criaNosRepositorio:
  *Transformando ambos os arrays alfabeto (char) e alfabeto_num (int) em NoArvore. 
  *O número de nós criados será igual ao tamanho dos arrays.
  * Ex:
  * alfabeto[0] = 'A', alfabeto_num[0] = 6;
  * 
  *Os dois formaram o novo NoArvore com letra = 'A' e valor = 6*/
   
    void criaNosRepositorio() {
        repositorio = new NoArvore*[tam];
        for (int i = 0; i < tam; i++) {
            NoArvore *temp = criaNo(alfabeto[i], alfabeto_num[i]);
            repositorio[i] = temp;
            tam_r++;
        }
    }

    /*
     * Método principal que irá criar a árvore com base no repositorio
     */
    void huffman() {
        while (tam_r > 1) {
            /*
             * getNode() pegara o item do array repositorio de indice tam_r. Esse
             * indice sofrerá um decremento a cada chamada do método. O objetivo é
             * simular o método pop();
             * Ex:
             * tam_r = 6;
             * n1 = getNode() -> recebera o item repositorio[5];
             * n2 = getNode() -> recebera o item repositorio[4];
             * 
             * Na sequencia um novo NoArvore será criado com valor igual a
             * (n1->getValor() + n2->getValor). Seu ponteiro direito irá apontar
             * para n1 e o esquerdo para n2;
             * 
             * Este novo nó será incluso no repositorio, e um novo Sort será
             * chamado para orderná-lo.
             * 
             * tam_r será decrementado. Portante, no exemplo, tam_r = 5;
             * 
             * No próximo loop (como tam_r > 1):
             * n1 = getNode() -> recebera o item repositorio[4];
             * n2 = getNode() -> recebera o item repositorio[3];
             * 
             * e assim por diante até que tam_r seja igual a 1;
             */
            NoArvore *n1 = getNode();
            NoArvore *n2 = getNode();

            NoArvore *novo = new NoArvore();
            novo->setValor(n1->getValor() + n2->getValor());
            novo->setDir(n1);
            novo->setEsq(n2);
            insereRepositorio(novo);

            bubbleSortNo();
	   
        }

        // Recebe o último item do repositório;
        // A árvore está criada;
        raiz = getNode();
    }

    void insereRepositorio(NoArvore *no) {
        repositorio[tam_r++] = no;
    }

    NoArvore* getNode() {
        return repositorio[--tam_r];
    }

    // Ordena o array de NoArvore com base em seu valor

    void bubbleSortNo() {
      for (int i = tam_r - 1; i >= 0; i--) {
            for (int j = 1; j <= i; j++) {
                NoArvore *tmp1 = repositorio[j];
                NoArvore *tmp2 = repositorio[j - 1];
		//cout<< tmp2->getValor()<<" "<< tmp1->getValor()<<" ";
                if (tmp2->getValor() < tmp1->getValor()) {
                    NoArvore tmp = *tmp1;
                    *tmp1 = *tmp2;
                    *tmp2 = tmp;
                }
            }
        }
    }



    void initTabela(NoArvore *tmp, string cd) {

        if (tmp->getEsq() == NULL && tmp->getDir() == NULL) {

            tabela[tabela_size][0] = tmp->getLetra();
            tabela[tabela_size][1] = cd;
            tabela_size++;
        }

        if (tmp->getEsq() != NULL) {
            initTabela(tmp->getEsq(),cd + "0");

	  
	}

        if (tmp->getDir() != NULL) {
            initTabela(tmp->getDir(), cd + "1");
        }


    }

    // Inicia a construção da tabela de códigos de cada caractere;

    void montaTabela() {

        tabela_size = 0;

        initTabela(raiz, "");
        cout <<setw(6)<< "\nTabela" << endl;
        cout<<"Letra"<< setw(10)<<"Valor:"<<endl;   
          
	for (int i = 0; i < tam; i++) {
	    cout << tabela[i][0] <<"        "<<tabela[i][1] << endl;
        }
        cout << "\n-------------" << endl;

        sortTabela();

        cout <<setw(6)<< "\nTabela ordenada" << endl;
        cout<<"Letra"<< setw(10)<<"Valor:"<<endl;   
          
        for (int i = 0; i < tam; i++) {
            cout << tabela[i][0] <<"        "<< tabela[i][1] << endl;
        }
        
    }

    /* Ordena o array de array tabela com base no segundo indice (codigo) de
     * cada array;
     * Ex:
     * 
     *          tabela[3][1] = "11"
     *          tabela[4][1] = "10"
     * 
     * Ocorrerá troca pois o "10" é menor que "11"
     */
    void sortTabela() {
        for (int i = tabela_size - 1; i >= 0; i--) {
            for (int j = 1; j <= i; j++) {
                string s1 = tabela[j][1];
                string s2 = tabela[j - 1][1];

                if (compara(s1, s2) < 0) {

                    string *tmps = tabela[j - 1];
                    tabela[j - 1] = tabela[j];
                    tabela[j] = tmps;
                }
            }
        }
    }

    /*
     * Primeiramente o método irá igualar as strings em termos de tamanho. 
     * Caso uma das string seja maior que a outra, a maior irá ganhar um "1" em 
     * sua frente, uma única vez, e a menor irá ganhar "0" em sua frente até que
     * o tamanho das duas seja igual.
     * No final será feito uma comparação, retornando 0 caso sejam iguais, < 0 
     * caso b seja menor que a ou > 0 caso b seja maior que a.
     */
    int compara(string a, string b) {
        if (a.length() > b.length()) {
            a = "1" + a;
            while (a.length() > b.length()) {
                b = "0" + b;
            }
        }

        if (a.length() < b.length()) {
            b = "1" + b;
            while (a.length() < b.length()) {
                a = "0" + a;
            }
        }
        //compare é do strng.h
        return a.compare(b);
    }

    string** getTabela() {
        return tabela;
    }

    void imprimir() {
        if (raiz == NULL)
            cout << "ArvoreBinaria vazia" << endl;
        else {
            imprimir(raiz);
        }//fim do else
        cout << endl;
    }// fim imprimir

}; //fim da classe ArvoreBinaria
