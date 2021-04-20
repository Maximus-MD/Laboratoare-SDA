#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **alocare_mem(int n, int m);
void eliberare_mem(int **tab, int n);
void init_matrice(int **tab, int N);
void afis_matrice(int **tab, int n, int m);
void matrice_inc(int **tab, int N, int M, int **ARR);
void matrice_ad(int **tab, int N, int M, int **ARR);
void lista_ad(int **tab, int N, int M, int **ARR);
void afis_list(int **tab, int N);

int main(void)
{
    int r = 1;
    int op;
    int N, cardU;
    int **g;
    int **h;
    int **K;
    int **L;
    printf("Introduceti numarul de varfuri: ");
    scanf("%d", &N);
    printf("Introduceti numarul de arce: ");
    scanf("%d", &cardU);
    g = alocare_mem(cardU, 2);
    init_matrice(g, cardU);
    while(r)
    {
        printf("\n\n\n");
        printf("\t _______________________________________________________ \n");
        printf("\t|                                                       |\n");
        printf("\t|        *Alege una din metodele de introducere:*       |\n");
        printf("\t|_______________________________________________________|\n");
        printf("\t|                                                       |\n");
        printf("\t|                1. Matrice de incidenta.               |\n");
        printf("\t|                2. Matrice de adiacenta.               |\n");
        printf("\t|                 3. Lista de adiacenta.                |\n");
        printf("\t|                       0. Iesire.                      |\n");
        printf("\t|_______________________________________________________|\n");
        printf("\n\n\t        Alegeti optiunea de afisare a grafului:  ");
        scanf("%d", &op);
        printf("\t_________________________________________________________\n");
        switch(op)
        {
            case 1:
            {
                h = alocare_mem(cardU, N);
                matrice_inc(h, cardU, N, g);
                printf("\n\t _________________________");
                printf("\n\t|                         |");
                printf("\n\t| *Matricea de incidenta* |");
                printf("\n\t|_________________________|\n");
                afis_matrice(h, cardU, N);
                break;
            }
            case 2:
            {
                K = alocare_mem(N, N);
                matrice_ad(K, cardU, N, g);
                 printf("\n\t_________________________");
                printf("\n\t|                         |");
                printf("\n\t| *Matricea de adiacenta* |");
                printf("\n\t|_________________________|\n");
                afis_matrice(K, N, N);
                break;
            }
            case 3:
            {
                L = alocare_mem(N, N);
                lista_ad(L, N, cardU, g);
                printf("\n\t _________________________");
                printf("\n\t|                         |");
                printf("\n\t|   *Lista de adiacenta*  |");
                printf("\n\t|_________________________|\n");
                afis_list(L, N);
                break;
            }
            case 0:
            {
                if(L!=NULL)
                    free(L);
                if(h!=NULL)
                    eliberare_mem(h, cardU);
                if(K!=NULL)
                    eliberare_mem(K, N);
                r = 0;
                return 0;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}
// alocarea memoriei pentru o matrice
int **alocare_mem(int n,int m)
{
    int i;
    int **T = (int**)malloc(100*sizeof(int *));
    for(i = 0; i < 100; i++)
    {
        T[i] = (int*)malloc(100*sizeof(int));
    }
    return T;
}

// eliberarea memoriei a unei matrice
void eliberare_mem(int **tab, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        free(tab[i]);
    }
    free(tab);
}

// initializarea matricei
void init_matrice(int **tab, int N)
{
  int i;
  int a, b;
  for(i = 0; i < N; i++)
    {
        printf("Introduceti arcul U%d:\n", i+1);
        scanf("%d%d", &tab[i][0], &tab[i][1]);
    }
}
// initializarea matricei de incidenta
void matrice_inc(int **tab, int N, int M, int **ARR)
{
    int i;
    for(i = 0; i < N; i++)
    {
        if (ARR[i][0]==ARR[i][1])
        {
            tab[i][ARR[i][0]-1] = 2;
        }
        else
        {
            tab[i][ARR[i][0]-1] = 1;
            tab[i][ARR[i][1]-1] =-1;
        }
    }
}

// initializarea matricei de adiacenta
void matrice_ad(int **tab, int N, int M, int **ARR)
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            tab[i][j] = 0;
        }
    }
    for(i = 0; i < N; i++)
    {
        tab[ARR[i][0]-1][ARR[i][1]-1] = 1;
    }
}

// initializarea listei de adiacenta
void lista_ad(int **tab, int N, int M, int **ARR)
{
    int i, j, a;
    for(i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            tab[i][j] = 0;
        }
    }
    for(i = 0; i < N; i++)
    {
        a = ARR[i][0]-1;
        j = 0;
        while(tab[a][j]!=0)
        {
            j++;
        }
        tab[a][j] = ARR[i][1];
    }
}

// afisarea matricii pe ecran
void afis_matrice(int **tab, int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("\t%d   ", tab[i][j]);
        }
        printf("\n");
    }
}

// afisarea listei la ecran
void afis_list(int **tab, int N)
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        printf("%d:", i+1);
        j = 0;
        while(tab[i][j]!=0)
        {
            printf("%d->", tab[i][j]);
            j++;
        }
        printf("0\n");
    }
}
