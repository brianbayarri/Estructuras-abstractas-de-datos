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

int sacar_ultimo(t_lista *pl,t_dato *d)
{
    if(*pl==NULL)
        return 0;
    while((*pl)->psig)
         pl=&(*pl)->psig;
    *d=(*pl)->dato;
    free(*pl);
    *pl=NULL;
    return 1;
}

int sacar_primero(t_lista *pl, t_dato *d)
{
    t_nodo *aux;
    if(*pl==NULL)
        return 0;
    aux=*pl;
    *d=aux->dato;
    *pl=aux->psig;
    free(aux);
    return 1;
}

/*int menor_edad(t_lista *pl,t_dato *d)
{

    while(*pl)
    {
        if(pl->dato>(*pl++)->dato))
        {
            *d=(*pl)->dato;
        }
    }
    return 1;
}*/

int main()
{
    int b=0;
    t_lista lista;
    t_persona reg;
    FILE *pf;
    pf=fopen("C:\\Brian\\UNLaM\\Programacion\\Programas\\Brian\\Varios\\Archivo binario a lista\\Archivo\\persona.dat","rb");
    if(pf==NULL)
        exit(1);
    crear_lista(&lista);
    fread(&reg,sizeof(t_persona),1,pf);
    while(!feof(pf))
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
        fread(&reg,sizeof(t_persona),1,pf);
    }
    printf("Lista original: \n");
    mostrar_lista(&lista,mostrar);
    sacar_ultimo(&lista,&reg);
    printf("\nEl ultimo que sacamos es %d|%s|%s\n",reg.edad,reg.nombre,reg.apellido);
    printf("Quedando nuestra lista como: \n");
    mostrar_lista(&lista,mostrar);
    sacar_primero(&lista,&reg);
    printf("\nEl primero que sacamos es %d|%s|%s\n",reg.edad,reg.nombre,reg.apellido);
    printf("Quedando la lista como: \n");
    mostrar_lista(&lista,mostrar);
    //menor_edad(&lista,&reg);
    printf("El de menor edad es: %d|%s|%s",reg.edad,reg.nombre,reg.apellido);
    fclose(pf);
    return 0;
}
