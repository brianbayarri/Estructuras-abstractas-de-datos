#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int nro;
    float importe;
}t_info;
typedef t_info t_dato;
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

/*int poner_ultimo(t_lista *pl, const t_dato *d)
{
    while(*pl)
        pl=&(*pl)->psig;
    *pl=(t_nodo *)malloc(sizeof(t_nodo));
    if(*pl==NULL);
    return 0;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return 1;
}*/

int comparar(const t_dato *a, const t_dato *b)
{
    return (a->nro)-(b->nro);
}

void acum(t_dato *a, const t_dato *b)
{
    (a->importe)+=(b->importe);
}

void eliminar_dup_acum(t_lista *pl, int(*comparar)(const t_dato *, const t_dato *), void(*acum)(t_dato *, const t_dato *))
{
    t_nodo **pr, *pelim;
    while(*pl)
    {
        pr=&(*pl)->psig;
        while(*pr)
        {
            if(comparar(&(*pr)->dato,&(*pl)->dato)==0)
            {
                acum(&(*pl)->dato,&(*pr)->dato);
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

t_info ingreg()
{
    t_info aux;
    printf("Ingrese numero de pedido: ");
    scanf("%d",&aux.nro);
    printf("Ingrese importe: ");
    scanf("%f",&aux.importe);
    return aux;

}

void mostrar(const t_dato *d)
{
    printf("%d|%f\n",d->nro,d->importe);
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
    int b=0;
    t_lista lista;
    t_info reg;
    crear_lista(&lista);
    reg=ingreg();
    while(reg.nro!=0)
    {
        //if(b==0)
        //{
            poner_primero(&lista,&reg);
          //  b=1;
        //}
        //else
        //{
          //  poner_ultimo(&lista,&reg);
       // }
        reg=ingreg();
    }
    mostrar_lista(&lista,mostrar);
    eliminar_dup_acum(&lista,comparar,acum);
    printf("\n\n<<<TOTALES>>>\n");
    mostrar_lista(&lista,mostrar);

    return 0;
}
