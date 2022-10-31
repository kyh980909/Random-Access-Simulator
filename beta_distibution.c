#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double beta_distribution(double alpha, double beta, double x);
double beta_function(double alpha, double beta);
double access_intensity(double t, double T, double alpha, double beta);


int main(void)
{
    FILE *fp = fopen("beta_distribution_5000.txt", "w");

    srand(time(NULL));
    double T = 10.0, t = 0.0;
    double N = 5000;

    while(t <= T)
    {
        printf("%1.f\n", N*access_intensity(t, T, 3.0, 4.0)/1000);
        fprintf(fp, "%1.f\n", N*access_intensity(t, T, 3.0, 4.0)/1000);
        t += 0.001;
    }
    // printf("%f", 1.0/(tgamma(7.0)/(gamma_a*gamma_b)));

    
    // for (int i = 0; i < 100; i++)
    // {
    //     fprintf(fp, "%f\n", (float) rand()/RAND_MAX);
    // }
    

    return 0;
}

double beta_distribution(double alpha, double beta, double x)
{
    double gamma_a = 0.0, gamma_b = 0.0;

    gamma_a = tgamma(alpha);
    gamma_b = tgamma(beta);

    return (1.0/(tgamma(alpha+beta)/(gamma_a*gamma_b)))*pow(x,alpha-1.0)*pow((1-x), beta-1.0);
}

double beta_function(double alpha, double beta)
{
    double gamma_a = 0.0, gamma_b = 0.0;

    gamma_a = tgamma(alpha);
    gamma_b = tgamma(beta);

    return 1.0/(tgamma(alpha+beta)/(gamma_a*gamma_b));
}

double access_intensity(double t, double T, double alpha, double beta)
{
    return (pow(t,alpha-1.0)*pow((T-t),beta-1.0))/(pow(T,alpha+beta-1.0)*beta_function(alpha, beta));
}