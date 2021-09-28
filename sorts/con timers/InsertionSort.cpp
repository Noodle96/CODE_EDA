#include <iostream>
#include <fstream>
#include<chrono>

using namespace std;
using namespace std::chrono;


int convertToInt(string line){
    return stoi(line);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

auto timeInsertionSort(int arr[],int len){
    auto start = high_resolution_clock::now();
    insertionSort(arr,len);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration;
}

/* Function to print an array */
void printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main(){

    int TOTAL = 3000;
    int arr[TOTAL+1];
    cout << "hello" << endl;

    std::ofstream dataInsertionSort;
    dataInsertionSort.open("insertionSortCPP.txt",std::ios::trunc);
    for(int intervalo = 100 ; intervalo < TOTAL+1; intervalo+=100){
        int contador = 0;
        string line;
        ifstream numeros ("../numeros.txt");
        if (numeros.is_open()) {
            while ( getline (numeros,line) && contador < intervalo ){
                arr[contador] = convertToInt(line);
                contador++;
            }
        numeros.close();

        //AGREGANDO A selectionSortCPP.txt
        auto time = timeInsertionSort(arr,intervalo);
        //cout << "Time: "<< time.count() << endl;
        dataInsertionSort << intervalo << "," << (time.count()/1000000) << endl;

        }
    }
    return 0;
}
