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


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
        heapSort(array,n);
        auto end = std::chrono::high_resolution_clock::now(); // FINAL
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        //cout << n << "," << elapsed.count() * 1e-9 << " seg" << endl;
        salidaTxt.append(to_string(n) + "," + to_string(elapsed.count() * 1e-9) + "\n");
        //printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
        f.close();
    }
    guarda_txt(salidaTxt, "tiempos_heap.txt");

    return 0;
}

