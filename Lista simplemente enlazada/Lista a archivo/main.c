#include <stdio.h>
#include <stdlib.h>
#define todo_piola 1
#define lista_llena 0
#define lista_vacia 0
typedef int t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
} t_nodo;
typedef t_nodo *t_lista;

int crear_lista(t_lista *pl)
{
    *pl=NULL;
    return todo_piola;
}

int poner_primero(t_lista *pl, const t_dato *d)
{
    t_nodo *pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
        return lista_llena;
    pnue->dato=*d;
    pnue->psig=*pl;
    *pl=pnue;
    return todo_piola;

}

int poner_ultimo(t_lista *pl, const t_dato *d)
{
    while(*pl)
        pl=&(*pl)->psig;
    *pl=(t_nodo *)malloc(sizeof(t_nodo));
    if(pl==NULL)
        return lista_llena;
    (*pl)->dato=*d;
    (*pl)->psig=NULL;
    return todo_piola;
}

void mostrar(const t_dato *d)
{
    printf("\n%d",*d);
}

void mostrar_lista(const t_lista *pl, void(*mostrar)(const t_dato *))
{
    while(*pl)
    {
        mostrar(&(*pl)->dato);
        pl=&(*pl)->psig;
    }
}

int es_lista_vacia(const t_lista *pl)
{
    return *pl==NULL;
}

int sacar_primero (t_lista*pl, t_dato *d)
{
    t_nodo *pelim;
    if(!*pl)
        return lista_vacia;
    pelim=*pl;
    *d=pelim->dato;
    *pl=pelim->psig;
    free(pelim);
    return todo_piola;

}

int main()
{
    int n,b=0,a;
    t_lista lista;
    FILE*pf;
    pf=fopen("prueba.txt","wt");
    if(pf==NULL)
        exit(1);
    crear_lista(&lista);
    printf("Ingrese un numero: ");
    scanf("%d",&n);
    while(n!=0)
    {
        if(b==0)
        {
            poner_primero(&lista,&n);
            b=1;
        }
        else
        {
            poner_ultimo(&lista,&n);
        }
        printf("Ingrese un numero: ");
        scanf("%d",&n);
    }
    mostrar_lista(&lista,mostrar);
    while(!es_lista_vacia(&lista))
    {
        sacar_primero(&lista,&b);
        fprintf(pf,"%d\n",b);
    }



fclose(pf);
return 0;
}
