#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
    FILE* arquivo;
    char v[25];
    int rg=0, i=0, j=0;
    char nome[10];

    arquivo = fopen("teste.txt", "r");

    while (fgets(v,25,arquivo))
    {
        i = 0;
        rg = 0;

        do
            nome[i] = v[i];
        while(v[++i] != ',');

        nome[i] = '\0';

        while(v[++i] != '\n')
        {
            rg = (rg*10) + v[i] - 48;
        }

        for(i=0; nome[i]; i++)
            cout << nome[i];

        cout << endl << rg << endl;

    }

  return 0;
}
