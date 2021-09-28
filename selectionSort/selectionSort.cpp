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

/* Function to print an array */
void printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main(){

    int TOTAL = 1000000;
    int arr[TOTAL+1];
    cout << "hello" << endl;
    // for(int e = 1000000 ; e < 5000001; e+=1000000){
    //
    // }


    // int cont = 0;
    // string line;
    // ifstream myfile ("../filenumbers.txt");
    // if (myfile.is_open()) {
    //     while ( getline (myfile,line) ){
    //         //cout << line << '\n';
    //         cont++;
    //     }
    //     myfile.close();
    // }else{cout << "error al abrir0";}
    // std::cout << "constador: "<<cont << std::endl;

    std::ofstream dataSelectionSort;
    dataSelectionSort.open("selectionSortCPP.txt",std::ios::trunc);
    for(int intervalo = 100000 ; intervalo < TOTAL+1; intervalo+=400000){
        int contador = 0;
        string line;
        ifstream numeros ("../numeros.txt");
        if (numeros.is_open()) {
            while ( getline (numeros,line) && contador < intervalo ){
                // for(int num = 0 ; num < intervalo; num++){
                //     arr[num] = convertToInt(line);
                // }
                //cout << line << endl;
                arr[contador] = convertToInt(line);
                contador++;
            }
        numeros.close();

        //printing
        // for(int num = 0 ; num < 10; num++)
        //     std::cout << arr[num] << endl;
        // }std::cout << endl;

        //AGREGANDO A selectionSortCPP.txt
        auto time = timeSelectionSort(arr,intervalo);
        //cout << "Time: "<< time.count() << endl;
        dataSelectionSort << intervalo << "," << (time.count()/1000000) << endl;

        }
    }





    // int arr[] = {64, 25, 12, 22, 11};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // selectionSort(arr, n);
    // cout << "Sorted array: \n";
    // printArray(arr, n);






    return 0;
}

// This is code is contributed by rathbhupendra
