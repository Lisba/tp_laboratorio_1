#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "lisba_utn.h"

#define TAM 10

int main()
{
    int id = 1000;
    eEmployee employeesArray[TAM];
    char exit;
    char exitSubMenu;
    int retorno;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int idForRemove;
    int initiated;
    int order;
    initEmployee(employeesArray, TAM);
    do
    {

        switch( menu() )
        {
            case 1:
                system("cls");
                printf("****** Alta de Empleado *******\n\n");
                getString(name, "Ingrese el nombre: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                getString(lastName, "Ingrese el apellido: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                getFloat(&salary, "Ingrese el salario: ", "Error, debe ingresar un flotante. ", 1, 1000000);
                getInt(&sector, "Ingrese el sector: ", "Error, debe ingresar un entero. ", 1, 50);
                retorno = addEmployee(employeesArray, TAM, id, name, lastName, salary, sector);
                if(retorno)
                {
                    id++;
                }
                break;

            case 2:
                initiated = validateArrayInitiated(employeesArray, TAM);
                if(initiated)
                {
                    printf("opcion 2");
                }
                else
                {
                    printf("\nDebe cargar empleados primero!\n\n");
                }
                break;

            case 3:
                initiated = validateArrayInitiated(employeesArray, TAM);
                if(initiated)
                {
                    getInt(&idForRemove, "\nIngrese el ID del usuario a eliminar: ", "Error", 1000, 1999);
                    removeEmployee(employeesArray, TAM, idForRemove);
                }
                else
                {
                    printf("\nDebe cargar empleados primero!\n\n");

                }
                break;

            case 4:
                initiated = validateArrayInitiated(employeesArray, TAM);
                if(initiated)
                {
                    do
                    {
                        switch(subMenu())
                        {
                            case 1:
                                printf("Ascendente(0) o Descendente(1)?: ");
                                scanf("%d", &order);
                                sortEmployee(employeesArray, TAM, order);
                                printEmployees(employeesArray, TAM);
                                break;

                            case 2:
                                printf("Opcion 2");
                                break;

                            case 3:
                                printf("Confirma que desea volver al menu anterior? (s/n): ");
                                fflush(stdin);
                                exitSubMenu = getch();
                                break;

                            default:
                                printf("\nOpcion Invalida!\n\n");
                                break;

                        }
                    } while(exitSubMenu != 's');
                }
                else
                {
                    printf("\nDebe cargar empleados primero!\n\n");
                }
                break;

            case 5:
                printf("Confirma salir? (s/n): ");
                fflush(stdin);
                exit = getch();
                break;

            default:
                printf("\nOpcion Invalida!\n\n");
                break;
        }

        system("pause");

    } while (exit != 's');

    return 0;
}
