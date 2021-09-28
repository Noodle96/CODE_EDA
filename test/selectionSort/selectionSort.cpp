#include <iostream>
#include <fstream>
#include<chrono>

using namespace std;
using namespace std::chrono;


int convertToInt(string line){
    return stoi(line);
}

void selectionSort(int arr[], int n){
    int min_idx;
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}


auto timeSelectionSort(int arr[],int len){
    auto start = high_resolution_clock::now();
    selectionSort(arr,len);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration;
}

int main(){

    int TOTAL = 1000000;
    int arr[TOTAL+1];
    cout << "hello" << endl;

    std::ofstream dataSelectionSort;
    dataSelectionSort.open("selectionSortCPP.txt",std::ios::trunc);
    for(int intervalo = 100000 ; intervalo < TOTAL+1; intervalo+=400000){
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
        auto time = timeSelectionSort(arr,intervalo);
        dataSelectionSort << intervalo << "," << time.count() << endl;

        }
    }
    return 0;
}
