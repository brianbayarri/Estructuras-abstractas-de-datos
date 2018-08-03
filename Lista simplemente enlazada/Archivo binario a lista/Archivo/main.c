#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int edad;
    char nombre[30];
    char apellido[30];
}t_persona;

t_persona ingreg()
{
    t_persona aux;
    printf("Ingrese edad: ");
    scanf("%d",&aux.edad);
    fflush(stdin);
    if(aux.edad==0)
        exit(1);
    printf("Ingrese nombre: ");
    gets(aux.nombre);
    fflush(stdin);
    printf("Ingrese apellido: ");
    gets(aux.apellido);
    fflush(stdin);
    return aux;
}

void grabar_archivo()
{
    t_persona aux;
    FILE *pfbin,*pftxt;
    pfbin=fopen("persona.dat","wb");
    if(pfbin==NULL)
        exit(1);
    pftxt=fopen("persona.txt","wt");
    if(pftxt==NULL)
        exit(1);
    aux=ingreg();
    while(aux.edad!=0)
    {
        fwrite(&aux,sizeof(t_persona),1,pfbin);
        fprintf(pftxt,"%d|%s|%s\n",aux.edad,aux.nombre,aux.apellido);
        aux=ingreg();
    }
}

int main()
{
    grabar_archivo();
    return 0;
}
