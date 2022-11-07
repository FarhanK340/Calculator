#include <stdio.h>
int main(void)
{
    float left_op, right_op, num, min, max, avg, n, ans, result, Power;
    int error;
    char expr, operation, sqrt, cuberoot, power,re;
    
    printf("********************************\n");
    printf("********************************\n");
    printf("**        WELCOME TO THE      **\n");
    printf("**   MATHEMATICAL CALCULATOR  **\n");
    printf("********************************\n");
    printf("********************************\n");
    printf("** Acceptable Symbols:        **\n");
    printf("** Sum +                      **\n");
    printf("** Difference -               **\n");
    printf("** Product *                  **\n");
    printf("** Division /                 **\n");
    printf("** Squareroot s               **\n");
    printf("** Cuberoot c                 **\n");
    printf("** Power ^                    **\n");
    printf("**                            **\n");
    printf("********************************\n\n");
    
    do
    {
        printf("Enter the expression: ");
        scanf("%f%c", &left_op, &operation);
        while (operation != '\n')
        {
            switch (operation)
            {
            case '+':
            case '-':
            case '*':
            case '/':
                scanf("%f", &right_op);

                switch (operation)
                {
                case '+':
                    result = left_op + right_op;
                    break;
                case '-':
                    result = left_op - right_op;
                    break;
                case '*':
                    result = left_op * right_op;
                    break;
                case '/':
                    if (right_op == 0)
                    {
                        error = 1;
                    }
                    else
                        result = left_op / right_op;
                    break;
                default:
                    break;
                }
                break;
            case 's':
            case 'c':
            case '^':
                switch (operation)
                {
                case 's':
                    num = left_op;
                    if (num < 0)
                    {
                        printf("Error: You cannot take squareroot of a negative number!\n");
                        error = 1;
                    }
                    else
                    {
                        min = 1, max = num;
                        avg = (min + max) / 2;
                        while (((avg * avg) - num) > 0.001 || ((avg * avg) - num) < 0)
                        {
                            if (num < 1)
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
                    left_op = avg;
                    goto next;
                case 'c':
                    num = left_op;
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
                    left_op = avg;
                    goto next;
                case '^':

                    scanf("%f", &Power);
                    n = Power;
                    num = left_op;
                    ans = 1;
                    if (n < 0) // if power is negative
                    {
                        n = -1 * n;
                    }

                    else if (n == 0) // if power is zero
                    {
                        ans = 1;
                        left_op = ans;
                        goto next;
                    }
                    while (n != 0)
                    {
                        ans *= num;
                        n--;
                    }
                    if (Power < 0) // In case of negative power
                    {
                        ans = (1 / ans);
                    }
                    left_op = ans;
                    goto next;
                default:
                    break;
                }
                break;
            default:
                printf("ERROR:YOU ENTERED INVALID EXPRESSION!!!\n");
                error = 1;
                break;
            }

            left_op = result;
        next:
            scanf("%c", &operation);
        }
        if (error != 1)
        {
            printf("ANS=%g\n", left_op);
        }
        printf("Do you want to perform another calculation?\n");
        printf("Press any KEY to continue...\n");
        printf("Enter 0 to exit: ");
        scanf(" %c", &re);
        if (re == '0')
        {
            return 0;
        }
        else
            re == '1';
    } while (re > 0);

    return 0;
}
