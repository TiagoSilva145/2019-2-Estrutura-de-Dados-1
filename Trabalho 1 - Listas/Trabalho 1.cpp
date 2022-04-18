#include <stdlib.h>
#include <iostream>
#include <new>
#include <fstream>
#include <string>

using namespace std;

struct FichaS //Pronto
{
    int rg;
    char nome[10];
};

struct FichaE //Pronto
{
    int rg;
    char nome[10];

    FichaE* prox;
};

int menu1 ()
{
    int i;

    /*cout << "Qual arquivo voce deseja ler?" <<
    endl << "1. 10" <<
    endl << "2. 50" <<
    endl << "3. 100" <<
    endl << "4. 1K" <<
    endl << "5. 10K" <<
    endl << "6. 1M" <<
    endl << "7. 100M" << endl;

    cin >> i;*/

    i = 1;

    return i;
}

int menu2() //Pronto
{
    int i;

    system("CLS");

    cout << "O que deseja fazer com as listas?  \n"
    << "1. Inserir um node no inicio da lista \n"
    << "2. Inserir um node no fim da lista \n"
    << "3. Inserir um node no meio da lista \n"
    << "4. Remover um node do inicio da lista \n"
    << "5. Remover um node do fim da lista \n"
    << "6. Remover um node do meio da lista \n"
    << "7. Procurar um node pelo campo RG \n"
    << "8. Mostrar lista na tela \n"
    << "9. Salvar a lista em um arquivo \n"
    << "10. Sair \n";

    cin >> i;

    system("CLS");

    return i;
}

void preencheS(FichaS* seq, FichaE* en, FichaE** fim, FILE* arquivo) //Pronto
{
    int i=0, j=0;
    FichaE* q = NULL;
    char v[25]; //String que armazenará a linha do arquivo;

    fgets(v,25,arquivo);

    seq[j].rg = 0;

    do
    {
        seq[j].nome[i] = v[i];
        (*fim)->nome[i] = v[i];
    }
    while(v[++i] != ',');

    seq[j].nome[i] = '\0';
    (*fim)->nome[i] = '\0';

    while(v[++i] != '\n')
        seq[j].rg = (seq[j].rg*10) + v[i] - 48;

    (*fim)->rg = seq[j].rg;

    j++;

    while (fgets(v,25,arquivo))
    {
        q = new (nothrow) FichaE;
        q->prox = NULL;

        i = 0;
        seq[j].rg = 0;

        do
        {
            seq[j].nome[i] = v[i];
            q->nome[i] = v[i];
        }
        while(v[++i] != ',');

        seq[j].nome[i] = '\0';
        q->nome[i] = '\0';

        while(v[++i] != '\n')
            seq[j].rg = (seq[j].rg*10) + v[i] - 48;

        q->rg = seq[j].rg;

        /*cout << "Nome : ";

        for(i=0; seq[j].nome[i]; i++)
            cout << seq[j].nome[i];

        cout << "; RG : " << seq[j].rg << endl;*/
        j++;

        (*fim)->prox = q;
        (*fim) = q;
    }
}

int selecionaArquivo (FichaS** seq, FichaE* en, FichaE** fim) //Pronto
{
    int i;
    FILE* arquivo; // Ponteiro pra abrir o arquivo;

    i = menu1();

    switch (i)
    {
    case 1:
        arquivo = fopen("NomeRG10.txt", "r");
        *seq = new (nothrow) FichaS[10];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 10;
    case 2:
        arquivo = fopen("NomeRG50.txt", "r");
        *seq = new (nothrow) FichaS[50];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 50;
    case 3:
        arquivo = fopen("NomeRG100.txt", "r");
        *seq = new (nothrow) FichaS[100];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 100;
    case 4:
        arquivo = fopen("NomeRG1K.txt", "r");
        *seq = new (nothrow) FichaS[1000];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 1000;
    case 5:
        arquivo = fopen("NomeRG10K.txt", "r");
        *seq = new (nothrow) FichaS[10000];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 10000;
    case 6:
        arquivo = fopen("NomeRG1M.txt", "r");
        *seq = new (nothrow) FichaS[1000000];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 1000000;
    case 7:
        arquivo = fopen("NomeRG100M.txt", "r");
        *seq = new (nothrow) FichaS[100000000];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 100000000;
    default:
        cout << "Valor invalido.";
        return 0;
    }
}

void imprimeS(FichaS* seq, FichaE* en, int t) //Pronto
{
    int i;

    cout << "Lista sequencial: \n";
    for(i = 0; i<t; i++)
    {
        cout << i+1 << ". Nome: ";
        puts(seq[i].nome);
        cout << "RG: " << seq[i].rg << endl;
    }

    i=0;

    cout << "\nLista encadeada: \n";
    while(en != NULL)
    {
        cout << ++i << ". Nome: ";
        puts(en->nome);
        cout << "RG: " << en->rg << endl;

        en = en->prox;
    }

    getchar();
    getchar();
}

void escreveS(FichaS* seq, FichaE* en, int t) //Pronto
{
    int i;

    FILE* arquivo;

    arquivo = fopen("ListaSeq.txt", "w");

    for(i=0; i<t;i++)
        fprintf(arquivo, "%s,%d\n", seq[i].nome, seq[i].rg);

    arquivo = fopen("ListaEn.txt", "w");

    while(en->prox != NULL)
    {
        fprintf(arquivo, "%s,%d\n", en->nome, en->rg);
        en = en->prox;
    }
    fclose(arquivo);
}

void insereI(FichaS** seq, FichaE** en, int i) //Colocar tempo
{
    FichaS* novo;
    FichaE* p = NULL;
    int c=0, m=0;

    novo = new (nothrow) FichaS[i];
    m++;

    for (int j=0; j<i-1; j++)
    {
        novo[j+1] = (*seq)[j];
        m++;
    }

    delete[] (*seq);
    *seq = novo;

    cout << "Digite o nome e o RG para a lista sequencial: ";
    cin >> novo[0].nome >> novo[0].rg;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";
    c = m = 0;

    p = new (nothrow) FichaE;
    m++;

    cout << "Digite o nome e o RG para a lista encadeada: ";
    cin >> p->nome >> p->rg;

    p->prox = *en;
    m++;

    *en = p;
    m++;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    getchar();
    getchar();
}

void insereM(FichaS** seq, FichaE* en, int i) //Colocar tempo
{
    FichaS* novo;
    FichaE* p = NULL;
    FichaE* aux = NULL;
    int n;
    int j;
    int c=0, m=0;

    cout << "Qual posicao deseja adicionar: ";
    cin >> n;

    n--;

    novo = new (nothrow) FichaS[i];

    for (j=0; j<n; j++)
    {
        novo[j] = (*seq)[j];
        m++;
    }

    for (int j=n+1; j<i; j++)
    {
        novo[j] = (*seq)[j-1];
        m++;
    }

    delete[] (*seq);
    *seq = novo;
    m++;

    cout << "Digite o nome e o RG da lista sequencial: ";
    cin >> novo[n].nome >> novo[n].rg;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    j = m = c = 0;

    while(j++ != n-1)
    {
        en = en->prox;
        m++;
    }

    aux = en->prox;
    m++;

    p = new (nothrow) FichaE;
    m++;

    cout << "Digite o nome e o RG da lista encadeada: ";
    cin >> p->nome >> p->rg;

    en->prox = p;
    m++;
    p->prox = aux;
    m++;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    getchar();
    getchar();

}

void insereF(FichaS** seq, FichaE** fim, int i) //Colocar tempo
{
    FichaS* novo;
    FichaE* p;
    int j;
    int c=0, m=0;

    novo = new (nothrow) FichaS[i];
    m++;

    for (j=0; j<i; j++)
    {
        novo[j] = (*seq)[j];
        m++;
    }

    delete[] (*seq);
    *seq = novo;
    m++;

    cout << "Digite o nome e o RG da lista sequencial: ";
    cin >> novo[i-1].nome >> novo[i-1].rg;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    j = m = c = 0;

    p = new (nothrow) FichaE;
    m++;
    p->prox = NULL;
    m++;

    cout << "Digite o nome e o RG da lista encadeada: ";
    cin >> p->nome >> p->rg;

    (*fim)->prox = p;
    m++;
    *fim = p;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    getchar();
    getchar();

}

void removeI(FichaS** seq, FichaE** en, int i) //Colocar tempo
{
    FichaS* novo;
    FichaE* aux;
    int c=0, m=0;

    novo = new (nothrow) FichaS[i];
    m++;

    for (int j=0; j<i; j++)
    {
        novo[j] = (*seq)[j+1];
        m++;
    }

    delete[] (*seq);
    *seq = novo;
    m++;

    cout << "\nNumero de comparacoes sequencial: " << c << "\nNumero de movimentacoes sequencial: " << m << "\n";

    m = c = 0;

    aux = (*en)->prox;
    m++;
    delete (*en);
    (*en) = aux;
    m++;

    cout << "\nNumero de comparacoes encadeada: " << c << "\nNumero de movimentacoes encadeada: " << m << "\n";

    getchar();
    getchar();
}

void removeM(FichaS** seq, FichaE* en, int i) //Colocar tempo
{
    FichaS* novo;
    FichaE* aux;
    int p;
    int j;
    int c=0, m=0;

    cout << "Qual posicao deseja remover da lista sequencial: ";
    cin >> p;

    p--;

    novo = new (nothrow) FichaS[i];

    for (j=0; j<p; j++)
    {
        novo[j] = (*seq)[j];
        m++;
    }

    for (int j=p; j<i; j++)
    {
        novo[j] = (*seq)[j+1];
        m++;
    }

    delete[] (*seq);
    *seq = novo;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    j = m = c = 0;

    cout << "Qual posicao deseja remover da lista encadeada: ";
    cin >> p;

    p--;

    while (j++ != p-1)
    {
        en = en->prox;
        m++;
    }

    aux = en->prox;
    m++;
    en->prox = aux->prox;
    m++;
    delete aux;

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    getchar();
    getchar();
}

void removeF(FichaS** seq, FichaE* en, FichaE** fim, int i) //Colocar tempo
{
    FichaS* novo;
    FichaE* aux;
    int c=0, m=0, j;

    novo = new (nothrow) FichaS[i];
    m++;

    for (j=0; j<i; j++)
    {
        novo[j] = (*seq)[j];
        m++;
    }

    delete[] (*seq);
    *seq = novo;

    cout << "\nNumero de comparacoes sequencial: " << c << "\nNumero de movimentacoes sequencial: " << m << "\n";
    j = m = c = 0;

    while(j++ != i-1)
    {
        en = en->prox;
        m++;
    }

    *fim = en;
    m++;
    (*fim)->prox = NULL;
    m++;
    en = en->prox;
    m++;
    delete en;

    cout << "\nNumero de comparacoes encadeada: " << c << "\nNumero de movimentacoes encadeada: " << m << "\n";

    getchar();
    getchar();
}

void procura (FichaS* seq, FichaE* en, int i)
{
    FichaE* p = en;
    int rg , j;
    int c=0, m=0;

    cout << "Qual RG deseja procurar: ";
    cin >> rg;

    for(j=0; j < i; j++)
    {
        c++;
        if(seq[j].rg == rg)
        {
            cout << "Posicao: " << j+1 << " Nome: " << seq[j].nome << endl;
            break;
        }
    }

    c++;
    if (j == i)
        cout << "CPF nao cadastrado na lista sequencial\n";

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    j = m = c = 0;

    while(p->prox != NULL)
    {
        j++;
        c++;
        if(p->rg == rg)
        {
            cout << "Posicao: " << j << " Nome: " << p->nome;
            break;
        }
        p = p->prox;
        m++;
    }

    cout << "\nNumero de comparacoes: " << c << "\nNumero de movimentacoes: " << m << "\n\n";

    getchar();
    getchar();
}

int main ()
{
    int a=-1;
    int i=0, j=0;
    FichaS* seq = NULL;
    FichaE* en = NULL;
    FichaE* fim = NULL;

    en = new (nothrow) FichaE;
    fim = en;

    i = selecionaArquivo(&seq, en, &fim);
    j = i;
    if (!i)
        return 0;

    while (a)
    {
        a = menu2();
        switch (a)
        {
        case 1: //Insere node no inicio;
            insereI(&seq, &en, ++i);
            break;
        case 2: //Insere node no fim;
            insereF(&seq, &fim, ++i);
            break;
        case 3: //Insere node no meio;
            insereM(&seq, en, ++i);
            break;
        case 4: //Remove node do inicio;
            removeI(&seq, &en, --i);
            break;
        case 5: //Remove node do fim;
            removeF(&seq, en, &fim, --i);
            break;
        case 6: //Remove node do meio;
            removeM(&seq, en, --i);
            break;
        case 7: //Procura node por RG;
            procura(seq, en, i);
            break;
        case 8: //Imprime seq na tela;
            imprimeS(seq, en, i);
            break;
        case 9: //Escreve seq no arquivo;
            escreveS(seq, en, i);
            break;
        default:
            delete[] seq;
            while (en != NULL)
            {
                fim = en;
                en = en->prox;
                delete fim;
            }
            return 0;
        }
    }

    return 0;
}
