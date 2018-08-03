#include <stdio.h>
#include <stdlib.h>
typedef int t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
}t_nodo;
typedef t_nodo *t_lista;

void crear_lista(t_lista *pl)
{
    *pl=NULL;
}

int insertar_primero(t_lista *pl, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;
}

int insertar_ultimo (t_lista *pl, const t_dato *d)
{
    while(*pl)
        pl=&(*pl)->psig;
    *pl=(t_nodo *)malloc(sizeof(t_nodo));
    if(*pl==NULL)
        return 0;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return 1;
}

void mostrar(const t_dato *d)
{
    printf("%d\n",*d);
}

void mostrar_lista(const t_lista *pl,void(*mostrar)(const t_dato *))
{
    while(*pl)
    {
        mostrar(&(*pl)->dato);
        pl=&(*pl)->psig;
    }
}

int comparar(const t_dato *a, const t_dato *b)
{
    return *a-*b;
}

void ordenar_lista(t_lista *pl,int(*comparar)(const t_dato *,const t_dato *))
{
    int marca=1;
    t_lista *q;
    t_nodo *aux;
    if(*pl)
    {
        while(marca)
        {
            marca=0;
            q=pl;
            while((*q)->psig)
            {
                if(comparar(&(*q)->dato,&(*q)->psig->dato)>0)
                {
                    marca=1;
                    aux=*q;
                    *q=aux->psig;
                    aux->psig=(*q)->psig;
                    (*q)->psig=aux;
                }
                q=&(*q)->psig;
            }
        }
    }
}

void eliminar_unicos(t_lista *pl,int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *aux;
    while(*pl)
    {
        aux=*pl;
        while(aux->psig && comparar(&(*pl)->dato,&aux->psig->dato)==0)
            aux=aux->psig;
        if(*pl!=aux)
            pl=&aux->psig;
        else
        {
            *pl=aux->psig;
            free(aux);

        }
    }
}


int main()
{
    int num,b=0;
    t_lista lista;
    crear_lista(&lista);
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    while(num!=0)
    {
        if(b==0)
        {
            insertar_primero(&lista,&num);
            b=1;
        }
        else
        {
            insertar_ultimo(&lista,&num);
        }
        printf("Ingrese un numero: ");
        scanf("%d",&num);
    }

    printf("\n\n\n<<<Lista original>>>\n");
    mostrar_lista(&lista,mostrar);
    printf("\n\n<<<Lista ordenada>>>\n");
    ordenar_lista(&lista,comparar);
    mostrar_lista(&lista,mostrar);
    eliminar_unicos(&lista,comparar);
    mostrar_lista(&lista,mostrar);

    return 0;
}
