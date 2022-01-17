#include <stdio.h>
#include "/Users/hiteshkumar/opt/anaconda3/pkgs/llvm-openmp-10.0.0-h28b9765_0/lib/clang/10.0.0/include/omp.h"

int main()
{
    int i;
    int sum=0;
    omp_set_num_threads(8);
    #pragma omp parallel for reduction(+:sum)
        for (i=0; i<100; i++)
    {
            sum = sum + i;
            printf("Thread number: %d  Iteration: %d  Local Sum: %d \n",
                omp_get_thread_num(), i, sum);
        }
    printf("\n All Threads Done – Final Global Sum: %d \n\n", sum);
}
