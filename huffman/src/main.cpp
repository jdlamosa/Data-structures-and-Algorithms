/* Jéssica Domingues Lamosa
 * Codificação de Huffman
 */


#include <algorithm>
#include "ArvoreBinaria.h"

using namespace std;

void bubbleSort(char array[], int array_n[], int tam);
string toBin(int i);
void tabela(char array[], int tam);

int ArvoreBinaria::tabela_size = 0;

int main() {
    ArvoreBinaria a;

   string str = "AAAAAABBBBBCCCCDDDEEF";
   // string str ="Trabalho de Analise";
   
    cout<<"Sequencia que sera codificada:\n"<<str<<endl;
    char *letras;
    int *letras_n;
    int tam = 0;

    /*
     * Separando cada letra da string em uma array de char.
     * O numero de ocorrencias dessa letra é salvo em um array de int, sendo que
     * o indice do array de int corresponde a letra de mesmo indice no array de
     * char
     */
    for (int i = 0; i < str.length(); i++) {

        if (tam > 0) {

            bool addLetra = true;
            // Caso a letra já tenha sido adicionada, não adicionar de novo
            for (int j = 0; j < tam; j++) {
                if (letras[j] == str[i]) {
                    addLetra = false;
                    break;
                }
            }

            // Caso a letra não tenha sido adicionada, adicionar.
            if (addLetra) {

                // Aray de char temporario que irá conter todas as letras
                // previamente adicionadas ao array letras
                char temp[tam];
                strcpy(temp, letras);

                // Array de int temporario que irá conter todas as ocorrencias
                // previamente adicionadas ao array letras_num
                int temp_num[tam];
                memcpy(temp_num, letras_n, sizeof (letras_n) * tam);

                // Alocando um novo espaço para os arrays
                letras = new char[tam + 1];
                letras_n = new int[tam + 1];

                // Contando o numero de vezes que a letra a ser adicionada
                // aparece na string
                int ct = count(str.begin(), str.end(), str[i]);

                // Copiando os arrays temporários nos arrays originais
                strcpy(letras, temp);
                memcpy(letras_n, temp_num, sizeof (letras_n) * tam);

                // Adicionando a nova letra ao array
                letras[tam] = str[i];
                // Adicionando o numero de ocorrencias ao array de inteiro
                letras_n[tam] = ct;

                tam++;
            }

        } else {
            // Primeira vez que uma letra está sendo adicionado ao array
            letras = new char[tam + 1];
            letras_n = new int[tam + 1];

            // Numero de vezes dessa letra
            int ct = count(str.begin(), str.end(), str[i]);

            letras[tam] = str[i];
            letras_n[tam] = ct;

            tam++;
        }
    } //fim do for pra add

    // Ordenando o array de acordo com o número de ocorrencias
    bubbleSort(letras, letras_n, tam);
    cout<<"Frequencia"<<endl;
    for (int i = 0; i < tam; i++) {
        cout << letras[i] << " " << letras_n[i] << endl;
    }

    cout << "\nTabela antes do algoritmo" << endl;
    tabela(letras, tam);
   
    a.iniciaRepositorio(letras, letras_n, tam);
    a.huffman();
    a.montaTabela();
    cout<<"\nImprimindo arvore: "<<endl;   
    a.imprimir();

    string **tabela = a.getTabela();

    cout << "\nSequencia codificada:" << endl;

    for (int i = 0; i < str.length(); i++) {
        // Recebendo um caractere e convertendo-o para string
        string s(1, str[i]);

        for (int i = 0; i < tam; i++) {
            if (tabela[i][0].compare(s) == 0) {
                cout << tabela[i][1];
            }
        }
    }
    cout<<endl;
}


void bubbleSort(char array[], int array_n[], int tam) {
    for (int i = tam - 1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (array_n[j - 1] < array_n[j]) {
                int temp_num = array_n[j - 1];
                array_n[j - 1] = array_n[j];
                array_n[j] = temp_num;

                char temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Imprime na tela os valores para a tabela antes do algoritmo

void tabela(char array[], int tam) {
     // Imprime cada caractere do array com seu respectivo
    // codigo
    for (int i = 0; i < tam; i++) {
        string tam_binario = toBin(i);

        // Padroniza o tamanho do codigo
        while (tam_binario.length() < 3) {
            tam_binario = "0" + tam_binario;
        }

        cout << array[i] << " " << tam_binario << endl;
    }

}

// Converte de decimal para binário

string toBin(int i) {
    if (i == 0) {
        return "0";
    }
    if (i == 1) {
        return "1";
    }

    string retorno = "";
    while (i > 0) {
        if (i % 2 == 0) {
            retorno = "0" + retorno;
        } else {
            retorno = "1" + retorno;
        }
        i = i / 2;
    }

    return retorno;
}
