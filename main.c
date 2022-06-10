#include <stdio.h>
#include <pthread.h>


int qntDeNumeros = 0;
int media = 0;
int maior = 0;
int menor = 0;
int arr[];

void *Media(void *argumentos) {

    int i = 0;
    int soma = 0;

    for(i = 0; i < qntDeNumeros; i++)
    {
        soma += arr[i];
    }

    media = soma/qntDeNumeros;

}

void *Maior(void *argumentos) {

    int i = 0;
    maior = arr[0];
    for(i = 0; i < qntDeNumeros; i++)
    {
        if(arr[i] > maior){
            maior = arr[i];
        }
    }

}

void *Menor(void *argumentos) {

    int i = 0;
    menor = arr[0];
    for(i = 0; i < qntDeNumeros; i++)
    {
        if(arr[i] < menor){
            menor = arr[i];
        }
    }

}

int main ( ){

    int i = 0;

    pthread_t threadMedia;
    pthread_t threadMinimo;
    pthread_t threadMaximo;

    int flag;

    int novoNumero = 0;

    scanf("%d", &qntDeNumeros);

    for(i = 0; i < qntDeNumeros; i++)
    {
        scanf("%d", &novoNumero);
        arr[i] = novoNumero;
    }

    flag = pthread_create(&threadMedia, NULL, Media, NULL);

    if (flag!=0)
        printf("Erro na criação da thread\n");

    flag = pthread_create(&threadMinimo, NULL, Maior, NULL);

    if (flag!=0)
        printf("Erro na criação da thread\n");

    flag = pthread_create(&threadMaximo, NULL, Menor, NULL);

    if (flag!=0)
        printf("Erro na criação da thread\n");


    pthread_join(threadMedia, NULL);
    pthread_join(threadMinimo, NULL);
    pthread_join(threadMaximo, NULL);

    printf("Media: %d \n", media);
    printf("Maior: %d \n", maior);
    printf("Menor: %d \n", menor);

    return 0;
}
