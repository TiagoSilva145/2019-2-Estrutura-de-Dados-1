//#include <stdlib.h>
#include <iostream>
#include <new>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sys/time.h>


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

int menu1 () //Selecionar o arquivo
{
    int i;

    cout << "Qual arquivo voce deseja ler?" <<
    endl << "1. 10" <<
    endl << "2. 50" <<
    endl << "3. 100" <<
    endl << "4. 1K" <<
    endl << "5. 10K" <<
    endl << "6. 1M" <<
    endl << "7. 100M" << endl;

    cin >> i;

    //i = 1;

    return i;
}

int menu2() //Pronto
{
    int i;

    system("CLS");

    cout << "O que deseja fazer com as listas?  \n\n"

    << "Inserir um node no: \n"
    << "1. Inicio da lista \n"
    << "2. Fim da lista \n"
    << "3. Meio da lista \n"
    << "Remover um node do: \n"
    << "4. Inicio da lista \n"
    << "5. Fim da lista \n"
    << "6. Meio da lista \n\n"

    << "Procurar por um node pelo campo RG usando: \n"
    << "7. Busca sequencial \n"
    << "8. Busca binaria \n\n"

    << "Ordenar a lista usando: \n"
    << "9. Selection sort \n"
    << "10. Insertion sort \n"
    << "11. Bubble sort \n"
    << "12. Shell sort \n"
    << "13. Quick sort \n"
    << "14. Merge sort \n\n"

    << "Mostrar a lista: \n"
    << "15. Sequencial \n"
    << "16. Encadeada \n"
    << "17. Indireta \n\n"

    << "18. Salvar a lista em um arquivo \n"

    << "19. Criar um vetor indireto \n"
    << "20. Sair \n";

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

            i++;
        }
        while(v[i] != ',' && v[i] != '\n');

        if(v[i] == '\n')
            continue;

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
        //arquivo = fopen("teste.txt", "r");
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
        *seq = new FichaS[11748443];
        preencheS(*seq, en, fim, arquivo);
        fclose(arquivo);
        return 11748443;
    default:
        cout << "Valor invalido.";
        return 0;
    }
}

void imprimeS(FichaS* seq, int t) //Pronto
{
    int i;

    cout << "Lista sequencial: \n";
    for(i = 0; i<t; i++)
    {
        cout << i+1 << ". Nome: ";
        puts(seq[i].nome);
        cout << "RG: " << seq[i].rg << endl;
    }

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void imprimeE(FichaE* en)
{
    int i=0;

    cout << "Lista encadeada: \n";
    while(en != NULL)
    {
        cout << ++i << ". Nome: ";
        puts(en->nome);
        cout << "RG: " << en->rg << endl;

        en = en->prox;
    }

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void imprimeIn(FichaS** ind, int tam)
{
    int i;

    cout << "Lista indireta:\n";
    for(i = 0; i<tam; i++)
    {
        cout << i+1 << ". Nome: ";
        puts(ind[i]->nome);
        cout << "RG: " << ind[i]->rg << endl;
    }

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
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

void insereI(FichaS** seq, FichaE** en, int i) //Pronto
{
    FichaS* novo;
    FichaE* p = NULL;
    int c=0, m=0;

    clock_t in, fi;
    double tempo;

    in = clock();

    novo = new (nothrow) FichaS[i];
    m++;

    for (int j=0; j<i-1; j++)
    {
        novo[j+1] = (*seq)[j];
        c++;
        m++;
    }

    delete[] (*seq);
    *seq = novo;
    m++;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Digite o nome e o RG para a lista sequencial: ";
    cin >> novo[0].nome >> novo[0].rg;

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    in = fi = c = m = 0;

    p = new (nothrow) FichaE;
    m++;

    cout << "Digite o nome e o RG para a lista encadeada: ";
    cin >> p->nome >> p->rg;

    in = clock();

    p->prox = *en;
    m++;

    *en = p;
    m++;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void insereM(FichaS** seq, FichaE* en, int i) //Pronto
{
    FichaS* novo;
    FichaE* p = NULL;
    FichaE* aux = NULL;
    int n;
    int j;
    int c=0, m=0;

    clock_t in, fi;
    double tempo;

    cout << "Qual posicao deseja adicionar: ";
    cin >> n;

    n--;

    in = clock();

    novo = new (nothrow) FichaS[i];
    m++;

    for (j=0; j<n; j++)
    {
        novo[j] = (*seq)[j];
        m++;
        c++;
    }

    for (int j=n+1; j<i; j++)
    {
        novo[j] = (*seq)[j-1];
        m++;
        c++;
    }

    delete[] (*seq);
    *seq = novo;
    m++;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Digite o nome e o RG da lista sequencial: ";
    cin >> novo[n].nome >> novo[n].rg;

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    in = fi = j = m = c = 0;

    in = clock();

    while(j++ != n-1)
    {
        en = en->prox;
        m++;
        c++;
    }

    aux = en->prox;
    m++;

    p = new (nothrow) FichaE;
    m++;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Digite o nome e o RG da lista encadeada: ";
    cin >> p->nome >> p->rg;

    en->prox = p;
    m++;
    p->prox = aux;
    m++;

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void insereF(FichaS** seq, FichaE** fim, int i) //Pronto
{
    FichaS* novo;
    FichaE* p;
    int j;
    int c=0, m=0;

    clock_t in, fi;
    double tempo;

    in = clock();

    c++;
    novo = new (nothrow) FichaS[i];
    m++;

    for (j=0; j<i; j++)
    {
        novo[j] = (*seq)[j];
        m++;
        c++;
    }

    delete[] (*seq);
    *seq = novo;
    m++;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Digite o nome e o RG da lista sequencial: ";
    cin >> novo[i-1].nome >> novo[i-1].rg;

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    in = fi = m = c = 0;

    p = new (nothrow) FichaE;
    m++;
    p->prox = NULL;
    m++;

    cout << "Digite o nome e o RG da lista encadeada: ";
    cin >> p->nome >> p->rg;

    in = clock();

    (*fim)->prox = p;
    m++;
    *fim = p;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void removeI(FichaS** seq, FichaE** en, int i) //Pronto
{
    FichaS* novo;
    FichaE* aux;
    int c=0, m=0;

    clock_t in, fi;
    double tempo;

    in = clock();

    novo = new (nothrow) FichaS[i];
    m++;

    for (int j=0; j<i; j++)
    {
        novo[j] = (*seq)[j+1];
        m++;
        c++;
    }

    delete[] (*seq);
    *seq = novo;
    m++;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    in = fi = m = c = 0;

    in = clock();

    aux = (*en)->prox;
    m++;
    delete (*en);
    (*en) = aux;
    m++;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void removeM(FichaS** seq, FichaE* en, int i) //Pronto
{
    FichaS* novo;
    FichaE* aux;
    int p;
    int j;
    int c=0, m=0;

    clock_t in, fi;
    double tempo;

    cout << "Qual posicao deseja remover da lista sequencial: ";
    cin >> p;

    p--;

    in = clock();

    novo = new (nothrow) FichaS[i];

    for (j=0; j<p; j++)
    {
        novo[j] = (*seq)[j];
        m++;
        c++;
    }

    for (int j=p; j<i; j++)
    {
        novo[j] = (*seq)[j+1];
        m++;
        c++;
    }

    delete[] (*seq);
    *seq = novo;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    in = fi = j = m = c = 0;

    cout << "Qual posicao deseja remover da lista encadeada: ";
    cin >> p;

    in = clock();

    p--;

    while (j++ != p-1)
    {
        en = en->prox;
        m++;
        c++;
    }

    aux = en->prox;
    m++;
    en->prox = aux->prox;
    m++;
    delete aux;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void removeF(FichaS* seq, FichaE* en, FichaE** fim, int i) //Pronto
{
    int c=0, m=0, j;

    clock_t in, fi;
    double tempo;

    in = clock();

    strcpy(seq[i+1].nome,"");
    seq[i+1].rg = 0;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    /*novo = new (nothrow) FichaS[i];
    m++;

    for (j=0; j<i; j++)
    {
        novo[j] = (*seq)[j];
        m++;
        c++;
    }

    delete[] (*seq);
    *seq = novo;*/

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    in = fi = j = m = c = 0;

    in = clock();

    while(j++ != i-1)
    {
        en = en->prox;
        m++;
        c++;
    }

    *fim = en;
    m++;
    (*fim)->prox = NULL;
    m++;
    en = en->prox;
    m++;
    delete en;

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void procuraSeq (FichaS* seq, FichaE* en, FichaE* fim, int i, int& c, int& m) //Pronto
{
    FichaE* p = en;
    int rg , j;

    clock_t in, fi;
    double tempo;

    cout << "Qual RG deseja procurar: ";
    cin >> rg;

    in = clock();

    for(j=0; j < i; j++)
    {
        c++;
        if(seq[j].rg == rg)
        {
            c++;
            cout << "Posicao: " << j+1 << " Nome: " << seq[j].nome << endl;
            break;
        }
    }

    c++;
    if (j == i)
        cout << "RG nao cadastrado na lista sequencial\n";

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nLista sequencial:"
        << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    in = fi = j = m = c = 0;

    in = clock();

    while(p != NULL)
    {
        j++;
        c++;
        if(p->rg == rg)
        {
            c++;
            cout << "\nPosicao: " << j << " Nome: " << p->nome << endl;
            break;
        }
        p = p->prox;
        m++;
    }

    /*if (p == fim)
        cout << "\nRG nao cadastrado na lista encadeada\n";*/

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "\nLista encadeada:"
        << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;

    fflush(stdin);
    cout << "\nAperte qualquer tecla para continuar\n";
    getchar();
}

void criaInd(FichaS* seq, FichaS*** ind, int tam) //Pronto
{
    for(int i=0; i<tam; i++)
        (*ind)[i] = &(seq[i]);
}

void procuraBin (FichaS** ind, int tam, int& c, int& m) //Pronto
{
    int i=0, me;
    int rg = -1;

    clock_t in, fi;
    double tempo;

    cout << "Digite o RG que deseja procurar:\n";
    cin >> rg;

    in = clock();

    me = (i+tam)/2;

    while(rg != ind[me]->rg)
    {
        if(i >= tam)
        {
            c++;
            cout << "RG nao encontrado";
            return;
        }

        me = (i+tam)/2;

        if(rg > ind[me]->rg)
        {
            c++;
            m++;
            i= me+1;
        }
        else
        {
            m++;
            tam = me;
        }

    }

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Posicao: " << me+1 << "\nNome : " << ind[me]->nome << "\nRG: " << ind[me]->rg << endl;

    cout << "\nNumero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;
}

void selectionSort (FichaS*** ind, int tam, int& c, int& m) //Pronto
{
    int i,j,pos;
    FichaS* aux;
    FichaS* aux2;

    clock_t in, fi;
    double tempo;

    in = clock();

    for(i=0; i<tam; i++)
    {
        imprimeIn(*ind, tam);
        system("CLS");

        c++;
        m += 2;

        aux = (*ind)[i];
        pos = i;
        for(j=i; j<tam; j++)
        {
            c += 2;

            if(aux->rg > (*ind)[j]->rg)
            {
                m+=2;

                aux = (*ind)[j];
                pos = j;
            }
        }

        m += 3;

        aux2 = (*ind)[i];
        (*ind)[i] = aux;
        (*ind)[pos] = aux2;
    }

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Numero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;
}

void insertionSort (FichaS*** ind, int tam, int& c, int& m)
{
    int i,j,k;
    FichaS* aux;

    clock_t in, fi;
    double tempo;

    in = clock();

    for(i=1; i<tam; i++)
    {
        c++;

        j = i;
        aux = (*ind)[i];

        m += 2;

        //imprimeIn(*ind, tam);
        //system("CLS");

        while(j > 0 && (*ind)[j-1]->rg > aux->rg)
        {
            c+=2;
            m++;
            (*ind)[j] = (*ind)[j-1];
            j--;
        }

        c++;
        if(j != i)
        {
            (*ind)[j] = aux;
            m++;
        }
    }

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Numero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;
}

void bubbleSort (FichaS*** ind, int tam, int& c, int& m)
{
    int i,j;
    FichaS* aux;

    clock_t in, fi;
    double tempo;

    in = clock();

    for (i=1; i<tam; i++)
    {
        c += 2;

        m++;
        j = i;

        while ((*ind)[i]->rg < (*ind)[i-1]->rg)
        {
            imprimeIn(*ind, tam);
            system("CLS");

            aux = (*ind)[i];
            (*ind)[i] = (*ind)[i-1];
            (*ind)[i-1] = aux;
            i--;

            m += 3;

            if (!i)
                break;

            c++;
        }

        m++;
        i = j;
    }

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Numero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;
}

void shellSort (FichaS*** ind, int tam, int& c, int& m)
{
    int i,j;
    FichaS* aux;
    int h;

    clock_t in, fi;
    double tempo;

    in = clock();

    m++;
    h = tam/9;

    while(h > 0)
    {
        c++;
        for(i=h; i<tam; i++)
        {
            m += 2;

            j = i;
            aux = (*ind)[i];

            c += 2;
            while(j >= h && (*ind)[j-h]->rg > aux->rg)
            {
                m += 2;
                (*ind)[j] = (*ind)[j-h];
                j -= h;
            }

            c++;
            if(j != i)
            {
                (*ind)[j] = aux;
            }
        }

        cout << "Sort com h = " << h << endl;
        imprimeIn(*ind, tam);
        system("CLS");

        m++;
        h /= 2;
    }

    fi = clock();
    tempo = double(fi - in) / double(CLOCKS_PER_SEC);

    cout << "Numero de comparacoes: " << c
        << "\nNumero de movimentacoes: " << m
        << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;
}

void quickSort (FichaS*** ind, int ini, int fim, int& c, int& m)
{
    FichaS* aux;
    int e = ini, d = fim;
    int pivo;

    pivo = ((*ind)[ini]->rg + (*ind)[fim]->rg) / 2;
    m++;

    c++;
    while(e < d)
    {
        //imprimeIn(*ind, fim);
        //system("CLS");

        while((*ind)[e]->rg < pivo && e < fim)
        {
            e++;
            c++;
        }
        while((*ind)[d]->rg > pivo && d > ini)
        {
            c++;
            d--;
        }

        if(e < d)
        {
            m += 5;
            aux = (*ind)[d];
            (*ind)[d] = (*ind)[e];
            (*ind)[e] = aux;
            e++;
            d--;
        }
    }

    //cout << e << " " << d << endl;

    if(d > ini)
    {
        c++;
        //cout << "1 " << e << " " << d << endl;
        quickSort(ind, ini, d, c, m);
    }
    if(e < fim && e != ini)
    {
        c += 2;
        //cout << "2 " << e << " " << d << endl;
        quickSort(ind, e, fim, c, m);
    }

}

void junta(FichaS*** ind, FichaS*** ind2, int ini, int meio, int fim, int& c, int& m)
{
    int i = ini, j = meio;


    /*cout << "Antes: " << endl;
    for(int i = ini; i<fim; i++)
        cout << "Posicao: " << i+1 << " RG: " << (*ind)[i]->rg << endl;*/

    for(int k=ini; k<fim; k++)
    {
        c += 4;
        if(i<meio && (j >= fim || (*ind)[i]->rg <= (*ind)[j]->rg))
        {
            m++;
            (*ind2)[k] = (*ind)[i];
            i++;
        }
        else
        {
            m++;
            (*ind2)[k] = (*ind)[j];
            j++;
        }
    }

    /*cout << "\nDepois: " << endl;
    for(int i = ini; i<fim; i++)
        cout << "Posicao: " << i+1 << " RG: " << (*ind2)[i]->rg << endl;
    fflush(stdin);
    getchar();*/
}

void separa (FichaS*** ind2, FichaS*** ind, int ini, int fim, int& c, int& m)
{
    c++;
    if((fim - ini) < 2)
        return;

    m++;
    int meio = (fim + ini) / 2;

    separa(ind, ind2, ini, meio, c, m);
    separa(ind, ind2, meio, fim, c, m);

    junta(ind2, ind, ini, meio, fim, c, m);
}

void mergeSort (FichaS*** ind, int tam, int& c, int& m)
{
    FichaS** ind2;

    m++;
    ind2 = new FichaS* [tam];

    for(int i=0; i<tam; i++)
    {
        m++;
        c++;
        ind2[i] = (*ind)[i];
    }

    separa(&ind2, ind, 0, tam, c, m);
}

int main ()
{
    int a=-1;
    int i=0;
    FichaS* seq = NULL;
    FichaE* in = NULL;
    FichaE* fim = NULL;
    FichaS** ind;

    int c = 0, m = 0;
    clock_t tempoI, tempoF;
    double tempo;

    in = new (nothrow) FichaE;
    fim = in;

    i = selecionaArquivo(&seq, in, &fim);
    if (!i)
        return 0;

    ind = new FichaS* [i];
    criaInd(seq, &ind, i);

    while (a)
    {
        fflush(stdin);
        cout << "Aperte qualquer tecla para continuar\n";
        getchar();
        c = m = 0;

        a = menu2();
        switch (a)
        {
        case 1: //Insere node no inicio;
            insereI(&seq, &in, ++i);
            break;
        case 2: //Insere node no fim;
            insereF(&seq, &fim, ++i);
            break;
        case 3: //Insere node no meio;
            insereM(&seq, in, ++i);
            break;
        case 4: //Remove node do inicio;
            removeI(&seq, &in, --i);
            break;
        case 5: //Remove node do fim;
            removeF(seq, in, &fim, --i);
            break;
        case 6: //Remove node do meio;
            removeM(&seq, in, --i);
            break;
        case 7: //Procura node por RG;
            procuraSeq(seq, in, fim, i, c, m);
            break;
        case 8: //Busca binaria
            procuraBin(ind, i, c, m);
            break;
        case 9: //Selection sort
            selectionSort(&ind,i, c, m);
            break;
        case 10: //Insertion sort
            insertionSort(&ind,i, c, m);
            break;
        case 11: //Bubble sort
            bubbleSort(&ind,i, c, m);
            break;
        case 12: //Shell sort
            shellSort(&ind,i, c, m);
            break;
        case 13: //Quick sort
            tempoI = clock();

            quickSort(&ind, 0, i-1, c, m);

            tempoF = clock();
            tempo = double(tempoF - tempoI) / double(CLOCKS_PER_SEC);
            cout << "Numero de comparacoes: " << c
                << "\nNumero de movimentacoes: " << m
                << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;
            break;
        case 14: //Merge sort
            tempoI = clock();

            mergeSort(&ind, i, c, m);

            tempoF = clock();
            tempo = double(tempoF - tempoI) / double(CLOCKS_PER_SEC);
            cout << "Numero de comparacoes: " << c
                << "\nNumero de movimentacoes: " << m
                << "\nTempo usado: " << fixed << tempo << setprecision(5) << " segundos " << endl;
            break;
        case 15: //Imprime seq na tela;
            imprimeS(seq, i);
            break;
        case 16:
            imprimeE(in);
            break;
        case 17:
            imprimeIn(ind, i);
            break;
        case 18: //Escreve seq no arquivo;
            escreveS(seq, in, i);
            break;
        case 19:
            delete ind;
            ind = new FichaS* [i];
            criaInd(seq, &ind, i);
            break;
        default:
            delete[] seq;
            while (in != NULL)
            {
                fim = in;
                in = in->prox;
                delete fim;
            }
            return 0;
        }
    }

    return 0;
}

