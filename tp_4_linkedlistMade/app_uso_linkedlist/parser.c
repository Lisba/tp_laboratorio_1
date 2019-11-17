#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][30];
    int cant;
    sEmployee* employee;
    int able = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while( !feof(pFile) )
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant < 4)
            {
                break;
            }
            else
            {
                employee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(employee != NULL && validateEmployee(employee))
                {
                    ll_add(pArrayListEmployee, employee);
                    able = 1;
                }
            }
        }
    }

    return able;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int able = 0;
    int cant = 0;
    sEmployee* employee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while( !feof(pFile) )
        {
            employee = employee_new();
            if( employee == NULL )
            {
                break;
            }

            cant = fread(employee, sizeof(sEmployee), 1, pFile);

            employee_setId(employee, employee->id);

            if( validateEmployee(employee) == 1 )
            {
                ll_add(pArrayListEmployee, employee);
                able = 1;
            }
            else
            {
                employee_delete(employee);
            }

            if(cant < 1)
            {
                if( !feof(pFile) )
                {
                    break;
                }
                else
                {
                    able = 0;
                    break;
                }
            }
        }
    }

    return able;
}
