#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int edad;
    char nombre[30];
}t_registro;

t_registro ingreg()
{
    t_registro aux;
    printf("Ingrese edad: ");
    scanf("%d",&aux.edad);
    fflush(stdin);
    printf("Ingrese nombre: ");
    scanf("%s",aux.nombre);
    fflush(stdin);
    return aux;
}

void grabar_archivo()
{
    t_registro aux;
    FILE *pfbin,*pftxt;
    pfbin=fopen("prueba.dat","wb");
    if(pfbin==NULL)
        exit(1);
    pftxt=fopen("prueba.txt","wt");
    if(pftxt==NULL)
        exit(1);
    aux=ingreg();
    while(aux.edad!=0)
    {
        fwrite(&aux,sizeof(t_registro),1,pfbin);
        fprintf(pftxt,"%d|%s\n",aux.edad,aux.nombre);
        aux=ingreg();
    }
    fclose(pfbin);
    fclose(pftxt);

}

int main()
{
    grabar_archivo();
    return 0;
}
