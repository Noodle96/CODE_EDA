// Merge sort in Java

import java.util.Arrays;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors

class MergeSort {

  // Merge two subarrays L and M into arr
  static void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[] = new int[n1];
    int M[] = new int[n2];

    for (int i = 0; i < n1; i++)
      L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
      M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = M[j];
        j++;
      }
      k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = M[j];
      j++;
      k++;
    }
  }

  // Divide the array into two subarrays, sort them and merge them
  static void mergeSort(int arr[], int l, int r) {
    if (l < r) {

      // m is the point where the array is divided into two subarrays
      int m = (l + r) / 2;

      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);

      // Merge the sorted subarrays
      merge(arr, l, m, r);
    }
  }

  // Print the array
  static void printArray(int arr[]) {
    int n = arr.length;
    for (int i = 0; i < n; ++i)
      System.out.print(arr[i] + " ");
    System.out.println();
  }

  // Driver program
  public static void main(String args[]) {

    // int arr[] = { 6, 5, 12, 10, 9, 1 };
    // MergeSort ob = new MergeSort();
    // ob.mergeSort(arr, 0, arr.length - 1);
    // System.out.println("Sorted array:");
    // printArray(arr);


    //since here
    try {
      FileWriter myWriter = new FileWriter("mergeSort.txt");
     // myWriter.write("Files in Java might be tricky, but it is fun enough!");
     for(int intervalo = 100000 ; intervalo<1000001; intervalo+=300000){
            int contadorIntervals = 0;
            int[] ARRAY = new int[intervalo];
            try {
              File myObj = new File("../numeros.txt");
              Scanner myReader = new Scanner(myObj);
              while ((myReader.hasNextLine()) &(contadorIntervals<intervalo)) {
                String data = myReader.nextLine();
                //System.out.println(data);
                ARRAY[contadorIntervals] = Integer.parseInt(data);
                contadorIntervals+=1;
              }
              myReader.close();
            } catch (FileNotFoundException e) {
              System.out.println("An error occurred.");
              e.printStackTrace();
            }

            long inicio = System.currentTimeMillis();
            MergeSort.mergeSort(ARRAY,0,contadorIntervals-1);
            long fin = System.currentTimeMillis();
            double tiempo = (fin - inicio);
            myWriter.write(contadorIntervals+","+tiempo/1000+"\n");
     }
      myWriter.close();
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }

  }
}
