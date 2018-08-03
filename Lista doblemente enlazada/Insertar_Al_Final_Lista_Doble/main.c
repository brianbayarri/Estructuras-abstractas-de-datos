#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig, *pant;
} t_nodo;

typedef t_nodo *t_lista;

void Crear_Lista_Doble(t_lista *pl)
{
    *pl=NULL;
}

int Insertar_Al_Final_Lista(t_lista *pl, t_dato *pd)
{
    t_nodo *pact=*pl, *pnue;
    if(pact)
    {
        while(pact->psig)
            pact=pact->psig;
    }
    pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
    {
        return 0;
    }
    pnue->psig=NULL;
    pnue->dato=*pd;
    pnue->pant=pact;
    if(pact)
        pact->psig=pnue;
    else
        *pl=pnue;
    return 1;
}

void Mostrar_Lista_Doble(const t_lista *pl)
{
    if(*pl==NULL)
        printf("\n\nLa lista esta vacia.\n\n");
    else
    {
        while((*pl)->pant)
            pl=&(*pl)->pant;

        while(*pl)
        {
            printf("\n%d",(*pl)->dato.dato);
            pl=&(*pl)->psig;
        }
    }

}

int main()
{
    t_lista lista;
    t_dato d;
    Crear_Lista_Doble(&lista);
    printf("\nCargaremos la lista. La condicion de\nfin de carga es '0'.\n\n");
    printf("Ingrese el numero a cargar en la lista: ");
    scanf("%d",&d.dato);
    while(d.dato!=0)
    {
        Insertar_Al_Final_Lista(&lista,&d);
        printf("\n\nIngrese el numero a cargar en la lista: ");
        scanf("%d",&d.dato);
    }

    printf("\n\nSe ha terminado de cargar la lista.");
    printf("\n\nMostraremos la lista:\n ");
    Mostrar_Lista_Doble(&lista);
    return 0;
}
