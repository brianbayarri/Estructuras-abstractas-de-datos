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

void mostrar(const t_dato *d)
{
    printf("%d\n",d->dato);
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

int Comparar(const t_dato *n1, const t_dato *n2)
{
    return (n2->dato)-(n1->dato);
}

void Ordenamiento_Binario_Lista_Doble(t_lista *pl)
{
    int marca=1;
    t_nodo *pri=*pl,*pact,*ant,*sig,*sigsig;
    if(pri)
    {
        while(pri->pant)
            pri=pri->pant;

        while(marca)
        {
            marca=0;
            pact=pri;
            while(pact->psig)
            {
                if(Comparar(&(pact->dato),&(pact->psig->dato))>0)
                {
                    marca=1;
                    ant=pact->pant;
                    sig=pact->psig;
                    sigsig=sig->psig;
                    if(ant)
                        ant->psig=sig;
                    sig->pant=ant;
                    if(sigsig)
                        sigsig->pant=pact;
                    pact->psig=sigsig;
                    pact->pant=sig;
                    sig->psig=pact;
                }
                else
                    pact=pact->psig;
            }
            while(pri->pant)
                pri=pri->pant;
        }
    }
}


int main()
{
    t_lista lista;
    t_dato d;
    printf("\nCrearemos la lista.");
    Crear_Lista_Doble(&lista);
    printf("\n\nCargaremos la lista.\nLa condicion de fin de carga es '0'.");
    printf("\n\nIngrese un numero a colocar en la lista: ");
    scanf("%d",&d.dato);
    while(d.dato!=0)
    {
        Insertar_Al_Final_Lista(&lista,&d);
        printf("\n\nIngrese un numero a colocar en la lista: ");
        scanf("%d",&d.dato);
    }
    printf("\n\nTerminamos de cargar la lista.");
    printf("\n\nMostraremos la lista inicial: ");
    Mostrar_Lista_Doble(&lista);
    printf("\n\nAhora ordenamos la lista por metodo binario.");
    Ordenamiento_Binario_Lista_Doble(&lista);
    printf("\n\nMostraremos la lista final: ");
    Mostrar_Lista_Doble(&lista);

    return 0;
}
