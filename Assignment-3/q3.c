#include <stdio.h>
#include "/Users/hiteshkumar/opt/anaconda3/pkgs/llvm-openmp-10.0.0-h28b9765_0/lib/clang/10.0.0/include/omp.h"
int main()
{
    omp_set_num_threads(1);
    #pragma omp parallel
    {
        printf("\n Hello from thread = %d ", omp_get_thread_num() );
    }

    printf("\n\n GoodBye – Team Destroyed – Exiting Program \n\n");

}
