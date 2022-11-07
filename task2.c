#include <stdio.h>
int main(void)
{
    float left_op, right_op, num, min, max, avg, power, n, ans;
    int operation;

    printf("Welcome to the Calculator\n");
    printf("1. Sum\t\t\t");
    printf("2. Difference\n");
    printf("3. Product\t\t");
    printf("4. Division\n");
    printf("5. Squareroot\t\t");
    printf("6. Cuberoot\n");
    printf("7. Power\n");
    printf("Enter number of operation you would like to perform: ");
    scanf("%d", &operation);

    if (operation == 1 || operation == 2 || operation == 3 || operation == 4)
    {
        printf("Enter Left Operand: ");
        scanf("%f", &left_op);
                    
        printf("Enter Right Operand: ");
        scanf("%f", &right_op);
    }
    else if (operation == 5)
    {
        printf("Enter Number: ");
        scanf("%f", &num);
        if (num < 0)
        {
            printf("Error: You entered a negative number\n");
        }
        else
        {
            min = 1, max = num;
            avg = (min + max) / 2;
            while (((avg * avg) - num) > 0.0001 || ((avg * avg) - num) < 0)
            {   
                if (num<1)
                {
                    if (avg * avg < num)
                    {
                        max = avg;
                    }
                    else
                    {
                        min = avg;
                    }
                    avg = (min + max) / 2;
                }
                else
                {
                    if (avg * avg > num)
                    {
                        max = avg;
                    }
                    else
                    {
                        min = avg;
                    }
                    avg = (min + max) / 2;
                }
            }
        }
    }
    else if (operation == 6)
    {
        printf("Enter Number: ");
        scanf("%f", &num);
        if (num < 0)
        {
            num = num * -1;
            min = 1, max = num;
            avg = (min + max) / 2;
            while (((avg * avg * avg) - num) > 0.001 || ((avg * avg * avg) - num) < 0)
            {
                if (avg * avg * avg > num)
                {
                    max = avg;
                }
                else
                {
                    min = avg;
                }
                avg = (min + max) / 2;
            }
            avg = avg * -1;
        }
        else
        {
            min = 1, max = num;
            avg = (min + max) / 2;
            while (((avg * avg * avg) - num) > 0.001 || ((avg * avg * avg) - num) < 0)
            {
                if (avg * avg * avg > num)
                {
                    max = avg;
                }
                else
                {
                    min = avg;
                }
                avg = (min + max) / 2;
            }
        }
    }
    // Power Function
    else if (operation == 7)
    {
        printf("Enter Number: ");
        scanf("%f", &num);
        printf("Enter power to which number is to be raised: ");
        scanf("%f", &power);
        n = power;
        ans = 1;

        if (n < 0) // if power is negative
        {
            n = -1 * n;
        }

        else if (n == 0) // if power is zero
        {
            ans = 1;
            goto jump;
        }
        while (n != 0)
        {
            ans *= num;
            n--;
        }
        if (power < 0) //In case of negative power
        {
            ans = (1 / ans);
        }
    }

    switch (operation)
    {
    // for addition
    case 1:
        printf("%g", left_op + right_op);
        break;
    // for subtraction
    case 2:
        printf("%g", left_op - right_op);
        break;
    // for multiplication
    case 3:
        printf("%g", left_op * right_op);
        break;
    // for division
    case 4:
        if (right_op==0)
        {
            printf("ERROR: MATHS ERROR!!!");
        }
        else
        printf("%g", left_op / right_op);
        break;
    // for squarerot function
    case 5:
        if (num < 0)
        {
            printf("Error: You take squareroot of a negative number!");
            break;
        }
        else
        {
            printf("%.2f", avg);
        }
        break;
    // for cuberroot function
    case 6:
        printf("%.2f", avg);
        break;
    // for power function
    case 7:
    jump:
        printf("Number %g raised to power %g is: %g\n", num, power, ans);
        break;
    // In case user enters any other umber than asked in the menu
    default:
        printf("ERROR: You did not the correct operation");
        break;
    }
    return 0;
}