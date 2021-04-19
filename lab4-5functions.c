#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lab4prot.h"

Imobil *pop(void)
{
    ElStack *t;
    Imobil *v;
    t = top;
    v = t->adr;
    top = t->prev;
    free(t);
    return v;
}

int createQueue(void)
{
    Imobil* p, *s;
    int d, f;
    root = NULL;
    first = last = NULL;
    printf("Doriti sa creati un arbore(radacina)? (1/0): ");
    scanf("%d", &f);
    if(f == 0)
    {
        puts("Arborele nu a fost creat, memoria nu a fost alocata!");
        return 0;
    }
    p = (Imobil*)malloc(sizeof(*p));
    if(p == NULL)
    {
        return -1;
    }
    puts("Memoria a fost alocata cu succes!");
    puts("\nDati informatia pentru radacina: ");
    puts("________________________________");
    printf("- Denumire: ");
    fflush(stdin);
    gets(p->name);
    printf("- Proprietar: ");
    fflush(stdin);
    gets(p->owner);
    printf("- Tip: ");
    fflush(stdin);
    gets(p->type);
    printf("- Adresa: ");
    fflush(stdin);
    gets(p->addr);
    printf("- Suprafata: ");
    scanf("%d", &p->surf);
    printf("- Pret: ");
    scanf("%d", &p->price);
    d = inQueue(p);
    if(d == 0)
    {
        return -2;
    }
    root = p;
    while(first!=NULL)
    {
        p = delQueue();
        printf("\nDoriti sa creati copilul stang al nodului %s ? (1/0): ", p->name);
        scanf("%d", &f);
        if(f!=0)
        {
            s = (Imobil*)malloc(sizeof(*s));
            if(s == NULL)
            {
                return -3;
            }
            p->left = s;
            puts("Dati informatia pentru nod:");
            puts("___________________________");
            printf("- Denumire: ");
            fflush(stdin);
            gets(s->name);
            printf("- Proprietar: ");
            fflush(stdin);
            gets(s->owner);
            printf("- Tip: ");
            fflush(stdin);
            gets(s->type);
            printf("- Adresa: ");
            fflush(stdin);
            gets(s->addr);
            printf("- Suprafata: ");
            scanf("%d", &s->surf);
            printf("- Pret: ");
            scanf("%d", &s->price);
            d = inQueue(s);
            if(d == 0)
            {
                return -2;
            }
        } else {
            p->left = NULL;
        }
        printf("\nDoriti sa creati copilul drept al nodului %s? (1/0): ", p->name);
        scanf("%d", &f);
        if(f!=0)
        {
            s = (Imobil*)malloc(sizeof(*s));
            if(s == NULL){
                return -3;
            }
            p->right = s;
            puts("Dati informatia pentru nod:");
            puts("___________________________");
            printf("- Denumire: ");
            fflush(stdin);
            gets(s->name);
            printf("- Proprietar: ");
            fflush(stdin);
            gets(s->owner);
            printf("- Tip: ");
            fflush(stdin);
            gets(s->type);
            printf("- Adresa: ");
            fflush(stdin);
            gets(s->addr);
            printf("- Suprafata: ");
            scanf("%d", &s->surf);
            printf("- Pret: ");
            scanf("%d", &s->price);
            d = inQueue(s);
            if(d == 0)
            {
                return -2;
            }
        } else {
            p->right = NULL;
        }
    }
    return 1;
}

int createStack(void)
{
    Imobil *p, *s;
    int d, f;
    root = NULL;
    top = NULL;
    printf("\nDoriti sa creati un arbore(radacina)? (1/0): ");
    scanf("%d", &f);
    if(f == 0)
    {
        puts("Arborele nu a fost creat.");
        return 0;
    }
    p = (Imobil*)malloc(sizeof(*p));
    if(p == NULL)
    {
        return -1;
    }
    puts("Memoria a fost alocata cu succes!");
    puts("\nDati informatia pentru radacina: ");
    puts("___________________________________");
    printf("- Denumire: ");
    fflush(stdin);
    gets(p->name);
    printf("- Proprietar: ");
    fflush(stdin);
    gets(p->owner);
    printf("- Tip: ");
    fflush(stdin);
    gets(p->type);
    printf("- Adresa: ");
    fflush(stdin);
    gets(p->addr);
    printf("- Suprafata: ");
    scanf("%d", &p->surf);
    printf("- Pret: ");
    scanf("%d", &p->price);
    d = push(p);
    if(d == 0)
    {
        return -2;
    }
    root = p;
    while(top!=NULL)
    {
        p = pop();
        printf("Doriti sa creati copilul drept al nodului %s? (1/0): ", p->name);
        scanf("%d", &f);
        if(f!=0)
        {
            s = (Imobil*)malloc(sizeof(*s));
            if(s == NULL)
            {
                return -3;
            }
            p->right = s;
            puts("\nDati informatia pentru nod:");
            puts("______________________________");
            printf("- Denumire: ");
            fflush(stdin);
            gets(s->name);
            printf("- Proprietar: ");
            fflush(stdin);
            gets(s->owner);
            printf("- Tip: ");
            fflush(stdin);
            gets(s->type);
            printf("- Adresa: ");
            fflush(stdin);
            gets(s->addr);
            printf("- Suprafata: ");
            scanf("%d", &s->surf);
            printf("- Pret: ");
            scanf("%d", &s->price);
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        } else {
            p->right = NULL;
        }
        printf("\nDoriti sa creati copilul sting al nodului %s? (1/0): ", p->name);
        scanf("%d", &f);
        if(f!=0)
        {
            s = (Imobil*)malloc(sizeof(*s));
            if(s == NULL)
            {
                return -3;
            }
            p->left = s;
            puts("\nDati informatia pentru nod:");
            puts("______________________________");
            printf("- Denumire: ");
            fflush(stdin);
            gets(s->name);
            printf("- Proprietar: ");
            fflush(stdin);
            gets(s->owner);
            printf("- Tip: ");
            fflush(stdin);
            gets(s->type);
            printf("- Adresa: ");
            fflush(stdin);
            gets(s->addr);
            printf("- Suprafata: ");
            scanf("%d", &s->surf);
            printf("- Pret: ");
            scanf("%d", &s->price);
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        } else {
            p->left = NULL;
        }
    }
    return 1;
}

int show_treeQueue(void)
{
    Imobil *p, *s;
    int d;
    first = last = NULL;
    p = root;
    d = inQueue(p);
    if(d == 0)
    {
        return -2;
    }
    puts("\nInformatia despre noduri:");
    puts("___________________________________________");
    while(first!=NULL)
    {
        p = delQueue();
        printf("- Denumire: %s\n", p->name);
        printf("- Proprietar: %s\n", p->owner);
        printf("- Tip: %s\n", p->type);
        printf("- Adresa: %s\n", p->addr);
        printf("- Suprafata: %d\n", p->surf);
        printf("- Pret: %d\n", p->price);
        printf("- Nodul: %x;  Left: %x, Right: %x\n", p, p->left, p->right);
        puts("___________________________________________");
        s = p->left;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
                return -2;
            }
        }
        s = p->right;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
                return -2;
            }
        }
    }
    return 1;
}

int show_treeStack(void)
{
    Imobil *p, *s;
    int d;
    top = NULL;
    p = root;
    d = push(p);
    if(d == 0)
    {
        return -2;
    }
    puts("\nInformatii despre nod:");
    puts("___________________________________________");
    while(top!=NULL)
    {
        p = pop();
        printf("- Denumire: %s\n", p->name);
        printf("- Proprietar: %s\n", p->owner);
        printf("- Tip: %s\n", p->type);
        printf("- Adresa: %s\n", p->addr);
        printf("- Suprafata: %d\n", p->surf);
        printf("- Pret: %d\n", p->price);
        printf("- Nodul: %x;  Left: %x, Right: %x\n", p, p->left, p->right);
        puts("___________________________________________");
        s = p->right;
        if(s)
        {
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        }
        s = p->left;
        if(s)
        {
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        }
    }
    return 1;
}

int inQueue(Imobil *v)
{
    ElQueue *t;
    t = (ElQueue*)calloc(1,sizeof(*t));
    if(t == NULL) return 0;
    t->adr = v;
    t->next = NULL;
    if(first == NULL)
    {
        first = t;
    } else {
        last->next = t;
    }
    last = t;
    return 1;
}

Imobil *delQueue(void)
{
    ElQueue *t;
    Imobil *v;
    t = first;
    v = t->adr;
    if(t == last)
    {
        first = last = NULL;
    } else {
        first = t->next;
    }
    free(t);
    return v;
}

int push(Imobil *v)
{
    ElStack *t;
    t = (ElStack*)calloc(1,sizeof(*t));
    if(t == NULL)
    {
        return 0;
    }
    t->adr = v;
    t->prev = top;
    top = t;
    return 1;
}


Imobil *search_treeQueue(char* v)
{
    Imobil *p, *s;
    int d;
    first = last = NULL;
    p = root;
    d = inQueue(p);
    if(d == 0)
    {
        return NULL;
    }
    while(first!=NULL)
    {
        p = delQueue();
        if(stricmp(p->name, v)==0)
        {
            return p;
        }
        s = p->left;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
                return NULL;
            }
        }
        s = p->right;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
                return NULL;
            }
        }
    }
    return NULL;
}

Imobil *search_treeStack(char* v)
{
    Imobil *p, *s;
    top = NULL;
    int d;
    d = push(root);
    if(d == 0)
    {
        return NULL;
    }
    while(top!=NULL)
    {
        p = pop();
        if(stricmp(p->name, v)==0)
        {
            return p;
        }
        s = p->left;
        if(s!=NULL)
        {
            push(s);
        }
        s = p->right;
        if(s!=NULL)
        {
            push(s);
        }
    }
    return NULL;
}

void modify_information(Imobil *c)
{
    int f;
    printf("Doriti sa modificati denumirea imobilului? (1/0): ");
    scanf("%d", &f);
    if(f!=0)
    {
        printf("Dati denumirea imobilului: ");
        fflush(stdin);
        gets(c->name);
    }
    printf("Doriti sa modificati proprietarul imobilului? (1/0): ");
    scanf("%d", &f);
    if(f!=0)
    {
        printf("Dati proprietarul: ");
        fflush(stdin);
        gets(c->owner);
    }
    printf("Doriti sa modificati tipul imobilului? (1/0): ");
    scanf("%d", &f);
    if(f!=0)
    {
        printf("Dati tipul: ");
        fflush(stdin);
        gets(c->type);
    }
    printf("Doriti sa modificati adresa imobilului? (1/0): ");
    scanf("%d", &f);
    if(f!=0)
    {
        printf("Dati adresa: ");
        fflush(stdin);
        gets(c->addr);
    }
    printf("Doriti sa modificati suprafata imobilului? (1/0): ");
    scanf("%d", &f);
    if(f!=0)
    {
        printf("Dati suprafata: ");
        scanf("%d", &c->surf);
    }
    printf("Doriti sa modificati pretul imobilului? (1/0): ");
    scanf("%d", &f);
    if(f!=0)
    {
        printf("Dati pretul: ");
        scanf("%d", &c->price);
    }
    return;
}

int size_treeQueue(void)
{
    Imobil *p, *s;
    int d;
    int n = 0;
    first = last = NULL;
    p = root;
    d = inQueue(p);
    if(d == 0)
    {
        return -2;
    }
    while(first!=NULL)
    {
        p = delQueue();
        n++;
        s = p->left;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
                return -2;
            }
        }
        s = p->right;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
                return -2;
            }
        }
    }
    return n;
}

int size_treeStack(void)
{
    Imobil *p, *s;
    int d;
    int n = 0;
    top = NULL;
    p = root;
    d = push(p);
    if(d == 0)
    {
        return -2;
    }
    while(top!=NULL)
    {
        p = pop();
        n++;
        s = p->right;
        if(s)
        {
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        }
        s = p->left;
        if(s)
        {
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        }
    }
    return n;
}

int height_tree_Queue_and_Stack(Imobil *c)
{
    if(c)
    {
        int h_left = height_tree_Queue_and_Stack(c->left);
        int h_right = height_tree_Queue_and_Stack(c->right);
        int n = 1;
        if(h_left > h_right)
        {
            n = h_left;
        } else {
            n = h_right;
        }
        n++;
        return n;
       // return 1 + height_treeQueue(c->left) + height_treeQueue(c->right);
    } else {
        return 0;
    }
}

int free_mem_treeQueue(void)
{
    Imobil* p, *s;
    int d;
    first = last = NULL;
    p = root;
    d = inQueue(p);
    if(d == 0)
    {
        return -2;
    }
    while(first!=NULL)
    {
        p = delQueue();
        s = p->left;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
                return -2;
            }
        }
        s = p->right;
        if(s)
        {
            d = inQueue(s);
            if(d == 0)
            {
            return -2;
            }
        }
        free(p);
    }
    return 1;
}

int free_mem_treeStack(void)
{
    Imobil *p, *s;
    int d;
    top = NULL;
    p = root;
    d = push(p);
    if(d == 0)
    {
        return -2;
    }
    while(top!=NULL)
    {
        p = pop();
        s = p->right;
        if(s)
        {
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        }
        s = p->left;
        if(s)
        {
            d = push(s);
            if(d == 0)
            {
                return -2;
            }
        }
        free(p);
    }
    return 1;
}

void RDS(Imobil *c)
{
    if(c == NULL)
    {
        return;
    }
    puts("___________________________________________");
    printf("- Denumire: %s\n", c->name);
    printf("- Proprietar: %s\n", c->owner);
    printf("- Tip: %s\n", c->type);
    printf("- Adresa: %s\n", c->addr);
    printf("- Suprafata: %d\n", c->surf);
    printf("- Pret: %d\n", c->price);
    printf("- Nodul: %x;  Left: %x, Right: %x\n", c, c->left, c->right);
    puts("___________________________________________");
    RSD(c->right);
    RSD(c->left);
}
void RSD(Imobil *c)
{
    if(c == NULL)
    {
        return;
    }
    puts("___________________________________________");
    printf("- Denumire: %s\n", c->name);
    printf("- Proprietar: %s\n", c->owner);
    printf("- Tip: %s\n", c->type);
    printf("- Adresa: %s\n", c->addr);
    printf("- Suprafata: %d\n", c->surf);
    printf("- Pret: %d\n", c->price);
    printf("- Nodul: %x;  Left: %x, Right: %x\n", c, c->left, c->right);
    puts("___________________________________________");
    RSD(c->left);
    RSD(c->right);
}

void SRD(Imobil *c)
{
    if(c == NULL)
    {
        return;
    }
    SRD(c->left);
    printf("- Denumire: %s\n", c->name);
    printf("- Proprietar: %s\n", c->owner);
    printf("- Tip: %s\n", c->type);
    printf("- Adresa: %s\n", c->addr);
    printf("- Suprafata: %d\n", c->surf);
    printf("- Pret: %d\n", c->price);
    printf("- Nodul: %x;  Left: %x, Right: %x\n", c, c->left, c->right);
    puts("___________________________________________");
    SRD(c->right);
}

void DRS(Imobil *c)
{
    if(c == NULL)
    {
        return;
    }
    DSR(c->right);
    puts("___________________________________________");
    printf("- Denumire: %s\n", c->name);
    printf("- Proprietar: %s\n", c->owner);
    printf("- Tip: %s\n", c->type);
    printf("- Adresa: %s\n", c->addr);
    printf("- Suprafata: %d\n", c->surf);
    printf("- Pret: %d\n", c->price);
    printf("- Nodul: %x;  Left: %x, Right: %x\n", c, c->left, c->right);
    puts("___________________________________________");
    DSR(c->left);
}


void SDR(Imobil *c)
{
    if(c == NULL)
    {
        return;
    }
    SDR(c->left);
    SDR(c->right);
    puts("___________________________________________");
    printf("- Denumire: %s\n", c->name);
    printf("- Proprietar: %s\n", c->owner);
    printf("- Tip: %s\n", c->type);
    printf("- Adresa: %s\n", c->addr);
    printf("- Suprafata: %d\n", c->surf);
    printf("- Pret: %d\n", c->price);
    printf("- Nodul: %x;  Left: %x, Right: %x\n", c, c->left, c->right);
    puts("___________________________________________");
}

void DSR(Imobil *c)
{
    if(c == NULL)
    {
        return;
    }
    DSR(c->right);
    DSR(c->left);
    puts("___________________________________________");
    printf("- Denumire: %s\n", c->name);
    printf("- Proprietar: %s\n", c->owner);
    printf("- Tip: %s\n", c->type);
    printf("- Adresa: %s\n", c->addr);
    printf("- Suprafata: %d\n", c->surf);
    printf("- Pret: %d\n", c->price);
    printf("- Nodul: %x;  Left: %x, Right: %x\n", c, c->left, c->right);
    puts("___________________________________________");
}
