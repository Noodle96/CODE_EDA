import java.util.Arrays;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors


class bubbleSortClass {

  // perform the bubble sort
  static void bubbleSort(int array[],int size) throws InterruptedException{

    // loop to access each array element
    for (int i = 0; i < (size-1); i++) {

      // check if swapping occurs
      boolean swapped = false;

      // loop to compare adjacent elements
      for (int j = 0; j < (size-i-1); j++) {

        // compare two array elements
        // change > to < to sort in descending order
        if (array[j] > array[j + 1]) {

          // swapping occurs if elements
          // are not in the intended order
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;

          swapped = true;
        }
      }
      // no swapping means the array is already sorted
      // so no need for further comparison
      if (!swapped)
        break;

    }
  }

  public static void main(String args[])throws InterruptedException {

    // int[] arr = { -2, 45, 0, 11, -9 };
    // int size = arr.length;
    //
    // // call method using the class name
    // bubbleSortClass.bubbleSort(arr,size);
    //
    // System.out.println("Sorted Array in Ascending Order:");
    // System.out.println(Arrays.toString(arr));

    try {
      FileWriter myWriter = new FileWriter("bubbleSort.txt");
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
            //print Array
            // for(int y = 0 ; y<contadorIntervals; y++){
            //     System.out.print(ARRAY[y]+" ");
            // }System.out.print("\n");

            //System.out.println(Arrays.toString(ARRAY));
            //System.out.println("Sorted Array in Ascending Order:");
            // System.out.println(Arrays.toString(arr));
            //bubbleSortClass.bubbleSort(ARRAY,contadorIntervals);
            //System.out.println(Arrays.toString(ARRAY));
            long inicio = System.currentTimeMillis();
            bubbleSortClass.bubbleSort(ARRAY,contadorIntervals);
            //Thread.sleep(2000); // 2 segundos
            long fin = System.currentTimeMillis();
            double tiempo = (fin - inicio);
            //System.out.println(tiempo/1000);
            // System.out.println( contadorIntervals+" , "+tiempo);
            // tiempo /=1000;
            myWriter.write(contadorIntervals+","+tiempo/1000+"\n");
     }
      myWriter.close();
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }


    // try {
    //   File myObj = new File("../nombreIntegrantesTest.txt");
    //   Scanner myReader = new Scanner(myObj);
    //   while (myReader.hasNextLine()) {
    //     String data = myReader.nextLine();
    //     System.out.println(data);
    //   }
    //   myReader.close();
    // } catch (FileNotFoundException e) {
    //   System.out.println("An error occurred.");
    //   e.printStackTrace();
    // }

    // int[] any = new int[10];
    // for(int e =  0 ; e < any.length; e++){
    //         System.out.println(any[e]);
    // }
  }
}
