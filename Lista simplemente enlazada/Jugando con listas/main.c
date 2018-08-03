#include <stdio.h>
#include <stdlib.h>
#define lista_llena 1
#define lista_vacia 1
#define todo_piola 0
typedef int t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
} t_nodo;
typedef t_nodo *t_lista;

void crear_lista (t_lista *pl)
{
    *pl=NULL;
}

int poner_primero (t_lista *pl, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(!pnue)
        return lista_llena;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return todo_piola;
}

int poner_ultimo (t_lista *pl, const t_dato *d)
{
    while(*pl)
        pl=&(*pl)->psig;
    *pl=(t_nodo *)malloc(sizeof(t_nodo));
    if(*pl==NULL)
        return lista_llena;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return todo_piola;

}

int ver_primero (const t_lista *pl, t_dato *d)
{
    if(*pl==NULL)
        return lista_vacia;
    *d=(*pl)->dato;
    return todo_piola;

}

int ver_ultimo (const t_lista *pl, t_dato *d)
{
    if(*pl==NULL)
        return 0;
    while((*pl) && (*pl)->psig)
        pl=&(*pl)->psig;
    *d=(*pl)->dato;
    return 1;
}

int sacar_primero (t_lista*pl, t_dato*d)
{
    t_nodo*pelim;
    if(*pl==NULL)
        return 0;
    pelim=(*pl);
    *d=pelim->dato;
    *pl=pelim->psig;
    free(pelim);
    return 1;
}

void mostrar(const t_dato *d)
{
    printf(" %d ",d->dato);
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
    t_lista lista;
    int a=5, b=6, c=7, d, e;
    crear_lista(&lista);
    poner_primero(&lista,&a);
    poner_ultimo(&lista,&b);
    poner_ultimo(&lista,&c);
    ver_primero(&lista,&d);
    printf("El primero es %d",d);
    poner_primero(&lista,&c);
    ver_primero(&lista,&d);
    printf("El primero es %d",d);
    sacar_primero(&lista,&e);
    printf("El primero que lo saque es %d",e);
    mostrar_lista(&lista,mostrar,stdout);
    return 0;
}
