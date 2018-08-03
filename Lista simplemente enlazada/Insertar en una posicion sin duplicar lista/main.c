#include <stdio.h>
#include <stdlib.h>
typedef int t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
} t_nodo;
typedef t_nodo *t_lista;

void crear_lista(t_lista *pl)
{
    *pl=NULL;
}

int poner_primero (t_lista *pl, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;
}

int poner_ultimo(t_lista *pl, const t_dato *d)
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

int insertar_en_pos(t_lista *pl, const t_dato *d, int pos)
{
    t_lista *q;
    q=pl;
    while((*q) &&(comparar(&(*q)->dato,d)!=0))
        q=&(*q)->psig;

    if(*q)
    {
        printf("No se pudo insertar, hay duplicado");
        return 0;
    }
    while((*pl) && --pos )
        pl=&(*pl)->psig;
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;

}

int main()
{
    int num,b=0,pos;
    t_lista lista;
    crear_lista(&lista);
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    while(num!=0)
    {
        if(b==0)
        {
            poner_primero(&lista,&num);
            b=1;
        }
        else
        {
            poner_ultimo(&lista,&num);
        }
        printf("Ingrese un numero: ");
        scanf("%d",&num);
    }
    printf("\n\n<<<Lista original>>>\n");
    mostrar_lista(&lista,mostrar);
    printf("\n\nIngrese un numero numero: ");
    scanf("%d",&num);
    printf("En que posicion desea ponerlo: ");
    scanf("%d",&pos);
    if(insertar_en_pos(&lista,&num,pos)==1)
    {
        printf("\n\n<<<Nueva lista>>>\n");
        mostrar_lista(&lista,mostrar);
    }
    return 0;
}
