#include"carta.h"

void EmbaralhaBaralho(Carta vetorCartas[16]){
    Carta novoBaralho[16];
    int listaDeNumeros[16];
    preencheCom20(listaDeNumeros);
    int numeroRandom;
    for(int i=0; i<=15;i++){
        do{
            numeroRandom = rand()%16;
            if(numeroExisteNoVetor(listaDeNumeros, i, numeroRandom) == 0){
                break;
            }
        }while(1);
        listaDeNumeros[i]=numeroRandom;//adiciona numero random ao vetor de numeros usados
        novoBaralho[i]=vetorCartas[numeroRandom];//na iteracao i pega um valor aleatorio nao utilizado do vetor de cartas
    }
    rearranjaVetor(vetorCartas, novoBaralho);
}

int numeroExisteNoVetor(int vetor[], int tamanhoDoVetor, int numero){
    for(int i=0; i<=tamanhoDoVetor; i++){
        if(numero==vetor[i]){
            //o numero ja esta no vetor e nao podera ser utilizado novamente
            return 1;
        }
    }
    //se conseguir sair do for eh por que nao esta no vetor portando pode ser utilizado
    return 0;
}

void preencheCom20(int vetor[]){
    for (int i = 0; i<=15; i++){
        vetor[i]=20;
    }
}

void rearranjaVetor(Carta vetorDeCartas[], Carta embaralhado[]){
    for(int i = 0; i <=15; i++){
        vetorDeCartas[i]=embaralhado[i];
    }
}
