#include <stdio.h>
#include <stdlib.h>
#include "funcMath.h"

int main()
{

    float number1=0;
    float number2=0;
    float resultAdd;
    float resultSubtract;
    char calculated='0';
    float resultDivide;
    float resultMultiply;
    long resultFactorialA;
    long resultFactorialB;
    char option;


    do
    {
        printf("\n================================\n");
        printf(" %cBIENVENIDO A SU CALCULADORA!\n", 173);
        printf("================================\n\n");

        printf("SELECCIONE UNA OPCI%cN DEL MEN%c:\n\n", 224, 233);

        printf("1) AGREGAR PRIMER OPERANDO (A = %.2f)\n", number1);
        printf("2) AGREGAR SEGUNDO OPERANDO (B = %.2f)\n", number2);
        printf("3) CALCULAR TODAS LAS OPERACIONES\n");
        printf("4) MOSTRAR RESULTADOS\n");
        printf("5) SALIR\n");
        fflush(stdin);
        printf("\nINGRESE UNA OPCI%cN: ", 224);
        scanf("%c", &option);

        switch(option)
        {
        case '1':

            system("cls");
            number1 = getNumber();
            break;

        case '2':

            system("cls");
            number2 = getNumber();
            break;

        case '3':

            if(number1==0 && number2==0)
            {
                printf("\n=========================================================\n");
                printf("%cDEBE INGRESAR LOS OPERANDOS PARA EFECTUAR LOS C%cLCULOS!", 173, 181);
                printf("\n=========================================================\n\n");

            }else
            {
                resultAdd = add(number1, number2);
                resultSubtract = subtract(number1, number2);
                resultDivide = divide(number1, number2);
                resultMultiply = multiply(number1, number2);
                resultFactorialA = factorial(number1);
                resultFactorialB = factorial(number2);
                printf("\n======================================");
                printf("\n%cSus operaciones han sido calculadas!\n", 173);
                printf("======================================\n\n");
                calculated=1;
            }
            break;

        case '4':
            if(calculated=='0')
            {
                printf("\n=========================================================");
                printf("\n%cDEBE HACER EL C%cLCULO DE LAS OPERACIONES PARA MOSTRAR LOS RESULTADOS!\n", 173, 181);
                printf("=========================================================\n\n");

            }else
            {
                printf("\n===================================================\n\n");
                printf("a) El resultado de A+B es: %f\n", resultAdd);
                printf("b) El resultado de A-B es: %f\n", resultSubtract);

                if(number2 == 0)
                {
                    printf("d) No se puede dividir por cero (0).\n");
                }else
                {
                    printf("c) El resultado de A/B es: %f\n", resultDivide);

                }

                printf("d) El resultado de A*B es: %f\n", resultMultiply);
                printf("e) El factorial del 1er operando es: %ld y el factorial del 2do operando es: %ld\n", resultFactorialA, resultFactorialB);
                printf("\n===================================================\n\n");

            }
            break;
        }

        system("pause");

        system("cls");

    }while(option!='5');

    return 0;
}
