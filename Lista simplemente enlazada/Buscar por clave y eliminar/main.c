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

int insertar_ultimo(t_lista *pl, const t_dato *d)
{
    while(*pl)
        pl=&(*pl)->psig;
    *pl=(t_nodo *)malloc(sizeof(t_nodo));
    if((*pl)==NULL)
        return 0;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return 1;
}

int comparar(const t_dato *a, const t_dato *b)
{
    return *a-*b;
}

int buscar_eliminar_desord (t_lista *pl, t_dato *d, int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *aux;
    while((*pl) && (comparar(&(*pl)->dato,d)))
        pl=&(*pl)->psig;
    if((*pl)==NULL)
        return 0;
    aux=*pl;
    *d=aux->dato;
    *pl=aux->psig;
    free(aux);
    return 1;
}

int buscar_eliminar_ord (t_lista *pl, t_dato *d, int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *aux;
    while((*pl) && (comparar(&(*pl)->dato,d)<0))
        pl=&(*pl)->psig;
    if((*pl)==NULL || comparar(&(*pl)->dato,d))
        return 0;
    aux=*pl;
    *d=aux->dato;
    *pl=aux->psig;
    free(aux);
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

int main()
{
    int n,b=0;
    t_lista lista;
    crear_lista(&lista);
    printf("Ingrese un numero: ");
    scanf("%d",&n);
    while(n!=0)
    {
        if(b==0)
        {
            insertar_primero(&lista,&n);
            b=1;
        }
        else
        {
            insertar_ultimo(&lista,&n);
        }
        printf("Ingrese un numero: ");
        scanf("%d",&n);
    }

    mostrar_lista(&lista,mostrar);
    printf("\n\n<<<<Saquemos un elemento>>>>\n");
    printf("Ingrese elemento a sacar: ");
    scanf("%d",&n);
    buscar_eliminar_desord(&lista,&n,comparar);
    printf("La lista queda: ");
    mostrar_lista(&lista,mostrar);
    return 0;
}
