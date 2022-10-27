#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
void result (double a, double b, unsigned int n, double I);
double lrect(double a, double b, unsigned int n);
double rrect(double a, double b, unsigned int n);
double trapez(double a, double b, unsigned int n);
double parab(double a, double b, unsigned int n);

int main()
{
    unsigned int method;
    const double a=0;
    const double b=1;
    unsigned int n, N;
    double I, I1, I2;
    const double e=0.0001;

    printf(" The following methods of integration are available:");
    printf("\n\t1 - left rectangles");
    printf("\n\t2 - right rectangles");
    printf("\n\t3 - trapezoids");
    printf("\n\t4 - parabols");
    printf("\n\n Please choose the preferred one: ");
    scanf("%u", &method);

    while (method!=1&&method!=2&&method!=3&&method!=4)
    {
    printf("\n We only have 4 (four) options, please choose one of them (1, 2, 3, 4):\t");
    scanf("%d", &method);
    }

    do{
            printf("\n Enter n (number of partition intervals):\t");
            scanf("%u", &n);
     }while(n<=0);

    switch (method)
    {
        case 1:
        {
            I=lrect(a, b, n);
            result(a, b, n, I);
            N=0;
            do {
                N = N+2;
                I1 = lrect(a, b, N);
                I2 = lrect(a, b, N+2);
               } while (fabs(I2-I1)>e);
            printf("\n\nN=%u, I1(N)=%.5lf\n", N, I1);
        }
        break;

        case 2:
        {
            I=rrect(a, b, n);
            result(a, b, n, I);
            N=0;
            do {
                N = N+2;
                I1 = rrect(a, b, N);
                I2 = rrect(a, b, N+2);
               } while (fabs(I2-I1)>e);
            printf("\n\nN=%u, I1(N)=%.5lf\n", N, I1);
        }
        break;

        case 3:
        {
            I=trapez(a, b, n);
            result(a, b, n, I);
            N=0;
            do {
                N = N+2;
                I1 = trapez(a, b, N);
                I2 = trapez(a, b, N+2);
               } while (fabs(I2-I1)>e);
            printf("\n\nN=%u, I1(N)=%.5lf\n", N, I1);
        }
        break;

        case 4:
        {
            if (n%2!=0)
            {
                printf("\n For the chosen method an even number of partition intervals is needed");
                printf("\n Please enter a different number: ");
                scanf("\t%d", &n);
            }

            I=parab(a, b, n);
            result(a, b, n, I);
            N=0;
            do {
                N = N+2;
                I1 = parab(a, b, N);
                I2 = parab(a, b, N+2);
               } while (fabs(I2-I1)>e);
            printf("\n\nN=%u, I1(N)=%.5lf\n", N, I1);
        }
        break;
    }
}

double f(double x)
{
    double y;
    y=pow(x,2)*exp(2*x);
    return y;
}

double lrect(double a, double b, unsigned int n)
{
    double h;
    unsigned int i;
    double x;
    double S=0;

    h = (b-a)/n;
    x = a;
    for (i=0; i<=n-1; i++)
    {
        S = S + f(x);
        x = x+h;
    }
    return S*h;
}

double rrect(double a, double b, unsigned int n)
{
    double h;
    unsigned int i;
    double x;
    double S=0;

    h = (b-a)/n;
    x = a+h;
    for (i=1; i<=n; i++)
    {
        S = S + f(x);
        x = x+h;
    }
    return S*h;
}

double trapez(double a, double b, unsigned int n)
{
    double h;
    unsigned int i;
    double x;
    double S=0;

    h = (b-a)/n;
    x = a+h;
    for (i=0; i<=n-1; i++)
    {
        S = S + (f(x)+f(x+h))/2;
        x = x+h;
    }
    return S*h;
}

double parab(double a, double b, unsigned int n)
{
    double h;
    double x;
    double I=0;

    h = (b-a)/n;
    x = a+h;
    while (x<b)
    {
        I += 4*f(x);
        x += h;
        if (x>=b)
        {
            I += 2*f(x);
            x += h;
        }
    }
    I = (h/3)*(I+f(a)+f(b));
    return I;
}

void result (double a, double b, unsigned int n, double I)
{
    system ("cls");
    printf("----------------------");
    printf("\n+~~~~~~~Result~~~~~~~+");
    printf("\n----------------------");
    printf("\na = %.1lf \nb = %.1lf \nn = %u \nIntegral = %.5lf", a, b, n, I);
}
