#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int edad;
    char nombre[30];
}t_registro;

typedef t_registro t_dato;
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

int comparar(const t_dato *a, const t_dato *b)
{
    return (a->edad)-(b->edad);
}
void ordenar_lista (t_lista *pl, int(*comparar)(const t_dato *, const t_dato *))
{
    t_lista *q;
    int marca=1;
    t_nodo *aux;
    if(*pl)
    {
        while(marca)
        {
            marca=0;
            q=pl;
            while((*q)->psig)
            {
                if((comparar(&(*q)->dato,&(*q)->psig->dato)>0))
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

int top_five(t_lista *pl, const t_dato *d, int(*comparar)(const t_dato *, const t_dato *))
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return 0;
    while(*pl && (comparar(&(*pl)->dato,d)<0))
          pl=&(*pl)->psig;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;

    if(*pl==NULL)
        return 0;
    while((*pl)->psig)
        pl=&(*pl)->psig;
    free(*pl);
    *pl=NULL;
    return 1;
}

void mostrar(const t_dato *d)
{
    printf("%d|%s\n",d->edad,d->nombre);
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
    t_lista lista;
    t_registro reg;
    int i=0;
    crear_lista(&lista);
    FILE *pf;
    pf=fopen("C:\\Brian\\UNLaM\\Programacion\\Programas\\Brian\\Varios\\Top 5\\Archivo\\Registros\\prueba.dat","rb");
    if(pf==NULL)
        exit(1);
    fread(&reg,sizeof(t_registro),1,pf);
    while(!feof(pf) && i<5)
    {
        poner_primero(&lista,&reg);
        fread(&reg,sizeof(t_registro),1,pf);
        i++;
    }
    ordenar_lista(&lista,comparar);
    while(!feof(pf))
    {
        top_five(&lista,&reg,comparar);
        fread(&reg,sizeof(t_registro),1,pf);
    }
    mostrar_lista(&lista,mostrar);
    return 0;
}
