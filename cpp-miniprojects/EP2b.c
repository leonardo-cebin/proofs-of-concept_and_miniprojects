#include <stdio.h>

//Aqui seguem as funções que são substituições das funções presentes em math.h
double valor_absoluto(double x) {
    if (x < 0.0){
        return -x;
    }
    return x;
}

double potencia(double x, int n) {
    double resultado = 1.0;
    for (int i=0; i<n; i++) {
        resultado *= x;
    }
    return resultado;
}

// Implementação do Método Babilônico (Newton-Raphson) para Raiz Quadrada
double raiz_quadrada(double x, double epsilon) {
    if (x == 0.0) return 0.0;
    double r = x;
    double r_ant;
    do {
        r_ant = r;
        r = 0.5 * (r + x / r);
    } while (valor_absoluto((r - r_ant) / r) >= epsilon);
    return r;
}

 // Método descrito no enunciado do EP2
double erro_relativo(double x, double y) {
    if (y == 0.0) return 1.0;
    return valor_absoluto((x - y) / y);
}


double calcula_f(double j, double vbem, double p, int n) {
    double S;
    if (j == 0.0) {
        S = (double) n;
    } else {
        double base = 1.0 / (1.0 + j);
        S = (1.0 - potencia(base, n)) / (1.0 - base);
    }
    return S - (vbem / p);
}

double juros(double vbem, int n, double prestacao, double epsilon) {
    // Aproximações iniciais (Sementes)
    double x_n2 = 0.0;
    double x_n1 = 0.3 * (prestacao / (vbem - prestacao));
    double x_n  = prestacao / (vbem - prestacao);

    // Avaliação inicial da função
    double f_n2 = calcula_f(x_n2, vbem, prestacao, n);
    if (f_n2 == 0.0) return x_n2;
    
    double f_n1 = calcula_f(x_n1, vbem, prestacao, n);
    if (f_n1 == 0.0) return x_n1;
    
    double f_n  = calcula_f(x_n, vbem, prestacao, n);
    if (f_n == 0.0) return x_n;

    double erro;
    double x_novo;

    // Loop do Método de Muller
    do {
        // Distâncias e Proporções
        double h_n1 = x_n1 - x_n2;
        double h_n  = x_n - x_n1;
        double q_n  = h_n / h_n1;

        // Coeficientes da Parábola
        double A = (q_n * f_n) - (q_n * (1.0 + q_n) * f_n1) + (q_n * q_n * f_n2);
        double B = ((2.0 * q_n + 1.0) * f_n) - ((1.0 + q_n) * (1.0 + q_n) * f_n1) - (q_n * q_n * f_n2);
        double C = (1.0 + q_n) * f_n;

        // Fórmula das Raízes (Variação de Bhaskara)
        double delta = (B * B) - (4.0 * A * C);
        if (delta < 0.0) delta = 0.0; // Prevenção contra flutuações de ponto flutuante
        
        double raiz_delta = raiz_quadrada(delta, epsilon);
        double denom1 = B + raiz_delta;
        double denom2 = B - raiz_delta;

        // Proteção contra divisão por zero e cálculo das raízes
        double q_linha = 0.0, q_duas_linhas = 0.0;
        if (denom1 != 0.0) q_linha = (-2.0 * C) / denom1;
        if (denom2 != 0.0) q_duas_linhas = (-2.0 * C) / denom2;

        // Seleção da menor raiz em módulo
        double q_prox;
        if (denom1 != 0.0 && denom2 != 0.0) {
            if (valor_absoluto(q_linha) < valor_absoluto(q_duas_linhas)) {
                q_prox = q_linha;
            } else {
                q_prox = q_duas_linhas;
            }
        } else if (denom1 != 0.0) {
            q_prox = q_linha;
        } else {
            q_prox = q_duas_linhas;
        }

        // A nova aproximação
        x_novo = x_n + (h_n * q_prox);
        erro = erro_relativo(x_n, x_novo);

        printf("j=%.20g erro=%.20g\n", x_novo, erro);

        // Deslocamento de variáveis para a próxima iteração
        x_n2 = x_n1;
        f_n2 = f_n1;
        
        x_n1 = x_n;
        f_n1 = f_n;
        
        x_n = x_novo;
        f_n = calcula_f(x_novo, vbem, prestacao, n);

    } while (erro >= epsilon && f_n != 0.0);

    return x_novo;
}

//  FUNÇÃO MAIN (Entrada e Saída)

int main() {
    double vbem, prestacao, epsilon;
    int n;

    printf("Digite respectivamente os valores de Valor NPrest Prestacao ErroRelativo\n");
    
    // O loop continua lendo as entradas até que o valor de V_Bem seja negativo
    while (scanf("%lf", &vbem) == 1 && vbem >= 0) { //trutsy value
        scanf("%d %lf %lf", &n, &prestacao, &epsilon);
        
        // Avalia um edge case financeiro imediato: se prestação * n <= V_bem, não há juros.
        if (prestacao * (double)n <= vbem) {
            printf("Juros = 0\n");
        } else {
            double j_final = juros(vbem, n, prestacao, epsilon);
            printf("Juros = %.20g\n", j_final);
        }
        
        printf("Valor NPrest Prestacao ErroRelativo\n");
    }
    
    printf("Acabou!\n");
    return 0;
}