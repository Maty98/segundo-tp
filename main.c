#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funcionpers.h"
int main()
{
    ePersonas cantpersonas[20];
    char seguir='s';
    int confirmar;
    iniciarPersonas(cantpersonas,20);
    do
    {
    switch(menu())
    {
    case 1:
        altaPersonas(cantpersonas,20);
        system("pause");
    break;
    case 2:
        borrarPersona(cantpersonas,20);
        system("pause");
    break;
    case 3:
        printf("\nOrdenado alfabeticamente\n");
        ordenarPersonas(cantpersonas,20);
        mostrarPersonas(cantpersonas,20);
        mostrarPersonas(cantpersonas,20);
        system("pause");
    break;
    case 4:
        grafico(cantpersonas,20);
        system("pause");
    break;
    case 5:
        printf("Seguro que desea salir?\n");
        confirmar=tolower(getche());
        if(confirmar=='n')
        {
        system("pause");
    return menu;
        }
    if (confirmar=='s')
        {
        seguir='n';
        system("pause");
        break;
        }
    if(confirmar!='s'&&confirmar!='n')
        {
        printf("El caracter ingresado no es valido, desea salir SI(s), NO(n)");
        system("pause");
    break;
        }
        system("pause");
    }
    system("cls");
    }while(seguir=='s');
    return 0;
}
