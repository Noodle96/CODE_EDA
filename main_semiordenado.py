from generador_random import *
# from quicksort import *
from quick import *
from insercion import insercion
from merge import *

import time
from os import remove
from os import path
import sys
import copy


#escribe los tiempos generados en un archivo times.dot
def write_time(tam, tiempo,opcion):
    ss=""
    if opcion==3:  
        ss="quicks.dot"        
    elif opcion==2:
        ss="insers.dot"
    elif opcion==1:
        ss="merges.dot"
    else:
        quit()
    with open("./times{}".format(ss), "a" ) as f:
        f.write(str(tam)+','+str(tiempo))
        f.write('\n')
    f.close()

    
def promedio_tiempos(array):
    promedio=0
    for i in range(len(array)):
        promedio+= array[i]
    return promedio/len(array)


#Genera el tiempo que tarda y lo hace guardar 
def tiempo(nro_array,inicio, final, incremento):        
    main_array=(semi_ordenado(inicio, final, incremento))
    array_insercion=copy.deepcopy(main_array)
    array_quicksort=copy.deepcopy(main_array)
    array_mergesort=copy.deepcopy(main_array)
    nro_array=len(main_array)
    tiempo_insercion=[]
    tiempo_quicksort=[]
    tiempo_mergesort=[]
    print(nro_array)
    for j in range (nro_array):
        empiezo=time.time()
        # mergesort(array_mergesort[j],0,len(array_mergesort[j])-1)
        mergesort(array_mergesort[j])
        termino=time.time()
        tiempo_mergesort.append(termino-empiezo)       
        empiezo=time.time()
        # quicksort(array_quicksort[j],0,len(array_quicksort[j])-1)
        quicksort(0,len(array_quicksort[j])-1,array_quicksort[j])
        termino=time.time()
        tiempo_quicksort.append(termino-empiezo)        
        empiezo=time.time()
        insercion(array_insercion[j])
        termino=time.time()
        tiempo_insercion.append(termino-empiezo)
 
        print(' '*100)

        print(len(array_mergesort[j]),'mergesort '+'tardaste tiempo promedio: ',promedio_tiempos(tiempo_mergesort))
        write_time(len(array_mergesort[j]),promedio_tiempos(tiempo_mergesort),1)
        print('_'*50)

        print(len(array_mergesort[j]),'insertionsort '+'tardaste tiempo promedio: ',promedio_tiempos(tiempo_insercion))
        write_time(len(array_mergesort[j]),promedio_tiempos(tiempo_insercion),2)
        print('_'*50)

        print(len(array_mergesort[j]),'quicksort '+'tardaste tiempo promedio: ',promedio_tiempos(tiempo_quicksort))
        write_time(len(array_mergesort[j]),promedio_tiempos(tiempo_quicksort),3)
        print('_'*50)

if __name__ == '__main__':
    sys.setrecursionlimit(10000)
    if path.exists("./timesinsers.dot"):
        remove("./timesinsers.dot")
    if path.exists("./timesquicks.dot"):
        remove("./timesquicks.dot")
    if path.exists("./timesmerges.dot"):
        remove("./timesmerges.dot")
    tiempo(10,1000, 10000, 500)

    
    


