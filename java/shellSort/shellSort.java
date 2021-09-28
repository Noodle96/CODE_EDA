// Shell sort in Java programming

import java.util.Arrays;
import java.util.Arrays;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors

// Shell sort
class ShellSort {

  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  static void shellSort(int array[], int n) {
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

  // Driver code
  public static void main(String args[]) {
      // int[] data = { 9, 8, 3, 7, 5, 6, 4, 1 };
      // int size = data.length;
      // ShellSort ss = new ShellSort();
      // ss.shellSort(data, size);
      // System.out.println("Sorted Array in Ascending Order: ");
      // System.out.println(Arrays.toString(data));


      //since here
      try {
        FileWriter myWriter = new FileWriter("shellSort.txt");
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
              ShellSort.shellSort(ARRAY,contadorIntervals);
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
