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

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int partition(int array[], int low, int high) {

  int pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
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
        quickSort(array,0,n-1);
        auto end = std::chrono::high_resolution_clock::now(); // FINAL
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        //cout << n << "," << elapsed.count() * 1e-9 << " seg" << endl;
        salidaTxt.append(to_string(n) + "," + to_string(elapsed.count() * 1e-9) + "\n");
        //printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
        f.close();
    }
    guarda_txt(salidaTxt, "tiempos_quick.txt");

    return 0;
}

