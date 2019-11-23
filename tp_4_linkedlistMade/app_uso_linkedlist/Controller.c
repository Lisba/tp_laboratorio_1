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
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    sEmployee* employee;
    int respuesta;
    int indice;

    employee = employee_new();

    if(employee != NULL)
    {
        able = 1;
    }
    system("cls");
    printf("\nDESEA AGREAR UN NUEVO USUARIO AL FINAL DE LA LISTA O DENTRO DE UN IDICE ESPECIFICO?\n\n");
    printf("1) AL FINAL DE LA LISTA.\n");
    printf("2) EN UN INDICE ESPECIFICO.\n");
    printf("3) SALIR.\n\n");
    getInt(&respuesta, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 3);

    if(respuesta != 3 && able)
    {
        system("cls");
        fflush(stdin);
        getName(nombre, "\nINGRESE EL NOMBRE: ", "Error. Debe contener entre 2 y 128 caracteres. ", 2, 127);
        system("cls");
        getInt(&horasTrabajadas, "\nINGRESE LAS HORAS TRABAJADAS: ", "Error. Debe estar entre 1 y 1000", 1, 1000);
        system("cls");
        getInt(&sueldo, "\nINGRESE EL SUELDO: ", "Error. Debe estar entre 1 y 60000", 1, 60000);

        if( employee_setId(employee, -1) && employee_setNombre(employee, nombre) && employee_setHorasTrabajadas(employee, horasTrabajadas) && employee_setSueldo(employee, sueldo) )
        {
            switch(respuesta)
            {
            case 1:
                if( !ll_add(pArrayListEmployee, employee) )
                {
                    able = 1;
                    printf("\nALTA EXITOSA!\n\n");
                }
                else
                {
                    able = 0;
                }
                break;

            case 2:
                system("cls");
                getInt(&indice, "\nINGRESE EL INDICE: ", "ERROR! ", 0, ll_len(pArrayListEmployee));

                if( !ll_push(pArrayListEmployee, indice, employee) )
                {
                    able = 1;
                    printf("\nALTA EXITOSA!\n\n");
                }
                else
                {
                    able = 0;
                }
                break;
            }
        }
        else
        {
            able = 0;
        }

        if( !able )
        {
            printf("\nOCURRIO UN PROBLEMA DURANTE EL ALTA!\n\n");
        }
    }
    else
    {
        printf("\nALTA NO REALIZADA!\n\n");
        able = 0;
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
    int tam = ll_len(pArrayListEmployee);

    system("cls");
    printf("**************MODIFICAR EMPLEADO****************\n\n");

    getInt(&idToModify, "INGRESE EL ID DEL EMPLEADO A MODIFICAR: ", "ERROR. DEBE INGRESAR ENTRE 1 Y 2000. ", 1, 2000);

    for(int i=0; i<tam; i++)
    {
        if( idToModify == ( (sEmployee*) ll_get(pArrayListEmployee, i) )->id )
        {
            flag = 1;
            printf("\n");
            printf("ID             NOMBRE      HORAS T.    SUELDO\n");
            printEmployee((sEmployee*) ll_get(pArrayListEmployee, i));
            printf("\n");

            printf("1) MODIFICAR NOMBRE\n");
            printf("2) MODIFICAR HORAS TRABAJADAS\n");
            printf("3) MODIFCAR SUELDO\n");
            printf("4) SALIR\n\n");

            getInt(&datoAModificar, "SELECCIONE UNA OPCION: ", "ERROR. DEBE INGRESAR ENTRE 1 Y 4 ", 1, 4);

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
    int tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        getInt(&idToSearch, "\nINGRESE EL ID DEL EMPLEADO A ELIMINAR: ", "ERROR. ", 1, 10000);

        for(int i=0; i<tam; i++)
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

    if( printEmployees(pArrayListEmployee) )
    {
        able = 1;
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
    int opcion;
    int opcionPorId;
    int opcionPorNombre;
    int opcionPorHorasTrabajadas;
    int opcionPorSueldo;

    if(pArrayListEmployee != NULL)
    {
            system("cls");
            printf("\nCOMO DESEA ORDENAR LA LISTA?\n\n");
            printf("1) POR ID\n");
            printf("2) POR NOMBRE\n");
            printf("3) POR HORAS TRABAJADAS\n");
            printf("4) POR SUELDO\n");
            printf("5) SALIR\n\n");

            getInt(&opcion, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 5);

            switch(opcion)
            {
            case 1:
                printf("\n1) ASCENDENTE\n");
                printf("2) DESCENDENTE\n\n");
                getInt(&opcionPorId, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 2);
                switch(opcionPorId)
                {
                case 1:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorId, 1) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;

                case 2:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorId, 0) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;
                default:
                    printf("OPCION INVALIDA!\n");
                    break;
                }
                break;

            case 2:
                printf("\n1) ASCENDENTE\n");
                printf("2) DESCENDENTE\n\n");
                getInt(&opcionPorNombre, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 2);
                switch(opcionPorNombre)
                {
                case 1:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorNombre, 1) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;

                case 2:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorNombre, 0) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;
                default:
                    printf("OPCION INVALIDA!\n");
                    break;
                }
                break;

            case 3:
                printf("\n1) ASCENDENTE\n");
                printf("2) DESCENDENTE\n\n");
                getInt(&opcionPorHorasTrabajadas, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 2);
                switch(opcionPorHorasTrabajadas)
                {
                case 1:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorHorasTrabajadas, 1) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;

                case 2:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorHorasTrabajadas, 0) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;
                default:
                    printf("OPCION INVALIDA!\n");
                    break;
                }
                break;

            case 4:
                printf("\n1) ASCENDENTE\n");
                printf("2) DESCENDENTE\n\n");
                getInt(&opcionPorSueldo, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 2);
                switch(opcionPorSueldo)
                {
                case 1:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorSueldo, 1) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;

                case 2:
                    printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
                    if( ( ll_sort(pArrayListEmployee, ordenarPorSueldo, 0) ) == 0 )
                    {
                        printf("\nSE ORDENO CORRECTAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
                    }
                    break;
                default:
                    printf("OPCION INVALIDA!\n");
                    break;
                }
                break;

            case 5:
                printf("\nSE CANCELO EL ORDENAMIENTO!\n\n");
                break;
            default:
                printf("OPCION INVALIDA\n");
                break;
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
            fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i=0; i<tam; i++)
            {
                employee = (sEmployee*) ll_get(pArrayListEmployee, i);

                employee_getId(employee, &id);
                employee_getNombre(employee, nombre);
                employee_getHorasTrabajadas(employee, &horasTrabajadas);
                employee_getSueldo(employee, &sueldo);

                fprintf(f, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
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
                employee = (sEmployee*) ll_get(pArrayListEmployee, i);

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

/** \brief Clona la linkedList entera o parcialmente y guarda la nueva linkedList clonada en un archivo dataClonada.csv (modo texto).
 *
 * \param this LinkedList*
 * \return int
 *
 */
int controller_CloneLinkedList(LinkedList* this)
{
    int able = 0;
    LinkedList* newList = ll_newLinkedList();
    int response;
    int minId;
    int maxId;
    int minIndex;
    int maxIndex;
    int tam;

    if(this != NULL && newList != NULL)
    {
        tam = ll_len(this);

        do
        {
            system("cls");
            printf("\n1) CLONAR TODA LA LINKEDLIST.\n");
            printf("2) CLONAR UNA PARTE DE LA LINKEDLIST.\n");
            printf("3) VERIFICAR LINKEDLIST CLONADA.\n");
            printf("4) GUARDAR LINKEDLIST CLONADA.\n");
            printf("5) SALIR.\n\n");

            getInt(&response, "SELECCIONE UNA OPCION: ", "ERROR ", 1, 5);

            if(response != 5)
            {
                switch( response )
                {
                case 1:
                    newList = ll_clone(this);
                    if( ll_len(newList) == tam )
                    {
                        printf("\nLINKEDLIST CLONADA CON EXITO!\n\n");
                        able = 1;
                    }
                    else
                    {
                        printf("\nNO SE PUDO CLONAR LA LINKEDLIST!\n\n");
                    }
                    system("pause");
                    break;

                case 2:
                    system("cls");
                    ll_sort(this, ordenarPorId, 1);
                    printEmployees(this);

                    getInt(&minId, "\nINGRESE DESDE QUE ID: ", "ERROR, INGRESO UN NUMERO FUERA DE RANGO, INTENTE OTRO! ", 0, tam-1);
                    getInt(&maxId, "INGRESE HASTA QUE ID: ", "ERROR, INGRESO UN NUMERO FUERA DE RANGO, INTENTE OTRO! ", minId+1, tam);

                    for(int i=0; i<tam; i++)
                    {
                        if( minId == ( (sEmployee*) ll_get(this, i) )->id )
                        {
                            minIndex = ll_indexOf(this, (sEmployee*) ll_get(this, i) );
                        }
                        else if( maxId == ( (sEmployee*) ll_get(this, i) )->id )
                        {
                            maxIndex = ll_indexOf(this, (sEmployee*) ll_get(this, i) );
                        }
                    }

                    newList = ll_subList(this, minIndex, maxIndex);

                    if( ll_len(newList) > 0 && ll_len(newList) < maxIndex )
                    {
                        printf("\nLINKEDLIST CLONADA CON EXITO!\n\n");
                        able = 1;
                    }
                    else
                    {
                        printf("\nNO SE PUDO CLONAR LA LINKEDLIST\n\n");
                    }
                    system("pause");
                    break;

                case 3:
                    if(newList != NULL && ll_len(newList) > 0)
                    {
                        if( ll_containsAll(this, newList) )
                        {
                            printf("\nTODOS LOS ELEMENTOS DE LA LINKEDLIST CLONADA ESTAN EN LA LINKEDLIST ORIGINAL!\n\n");
                        }
                    }
                    else
                    {
                        printf("\nNO HAY LINKEDLIST CLONADA!\n\n");
                    }
                    system("pause");
                    break;

                case 4:
                    if( newList != NULL && ll_len(newList) > 0 )
                    {
                        if( controller_saveAsText("dataClonada.csv", newList) )
                        {
                            printf("\nLINKEDLIST GUARDADA CON EXITO!\n\n");
                        }
                        else
                        {
                            printf("\nNO SE PUDO GUARDAR LA LINKEDLIST!\n\n");
                        }
                    }
                    else
                    {
                        printf("\nNO HAY ELEMENTOS PARA GUARDAR!\n\n");
                    }
                    system("pause");
                    break;
                }
            }
            else
            {
                printf("\nSALIENDO AL MENU PRINCIPAL!\n\n");
            }

        }while(response != 5);
    }

    return able;
}
