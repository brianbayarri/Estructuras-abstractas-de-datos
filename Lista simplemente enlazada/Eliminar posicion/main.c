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
int eliminar_pos(t_lista *pl, t_dato *d, int pos)
{
    t_nodo *pelim;
    while((*pl) && (pl!=pos))
            pl=&(*pl)->psig;

    pelim=*pl;
    *d=pelim->dato;
    *pl=pelim->psig;
    free(pelim);
    return 1;
}

int main()
{
    int n,p,b=0;
    t_lista lista;
    crear_lista(&lista);
    printf("Ingrese un numero: ");
    scanf("%d",&n);
    while(n!=0)
    {
        if(b==0)
        {
            poner_primero_lista(&lista,&n);
            b=1;
        }
        else
        {
            poner_ultimo_lista(&lista,&n);
        }
        printf("Ingrese un numero: ");
        scanf("%d",&n);
    }
    mostrar_lista(&lista,mostrar);
    printf("Ingrese posicion a eliminar: ");
    scanf("%d",&p);
    eliminar_pos(&lista,&n,p);
    printf("\nEl elemento eliminado es %d",n);
    printf("La lista quedo: \n");
    mostrar_lista(&lista,mostrar);
    return 0;
}
