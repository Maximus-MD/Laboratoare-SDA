typedef struct Imobil
{
    char name[30];
    char owner[30];
    char type[30];
    char addr[30];
    int surf;
    int price;
    struct Imobil *left;
    struct Imobil *right;
}Imobil;

Imobil *root = NULL;
typedef struct ElQueue
{
    Imobil *adr;
    struct ElQueue *next;
}ElQueue;

ElQueue *first, *last;

typedef struct ElStack
{
    Imobil *adr;
    struct ElStack *prev;
}ElStack;

ElStack *top;

int inQueue(Imobil *v);
Imobil* delQueue(void);

int push(Imobil *v);
Imobil *pop(void);

int createQueue(void);
int createStack(void);
int show_treeQueue(void);
int show_treeStack(void);
Imobil *search_treeQueue(char *v);
Imobil *search_treeStack(char *v);
void modify_information(Imobil *a);
int size_treeQueue(void);
int size_treeStack(void);
int height_tree_Queue_and_Stack(Imobil *c);
int free_mem_treeQueue(void);
int free_mem_treeStack(void);
int max_ImobilQueue(void);
void RDS(Imobil *c);
void RSD(Imobil *c);
void SRD(Imobil *c);
void DRS(Imobil *c);
void SDR(Imobil *c);
void DSR(Imobil *c);
