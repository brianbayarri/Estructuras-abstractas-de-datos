#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
} t_nodo;

typedef t_nodo *t_pila;

void Crear_Pila_Circular(t_pila *pp)
{
    *pp=NULL;
}

int Cola_Pila_Llena(const t_pila *pp)
{
    void *pnue=malloc(sizeof(t_nodo));
    free(pnue);
    return pnue==NULL;
}

int main()
{
    t_pila pila;
    printf("\nCreamos la pila circular.");
    Crear_Pila_Circular(&pila);
    printf("\n\nVemos si la pila esta llena.");
    if(Cola_Pila_Llena(&pila))
        printf("\n\nLa pila circular esta llena.\n");
    else
        printf("\n\nLa pila no esta llena.\n");
    return 0;
}
