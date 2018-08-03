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

int Poner_En_Cola_Circular(t_cola *pc, t_dato *pd)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
    {
        printf("\n\nLa cola circular esta llena.");
        return 0;
    }
    pnue->dato=*pd;
    if(*pc==NULL)
    {
        *pc=pnue;
        pnue->psig=pnue;
        return 1;
    }
    pnue->psig=(*pc)->psig;
    (*pc)->psig=pnue;
    *pc=pnue;
    return 1;
}

void Mostrar_Cola_Circular(const t_cola *pc)
{
    t_nodo *pri=*pc;
    if(*pc)
    {
        printf("%d\n",(*pc)->dato.dato);
        pc=&(*pc)->psig;
    }
    while(*pc && *pc!=&(*pri))
    {
        printf("%d\n",(*pc)->dato.dato);
        pc=&(*pc)->psig;
    }
}

int Sacar_De_Cola_Circular(t_cola *pc, t_dato *pd)
{
    t_nodo *pelim;
    if(*pc==NULL)
    {
        printf("\n\nLa cola circular esta vacia.");
        return 0;
    }
    pelim=(*pc)->psig;
    *pd=pelim->dato;
    if(pelim==*pc)
        *pc=NULL;
    else
        (*pc)->psig=pelim->psig;
    free(pelim);
    return 1;
}

int main()
{
    t_cola cola;
    t_dato d;
    printf("\nCreamos la cola circular.");
    Crear_Cola_Circular(&cola);
    printf("\n\nCargaremos la cola circular.\nLa condicion de fin de carga es '0'.");
    printf("\n\nIngrese un dato a colocar en la cola: ");
    scanf("%d",&d.dato);
    while(d.dato!=0)
    {
        Poner_En_Cola_Circular(&cola,&d);
        printf("\n\nIngrese un dato a colocar en la cola: ");
        scanf("%d",&d.dato);
    }
    printf("\n\nSe ha terminado de cargar la cola circular.");
    printf("\n\nLa cola circular es:\n");
    Mostrar_Cola_Circular(&cola);
    printf("\n\nSacaremos/eliminaremos el primer dato de la cola circular.");
    Sacar_De_Cola_Circular(&cola,&d);
    printf("\n\nLa cola circular final es:\n");
    Mostrar_Cola_Circular(&cola);
    return 0;
}
