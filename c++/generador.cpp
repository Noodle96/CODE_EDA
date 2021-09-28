#include <iostream>
#include <fstream>
#include "windows.h"
#include "time.h"
using namespace std;

void guarda_txt(string num, string dir )
{
    ofstream fout(dir);
        fout << num << endl;
}


void generador(int cantidad, int rango, string dir)
{
    string lista, dato_str;

    for(int i = 0; i < cantidad; i++)
    {
        dato_str = to_string(rand()%rango);
        lista.append(dato_str);
        lista.push_back('\n');
    }
    guarda_txt(lista, dir);

}

int main()
{
    srand(time(NULL));
    generador(800000, 10000, "numeros.txt");
    //generador(30, 500,"numeros.txt");
    return 0;
}
