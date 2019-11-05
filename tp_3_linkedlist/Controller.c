#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "conio.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int able = 0;
    FILE* f = NULL;

    if( path != NULL && pArrayListEmployee != NULL )
    {
        f = fopen(path, "r");

        if( f != NULL )
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            fclose(f);
            able = 1;
        }
        else
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO DE TEXTO.\n\n");
            system("pause");
        }
    }

    return able;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int able = 0;
    FILE* f;

    if( path != NULL && pArrayListEmployee != NULL )
    {
        f = fopen(path, "rb");

        if( f != NULL )
        {
            parser_EmployeeFromBinary(f, pArrayListEmployee);
            fclose(f);
            able = 1;
        }
        else
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO BINARIO.\n\n");
            system("pause");
        }
    }

    return able;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int able = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    sEmployee* employee;

    employee = employee_new();

    if( IdAleatorio(pArrayListEmployee) != -1 )
    {
        id = IdAleatorio(pArrayListEmployee);
        able = 1;
    }

    system("cls");
    fflush(stdin);
    getName(nombre, "\nINGRESE EL NOMBRE: ", "Error. Debe contener entre 2 y 128 caracteres. ", 2, 127);

    if( nombre == NULL || able == 0)
    {
        able = 0;
    }

    system("cls");
    getInt(&horasTrabajadas, "\nINGRESE LAS HORAS TRABAJADAS: ", "Error. Debe estar entre 1 y 1000", 1, 1000);

    system("cls");
    getInt(&sueldo, "\nINGRESE EL SUELDO: ", "Error. Debe estar entre 1 y 60000", 1, 60000);

    if( able )
    {
        if( employee_setId(employee, id) && employee_setNombre(employee, nombre) && employee_setHorasTrabajadas(employee, horasTrabajadas) && employee_setSueldo(employee, sueldo) )
        {
            if( !ll_add(pArrayListEmployee, employee) )
            {
                able = 1;
            }
        }
    }

    return able;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int able = 0;
    int idToModify;
    int datoAModificar;
    int flag = 0;
    char nombreNuevo[128];
    int enteroAuxiliar;

    system("cls");
    printf("**************MODIFICAR EMPLEADO****************\n\n");

    getInt(&idToModify, "INGRESE EL ID DEL EMPLEADO A MODIFICAR: ", "ERROR. DEBE INGRESAR ENTRE 1 Y 2000. ", 1, 2000);

    for(int i=0; i<( ll_len(pArrayListEmployee) ); i++)
    {
        if( idToModify == ( (sEmployee*) ll_get(pArrayListEmployee, i) )->id )
        {
            flag = 1;
            printf("\n");
            printf("ID          NOMBRE  HORAS T.  SUELDO\n");
            printEmployee((sEmployee*) ll_get(pArrayListEmployee, i));
            printf("\n");

            printf("1) MODIFICAR NOMBRE.\n");
            printf("2) MODIFICAR HORAS TRABAJADAS.\n");
            printf("3) MODIFCAR SUELDO.\n");
            printf("4) SALIR.\n\n");

            getInt(&datoAModificar, "SELECCIONE UNA OPCION: ", "ERROR. DEBE INGRESAR ENTRE 1 Y 3", 1, 4);

            switch(datoAModificar)
            {
            case 1:
                getName(nombreNuevo, "\nINGRESE EL NOMBRE: ", "ERROR. ", 1, 127);
                if( employee_setNombre( (sEmployee*) ll_get(pArrayListEmployee, i), nombreNuevo) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 2:
                getInt(&enteroAuxiliar, "\nINGRESE LAS HORAS TRBAJADAS: ", "ERROR. ", 1, 1000);
                if( employee_setHorasTrabajadas( (sEmployee*) ll_get(pArrayListEmployee, i), enteroAuxiliar) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 3:
                getInt(&enteroAuxiliar, "\nINGRESE EL SUELDO: ", "ERROR. ", 1, 60000);
                if( employee_setSueldo( (sEmployee*) ll_get(pArrayListEmployee, i), enteroAuxiliar) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 4:
                printf("\nSE HA CANCELADO LA MODIFICACION!\n");
                break;
            default:
                printf("OPCION INVALIDA!\n");
            }
        }

    }

    if( !flag )
    {
        printf("\nNO SE ENCONTRO NINGUN CLIENTE CON ESE CODIGO!\n");
    }

    printf("\n");

    return able;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int able = 0;
    int idToSearch;
    char answer = 'n';
    int flag = 0;

    if(pArrayListEmployee != NULL)
    {
        getInt(&idToSearch, "\nINGRESE EL ID DEL EMPLEADO A ELIMINAR: ", "ERROR. ", 1, 10000);

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            if( idToSearch == ( (sEmployee*) ll_get(pArrayListEmployee, i) )->id )
            {
                printEmployee( (sEmployee*) ll_get(pArrayListEmployee, i) );

                printf("\nDESEA ELIMINAR ESTE EMPLEADO? (s/n): ");
                fflush(stdin);
                answer = getche();

                if( answer == 's' )
                {
                    if( !ll_remove(pArrayListEmployee, i) )
                    {
                        printf("\n\nEMPLEADO ELIMINADO!\n\n");
                        able = 1;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        printf("\n\nNO SE PUDO ELIMINAR AL EMPLEADO!\n\n");
                        flag = 1;
                    }
                }
                else
                {
                    printf("\n\nSE CANCELO LA OPERACION!\n\n");
                    flag = 1;
                    break;
                }
            }
            else
            {
                flag = 0;
            }
        }

        if(flag == 0)
        {
            printf("\nNO SE ENCONTRO EMPLEADO CON ESE ID!\n\n");
        }
    }

    return able;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int able = 0;

    if( pArrayListEmployee != NULL )
    {
        system("cls");
        printf("ID          NOMBRE  HORAS T.  SUELDO\n");

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            printEmployee(((sEmployee*) ll_get(pArrayListEmployee, i)));
            able = 1;
        }
    }

    return able;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int able = 0;

    if(pArrayListEmployee != NULL)
    {
        if( ( ll_sort(pArrayListEmployee, ordenarPorId, 0) ) == 0 )
        {
            printf("\nSE ORDENO CORRECTAMENTE!\n\n");
        }
        else
        {
            printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
        }
    }

    return able;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int able = 0;
    int tam = 0;
    int contador = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    FILE* f = NULL;
    sEmployee* employee;

    if( path != NULL && pArrayListEmployee != NULL )
    {
        tam = ll_len(pArrayListEmployee);
        f = fopen(path, "w");

        if( f != NULL )
        {
            for(int i=0; i<tam; i++)
            {
                employee = (sEmployee*) ll_get(pArrayListEmployee, i);

                employee_getId(employee, &id);
                employee_getNombre(employee, nombre);
                employee_getHorasTrabajadas(employee, &horasTrabajadas);
                employee_getSueldo(employee, &sueldo);

                fprintf(f, "%d,%s,%d,%d", id, nombre, horasTrabajadas, sueldo);
                contador++;
            }

            fclose(f);

            if( contador == tam )
            {
                able = 1;
            }

        }
        else
        {
            printf("No se pudo abrir el archivo de texto.\n");
        }
    }

    return able;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int able = 0;
    int contador = 0;
    int tam = 0;
    FILE* f = NULL;
    sEmployee* employee;

    if( path != NULL && pArrayListEmployee != NULL )
    {
        tam = ll_len(pArrayListEmployee);

        f = fopen(path, "wb");

        if( f != NULL )
        {
            for(int i=0; i<tam; i++)
            {
                employee = ll_get(pArrayListEmployee, i);

                if( employee != NULL )
                {
                    fwrite(employee, sizeof(sEmployee), 1, f);
                    contador++;
                }

                if( contador == tam )
                {
                    fclose(f);
                    able = 1;
                }
            }
        }
        else
        {
            printf("No se pudo abrir el archivo binario.\n");
        }
    }

    return able;
}

