#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef int t_dato;
typedef struct
{
    t_dato cola[TAM];
    int pri,ult:
}t_cola;

void crear_cola(t_cola *pc)
{
    pc->pri=0;
    pc->ult=-1;
}

int cola_llena (t_cola *pc)
{
    return ((pc->pri==0 && pc->ult==TAM-1) || (pc->pri==pc->ult+1 && pc->ult!=-1));
}

int poner_en_cola(t_cola *pc, const t_dato *d)
{
    if((pc->pri==0 && pc->ult==TAM-1) || (pc->pri=pc->ult+1 && pc->ult!=-1))
        return 0;
    pc->ult++;
    if(pc->ult==TAM)
        return 0;
    pc->cola[pc->ult]=*d;
    return 1;
}

int sacar_de_cola(t_cola *pc, t_dato *d)
{
    if(pc->ult==-1)
        return 0;
    *d=pc->cola[pc->pri];
    if(pc->pri==pc->ult)
    {
        pc->pri=0;
        pc->ult=-1;
    }
    else
    {
        pc->pri++;
        if(pc->pri==TAM)
            pc->pri=0;
    }
    return 1;
}

int cola_vacia (const t_cola *pc)
{
    return pc->ult==-1;
}

int ver_primero (const t_cola *pc, t_dato *d)
{
    if(pc->ult==-1)
        return 0;
    *d=pc->cola[pc->pri];
    return 1;
}

void vaciar_cola(t_cola *pc)
{
    pc->pri=0;
    pc->ult=-1;
}

int main()
{
    printf("Primitivas de cola estatica");
    return 0;
}
