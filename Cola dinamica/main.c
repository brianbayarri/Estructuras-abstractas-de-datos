#include <stdio.h>
#include <stdlib.h>
typedef int t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
}t_nodo;
typedef struct
{
    t_nodo *pri,*ult;
}t_cola;

void crear_cola(t_cola *pc)
{
    pc->pri=NULL;
    pc->ult=NULL;
}

int cola_llena(const t_cola *pc)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int poner_en_cola(t_cola *pc, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=NULL;
    if(pc->pri==NULL)
        pc->pri=pnue;
    else
        pc->ult->psig=pnue;
    pc->ult=pnue;
    return 1;
}

int cola_vacia(const t_cola *pc)
{
    return pc->pri==NULL;
}

int sacar_de_cola(t_cola *pc,t_dato *d)
{
    t_nodo *pelim;
    if(pc->pri==NULL)
        return 0;
    pelim=pc->pri;
    *d=pelim->dato;
    pc->pri=pelim->psig;
    if(pc->pri==NULL)
        pc->ult=NULL;
    free(pelim);
    return 1;
}

int ver_primero_cola(const t_cola *pc, t_dato *d)
{
    if(pc->pri==NULL)
        return 0;
    *d=pc->pri->dato;
    return 1;
}

void vaciar_cola(t_cola *pc)
{
    t_nodo *pelim;
    while(pc->pri)
    {
        pelim=pc->pri;
        pc->pri=pelim->psig;
        free(pelim);
    }
    pc->ult=NULL;
}

int main()
{
    printf("Primitivas de cola dinamica");
    return 0;
}
