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

int main()
{
    int b=0,num;
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

    return 0;
}
