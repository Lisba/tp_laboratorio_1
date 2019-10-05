#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "lisba_utn.h"

int menu(void)
{
    int option;

    system("cls");

    printf("****** Nomina de Empleados *******\n\n");
    printf("1) Alta de Empleado\n");
    printf("2) Modificar Empleado\n");
    printf("3) Baja de Empleado\n");
    printf("4) Informes de Empleados\n");
    printf("5) Salir\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int subMenu(void)
{
    int option;

    system("cls");

    printf("****** Informe de Empleados *******\n\n");
    printf("1) Listar Empleados\n");
    printf("2) Estadisticas sobre salarios\n");
    printf("3) Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int initEmployee(eEmployee* listEmployee, int lenghtEmployee)
{
    int able = -1;

    for(int i=0; i<lenghtEmployee; i++)
    {
        listEmployee[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 0;
    }

    return able;
}

int findFreePosition(eEmployee listEmployee[], int lenghtEmployee)
{
    int index = -1;

    for(int i=0; i<lenghtEmployee; i++)
    {
        if(listEmployee[i].isEmpty == 1)
        {
            index = i; // Guardo en la variable i el valor de la primera posicion disponible encontrada.
            break; // Corto la ejecucion del bucle ya que de lo contrario la variable i tomará el valor de la ultima posicion disponible encontrada y deseo la primera posicion disponible.
        }
    }

    return index;
}

int addEmployee(eEmployee* listEmployee, int lenghtEmployee, int id, char name[], char lastName[], float salary, int sector)
{
    int able = 0;
    int index;

    index = findFreePosition(listEmployee, lenghtEmployee); // Obtengo -1 si el arraya de estructuras esta lleno o el indice de la primera posicion disponible.

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar.\n");
    }
    else
    {
        listEmployee[index] = newEmployee(id, name, lastName, salary, sector); // Almaceno los datos del nuevo empleado en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
    }

    return able;
}

eEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector)
{
    eEmployee newEmployee;

    newEmployee.id = id;
    strcpy(newEmployee.name, name);
    strcpy(newEmployee.lastName, lastName);
    newEmployee.salary = salary;
    newEmployee.sector = sector;
    newEmployee.isEmpty = 0;

    return newEmployee;
}

int findEmpoyeeById(eEmployee* listEmployee, int lengthEmployee, int id)
{
    int index = -1;

    for(int i=0; i<lengthEmployee; i++)
    {
        if(listEmployee[i].id == id)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int removeEmployee(eEmployee* listEmployee, int lengthEmployee, int id)
{
    int able = -1;
    char option;
    int flag=0;

    for(int i=0; i<lengthEmployee; i++)
    {
        if(listEmployee[i].id == id && listEmployee[i].isEmpty == 0)
        {
            printf("\n ID    NOMBRE    APELLIDO    SALARIO    SECTOR\n");
            printEmployee(listEmployee[i]);

            printf("\nEsta seguro de eliminar a este empleado? (s/n)");
            fflush(stdin);
            option = getch();

            if(option == 's')
            {
                listEmployee[i].isEmpty = 1;
                printf("\n\nBAJA EXITOSA!\n\n");
                able = 0;
            }
            flag = 1; // flag para indicar que se encontro un usuario con dicho ID independientemente de si se remueve o no.
            break;
        }
    }

    if( able == -1 && flag == 0)
    {
        printf("\nNo se encontro ningun empleado con ese ID.\n\n");
    }

    return able;
}

int sortEmployees(eEmployee* listEmployee, int lengthEmployee, int order)
{
    int able = 0;

    eEmployee aux;

    switch(order)
    {
        case 0:
            for(int i=0; i<lengthEmployee-1; i++)
            {
                for(int j=i+1; j<lengthEmployee; j++)
                {
                    if(listEmployee[i].sector > listEmployee[j].sector)
                    {
                        aux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = aux;
                    }
                    else
                    {
                        if(listEmployee[i].sector == listEmployee[j].sector)
                        {
                            if(strcmp(listEmployee[i].lastName, listEmployee[j].lastName)>0)
                            {
                                aux = listEmployee[i];
                                listEmployee[i] = listEmployee[j];
                                listEmployee[j] = aux;
                            }
                        }
                    }
                }
            }
            able = 1;
            break;
        case 1:
            for(int i=0; i<lengthEmployee-1; i++)
            {
                for(int j=i+1; j<lengthEmployee; j++)
                {
                    if(listEmployee[i].sector < listEmployee[j].sector)
                    {
                        aux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = aux;
                    }
                    else
                    {
                        if(listEmployee[i].sector == listEmployee[j].sector)
                        {
                            if(strcmp(listEmployee[i].lastName, listEmployee[j].lastName)<0)
                            {
                                aux = listEmployee[i];
                                listEmployee[i] = listEmployee[j];
                                listEmployee[j] = aux;
                            }
                        }
                    }
                }
            }
            able = 1;
            break;
    }

    return able;
}

void printEmployees(eEmployee* listEmployee, int lengthEmployee)
{
    system("cls");
    printf("****** Lista de Empleados *******\n\n");
    printf(" ID    NOMBRE    APELLIDO    SALARIO    SECTOR\n");

    for(int i=0; i<lengthEmployee; i++)
    {
        if(listEmployee[i].isEmpty == 0)
        {
            printEmployee(listEmployee[i]);
        }
    }
    system("pause");
}

void printEmployee(eEmployee employee)
{
    printf("%4d %9s %9s %11.2f %8d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);

}

int validateArrayInitiated(eEmployee listEmployee[], int lengthEmployee)
{
    int arrayInitiated = 0;

    for(int i=0; i<lengthEmployee; i++)
    {
        if(listEmployee[i].isEmpty == 0)
            arrayInitiated = 1; // retorno true si alguna de las posiciones del array de estructuras esta ocupada.
    }

    return arrayInitiated;
}

int loadEmployee(eEmployee* listEmployee, int lengthEmployee, int lastId)
{
    int able = 0;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    system("cls");

    printf("****** Alta de Empleado *******\n\n");

    getString(name, "Ingrese el nombre: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
    getString(lastName, "Ingrese el apellido: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
    getFloat(&salary, "Ingrese el salario: ", "Error, debe ingresar un flotante. ", 1.0, 1000000.0);
    getInt(&sector, "Ingrese el sector: ", "Error, debe ingresar un entero. ", 1, 50);

    able = addEmployee(listEmployee, lengthEmployee, lastId, name, lastName, salary, sector); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.

    return able;
}

int modifyEmployee(eEmployee listEmployee[], int lengthEmployee)
{
    int id;
    int option;
    float salary;
    int sector;
    int index;
    int able=0;

        system("cls");

        printf("****** Modificar Empleado *******\n\n");

        fflush(stdin);
        getInt(&id, "Ingrese el ID del Empleado a modificar: ", "Error, debe ingresar un ID valido. ", 1000, 2000);

        index = findEmpoyeeById(listEmployee, lengthEmployee, id);

            if(index == -1)
            {
                printf("\nNo se encontro ningun empleado con ese ID.\n\n");
            }
            else
            {
                able = 1;

                printf("\n");
                printf(" ID    NOMBRE    APELLIDO    SALARIO    SECTOR\n");
                printEmployee(listEmployee[index]);

                printf("\nQue desea modificar de este empleado?\n");
                printf("\n1) Nombre\n");
                printf("2) Apellido\n");
                printf("3) Salario\n");
                printf("4) Sector\n");
                printf("5) Salir\n\n");

                printf("Seleccione una opcion: ");
                scanf("%d", &option);


                switch(option)
                {
                case 1:
                    getString(listEmployee[index].name, "\nIngrese el nuevo nombre: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                    printf("\nNombre modificado!\n\n");
                    break;
                case 2:
                    getString(listEmployee[index].lastName, "\nIngrese el nuevo apellido: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                    printf("\nApellido modificado!\n\n");
                    break;
                case 3:
                    getFloat(&salary, "\nIngrese el nuevo salario: ", "Error, debe ingresar un flotante. ", 1.0, 1000000.0);
                    printf("\nSalario modificado!\n\n");
                    listEmployee[index].salary = salary;
                    break;
                case 4:
                    getInt(&sector, "\nIngrese el nuevo sector: ", "Error, debe ingresar un entero. ", 1, 50);
                    printf("\nSector modificado!\n\n");
                    listEmployee[index].sector = sector;
                    break;
                case 5:
                    printf("\nSe ha cancelado la modificacion!\n\n");
                    break;
                default:
                    printf("\nOpcion no valida!\n\n");
                    break;
                }
            }

    return able;
}

void infoEmployees(eEmployee* listEmployee, int lengthEmployee)
{
    float total=0;
    float average=0;
    int i;
    int counter=0;

    for(i=0; i<lengthEmployee; i++)
    {
        if(listEmployee[i].isEmpty == 0)
        {
            total += listEmployee[i].salary;
            counter++;
        }
    }

    average = (float) (total / counter);

    system("cls");

    printf("****** Informes de Empleados *******\n\n");
    printf("El total de los salarios es: %.2f\n\n", total);
    printf("El promedio de los salarios es: %.2f\n\n", average);
    printf("Los empleados que superan el salario promedio son:\n\n");
    printf(" ID    NOMBRE    APELLIDO    SALARIO    SECTOR\n");

    for(int j=0; j<lengthEmployee; j++)
    {
         if(listEmployee[j].salary >= average)
         {
             printEmployee(listEmployee[j]);
         }
    }
    system("pause");
}
