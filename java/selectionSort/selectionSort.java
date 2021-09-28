// Selection sort in Java

import java.util.Arrays;
import java.util.Arrays;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors

class SelectionSort {
  static void selectionSort(int array[],int size) {
    // int size = array.length;

    for (int step = 0; step < size - 1; step++) {
      int min_idx = step;

      for (int i = step + 1; i < size; i++) {

        // To sort in descending order, change > to < in this line.
        // Select the minimum element in each loop.
        if (array[i] < array[min_idx]) {
          min_idx = i;
        }
      }

      // put min at the correct position
      int temp = array[step];
      array[step] = array[min_idx];
      array[min_idx] = temp;
    }
  }

  // driver code
  public static void main(String args[]) {

    // int[] data = { 20, 12, 10, 15, 2 };
    // SelectionSort ss = new SelectionSort();
    // ss.selectionSort(data);
    // System.out.println("Sorted Array in Ascending Order: ");
    // System.out.println(Arrays.toString(data));


    //since here
    try {
      FileWriter myWriter = new FileWriter("selectionSort.txt");
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
            SelectionSort.selectionSort(ARRAY,contadorIntervals);
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
