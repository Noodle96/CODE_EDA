// Insertion sort in Java

import java.util.Arrays;
import java.util.Arrays;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors



class InsertionSort {

  static void insertionSort(int array[],int size) {
    //int size = array.length;

    for (int step = 1; step < size; step++) {
      int key = array[step];
      int j = step - 1;

      // Compare key with each element on the left of it until an element smaller than
      // it is found.
      // For descending order, change key<array[j] to key>array[j].
      while (j >= 0 && key < array[j]) {
        array[j + 1] = array[j];
        --j;
      }

      // Place key at after the element just smaller than it.
      array[j + 1] = key;
    }
  }

  // Driver code
  public static void main(String args[]) {
    // int[] data = { 9, 5, 1, 4, 3 };
    // InsertionSort is = new InsertionSort();
    // is.insertionSort(data);
    // System.out.println("Sorted Array in Ascending Order: ");
    // System.out.println(Arrays.toString(data));

    //since here
    try {
      FileWriter myWriter = new FileWriter("insertionSort.txt");
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
            InsertionSort.insertionSort(ARRAY,contadorIntervals);
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
