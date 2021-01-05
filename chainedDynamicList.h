typedef struct
{
    int info;
    char* name;
}pItem;

typedef struct pCell
{
    pItem data;
    struct pCell* next;
}pCell;

typedef struct
{
    pCell* first;
    int size;
}pList;

pList* creat_list();

void insert_list(pList* list, pItem node);

void print_list(pList* list);

void insert_beginning_list(pList* list, pItem node);

pCell* at_Position(pList* list, int index);

int index_Of(pList* list, pCell* node);

void remove_beginning(pList* list);

bool empty_list(pList* list);
