#include <iostream>
#include <fstream>
#include<chrono>

using namespace std;
using namespace std::chrono;

int convertToInt(string line){
    return stoi(line);
}
void merge(int arr[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

auto timeMergeSort(int arr[],int len){
    auto start = high_resolution_clock::now();
    merge_sort(arr,0,len-1);
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

    std::ofstream dataMergeSort;
    dataMergeSort.open("mergeSortCPP.txt",std::ios::trunc);
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
        auto time = timeMergeSort(arr,intervalo);
        //cout << "Time: "<< time.count() << endl;
        dataMergeSort << intervalo << "," << (time.count()/1000000) << endl;
        }
    }

    return 0;
}
