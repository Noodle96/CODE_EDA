#include <iostream>
#include <fstream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int convertToInt(string line){
    return stoi(line);
}

// Shell sort
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
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

auto timeShellSort(int arr[],int len){
    auto start = high_resolution_clock::now();
    shellSort(arr,len);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration;
}


// Driver code
int main() {
    int TOTAL = 1000000;
    int arr[TOTAL+1];

    std::ofstream dataShellSort;
    dataShellSort.open("shellSortCPP.txt",std::ios::trunc);
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

        auto time = timeShellSort(arr,intervalo);
        dataShellSort << intervalo << "," << (time.count()) << endl;
        }
    }
    dataShellSort.close();
}
