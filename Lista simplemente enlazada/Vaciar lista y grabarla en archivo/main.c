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

t_persona ingreg()
{
    t_persona aux;
    printf("Ingrese edad: ");
    scanf("%d",&aux.edad);
    fflush(stdin);
    if(aux.edad==0)
        return aux;
    printf("Ingrese nombre: ");
    gets(aux.nombre);
    fflush(stdin);
    printf("Ingrese apellido: ");
    gets(aux.apellido);
    fflush(stdin);
    return aux;
}

void mostrar(const t_dato *d)
{
    printf("%d|%s|%s\n",d->edad,d->nombre,d->apellido);
}

void mostrar_lista(const t_lista *pl,void(*mostrar)(const t_dato *))
{
    while(*pl)
    {
        mostrar(&(*pl)->dato);
        pl=&(*pl)->psig;
    }
}

void vaciar_lista_grabar(t_lista *pl, FILE *pf, FILE *pft)
{
    t_nodo *aux;
    while(*pl)
    {
        aux=*pl;
        fwrite(&aux->dato,sizeof(t_dato),1,pf);
        fprintf(pft,"%d|%s|%s\n",aux->dato.edad,aux->dato.nombre,aux->dato.apellido);
        free(aux);
        pl=&(*pl)->psig;
    }
}

int main()
{
    int b=0;
    t_lista lista;
    t_persona reg;
    FILE *pf,*pft;
    pf=fopen("prueba.dat","wb");
    pft=fopen("prueba.txt","wt");
    crear_lista(&lista);
    reg=ingreg();
    while(reg.edad!=0)
    {
        if(b==0)
        {
            poner_primero(&lista,&reg);
            b=1;
        }
        else
        {
            poner_ultimo(&lista,&reg);
        }
        reg=ingreg();
    }
    mostrar_lista(&lista,mostrar);
    vaciar_lista_grabar(&lista,pf,pft);
    fclose(pf);
    fclose(pft);
    return 0;
}
