#include <stdio.h>
#include <stdlib.h>
#include "funcMath.h"

/** \brief Solicita un n�mero al usuario y devuelve dicho n�mero.
 *
 * \param No recibe parametros.
 * \return El n�mero ingresado por el usuario.
 *
 */
float getNumber(void)
{
    float number;
    float validation;

    do
    {
        fflush(stdin);
        printf("\n======================\n");
        printf("INGRESE UN OPERANDO: ");
        validation = scanf("%f", &number);

        if(!validation)
        {
            printf("\n%cERROR!, DEBE INGRESAR UN N%cMERO.\n", 173, 233);
        }

    }while(!validation);

    return number;
}

/** \brief Caclula la suma entre dos n�meros.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la suma de ambos n�meros.
 *
 */
float add(float number1, float number2)
{
    float result;

    result = number1 + number2;

    return result;
}

/** \brief Caclula la resta entre dos n�meros.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la resta de ambos n�meros.
 *
 */
float subtract(float number1, float number2)
{
    float result;

    result = number1 - number2;

    return result;
}

/** \brief Caclula la divisi�n entre dos n�meros.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la divisi�n entre ambos n�meros.
 *
 */
float divide(float number1, float number2)
{
    float result;

    if(number2 == 0)
    {
        result = 0.00;
    }else
    {
        result = number1 / number2;
    }

    return result;
}

/** \brief Caclula la multiplicaci�n entre dos n�meros.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la multiplicaci�n entre ambos n�meros.
 *
 */
float multiply(float number1, float number2)
{
    float result;

    result = number1 * number2;

    return result;
}

/** \brief Caclula el factorial de un n�mero.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El factorial del n�mero.
 *
 */
float factorial(float number)
{
    float result = number;

    int i = 1;

    while(i<number)
    {
        result *= i;
        i++;
    }

    return result;
}
