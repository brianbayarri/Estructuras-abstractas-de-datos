#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *pant, *psig;
} t_nodo;

typedef t_nodo *t_lista;

void Crear_Lista_Doble(t_lista *pl)
{
    *pl=NULL;
}

int Insertar_Al_Final_Lista(t_lista *pl,t_dato *pd)
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
        printf("\n\nLista llena.");
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
    printf("\nCreamos la lista.");
    Crear_Lista_Doble(&lista);
    if(lista==NULL)
    {
        printf("\n\nLa lista fue creada.");
    }
    printf("\n\nCargaremos la lista.\nLa condicion de fin de carga es '0'.");
    printf("\n\nIngrese un numero a colocar en la lista: ");
    scanf("%d",&d.dato);
    while(d.dato!=0)
    {
        Insertar_Al_Final_Lista(&lista,&d);
        printf("\n\nIngrese un numero a colocar en la lista: ");
        scanf("%d",&d.dato);
    }
    printf("\n\nLa lista se termino de cargar.");
    printf("\n\nLa lista cargada es: \n");
    Mostrar_Lista_Doble(&lista);
    return 0;
}
