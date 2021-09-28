// Heap Sort in Java

import java.util.Arrays;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors



class HeapSort {

    static void sort(int arr[], int n) {
      //int n = arr.length;

      // Build max heap
      for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
      }

      // Heap sort
      for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify root element
        heapify(arr, i, 0);
      }
    }

    static void heapify(int arr[], int n, int i) {
      // Find largest among root, left child and right child
      int largest = i;
      int l = 2 * i + 1;
      int r = 2 * i + 2;

      if (l < n && arr[l] > arr[largest])
        largest = l;

      if (r < n && arr[r] > arr[largest])
        largest = r;

      // Swap and continue heapifying if root is not largest
      if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        heapify(arr, n, largest);
      }
    }

    // Driver code
    public static void main(String args[]) {
      // int arr[] = { 1, 12, 9, 5, 6, 10 };
      // HeapSort hs = new HeapSort();
      // hs.sort(arr);
      // System.out.println("Sorted array is");
      // printArray(arr);

      //since here
      try {
        FileWriter myWriter = new FileWriter("heapSort.txt");
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
              HeapSort.sort(ARRAY,contadorIntervals);
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
