#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void sieve_of_erastothenes(const unsigned int N)
{
    const int SQRT_N = sqrt(N);
    int actual_prime = 2;
    bool *result = malloc(N * sizeof(bool));
    memset(result, true, N * sizeof(bool));
    while (actual_prime < SQRT_N)
    {
        for (int i = actual_prime * actual_prime; i <= N; i += actual_prime)
            result[i] = false;
        while (!result[++actual_prime])
            ;
    }

    for (unsigned int i = 2, j = 0; i < N; i++)
        if (result[i])
            printf("p_%d = %d\n", j++, i);
}

int main(int argc, char const *argv[])
{
    unsigned int N;
    printf("Enter up limit for sieving:\t");
    scanf("%u", &N);
    sieve_of_erastothenes(N);
    return 0;
}
