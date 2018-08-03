#include <stdio.h>
#include <stdlib.h>
typedef int t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
}t_nodo;
typedef t_nodo *t_pila;

void crear_pila(t_pila *pp)
{
    *pp=NULL;
}

int poner_en_pila(t_pila *pp, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=*pp;
    *pp=pnue;
    return 1;
}

int pila_llena(const t_pila *pp)
{
    void *pnue=malloc(sizeof(t_nodo))
    free(pnue);
    return !pnue;
}

int pila_vacia(const t_pila *pp)
{
    return *pp==NULL;
}

int ver_tope(const t_pila *pp, t_dato *d)
{
    if(*pp==NULL)
        return 0;
    *d=(*pp)->dato;
    return 1;
}

void vaciar_pila(t_pila *pp)
{
    t_nodo *pelim;
    while(*pp)
    {
        pelim=*pp;
        *pp=pelim->psig;
        free(pelim);
    }
}

int sacar_de_pila(t_pila *pp, const t_dato *d)
{
    t_nodo *pelim;
    if(*pp==NULL)
        return 0;
    pelim=*pp;
    *d=pelim->dato;
    *pp=pelim->psig;
    free(pelim);
    return 1;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
