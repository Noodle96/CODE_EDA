


#include <stdio.h>
#include <chrono>
#include <istream>>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

void guarda_txt(string num, string dir)
{
    ofstream fout(dir);
    fout << num << endl;
}

string abre_lista_numeros(string dir, int filas)
{
    string num;
    string a;
    ifstream fin(dir);
    for(int i = 0; i < filas; i++)
    //fin >> num;
    {
        getline(fin,a);
        num.append(a);
        num.push_back(' ');
    }
    return num;
}

void shellSort(int array[], int n) {
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}


void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    string salidaTxt;
    int n_total = 500000;
    int array[n_total];

    string tmp;
    ifstream f;
    int ini = 100000;
    int fin = n_total;
    int salto = 100000;

    for(int n = ini; n <= fin; n+=salto)
    {
        f.open("numeros.txt");
        // lee los valores del fichero
        for(int i = 0; i < n; i++)
        {
            getline(f,tmp);
            array[i]= atoi(tmp.c_str());
        }

        // medicion del tiempo
        auto begin = std::chrono::high_resolution_clock::now(); //INICIO
        shellSort(array,n);
        auto end = std::chrono::high_resolution_clock::now(); // FINAL
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        //cout << n << "," << elapsed.count() * 1e-9 << " seg" << endl;
        salidaTxt.append(to_string(n) + "," + to_string(elapsed.count() * 1e-9) + "\n");
        //printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
        f.close();
    }
    guarda_txt(salidaTxt, "tiempos_shell.txt");

    return 0;
}

