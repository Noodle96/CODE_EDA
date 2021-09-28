def MergeSort(Arr):
    if len(Arr) > 1:
        mitad = len(Arr)//2
        Izq = Arr[:mitad]
        Der = Arr[mitad:]
        MergeSort(Izq)
        MergeSort(Der)

        i = j = k = 0
        while i < len(Izq) and j < len(Der):
            if Izq[i] < Der[j]:
                Arr[k] = Izq[i]
                i += 1
            else:
                Arr[k] = Der[j]
                j += 1
            k += 1

        while i < len(Izq):
            Arr[k] = Izq[i]
            i += 1
            k += 1
  
        while j < len(Der):
            Arr[k] = Der[j]
            j += 1
            k += 1
