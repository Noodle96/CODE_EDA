
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

void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;


    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    int n_total = 200000;
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
        mergeSort(array,0,n-1);
        auto end = std::chrono::high_resolution_clock::now(); // FINAL
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        //cout << n << "," << elapsed.count() * 1e-9 << " seg" << endl;
        salidaTxt.append(to_string(n) + "," + to_string(elapsed.count() * 1e-9) + "\n");
        //printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
        f.close();
    }
    guarda_txt(salidaTxt, "tiempos_merge.txt");

    return 0;
}

