#include <stdio.h>
#include <stdlib.h>
typedef char t_dato;
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

int poner_primero(t_lista *pl,const t_dato *d)
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
    printf("%c\n",*d);
}
void mostrar_lista(const t_lista *pl,void(*mostrar)(const t_dato *))
{
    while(*pl)
    {
        mostrar(&(*pl)->dato);
        pl=&(*pl)->psig;
    }

}

int comparar(const t_dato *a,const t_dato *b)
{
    return *a-*b;
}

int insertar_en_orden_sin_duplicar(t_lista *pl,const t_dato *d,int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *pnue;
    while((*pl) && (comparar(&(*pl)->dato,d)<0))
        pl=&(*pl)->psig;
   //para rebotar en caso de duplicado
   if((*pl) && (comparar(&(*pl)->dato,d)==0))
   {
       return 0;
   }

   pnue=(t_nodo *)malloc(sizeof(t_nodo));
   if(pnue==NULL)
    return 0;
   pnue->dato=*d;
   pnue->psig=*pl;
   *pl=pnue;
   return 1;
}

int main()
{
    int b=0;
    t_lista lista;
    char le;
    crear_lista(&lista);
    printf("Ingrese una letra: ");
    scanf("%c",&le);
    fflush(stdin);
    while(le!='0')
    {
        if(b==0)
        {
            poner_primero(&lista,&le);
            b=1;
        }
        else
        {
            poner_ultimo(&lista,&le);
        }
        printf("Ingrese una letra: ");
        scanf("%c",&le);
        fflush(stdin);
    }
    mostrar_lista(&lista,mostrar);
    printf("\n\n<<Insertemos otra letra en forma ordenada>>\n");
    printf("Ingrese una letra: ");
    scanf("%c",&le);
    insertar_en_orden_sin_duplicar(&lista,&le,comparar);
    mostrar_lista(&lista,mostrar);
    return 0;
}
