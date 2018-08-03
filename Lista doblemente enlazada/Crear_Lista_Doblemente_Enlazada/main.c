#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
}t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig, *pant;
}t_nodo;

typedef t_nodo *t_lista;

void Crear_Lista_Doble(t_lista *pl)
{
    *pl=NULL;
}

int main()
{
    t_lista lista;
    printf("\nCrearemos la lista doblemente enlazada\n\n");
    Crear_Lista_Doble(&lista);
    if(lista==NULL)
    {
        printf("\n\nExiste la lista.\n\n");

    }
    return 0;
}
