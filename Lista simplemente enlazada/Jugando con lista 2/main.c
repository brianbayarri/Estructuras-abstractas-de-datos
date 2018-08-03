#include <stdio.h>
#include <stdlib.h>
typedef int t_dato;
typedef struct s_nodo {
            t_dato dato;
            struct s_nodo *psig;
}t_nodo;
typedef t_nodo *t_lista;

void crear_lista(t_lista *pl)
{
    *pl=NULL;
}

int poner_primero_lista(t_lista *pl, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;
}

int poner_ultimo_lista(t_lista *pl, const t_dato *d)
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

int ver_primero_lista(const t_lista *pl, t_dato *d)
{
    if(*pl==NULL)
        return 0;
    *d=(*pl)->dato;
    return 1;
}

int ver_ultimo_lista(const t_lista *pl, t_dato *d)
{
    if(*pl==NULL)
        return 0;
    while((*pl)->psig)
    {
        pl=&(*pl)->psig;
    }
    *d=(*pl)->dato;
    return 1;
}

int insertar_en_pos(t_lista *pl, const t_dato *d, int pos)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    while((*pl) && --pos)
            pl=&(*pl)->psig;

    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;

}

void mostrar(const t_dato *d)
{
    printf("\n%d",*d);
}

void mostrar_lista(const t_lista *pl, void(*mostrar)(const t_dato *))
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

void eliminar_dup(t_lista *pl, int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo **pr,*pelim;
    while(*pl)
    {
        pr=&(*pl)->psig;
        while(*pr)
        {
            if(comparar(&(*pr)->dato,&(*pl)->dato)==0)
            {
                pelim=*pr;
                *pr=pelim->psig;
                free(pelim);
            }
            else
            {
                pr=&(*pr)->psig;
            }
        }
        pl=&(*pl)->psig;
    }
}


int main()
{
    t_lista lista;
    t_dato n,t,x;
    int p;
    crear_lista(&lista);
    printf("Ingrese un numero: ");
    scanf("%d",&n);
    poner_primero_lista(&lista,&n);
    printf("\nIngrese un numero: ");
    scanf("%d",&n);
    while(n!=0)
    {
        poner_ultimo_lista(&lista,&n);
        printf("\nIngresar un numero: ");
        scanf("%d",&n);
    }
    ver_primero_lista(&lista,&t);
    printf("\nEl primero de la lista es %d",t);
    ver_ultimo_lista(&lista,&t);
    printf("\nEl ultimo de la lista es %d",t);
    printf("\nIngrese ahora un dato a insertar en determinada posicion: ");
    scanf("%d",&n);
    printf("\nIngrese la posicion: ");
    scanf("%d",&p);
    insertar_en_pos(&lista,&n,p);
    mostrar_lista(&lista,mostrar);
    printf("\n\n<<<Eliminamos duplicados>>>");
    eliminar_dup(&lista,comparar);
    mostrar_lista(&lista,mostrar);

        return 0;
}
