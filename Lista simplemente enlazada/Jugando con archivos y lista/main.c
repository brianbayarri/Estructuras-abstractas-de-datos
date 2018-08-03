#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int edad;
    char nombre[30];
    char apellido[30];
}t_persona;

typedef t_persona t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
}t_nodo;
typedef t_nodo *t_lista;

void crear_lista (t_lista *pl)
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
    if(pl==NULL)
        return 0;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return 1;
}

void mostrar(const t_dato *d)
{
    printf("%d|%s|%s\n",d->edad,d->nombre,d->apellido);
}

void mostrar_lista(const t_lista *pl, void(*mostrar)(const t_dato *))
{
    while(*pl)
    {
        mostrar(&(*pl)->dato);
        pl=&(*pl)->psig;
    }
}

int comparar(const t_dato *a,const t_dato *b)
{
    return ((a->edad)-(b->edad));
}

void ordenar_lista(t_lista *pl,int (*comparar)(const t_dato *, const t_dato *))
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
                    *q=aux->psig;
                    aux->psig=(*q)->psig;
                    (*q)->psig=aux;
                }
                q=&(*q)->psig;
            }
        }
    }
}

int main()
{
    int b=0;
    t_persona reg;
    t_lista lista;
    FILE *pf;
    pf=fopen("C:\\Brian\\UNLaM\\Programacion\\Programas\\Brian\\Varios\\Jugando con archivos y lista\\Archivo\\persona.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo. . .");
        exit(1);
    }
    crear_lista(&lista);
    fread(&reg,sizeof(t_persona),1,pf);
    while(!feof(pf))
    {
        if(b==0)
        {
            insertar_primero(&lista,&reg);
            b=1;
        }
        else
        {
            insertar_ultimo(&lista,&reg);
        }

        fread(&reg,sizeof(t_persona),1,pf);
    }
    printf("Lista original: \n");
    mostrar_lista(&lista,mostrar);
    ordenar_lista(&lista,comparar);
    printf("\n\nLista ordenada por edad: \n");
    mostrar_lista(&lista,mostrar);
    return 0;
}
