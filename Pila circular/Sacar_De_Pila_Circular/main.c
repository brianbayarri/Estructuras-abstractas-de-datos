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

typedef t_nodo *t_pila;

void Crear_Pila_Circular(t_pila *pp)
{
    *pp=NULL;
}

int Poner_En_Pila_Circular(t_pila *pp, t_dato *pd)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
    {
        printf("\n\nLa pila circular esta llena.");
        return 0;
    }
    pnue->dato=*pd;
    if(*pp==NULL)
    {
        pnue->psig=pnue;
        *pp=pnue;
    }
    else
    {
        pnue->psig=(*pp)->psig;
        (*pp)->psig=pnue;
    }
    return 1;
}

void Mostrar_Pila_Circular(const t_pila *pp)
{
    t_nodo *pri=*pp;
    if(*pp)
    {
        pp=&(*pp)->psig;

        while(*pp && *pp!=&(*pri))
        {
            printf("%d\n",(*pp)->dato.dato);
            pp=&(*pp)->psig;
        }
        if(*pp)
        {
            printf("%d\n",(*pp)->dato.dato);
        }
    }
}


int Sacar_De_Pila_Circular(t_pila *pp, t_dato *pd)
{
    t_nodo *pelim;
    if(*pp==NULL)
    {
        printf("\n\nLa pila circular esta vacia.");
        return 0;
    }
    pelim=(*pp)->psig;
    *pd=pelim->dato;
    if(pelim==*pp)
        *pp=NULL;
    else
        (*pp)->psig=pelim->psig;
    free(pelim);
    return 1;
}

int main()
{
    t_pila pila;
    t_dato d;
    printf("\nCreamos la pila circular.");
    Crear_Pila_Circular(&pila);
    printf("\n\nCargaremos la pila circular.\nLa condicion de fin de carga es '0'.");
    printf("\n\nIngrese un dato a colocar en la pila: ");
    scanf("%d",&d.dato);
    while(d.dato!=0)
    {
        Poner_En_Pila_Circular(&pila,&d);
        printf("\n\nIngrese un dato a colocar en la pila: ");
        scanf("%d",&d.dato);
    }
    printf("\n\nSe ha terminado de cargar la pila circular.");
    printf("\n\nLa pila circular es:\n");
    Mostrar_Pila_Circular(&pila);
    printf("\n\nSacaremos/eliminaremos el ultimo dato de la pila circular.");
    Sacar_De_Pila_Circular(&pila,&d);
    printf("\n\nLa pila circular final es:\n");
    Mostrar_Pila_Circular(&pila);
    return 0;
}
