#include <stdio.h>
#include <stdlib.h>
#include "funcMath.h"

int main()
{

    float number1=0.00;
    float number2=0.00;
    float resultAdd;
    float resultSubtract;
    char calculated='0';
    float resultDivide;
    float resultMultiply;
    long resultFactorialA;
    long resultFactorialB;
    char option;

    do      // Menú principal
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

        switch(option)  // Se determina que ocurrirá en caso segun la opción seleccionada por el usuario.
        {
        case '1':

            system("cls");
            number1 = getFloat("INGRESE PRIMER OPERANDO: ");
            break;

        case '2':

            system("cls");
            number2 = getFloat("INGRESE SEGUNDO OPERANDO: ");
            break;

        case '3':

            if(number1 == 0 && number2 == 0) // Validación, en caso de que ambos operandos sean cero no se pueden realizar cálculos.
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
                printf("\n======================================");     // Muestra al usuario que cálculos se efectuaron.
                printf("\n%cSUS OPERACIONES HAN SIDO CALCULADAS!\n", 173);
                printf("a) SE CALCUL%c LA SUMA (A+B).\n", 224);
                printf("b) SE CALCUL%c LA RESTA (A-B).\n", 224);
                printf("c) SE CALCUL%c LA DIVISI%cN (A/B).\n", 224, 224);
                printf("d) SE CALCUL%c LA MULTIPLICACI%cN (A*B).\n", 224, 224);
                printf("e) SE CALCUL%c EL FACTORIAL DE LA PARTE ENTERA DE LOS OPERANDOS (A! Y B!).\n", 224);
                printf("======================================\n\n");
                calculated = '1';  // Confirma que ya se calcularon las operaciones.
            }
            break;

        case '4':
            if(calculated == '0') // Validación, si aún no se han realizado los cálculos entonces no se pueden mostrar los resultados.
            {
                printf("\n=========================================================");
                printf("\n%cDEBE HACER EL C%cLCULO DE LAS OPERACIONES PARA MOSTRAR LOS RESULTADOS!\n", 173, 181);
                printf("=========================================================\n\n");

            }else
            {
                printf("\n===================================================\n\n");
                printf("a) EL RESULTADO DE A+B ES: %f\n", resultAdd);
                printf("b) EL RESULTADO DE A-B ES: %f\n", resultSubtract);

                if(number2 == 0) // Validación, si el segundo operando es cero no se puede realizar la división.
                {
                    printf("d) NO ES POSIBLE DIVIDIR POR CERO (0).\n");

                }else
                {
                    printf("c) EL RESULTADO DE A/B ES: %f\n", resultDivide);

                }

                printf("d) EL RESULTADO DE A*B ES: %f\n", resultMultiply);
                printf("e) EL FACTORIAL DEL 1ER OPERANDO ES: %ld Y EL FACTORIAL DEL 2DO OPERANDO ES: %ld\n", resultFactorialA, resultFactorialB);
                printf("\n===================================================\n\n");

            }
            break;
        }

        system("pause");

        system("cls");

    }while(option != '5');

    return 0;
}
