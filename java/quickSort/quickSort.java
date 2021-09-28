// Quick sort in Java

import java.util.Arrays;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors

class Quicksort {

  // method to find the partition position
  static int partition(int array[], int low, int high) {

    // choose the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse through all elements
    // compare each element with pivot
    for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {

        // if element smaller than pivot is found
        // swap it with the greatr element pointed by i
        i++;

        // swapping element at i with element at j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }

    }

    // swapt the pivot element with the greater element specified by i
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    // return the position from where partition is done
    return (i + 1);
  }

  static void quickSort(int array[], int low, int high) {
    if (low < high) {

      // find pivot element such that
      // elements smaller than pivot are on the left
      // elements greater than pivot are on the right
      int pi = partition(array, low, high);

      // recursive call on the left of pivot
      quickSort(array, low, pi - 1);

      // recursive call on the right of pivot
      quickSort(array, pi + 1, high);
    }
  }
}

// Main class
class Main {
  public static void main(String args[]) {

    // int[] data = { 8, 7, 2, 1, 0, 9, 6 };
    // System.out.println("Unsorted Array");
    // System.out.println(Arrays.toString(data));
    // int size = data.length;
    // // call quicksort() on array data
    // Quicksort.quickSort(data, 0, size - 1);
    // System.out.println("Sorted Array in Ascending Order: ");
    // System.out.println(Arrays.toString(data));

    //since here
    try {
      FileWriter myWriter = new FileWriter("quickSort.txt");
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
            Quicksort.quickSort(ARRAY,0,contadorIntervals-1);
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
