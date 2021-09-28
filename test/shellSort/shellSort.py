import time

def getTime(array,size):
    empiezo=time.time()
    selectionSort(array,size)
    termino=time.time()
    return (termino-empezo)

def shellSort(array, n):

    # Rearrange elements at each n/2, n/4, n/8, ... intervals
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            temp = array[i]
            j = i
            while j >= interval and array[j - interval] > temp:
                array[j] = array[j - interval]
                j -= interval

            array[j] = temp
        interval //= 2


TOTAL = 1000000
arr = [None] * (TOTAL +1)

YT = [100000,400000,900000]
with open("./times{}".format(ss), "a" ) as f:
    for intervalo in YT:
        contador = 0
        line = ""
        fichero = open('../numeros.txt')
        lineas = fichero.readlines()
        for e in range(intervalo):
            arr[e]= linea[e]

        f.write(str(tam)+','+str(tiempo))
        f.write('\n')
    f.close()


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




data = [9, 8, 3, 7, 5, 6, 4, 1]
size = len(data)
shellSort(data, size)
print('Sorted Array in Ascending Order:')
print(data)
