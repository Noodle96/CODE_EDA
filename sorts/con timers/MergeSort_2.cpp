
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

int Merge(int A[],int p, int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;

    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
        }
    }
    while(i<n1)
    {
        A[k++]=L[i++];
    }
    while(j<n2)
    {
        A[k++]=R[j++];
    }
}

int MergeSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
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
    //total = 3000
    int n_total = 3000;
    int array[n_total];

    string tmp;
    ifstream f;
    int ini = 100;
    int fin = n_total;
    int salto = 500;

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
        MergeSort(array,0,n-1);
        auto end = std::chrono::high_resolution_clock::now(); // FINAL
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        //cout << n << "," << elapsed.count() * 1e-9 << " seg" << endl;
        salidaTxt.append(to_string(n) + "," + to_string(elapsed.count() * 1e-9) + "\n");
        printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
        f.close();
    }
    guarda_txt(salidaTxt, "tiempos_merge.txt");

    return 0;
}

