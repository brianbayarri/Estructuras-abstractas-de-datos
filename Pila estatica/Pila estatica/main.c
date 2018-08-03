#include <stdio.h>
#include <stdlib.h>
#define max 3
typedef struct
{
    int edad;
    char nombre[30];
}t_persona;
typedef t_persona t_dato;
typedef struct
{
    t_dato pila[max];
    int tope;
}t_pila;

void crear_pila(t_pila *pp)
{
    pp->tope=0;
}

int poner_primero(t_pila *pp, const t_dato *d)
{
    if(pp->tope==max)
        return 0;
    pp->tope++;
    pp->pila[pp->tope]=*d;
    return 1;
}

int pila_llena(const t_pila *pp)
{
    return pp->tope==max;
}

int pila_vacia (const t_pila *pp)
{
    return pp->tope==0;
}

void vaciar_pila (t_pila *pp)
{
    pp->tope=0;
}

int ver_tope(const t_pila *pp, t_dato *d)
{
    if(pp->tope==0)
        return 0;
    *d=pp->pila[pp->tope];
    return 1;
}

int sacar_de_pila(t_pila *pp, t_dato *d)
{
    if(pp->tope==0)
        return 0;
    pp->tope--;
    *d=pp->pila[pp->tope];
    return 1;
}

t_persona ingreg()
{
    t_persona aux;
    printf("Ingrese una edad: ");
    scanf("%d",&aux.edad);
    fflush(stdin);
    printf("Ingrese un nombre: ");
    scanf("%s",aux.nombre);
    fflush(stdin);
    return aux;
}

int main()
{
    t_pila pila;
    t_persona reg;
    int c;
    crear_pila(&pila);
    reg=ingreg();
    while(reg.edad!=0 && !pila_llena(&pila))
    {
        poner_primero(&pila,&reg);
        reg=ingreg();
    }
    ver_tope(&pila,&reg);
    printf("El tope es: %d|%s",reg.edad,reg.nombre);
    if(pila_llena(&pila))
        printf("Pila llena");
    else
        printf("Pila no llena");
    vaciar_pila(&pila);
    if(pila_vacia(&pila))
        printf("Pila vacia");

    return 0;
}
