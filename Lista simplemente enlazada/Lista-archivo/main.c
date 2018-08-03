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

int vaciar_lista(t_lista *pl)
{
    t_nodo *pelim;
    while(*pl)
    {
        pelim=*pl;
        *pl=pelim->psig;
        free(pelim);
    }
}

int vaciar_lista_grabar(t_lista *pl, FILE*pf)
{
    t_nodo *pelim;
    while(*pl)
    {
        pelim=*pl;
        fwrite(&pelim,sizeof(t_archivo),1,pf);
        *pl=pelim->psig;
        free(pelim);
    }
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
    if(*pl==NULL)
        return 0;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return 1;
}

int comparar(const t_dato *a, const t_dato *b)
{
    return *a-*b;
}

int insertar_ultimo_sin_duplicar(t_lista *pl, const t_dato,int(*comparar)(const t_dato *, const t_dato *))
{
    while(*pl && comparar(&(*pl)->dato,d))
        pl=&(*pl)->psig;
    if(*pl)
        return 0;
    *pl=(t_nodo *)malloc(sizeof(t_nodo));
    if(*pl==NULL)
        return 0;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return 1;
}

int insertar_en_orden_sin_duplicar(t_lista *pl, const t_dato *d,int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo))
                 if(pnue==NULL)
                     return 0;
    while(*pl && (comparar(&(*pl)->dato,d)<0))
        pl=&(*pl)->psig;
    if(*pl && comparar(&(*pl)->dato,d)==0)
    {
        return 0;
    }
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;
}

int ver_primero(const t_lista *pl, t_dato *d)
{
    if(*pl==NULL)
        return 0;
    *d=(*pl)->dato;
    return 1;
}

int ver_ultimo(const t_lista *pl, t_dato *d)
{
    if(*pl==NULL)
        return 0;
    while((*pl)->psig)
        pl=&(*pl)->psig;
    *d=(*pl)->dato;
    return 1;
}

int sacar_primero (t_lista*pl, t_dato*d)
{
    t_nodo*pelim;
    if(*pl==NULL)
        return 0;
    pelim=(*pl);
    *d=pelim->dato;
    *pl=pelim->psig;
    free(pelim);
    return 1;
}

int sacar_ultimo(t_lista *pl, t_dato *d)
{
    t_nodo *pelim;
    if(*pl==NULL)
        return 0;
    while((*pl)->psig)
        pl=&(*pl)->psig;
    free(*pl);
    *pl=NULL;
    return 1;
}

int buscar_por_clave_eliminar_ord(t_lista *pl, const t_dato, int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *pelim;
    while(*pl && (comparar(&(*pl)->dato,d)<0))
        pl=&(*pl)->psig;
    if(*pl==NULL || comparar(&(*pl)->dato,d))
        return 0;
    pelim=*pl;
    *d=pelim->dato;
    *pl=pelim->psig;
    free(pelim);
    return 1;

}

int buscar_por_clave_eliminar_no_ord(t_lista *pl, const t_dato, int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *pelim;
    while(*pl && comparar(&(*pl)->dato,d))
        pl=&(*pl)->psig;
    if(*pl==NULL)
        return 0;
    pelim=*pl;
    *d=pelim->dato;
    *pl=pelim->psig;
    free(pelim);
    return 1;
}

void ordenar (t_lista *pl, int(*comparar)(const t_dato *, const t_dato *))
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
                    (*q)=aux->psig;
                    aux->psig=(*q)->psig;
                    (*q)->psig=aux;
                }
                q=&(*q)->psig;
            }
        }
    }
}

void eliminar_duplicados_acumular(t_lista *pl,int(*comparar)(const t_dato *, const t_dato *), void(*acumular)(t_dato *, const t_dato *))
{
    t_nodo **pr, *pelim;
    while(*pl)
    {
        pr=&(*pl)->psig;
        while(*pr)
        {
            if(comparar(&(*pr)->dato,&(*pl)->dato)==0)
            {
                acumular(&(*pl)->dato,&(*pr)->dato);
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

int eliminar_pos(t_lista *pl, t_dato *d, int pos)
{
    t_nodo *pelim;
    while(*pl && --pos)
        pl=&(*pl)->psig;
    pelim=*pl;
    *d=pelim->dato;
    *pl=pelim->psig;
    free(pelim);
    return 1;
}

int insertar_en_pos(t_lista *pl, const t_dato *d, int pos)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo))
    if(pnue==NULL)
        return 0;
    while(*pl && --pos)
        pl=&(*pl)->psig;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return 1;
}

void mostrar(const t_dato *d)
{
    printf("%d|%s\n",d->dato1,d->dato2);
}

void mostrar_lista(t_lista *pl,void(*mostrar)(const t_dato *))
{
    while(*pl)
    {
        mostrar(&(*pl)->dato);
        pl=&(*pl)->psig;
    }
}




int main()
{
    printf("Funciones varias de lista");
    return 0;
}
