#include <stdio.h>
#include <string.h>
#include <math.h>

int task(void) 
{
    int radius;
    char symbol, answer;

    do 
    {
        int i, j;

        printf("Прямоугольный треугольник, вписанный в окружность.\n");

        printf("Введите символ рисования: ");
        scanf(" %c", &symbol);

        printf("Введите радиус R (3-25): ");

        if (scanf("%d", &radius) != 1) 
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

        if (radius < 3 || radius > 25) 
        {
            printf("Ошибка! Радиус должен быть от 3 до 25.\n");
        } 
        else 
        {

            int rows = 2 * radius;
            int columns = 4 * radius;

            printf("\n");

            for (i = 0; i <= rows; i++) 
            {

                double y = 1.0 - (double)i / radius;

                for (j = 0; j <= columns; j++) 
                {

                    double x = ((double)j - 2.0 * radius)
                               / (2.0 * radius);

                    int inTriangle =
                        (y >= 0.0 && y <= 1.0 - fabs(x));

                    int onCircle =
                        (fabs(x * x + y * y - 1.0)
                         <= 1.2 / radius);

                    if (inTriangle || onCircle) 
                    {
                        putchar(symbol);
                    } 
                    else 
                    {
                        putchar(' ');
                    }
                }

                putchar('\n');
            }
        }

        printf("\nНарисовать еще одну фигуру? (y/n): ");
        scanf(" %c", &answer);

    }
     while (answer != 'n' && answer != 'N');

    return 0;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    task(void);
} 