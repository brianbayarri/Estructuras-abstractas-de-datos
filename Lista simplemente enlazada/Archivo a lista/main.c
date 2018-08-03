#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char cad[50];
}t_cadena;
typedef t_cadena t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
}t_nodo;
typedef t_nodo *t_lista;

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
    int b=0;
    char cad[30];
    t_lista lista;
    t_cadena c;
    FILE*pf;
    pf=fopen("C:\\Brian\\UNLaM\\Programacion\\Programas\\Brian\\Varios\\Archivo a lista\\prueba.txt","rt");
    if(pf==NULL)
        {
            printf("Caca");
            exit(1);
        }
        exit(1);
    crear_lista(&lista);
    fgets(cad,sizeof(cad),pf);
    while(!feof(pf))
    {
        if(b==0)
        {
            poner_primero_lista(&lista,c.cad);
            b=1;
        }
        else
        {
            poner_ultimo_lista(&lista,c.cad);
        }
        fgets(cad,sizeof(cad),pf);
    }

    return 0;
}
