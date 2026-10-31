/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
    

    int n_max, N, semente, k, x;
    int desc_teacher = 0;
    int desc_aluno = 1;
    
    
    printf("Qual a carta mais alta a ser sacada?");
    scanf("%d",&n_max);
    
    printf("Qual a quantidade de cartas?");
    scanf("%d",&N);
    
    printf("Qual a semente aleatoria para gerar o baralho?");
    scanf("%d",&semente);
    
    srand(semente);
    for (k = 1; k <= N; k++) {
        x = 1 + (rand()/((double)RAND_MAX+1))*n_max;
        printf(" %d", x);
        
        if (desc_teacher == 0){
            printf("*");
            desc_teacher = x;
        }
        if (desc_aluno == 0){
            printf("+");
            desc_aluno = x;
        }
        
        desc_teacher--;
        desc_aluno--;
    }
    printf("\n");
    return 0;
}
