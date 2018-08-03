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

int main()
{
    t_cola cola;
    printf("\nCrearemos la cola circular.\n");
    Crear_Cola_Circular(&cola);
    if(cola==NULL)
    {
        printf("\n\nLa cola circular ha sido creada.\n");
    }
    return 0;
}
