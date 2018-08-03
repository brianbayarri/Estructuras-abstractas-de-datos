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

int Cola_Circular_Vacia(const t_cola *pc)
{
    return *pc==NULL;
}

int main()
{
    t_cola cola;
    printf("\nCreamos la cola circular.");
    Crear_Cola_Circular(&cola);
    printf("\n\nVerificamos que la cola este vacia.");
    if(Cola_Circular_Vacia(&cola))
        printf("\n\nLa cola circular esta vacia.\n");
    return 0;
}
