#include <iostream>
#include <fstream>
#include <stdio.h>
#include <locale.h>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Palavra
{
public:

    int qIndices;
    vector<int> indices;
    string palavra;

    Palavra(): qIndices(1)
    {
    }

    void operator=(int i)
    {
        indices.push_back(i);
        qIndices++;
    }

    void operator=(string s)
    {
        palavra = s;
    }

    void printIndices()
    {
        for(int i = 0; i < qIndices; i++)
            cout << indices[i] << " ";
        cout << endl;
    }

    void imprimeDados()
    {
        cout << "Palavra: " << palavra << "\nOcorrências: " << qIndices << "\nÍndices: " << endl;
        printIndices();
        cout << endl;
    }

    void ordenaIndices()
    {
        int i,j;
        int aux;

        for(i=1; i<qIndices; i++)
        {
            j = i;
            aux = indices[i];

            while(j > 0 && indices[j-1] > aux)
            {
                indices[j] = indices[j-1];
                j--;
            }

            if(j != i)
            {
                indices[j] = aux;
            }
        }
    }
};

int menu1()
{
    int a;

    cout << "Digite a opção desejada:\n" <<
         "1. Ler o arquivo texto\n" <<
         "2. Apresentar o arquivo invertido\n" <<
         "3. Procurar uma palavra\n" <<
         "4. Sair do programa\n";

    cin >> a;

    system("cls");

    return a;
}

void buscarPalavra(vector<Palavra> voc, string texto)
{
    string palavra;
    int inicio = 0;
    int fim = voc.size();
    int meio = fim/2;
    int i = 0;
    int j = 0;
    int k = 0;

    cout << "Digite a palavra que deseja buscar: " << endl;
    cin >> palavra;

    system("cls");

    while(palavra != voc[meio].palavra)
    {
        if(palavra > voc[meio].palavra)
            inicio = meio + 1;
        else
            fim = meio - 1;

        if(inicio > fim)
        {
            cout << "Palavra não encontrada\n";
            return;
        }

        meio = (inicio + fim)/2;
    }

    voc[meio].imprimeDados();


    while(i != -1 && j < voc[meio].qIndices)
    {
        i = voc[meio].indices[j++];

        cout << "\nPedaço de frase do indice " << i << endl;

        if(i < 50)
            k = 0;
        else
            k = i - 50;

        cout << "... ";

        while(k < (i + 100) && k < texto.size())
            cout << texto[k++];

        cout << " ...";

        cout << "\n\nDeseja acessar um pedaço de frase do proximo indice?\nPara sim digite 1\nPara não digite -1\n";
        cin >> i;
    }

    return;
}

void salvaArquivo(vector<Palavra> voc)
{
    ofstream tex ("ArquivoInvertido.txt", ios::out);

    int j;
    int aux;

    for(int i = 0; i < voc.size(); i++)
    {
        tex << voc[i].palavra << " " << voc[i].qIndices;
        tex << endl;

        aux = j = voc[i].qIndices;
        while(j--)
        {
            tex << voc[i].indices[aux - j - 1] << " ";
        }

        tex << endl << endl;
    }
}

void imprime(vector<Palavra> voc)
{
    int tam = voc.size();

    for(int i = 0; i < tam; i++)
        voc[i].imprimeDados();

    cout << endl;

    fflush(stdin);
    getchar();

    system("cls");
}

void verificaPalavra(string& s)
{
    if(s[s.size()-1] == '.' || s[s.size()-1] == ',' || s[s.size()-1] == '!' || s[s.size()-1] == '?' || s[s.size()-1] == ':')
        s = s.substr(0, s.size()-1);

    //cout << s << " ";
}

void ordenaIndices(vector<Palavra>& voc)
{
    int tam = voc.size();

    for(int i = 0; i < tam; i++)
        voc[i].ordenaIndices();
}

void ordenaPalavras(vector<Palavra>& voc)
{
    int i,j;
    Palavra aux;
    int h;
    int tam = voc.size();

    h = tam/9;

    while(h > 0)
    {
        for(i=h; i<tam; i++)
        {

            j = i;
            aux = voc[i];

            while(j >= h && voc[j-h].palavra > aux.palavra)
            {
                voc[j] = voc[j-h];
                j -= h;
            }

            if(j != i)
            {
                voc[j] = aux;
            }
        }

        h /= 2;
    }
}

void junta(vector<Palavra>& voc)
{
    int i;
    int j = 1;

    for(i = 0; i < voc.size()-1; i++)
    {
        if(voc[i].palavra == voc[i+1].palavra)
        {
            voc[i] = voc[i+1].indices[0];

            voc.erase(voc.begin()+i+1);
            i--;
        }
    }
}

void leArquivo(string& texto, vector<Palavra>& voc)
{
    ifstream tex ("Historia.txt", ios::in);

    string linha;
    string palavra;

    int i = 0;
    int indice = 0;
    int tam = 0;

    Palavra aux;
    aux.indices.push_back(0);

    if(not tex)
    {
        cout << "Erro ao ler o arquivo";
        return;
    }

    while(getline(tex, linha))
    {
        //cout << linha << endl << endl;

        texto += linha;
        int tam = linha.size();

        for(i = 0; i<tam; i++)
        {
            indice++;

            if(linha[i] != ' ' && linha[i] != '\0')
            {
                palavra += linha[i];
            }
            else
            {
                aux.indices[0] = indice - palavra.size();
                verificaPalavra(palavra);
                aux = palavra;
                voc.push_back(aux);

                palavra = "";
            }
        }
    }

    cout << "Arquivo lido com sucesso" << endl;

    return;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int a = 0;
    vector<Palavra> voc;
    string texto = "";
    int pos;

    while(a != 4)
    {
        cout << "Pressione enter para prosseguir:\n";
        fflush(stdin);
        getchar();
        system("cls");
        a = menu1();
        switch (a)
        {
        case 1: //Ler do arquivo
            leArquivo(texto, voc);
            ordenaPalavras(voc);
            junta(voc);
            ordenaIndices(voc);
            salvaArquivo(voc);
            break;
        case 2://Apresentar o arquivo invertido
            imprime(voc);
            break;
        case 3: //Procurar palavra
            buscarPalavra(voc,texto);
            break;
        case 4:
            return 0;
        default:
            cout << "Selecione uma opção válida";
            break;
        }
    }

}
