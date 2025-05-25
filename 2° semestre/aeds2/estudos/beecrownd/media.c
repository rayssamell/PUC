#include <stdio.h>

double calcularMedia(double a, double b, double c, double d){
    double peso = 2 + 3 + 4 + 1;
    double media = ((a*2) + (b*3) + (c*4) + d) / peso;

    return media; 
}

double exame(double media, double e){
    return (media + e)/2; 
}

int main(){
    double a, b, c, d, e;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);

    double media = calcularMedia(a,b,c,d);
    if(media >= 7.0){
        printf("Media: %.1lf\n", media);
        printf("Aluno aprovado.\n");
    } else if(media < 5.0){
        printf("Media: %.1lf\n", media);
        printf("Aluno reprovado.\n");
    } else {
        printf("Media: %.1lf\n", media);
        printf("Aluno em exame.\n");
        scanf("%lf", &e);
        double total = exame(media, e);
        printf("Nota do exame: %.1lf\n", e);
        if(total >= 5.0){
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1lf\n", total);
    }
    return 0;
}