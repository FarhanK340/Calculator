#include <stdio.h>
int main(void)
{
    float num1, num2;
    char operation;

    printf("Welcome to the Calculator\n");
    printf("1. Sum\t\t\t");
    printf("2. Difference\n");
    printf("3. Product\t\t");
    printf("4. Division\n");
    printf("Enter number of operation you would like to perform: ");
    scanf("%c", &operation);
    printf("Enter Operand 1: ");
    scanf("%f", &num1);
    printf("Enter Operand 2: ");
    scanf("%f", &num2);

    switch (operation)
    {
    case '1':
        printf("%g", num1 + num2);
        break;
    case '2':
        printf("%g", num1 - num2);
        break;
    case '3':
        printf("%g", num1 * num2);
        break;
    case '4':
        if (num2 == 0)
        {
            printf("ERROR: MATHS ERROR!!!");
        }
        else
            printf("%g", num1 / num2);
        break;
    default:
        printf("ERROR: You did not the correct operation");
        break;
    }
    return 0;
}
