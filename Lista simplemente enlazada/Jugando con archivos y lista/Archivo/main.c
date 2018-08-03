#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int edad;
    char nombre[30];
    char apellido[30];
} t_persona;

t_persona ingreg()
{
    t_persona aux;
    printf("Ingrese una edad: ");
    scanf("%d",&aux.edad);
    fflush(stdin);
    if(aux.edad==0)
        exit(1);
    printf("Ingrese un nombre: ");
    gets(aux.nombre);
    fflush(stdin);
    printf("Ingrese un apellido: ");
    gets(aux.apellido);
    fflush(stdin);
    return aux;
}

void grabar_archivo()
{
    t_persona aux;
    FILE *pf_bin,*pf_txt;
    pf_bin=fopen("persona.dat","wb");
    if(pf_bin==NULL)
        exit(1);
    pf_txt=fopen("persona.txt","wt");
    if(pf_txt==NULL)
        exit(1);
    aux=ingreg();
    while(aux.edad!=0)
    {
        fwrite(&aux,sizeof(t_persona),1,pf_bin);
        fprintf(pf_txt,"%d|%s|%s\n",aux.edad,aux.nombre,aux.apellido);
        aux=ingreg();
    }
    fclose(pf_bin);
    fclose(pf_txt);
}

int main()
{
    grabar_archivo();
    return 0;
}
