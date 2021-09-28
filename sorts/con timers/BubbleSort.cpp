#include <iostream>
#include <fstream>
#include<chrono>

using namespace std;
using namespace std::chrono;


int convertToInt(string line){
    return stoi(line);
}


void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if( arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

auto timeBubbleSort(int arr[],int len){
    auto start = high_resolution_clock::now();
    bubbleSort(arr,len);
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

    std::ofstream dataBubbleSort;
    dataBubbleSort.open("bubbleSortCPP.txt",std::ios::trunc);
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
        auto time = timeBubbleSort(arr,intervalo);
        //cout << "Time: "<< time.count() << endl;
        dataBubbleSort << intervalo << "," << (time.count()/1000000) << endl;
        }
    }

    return 0;
}
