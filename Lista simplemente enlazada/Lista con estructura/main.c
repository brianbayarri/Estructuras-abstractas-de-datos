#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int edad;
    char nombre[30];
    char apellido[30];
}t_persona;

typedef t_persona t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
}t_nodo;

typedef t_nodo *t_lista;

void crear_lista(t_lista *pl)
{
    *pl=NULL;
}

int poner_primero(t_lista *pl, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;
}

t_persona ingreg()
{
    t_persona aux;
    printf("Ingrese edad: ");
    scanf("%d",&aux.edad);
    fflush(stdin);
    printf("Ingrese nombre: ");
    scanf("%s",aux.nombre);
    fflush(stdin);
    printf("Ingrese apellido: ");
    scanf("%s",aux.apellido);
    fflush(stdin);
    return aux;
}

void mostrar(const t_dato *d)
{
    printf("%d | %s | %s\n",d->edad,d->nombre, d->apellido);
}

void mostrar_lista(const t_lista *pl, void(*mostrar)(const t_dato *))
{
    while(*pl)
    {
        mostrar(&(*pl)->dato);
        pl=&(*pl)->psig;
    }
}

int main()
{
    t_persona reg;
    t_lista lista;
    crear_lista(&lista);
    reg=ingreg();
    while(reg.edad>0)
    {
        poner_primero(&lista,&reg);
        reg=ingreg();
    }

    mostrar_lista(&lista,mostrar);
    return 0;
}
