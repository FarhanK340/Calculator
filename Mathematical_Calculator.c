#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265358979323846
int main()
{
    int mode, sfmode, mode2, num, a, b, c, d, choice;
    float l, w, r, s, left_op, right_op, ans;
    char operation, cont;

    printf("\t***********************************************************\n");
    printf("\t***********************************************************\n");
    printf("\t**                     WELCOME TO THE                    **\n");
    printf("\t**                MATHEMATICAL CALCULATOR                **\n");
    printf("\t***********************************************************\n");
    do
    {
    menu:
        printf("\t***********************************************************\n");
        printf("\t**  What type of calculations would you like to perform? **\n");
        printf("\t**  [1]. Normal Maths Operations                         **\n");
        printf("\t**  [2]. Special Functions                               **\n");
        printf("\t**  [3]. Factorial                                       **\n");
        printf("\t**  [4]. Area and Perimeter                              **\n");
        printf("\t**  [5]. Random Questions                                **\n");
        printf("\t**                                                       **\n");
        printf("\t**  [6].Exit                                             **\n");
        printf("\t**                                                       **\n");
        printf("\t***********************************************************\n\n");

        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            printf("\tWelcome to the Normal Maths Mode\n\n");
            printf("\t*************************************\n");
            printf("\t**  ACCEPTABLE SYMBOLS:            **\n");
            printf("\t**  Addition '+'     Division '/'  **\n");
            printf("\t**  Subtraction '-'  Power '^'     **\n");
            printf("\t**  Product '*'      Rooting '$'   **\n");
            printf("\t**                                 **\n");
            printf("\t*************************************\n\n");

            printf("Enter the expression: ");
            scanf("%f%c", &left_op, &operation);
            while (operation != '\n')
            {
                int check;
                float valid, ans1, ans2;
                scanf("%f", &right_op);

                switch (operation)
                {
                case '+':
                    ans = (left_op + right_op);
                    break;
                case '-':
                    ans = (left_op - right_op);
                    break;
                case '*':
                    ans = (left_op * right_op);
                    break;
                case '/':
                    ans = (left_op / right_op);
                    break;
                case '^':
                    ans = (pow(left_op, right_op));
                    break;
                case '$':
                    if (left_op < 0)
                    {
                        printf("You cannot root a NEGATIVE number!!");
                        goto next;
                    }
                    else
                        ans = (pow(left_op, 1 / right_op));
                    check = left_op;
                    valid = check % 2;
                    break;
                default:
                    printf("ERROR!!!!INVALID SYMBOLS USED!!");
                }
                left_op = ans;
                scanf("%c", &operation);
            }
            printf("Answer is: %g\n", ans);
            break;
        case 2:
            printf("\t     Welcome to the Special Functions Mode\n\n");
            printf("\t***********************************************\n");
            printf("\t** [1]. Sine Function                        **\n");
            printf("\t** [2]. Cosine Function                      **\n");
            printf("\t** [3]. Tangent Function                     **\n");
            printf("\t** [4]. Sine Inverse Function                **\n");
            printf("\t** [5]. Cosine Inverse Function              **\n");
            printf("\t** [6]. Tangent Inverse Function             **\n");
            printf("\t** [7]. Log(with base 10)                    **\n");
            printf("\t** [8]. Log(with base e)                     **\n");
            printf("\t** [9]. Log(with user defined base)          **\n");
            printf("\t** [10]. Return to main menu                 **\n");
            printf("\t***********************************************\n\n");

            scanf("%d", &sfmode);
            switch (sfmode)
            {
            case 1:
                printf("Enter the Angle: ");
                scanf("%f", &left_op);
                ans = (sin(left_op * PI / 180));
                break;
            case 2:
                printf("Enter the Angle: ");
                scanf("%f", &left_op);
                ans = (cos(left_op * PI / 180));
                break;
            case 3:
                printf("Enter the Angle: ");
                scanf("%f", &left_op);
                ans = (tan(left_op * PI / 180));
                break;
            case 4:
                printf("Enter the value: ");
                scanf("%f", &left_op);
                if (left_op < -1 || left_op > 1)
                {
                    printf("ERROR!!!The number should be from -1 to 1\n");
                }
                else
                {
                    ans = (asin(left_op));
                    ans = ans * 180 / PI;
                }
                break;
            case 5:
                printf("Enter the value: ");
                scanf("%f", &left_op);
                if (left_op < -1 || left_op > 1)
                {
                    printf("ERROR!!!The number should be from -1 to 1\n");
                }
                else
                {
                    ans = (acos(left_op));
                    ans = ans * 180 / PI;
                }
                break;
            case 6:
                printf("Enter the value: ");
                scanf("%f", &left_op);
                ans = (atan(left_op));
                ans = ans * 180 / PI;

                break;
            case 7:
                printf("Enter the number: ");
                scanf("%f", &left_op);
                if (left_op < 0)
                {
                    printf("ERROR!!!You cannot take log of a negative number!!\n");
                    goto next;
                }
                else if (left_op == 0)
                {
                    printf("ERROR!!!You cannot take log(0).\n");
                    goto next;
                }
                else
                {
                    ans = log10(left_op);
                }
                break;
            case 8:
                printf("Enter the number: ");
                scanf("%f", &left_op);
                if (left_op < 0)
                {
                    printf("ERROR!!!You cannot take ln of a negative number!!\n");
                    goto next;
                }
                else if (left_op == 0)
                {
                    printf("ERROR!!!You cannot take ln(0).\n");
                    goto next;
                }
                else
                {
                    ans = log(left_op);
                }
                break;
            case 9:
                printf("Enter the base followed by the number: ");
                scanf("%f%f", &left_op, &right_op);
                if (left_op <= 0 || right_op <= 0)
                {
                    printf("ERROR!!!You cannot take ln of a negative number/zero base!!\n");
                    goto next;
                }
                {
                    ans = log(left_op) / log(right_op);
                }
                break;
            case 10:
                goto menu;
            default:
                printf("You selected an Invalid function mode\n");
                break;
            }
            printf("Answer is: %g\n", ans);

            break;
        case 3:
            printf("Enter the number: ");
            scanf("%d", &num);
            a = num;
            while (a != 1)
            {
                a--;
                num *= a;
            }
            printf("Answer is: %d\n", num);
            break;
        case 4:
            printf("Select the shape:\n");
            printf("[1].Square\n[2].Rectangle\n[3].Triangle\n[4].Circle\n");
            scanf("%d", &mode);
            switch (mode)
            {
            case 1:
                printf("Enter the side length of the square: ");
                scanf("%f", &l);
            re1:
                printf("What do you want to find?\n");
                printf("[1].Area\t[2].Perimeter\n");
                scanf("%d", &mode2);
                if (mode2 == 1)
                {
                    ans = l * l;
                    printf("The Area is: %gcm^2\n", ans);
                }
                else if (mode2 == 2)
                {
                    ans = 4 * l;
                    printf("The Perimeter is: %gcm\n", ans);
                }
                else
                {
                    printf("ERROR!!You did not choose the correct option!\nPlease enter your choice again");
                    goto re1;
                }
                break;
            case 2:
                printf("Enter the length and width of the rectangle: ");
                scanf("%f%f", &l, &w);
            re2:
                printf("What do you want to find?\n");
                printf("[1].Area\t[2].Perimeter\n");
                scanf("%d", &mode2);
                if (mode2 == 1)
                {
                    ans = l * w;
                    printf("The Area is: %gcm^2\n", ans);
                }
                else if (mode2 == 2)
                {
                    ans = (2 * (l + w));
                    printf("The Perimeter is: %gcm\n", ans);
                }
                else
                {
                    printf("ERROR!!You did not choose the correct option!\nPlease enter your choice again");
                    goto re2;
                }
                break;
            case 3:
                printf("Enter the sides of the triangle: ");
                scanf("%f%f%f", &l, &w, &r);
            re3:
                printf("What do you want to find?\n");
                printf("[1].Area\t[2].Perimeter\n");
                scanf("%d", &mode2);
                if (mode2 == 1)
                {
                    s = ((l + w + r) / 2);
                    ans = (sqrt(s * (s - l) * (s - w) * (s - r)));
                    printf("The Area is: %gcm^2\n", ans);
                }
                else if (mode2 == 2)
                {
                    ans = l + w + r;
                    printf("The Perimeter is: %gcm\n", ans);
                }
                else
                {
                    printf("ERROR!!You did not choose the correct option!\nPlease enter your choice again");
                    goto re3;
                }
                break;
            case 4:
                printf("Enter the radius of the circle: ");
                scanf("%f", &r);
            re4:
                printf("What do you want to find?\n");
                printf("[1].Area\t[2].Perimeter\n");
                scanf("%d", &mode2);
                if (mode2 == 1)
                {
                    ans = (PI * r * r);
                    printf("The Area is: %gcm^2\n", ans);
                }
                else if (mode2 == 2)
                {
                    ans = (2 * PI * r);
                    printf("The Perimeter is: %gcm\n", ans);
                }
                else
                {
                    printf("ERROR!!You did not choose the correct option!\nPlease enter your choice again");
                    goto re4;
                }
                break;

            default:
                printf("ERROR!!Entered option not found!\n");
                break;
            }
            break;
        case 5:
            srand(time(NULL));
            choice = rand() % 3;
            switch (choice)
            {
            case 0:
                a = rand() % 5000;
                b = rand() % 5001;
                d = a + b;
                printf("What is %d+%d?: ", a, b);
                scanf("%d", &c);
                if (d == c)
                {
                    printf("HURRAY!!!You are right\n");
                }
                else
                {
                    printf("OPPS!!That is not the correct answer\nThe correct ans is: %d\n", d);
                }
                break;
            case 1:
                a = rand() % 5000;
                b = rand() % 5000;
                d = a - b;
                printf("What is %d-%d?: ", a, b);
                scanf("%d", &c);
                if (d == c)
                {
                    printf("HURRAY!!!You are right\n");
                }
                else
                {
                    printf("OPPS!!That is not the correct answer\nThe correct ans is: %d\n", d);
                }
                break;
            case 2:
                a = rand() % 20;
                b = rand() % 20;
                d = a * b;
                printf("What is %d*%d?: ", a, b);
                scanf("%d", &c);
                if (d == c)
                {
                    printf("HURRAY!!!You are right\n");
                }
                else
                {
                    printf("OPPS!!That is not the correct answer\nThe correct ans is: %d\n", d);
                }
                break;
            default:
                break;
            }
            break;
        case 6:
            goto exit;
        default:
            printf("ERROR 404!!Your option could not be found!\n");
            goto menu;
        }
    next:
        printf("Do you want to perform another calculation?\nPress any key to continue.\nPress [0] for exit.\n");
        scanf(" %c", &cont);
        if (cont == '0')
        {
            goto exit;
        }
        else
            cont == '1';

    } while (cont > 0);
exit:
    printf("Thank You for using My CALCULATOR!!\n");
    printf("Hope to see again!");
}
