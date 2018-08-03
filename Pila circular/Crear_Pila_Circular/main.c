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

int main()
{
    t_pila pila;
    printf("\nCrearemos la pila circular.\n");
    Crear_Pila_Circular(&pila);
    if(pila==NULL)
    {
        printf("\n\nLa pila circular ha sido creada.\n");
    }
    return 0;
}
