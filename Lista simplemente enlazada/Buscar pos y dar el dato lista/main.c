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

int poner_primero(t_lista *pl, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
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

/*void elemento_pos(const t_lista *pl, int *d, int pos)
{
    while(*pl && --pos)
        pl=&(*pl)->psig;
    *d=(*pl)->dato;
}*/
int main()
{
    int b=0,pos,num;
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
    printf("\n\n<<<Lista>>>\n");
    mostrar_lista(&lista,mostrar);
    printf("\n\nIngrese una posicion: ");
    scanf("%d",&pos);
    elemento_pos(&lista,&num,pos);
    printf("El elemento de esa posicion es: %d ",num);
    return 0;
}
