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
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char salir = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    char datosCargados = '0';
    do{
        switch(menu())
        {
            case 1:
                if( datosCargados == '0' )
                {
                    if( controller_loadFromText("data.csv", listaEmpleados) )
                    {
                        datosCargados = '1';
                        printf("\nDATOS CARGADOS DESDE EL ARCHIVO DE TEXTO EXITOSAMENTE!\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("\nNO SE PUDO CARGAR NINGUN DATO DESDE EL ARCHIVO DE TEXTO!\n\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("\nYA HAN SIDO CARGADOS LOS DATOS DESDE EL ARCHIVO!\n\n");
                    system("pause");
                }
                break;
            case 2:
                if( datosCargados == '0' )
                {
                    if( controller_loadFromBinary("data.bin", listaEmpleados) )
                    {
                        datosCargados = '1';
                        printf("\nDATOS CARGADOS DESDE EL ARCHIVO BINARIO EXITOSAMENTE!\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("\nNO SE PUDO CARGAR NINGUN DATO DESDE EL ARCHIVO BINARIO!\n\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("\nYA HAN SIDO CARGADOS LOS DATOS DESDE EL ARCHIVO!\n\n");
                    system("pause");
                }
                break;
            case 3:
                if( !ll_isEmpty(listaEmpleados) )
                {
                    controller_addEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                    printf("\nPRIMERO DEBE CARGAR LOS DATOS DESDE EL ARCHIVO!\n\n");
                    system("pause");
                }
                break;
            case 4:
                if( !ll_isEmpty(listaEmpleados) )
                {
                    controller_editEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS!\n\n");
                    system("pause");
                }
                break;
            case 5:
                if( !ll_isEmpty(listaEmpleados) )
                {
                    controller_removeEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS!\n\n");
                    system("pause");
                }
                break;
            case 6:
                if( !ll_isEmpty(listaEmpleados) )
                {
                    controller_ListEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                   printf("\nNO HAY DATOS CARGADOS!\n\n");
                    system("pause");
                }
                break;
            case 7:
                if( !ll_isEmpty(listaEmpleados) )
                {
                    controller_sortEmployee(listaEmpleados);
                    system("pause");
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS!\n\n");
                    system("pause");
                }
                break;
            case 8:
                if ( !ll_isEmpty(listaEmpleados) )
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
                    printf("\nNO HAY DATOS CARGADOS!\n\n");
                    system("pause");
                }
                break;
            case 9:
                if ( !ll_isEmpty(listaEmpleados) )
                {
                    if( controller_saveAsBinary("data.bin", listaEmpleados) )
                    {
                        printf("\nDATOS GUARDADOS EN EL ARCHIVO BINARIO EXITOSAMENTE!\n\n");
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
                    printf("\nNO HAY DATOS CARGADOS!\n\n");
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
