#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char salir = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                if( controller_loadFromText("data.csv", listaEmpleados) )
                {
                    printf("\nDATOS CARGADOS DESDE EL ARCHIVO DE TEXTO EXITOSAMENTE!\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nNO SE PUDO CARGAR NINGUN DATO DESDE EL ARCHIVO DE TEXTO!\n\n");
                    system("pause");
                }
                break;
            case 2:
                if( controller_loadFromBinary("data.bin", listaEmpleados) )
                {
                    printf("\nDATOS CARGADOS DESDE EL ARCHIVO BINARIO EXITOSAMENTE!\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nNO SE PUDO CARGAR NINGUN DATO DESDE EL ARCHIVO BINARIO!\n\n");
                    system("pause");
                }
                break;
            case 3:
                if( controller_addEmployee(listaEmpleados) )
                {
                    printf("\nALTA EXITOSA!\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nOCURRIO UN PROBLEMA DURANTE EL ALTA!\n\n");
                    system("pause");
                }
                break;
            case 4:
                if( arrayIniciado(listaEmpleados) )
                {
                    controller_editEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS PARA MODIFICAR!\n\n");
                    system("pause");
                }
                break;
            case 5:
                if( arrayIniciado(listaEmpleados) )
                {
                    controller_removeEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS PARA ELIMINAR!\n\n");
                    system("pause");
                }
                break;
            case 6:
                if( arrayIniciado(listaEmpleados) )
                {
                    controller_ListEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS PARA MOSTRAR!\n\n");
                    system("pause");
                }
                break;
            case 7:
                printf("7");
                break;
            case 8:
                system("cls");
                if ( arrayIniciado(listaEmpleados) )
                {
                    if( controller_saveAsText("data.csv", listaEmpleados) )
                    {
                        printf("\nDATOS GUARDADOS EN EL ARCHIVO DE TEXTO EXITOSAMENTE!\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("\nNO SE PUDO GUARDAR LOS DATOS!\n\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS PARA GUARDAR!\n\n");
                    system("pause");
                }
                break;
            case 9:
                system("cls");
                if ( arrayIniciado(listaEmpleados) )
                {
                    if( controller_saveAsBinary("data.bin", listaEmpleados) )
                    {
                        printf("\nDatos guardados en el archivo binario exitosamente!n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("\nNo se pudieron guardar los datos!\n\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("\nNo hay empleados cargados para mostrar!\n\n");
                    system("pause");
                }
                break;
            case 10:
                printf("Confirma salir? (s/n):");
                fflush(stdin);
                salir = getche();
                break;
            default:
                printf("\nOpcion Invalida!\n\n");
        }
    }while(salir != 's');
    return 0;
}
