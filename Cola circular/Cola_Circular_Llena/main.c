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

typedef t_nodo *t_cola;

void Crear_Cola_Circular(t_cola *pc)
{
    *pc=NULL;
}

int Cola_Circular_Llena(const t_cola *pc)
{
    void *pnue=malloc(sizeof(t_nodo));
    free(pnue);
    return pnue==NULL;
}

int main()
{
    t_cola cola;
    printf("\nCreamos la cola circular.");
    Crear_Cola_Circular(&cola);
    printf("\n\nVemos si la cola esta llena.");
    if(Cola_Circular_Llena(&cola))
        printf("\n\nLa cola circular esta llena.\n");
    else
        printf("\n\nLa cola no esta llena.\n");
    return 0;
}
