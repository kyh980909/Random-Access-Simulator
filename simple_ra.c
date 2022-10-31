#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include <string.h>
#include <complex.h>

struct UEinfo {
    int sendTime;
    int preamble;
    int delay;
};

int bigRandom(int M); // 큰 수 범위의 랜덤 함수
int* initialUE();

int main(void)
{
    srand(1004);

    initialUE();

    // int nUE = 1000;
    // int nPreambles = 64;
   
    // struct UEinfo *UE;
	// UE = (struct UEinfo *) calloc(nUE, sizeof(struct UEinfo));
 
    // int T = 60000, t = 0; // millisecond

    // for (t = 0; t < T; t++)
    // {
        
    // }
    

    return 0;
}

int bigRandom(int M)
{
    return (double) rand() / (((double) RAND_MAX + (double) + 1)/(double) M);
}

int* initialUE()
{
    for (int i = 0; i < 30000; i++)
    {
        printf("%d\n", bigRandom(60000));
    }
    
}