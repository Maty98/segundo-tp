#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funcionpers.h"
int menu()
{
    int option;
    printf("MENU PRINCIPAL\n");
    printf("\n1- Agregar persona");
    printf("\n2- Borrar persona");
    printf("\n3- listado de personas ordenadas por nombres alfabeticamente");
    printf("\n4- Grafico realizado basado en las edades de las personas");
    printf("\n5- Salir");
    printf("\nElija opcion: ");
    scanf("%d",&option);
    if (option<1||option>5)
    {
    printf("la opcion que ingreso no es valida, tiene que ser un num entre 1 y 5\n");
    }
    system("pause");
    return option;
}
void ordenarPersonas(ePersonas x[], int capa)
{
    int i;
    int j;
    ePersonas auxi;
    for (i=0;i<capa-1;i++)
    {
    for (j=i+1;j<capa;j++)
    {
    if (strcmp(x[i].nombre, x[j].nombre)>0)
    {
    auxi=x[i];
    x[i]=x[j];
    x[j]=auxi;
    }
    }
    }
}
void mostrarPersonas(ePersonas x[], int capa)
{
    int i;
    for (i=0;i<capa;i++)
    {
    if(x[i].estado==1)
    {
    mostrarPersona(x[i]);
    }
    }
}
void mostrarPersona(ePersonas unaPersona)
{
    printf("DNI %d\n", unaPersona.dni);
    printf("Nombre %s\n", unaPersona.nombre);
    printf("Edad %d\n", unaPersona.edad);
}
void iniciarPersonas(ePersonas x[],int capa)
{
    int i;
    for(i=0;i<capa;i++)
    {
    x[i].estado=0;
    }
}
int EspacioLibre(ePersonas x[],int capa)
{
    int indi=-1;
    int i;
    for (i=0;i<capa;i++)
    {
    if(x[i].estado==0)
    {
    indi=i;
    break;
    }
    }
    return indi;
}
int busquedaPorDni(ePersonas x[],int capa,int dni)
{
    int indi=-1;
    int i;
    for (i=0;i<capa;i++)
    {
    if(x[i].dni==dni)
    {
    indi=i;
    break;
    }
    }
    return indi;
}
void altaPersonas(ePersonas x[],int capa)
{
    int est;
    int ed;
    int indi;
    int dni=0;
    int auxil;
    char auxCad[40];
    indi=EspacioLibre(x,capa);
    if (indi==-1)
    {
    printf("\nYa alcanzo el maximo de personas que se pueden ingresar\n\n");
    }
    else
    {
    printf("\nIngresa DNI");
    fflush(stdin);
    scanf("%d", &auxil);
    while (auxil<=00000001||auxil>99999999)
    {
    printf("\nEl numero de DNI que ingreso no es valido, debe estar entre 00000001 y 99999999\n");
    printf("Vuelva a ingresar el numero de DNI\n");
    fflush(stdin);
    scanf("%d", &auxil);
    }
    dni=auxil;
    est=busquedaPorDni(x,capa,dni);
    if (est!=-1)
    {
    printf("el numero de DNI %d ya fue ingresado anteriormente\n", dni);
    }
    else
    {
    x[indi].dni=dni;
    printf("Ingrese nombre de la persona\n");
    fflush(stdin);
    gets(auxCad);
    while (strlen(auxCad)>30)
    {
    printf("El nombre ingresado es demasiado largo \n");
    fflush(stdin);
    gets(auxCad);
    }
    strcpy(x[indi].nombre, auxCad);
    printf("Ingrese edad: ");
    fflush(stdin);
    scanf("%d", &auxil);
    while (auxil<0||auxil>90)
    {
    printf("La edad debe estar entre 1 y 90\n");
    printf("por favor vuelva a ingresar la edad\n");
    fflush(stdin);
    scanf("%d", &auxil);
    }
    x[indi].edad=auxil;
    x[indi].estado=1;
    printf("\nLa persona fue ingresada exitosamente\n\n");
    }
    }
}
void borrarPersona(ePersonas x[], int capa)
{
    int confirmar;
    int indi;
    int dni;
    printf("\nIngrese el DNI de la persona que dea borrar");
    fflush(stdin);
    scanf("%d", &dni);
    indi=busquedaPorDni(x, capa, dni);
    if (indi==-1)
    {
    printf("La persona de DNI %d no esta cargada en sistema\n", dni);
    }
    else
    {
    mostrarPersona(x[indi]);
    printf("Usted va a borrar a %s, esta seguro del cambio?\n\n", x[indi].nombre);
    confirmar=tolower(getche());
    if (confirmar=='s')
    {
    x[indi].estado=2;
    }
    else
    {
    if(confirmar=='n')
    {
    printf("\nSe cancelo la accion de borrar a la persona del sistema\n");
    }
    else
    {
    printf("\nEl caracter ingresado no es valido, desea borrar ? SI (s), NO(n)");
    confirmar=tolower(getche());
    if (confirmar=='s')
    {
    x[indi].estado=2;
    }
    }
    }
    }
    system("pause");
}
void grafico(ePersonas x[],int capa)
{
    int i;
    int contmenor;
    int contjoven;
    int contmayor;
    int band=0;
    int mayor;
    contmenor=contjoven=contmayor=0;
    for(i=0;i<20;i++)
    {
        if(x[i].estado==1&&x[i].edad<18)
        {
        contmenor=contmenor+1;
        }
        if(x[i].estado==1&&x[i].edad>=18&&x[i].edad<=35)
        {
        contjoven=contjoven+1;
        }
        if(x[i].estado==1&&x[i].edad>35)
        {
        contmayor=contmayor+1;
        }
    }
     if(contmenor>=contjoven&&contmenor>=contmayor)
        {
        mayor=contmenor;
        }
        else
    {
        if (contjoven>=contmenor&&contjoven>=contmayor)
        {
        mayor=contjoven;
        }
        else
        {
        mayor=contmayor;
        }
    }
    for(i=mayor;i>0;i--)
        {
    if(i<=contmenor)
        {
        printf("*");
        }
    if(i<=contjoven)
        {
        band=1;
        printf("\t");
        }
    if(i<=contmayor)
        {
    if(band==0)
        {
        printf("\t\t");
        }
        if(band==1)
        {
        printf("\t");
        }
        }
        printf("\n");
        }
        printf("\n");
        printf("\nEdad<18\tEdad entre 19-35\tEdad>35\n\n");
        system("pause");
}
