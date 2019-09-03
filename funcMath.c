#include <stdio.h>
#include <stdlib.h>
#include "funcMath.h"

/** \brief Solicita un número al usuario y devuelve dicho número.
 *
 * \param No recibe parametros.
 * \return El número ingresado por el usuario.
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

/** \brief Caclula la suma entre dos números.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la suma de ambos números.
 *
 */
float add(float number1, float number2)
{
    float result;

    result = number1 + number2;

    return result;
}

/** \brief Caclula la resta entre dos números.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la resta de ambos números.
 *
 */
float subtract(float number1, float number2)
{
    float result;

    result = number1 - number2;

    return result;
}

/** \brief Caclula la división entre dos números.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la división entre ambos números.
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

/** \brief Caclula la multiplicación entre dos números.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El resultado de la multiplicación entre ambos números.
 *
 */
float multiply(float number1, float number2)
{
    float result;

    result = number1 * number2;

    return result;
}

/** \brief Caclula el factorial de un número.
 *
 * \param Primer operando.
 * \param Segundo operando.
 * \return El factorial del número.
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
