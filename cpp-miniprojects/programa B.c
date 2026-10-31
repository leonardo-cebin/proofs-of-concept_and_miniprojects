#include <stdio.h>
#include <stdlib.h>

int main(){
    

    int n_max, semente, k, x, state;
    int desc_teacher = 0;
    int desc_aluno = 1;
    state = 1;
    
    
    printf("Qual a carta mais alta a ser sacada?");
    scanf("%d",&n_max);
    
    printf("Qual a semente aleatoria para gerar o baralho?");
    scanf("%d",&semente);
    
    srand(semente);
    k = 1;
    while(state == 1){
        x = 1 + (rand()/((double)RAND_MAX+1))*n_max;
        printf(" %d", x);
        
        if (desc_teacher == 0 && desc_aluno == 0){
            state = 0;
        } else {
            k++;
        }
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
    printf("\n\n");
    printf("Numero de numeros gerados = %d",k);
    return 0;
}