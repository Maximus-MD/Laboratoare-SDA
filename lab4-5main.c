#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "Lab4fun.c"

int main()
{
    Imobil *p = NULL;
    int n, f, height;
    char num[40];
    int op;
    for(;;)
    {
        system("cls");
        puts("|======================================================================|");
        puts("|                             MENIU(coada):                            |");
        puts("|======================================================================|");
        puts("| 1. Crearea nodurilor arborelui binar oarecare in memoria dinamica... |");
        puts("| 2. Afisarea informatiei despre nodurile arborelui la ecran.          |");
        puts("| 3. Cautarea nodului in arbore.                                       |");
        puts("| 4. Modificarea informatiei unui nod din arbore.                      |");
        puts("| 5. Determinarea numarului de noduri.                                 |");
        puts("| 6. Determinarea inaltimii arborelui.                                 |");
        puts("| 7. Eliberarea memoriei alocate pentru arbore.                        |");
        puts("| 0. Iesirea din program.                                              |");
        puts("|======================================================================|\n");
        puts("|======================================================================|");
        puts("|                             MENIU(stiva):                            |");
        puts("|======================================================================|");
        puts("| 8. Crearea nodurilor arborelui binar oarecare in memoria dinamica... |");
        puts("| 9. Afisarea informatiei despre nodurile arborelui la ecran.          |");
        puts("| 10. Cautarea nodului in arbore.                                      |");
        puts("| 11. Modificarea informatiei unui nod din arbore.                     |");
        puts("| 12. Determinarea numarului de noduri.                                |");
        puts("| 13. Determinarea inaltimii arborelui.                                |");
        puts("| 14. Eliberarea memoriei alocate pentru arbore.                       |");
        puts("| 15. Iesirea din program.                                             |");
        puts("|======================================================================|\n");
        puts("|=============================|");
        puts("|           16)RDS            |");
        puts("|           17)RSD            |");
        puts("|           18)SRD            |");
        puts("|           19)DRS            |");
        puts("|           20)SDR            |");
        puts("|           21)DSR            |");
        puts("|=============================|");
        printf("\nAlegeti optiunea meniului: ");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            f = createQueue();
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 2:
            f = show_treeQueue();
            if(f == 0)
            {
                puts("Memoria nu a fost alocata.");
                exit(1);
            }
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 3:
            printf("Dati numele imobilului ce doriti sa-l cautati: ");
            fflush(stdin);
            gets(num);
            p = search_treeQueue(num);
            if(p == NULL)
            {
                puts("Nodul nu a fost gasit.");
            } else {
                puts("\nInformatii despre nod:");
                puts("_____________________________");
                printf("- Denumire: %s\n", p->name);
                printf("- Proprietar: %s\n", p->owner);
                printf("- Tip: %s\n", p->type);
                printf("- Adresa: %s\n", p->addr);
                printf("- Suprafata: %d\n", p->surf);
                printf("- Pret: %d\n", p->price);
                printf("- Nodul: %x;  Left: %x, Right: %x\n", p, p->left, p->right);
            }
            puts("\nPentru a continua apasati orice tasta...");
            getch();
            break;
        case 4:
            printf("Dati numele imobilului informatia caruia doriti sa o modificati: ");
            fflush(stdin);
            gets(num);
            p = search_treeQueue(num);
            if(p == NULL)
            {
                puts("Nu exista asa nod in arbore, incercati din nou!");
            } else {
                puts("\nInformatii despre nod:");
                puts("________________________________");
                printf("- Denumire: %s\n", p->name);
                printf("- Proprietar: %s\n", p->owner);
                printf("- Tip: %s\n", p->type);
                printf("- Adresa: %s\n", p->addr);
                printf("- Suprafata: %d\n", p->surf);
                printf("- Pret: %d\n", p->price);
                printf("- Nodul: %x;  Left: %x, Right: %x\n\n", p, p->left, p->right);
                modify_information(p);
            }
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 5:
            f = size_treeQueue();
            if(f == 0)
            {
                puts("Memoria nu a fost alocata!");
            } else {
                printf("Numarul de noduri este: %d\n", f);
            }
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 6:
            height = height_tree_Queue_and_Stack(root);
            printf("Inaltimea arborelui este de %d etaje.\n", height);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 7:
            free_mem_treeQueue();
            puts("Memoria a fost eliberata cu succes!");
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 0:
            puts("\nProgramul a fost inchis cu succes.");
            return 0;
            exit(1);
        case 8:
            f = createStack();
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 9:
            f = show_treeStack();
            if(f == 0)
            {
                puts("Memoria nu a fost alocata.");
                exit(1);
            }
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 10:
            printf("Dati numele imobilului ce doriti sa-l cautati: ");
            fflush(stdin);
            gets(num);
            p = search_treeStack(num);
            if(p == NULL)
            {
                puts("Nodul nu a fost gasit.");
            } else {
                puts("\nInformatii despre nod:");
                puts("___________________________________________");
                printf("- Denumire: %s\n", p->name);
                printf("- Proprietar: %s\n", p->owner);
                printf("- Tip: %s\n", p->type);
                printf("- Adresa: %s\n", p->addr);
                printf("- Suprafata: %d\n", p->surf);
                printf("- Pret: %d\n", p->price);
                printf("- Nodul: %x;  Left: %x, Right: %x\n", p, p->left, p->right);
            }
            puts("\nPentru a continua apasati orice tasta...");
            getch();
            break;
        case 11:
            printf("Dati numele imobilului informatia caruia doriti sa o modificati: ");
            fflush(stdin);
            gets(num);
            p = search_treeStack(num);
            if(p == NULL)
            {
                puts("Nu exista asa nod in arbore, incercati din nou!");
            } else {
                puts("Informatii despre nod:");
                puts("__________________________________");
                printf("- Denumire: %s\n", p->name);
                printf("- Proprietar: %s\n", p->owner);
                printf("- Tip: %s\n", p->type);
                printf("- Adresa: %s\n", p->addr);
                printf("- Suprafata: %d\n", p->surf);
                printf("- Pret: %d\n", p->price);
                printf("- Nodul: %x;  Left: %x, Right: %x\n\n", p, p->left, p->right);
                modify_information(p);
            }
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 12:
            f = size_treeStack();
            if(f == 0)
            {
                puts("Memoria nu a fost alocata!");
            } else {
                printf("Numarul de noduri este: %d\n", f);
            }
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 13:
            height = height_tree_Queue_and_Stack(root);
            printf("Inaltimea arborelui este de %d etaje.\n", height);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 14:
            free_mem_treeStack();
            puts("Memoria a fost eliberata cu succes!");
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 15:
            puts("\nProgramul a fost inchis cu succes.");
            return 0;
            exit(1);
        case 16:
            RDS(root);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 17:
            RSD(root);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 18:
            SRD(root);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 19:
            DRS(root);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 20:
            SDR(root);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        case 21:
            DSR(root);
            puts("Pentru a continua apasati orice tasta...");
            getch();
            break;
        default:
            puts("Ati ales o optiune incorecta, incercati din nou.");
            puts("Pentru a continua apasati orice tasta...");
            getch();
        }
    }
}
