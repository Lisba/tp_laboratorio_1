#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"

char menu(void)
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

char subMenu(void)
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

int initEmployee(eEmployee listEmployee[], int lenghtEmployee)
{
    int able = -1;

    for(int i=0; i<lenghtEmployee; i++)
    {
        listEmployee[i].isEmpty = 1;
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
            index = i;
            break;
        }
    }

    return index;
}

int addEmployee(eEmployee listEmployee[], int lenghtEmployee, int id, char name[], char lastName[], float salary, int sector)
{
    int able = 0;
    int index;

    index = findFreePosition(listEmployee, lenghtEmployee);

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar.\n");
    }
    else
    {
        listEmployee[index] = newEmployee(id, name, lastName, salary, sector);
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

int findEmpoyeeById(eEmployee listEmployee[], int lengthEmployee, int id)
{
    int index = -1;

    for(int i=0; i<lengthEmployee; i++)
    {
        if(listEmployee[i].id == id)
            index = i;
            break;
    }

    return index;
}

int removeEmployee(eEmployee listEmployee[], int lengthEmployee, int id)
{
    int able = -1;
    char option;
    int flag;

    for(int i=0; i<lengthEmployee; i++)
    {
        if(listEmployee[i].id == id && listEmployee[i].isEmpty == 0)
        {
            printf("\n%s %4s %4.2f %4d\n\n", listEmployee[i].name, listEmployee[i].lastName, listEmployee[i].salary, listEmployee[i].sector);

            printf("Esta seguro de eliminar a este empleado? (s/n)");
            fflush(stdin);
            option = getch();

            if(option == 's')
            {
                listEmployee[i].isEmpty = 1;
                printf("\n\nBAJA EXITOSA!\n\n");
                able = 0;
            }
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }

    if( able == -1 && flag == 0)
    {
        printf("\nNo se encontro ningun empleado con ese ID.\n\n");
    }

    return able;
}

int sortEmployee(eEmployee listEmployee[], int lengthEmployee, int order)
{
    int able = -1;

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
                            if(listEmployee[i].lastName > listEmployee[j].lastName)
                            {
                                aux = listEmployee[i];
                                listEmployee[i] = listEmployee[j];
                                listEmployee[j] = aux;
                            }
                        }
                    }
                }
            }
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
            break;
    }

    return able;
}

void printEmployees(eEmployee listEmployee[], int lengthEmployee)
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
            arrayInitiated = 1;
    }

    return arrayInitiated;
}
