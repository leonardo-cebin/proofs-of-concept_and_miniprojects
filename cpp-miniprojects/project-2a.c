//Lets go for the win!!!

#include <stdio.h>

double potencia(double numero, int power){
    int i;
    double quase;
    
    quase = numero;
    
    if (power == 0){
        return 1;
    }
    
    for(i = 1;i<power;i++){
        quase *= numero;
    }
    return quase;
}

int main()
{
    double valorbem = 1,quantparcelas,taxajuros;
    double parc_calc, soma_parcial;
    
    int i;
    
    printf("Digite respectivamente os valores de:");
    
    while (valorbem >= 0){
        printf("\nValor NPrest Juros\n");
        scanf("%lf%lf%lf",&valorbem,&quantparcelas,&taxajuros);

        if(valorbem >= 0 && quantparcelas > 0){
            i=1;
            soma_parcial = 1;
    
            while(i < quantparcelas){
                soma_parcial += 1/potencia(1 + taxajuros, i);
                i++;
            }
    
            parc_calc = (valorbem/soma_parcial);
    
            printf("Prestacao = %.20g",parc_calc);
        } else {
            printf("\nAcabou!");
        }

    }
    return 0;
}
