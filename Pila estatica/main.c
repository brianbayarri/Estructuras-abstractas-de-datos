#include <stdio.h>
#include <stdlib.h>
#define TAM
typedef int t_dato
typedef struct
{
    t_dato pila[TAM];
    int tope;
}t_pila;

void crear_pila(t_pila *pp)
{
    pp->tope=-1;
}

int poner_en_pila(t_pila *pp, const t_dato *d)
{
    if(tope==MAX)
        return 0;
    pp->tope++;
    pp->pila[pp->tope]=*d;
    return 1;
}

int pila_llena(const t_pila *pp)
{
    return pp->tope==MAX;
}

int pila_vacia(const t_pila *pp)
{
    return pp->tope==-1;
}

int ver_tope(const t_pila *pp, t_dato *d)
{
    if(pp->tope==-1)
        return 0;
    *d=pp->pila[pp->tope];
    return 1;
}

void vaciar_pila(t_pila *pp)
{
    pp->tope=-1;
}

int sacar_de_pila(t_pila *pp, t_dato *d)
{
    if(pp->tope==-1)
        return 0;
    pp->tope--;
    *d=pp->pila[pp->tope];
    return 1;
}


int main()
{
    printf("Primivitas de pila estatica");
    return 0;
}
