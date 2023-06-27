#include"baralhoFuncoes.h"
#include<time.h>
#include"jogador.h"
#include"mesa.h"

int main(){

    Carta baralho[16];
    adicionaCartasAoBaralho(baralho);
    srand(time(NULL));
    EmbaralhaBaralho(baralho);
    printf("Cartas do baralho:\n");
    for(int i = 0; i<16;i++){
        printaCarta(baralho[i]);
        printf("\n");
    }
    system("pause");
    system("cls");
    Jogador jogador1;
    jogador1.proximoAJogar=1;//jogador 1 comeca jogando;
    strcpy(jogador1.nome, "jogador1");
    jogador1.quantidadeCartas=8;


    Jogador jogador2;
    jogador2.proximoAJogar = 0;
    strcpy(jogador2.nome, "jogador2");
    jogador2.quantidadeCartas=8;
    distribuiCartasAosJogadores(jogador1.cartasDoJogador, jogador2.cartasDoJogador, baralho);
    Mesa mesaDeCartas;
    mesaDeCartas.quantidadeCartasNaMesa=0;
    mesaDeCartas.temCartasNaMesa=0;

    //loop principal do jogo
    while(1){
            if(jogador1.proximoAJogar==1){//jogador1 escolhe
                //verifica se o jogador 1 ganhou
                if(verificaVitoria(jogador1,jogador2)==1){
                    break;
                }

                int atributoEscolhido = escolheAtributo(jogador1.cartasDoJogador[0]);
                printf("Quantidade de cartas jogador1: %d\n", jogador1.quantidadeCartas);
                printf("Quantidade de cartas jogador2: %d\n", jogador2.quantidadeCartas);
                printf("Quantidade de cartas na mesa: %d\n", mesaDeCartas.quantidadeCartasNaMesa);

                printf("\nCarta do Jogador 1:\n");
                printaCarta(jogador1.cartasDoJogador[0]);
                printf("\n");

                printf("Carta do Jogador 2:\n");
                printaCarta(jogador2.cartasDoJogador[0]);
                printf("\n");
                int resultado = comparaCartas(jogador1, jogador2, atributoEscolhido);
                printf("\n");
                system("pause");
                system("cls");
                switch(resultado){
                case 1:
                    adicionaCartaAoGanhador(jogador1.cartasDoJogador, jogador2.cartasDoJogador, jogador1.quantidadeCartas, jogador2.quantidadeCartas);
                    jogador1.quantidadeCartas++;
                    jogador2.quantidadeCartas--;
                    jogador1.proximoAJogar=1;
                    jogador2.proximoAJogar=0;

                    if(mesaDeCartas.temCartasNaMesa==1){
                        adicionaMesaAoGanhador(jogador1.cartasDoJogador, mesaDeCartas.cartasNaMesa, jogador1.quantidadeCartas, mesaDeCartas.quantidadeCartasNaMesa);
                        jogador1.quantidadeCartas+=mesaDeCartas.quantidadeCartasNaMesa;
                        mesaDeCartas.quantidadeCartasNaMesa=0;
                        mesaDeCartas.temCartasNaMesa=0;
                    }
                    break;
                case 2:
                    adicionaCartaAoGanhador(jogador2.cartasDoJogador, jogador1.cartasDoJogador, jogador2.quantidadeCartas, jogador1.quantidadeCartas);
                    jogador2.quantidadeCartas++;
                    jogador1.quantidadeCartas--;
                    jogador2.proximoAJogar=1;
                    jogador1.proximoAJogar=0;

                    if(mesaDeCartas.temCartasNaMesa==1){
                        adicionaMesaAoGanhador(jogador2.cartasDoJogador, mesaDeCartas.cartasNaMesa, jogador2.quantidadeCartas, mesaDeCartas.quantidadeCartasNaMesa);
                        jogador2.quantidadeCartas+=mesaDeCartas.quantidadeCartasNaMesa;
                        mesaDeCartas.quantidadeCartasNaMesa=0;
                        mesaDeCartas.temCartasNaMesa=0;
                    }
                    break;
                case 3:
                    //caso de empate com um dos jogadores com apenas uma carta:
                    if(jogador1.quantidadeCartas==1 || jogador2.quantidadeCartas==1){
                        printf("Empate com apenas uma carta, outro atributo sera escolhido!\n");
                        break;
                    }else{
                        mesaDeCartas.temCartasNaMesa=1;
                        adicionaCartasAMesa(jogador1.cartasDoJogador, jogador2.cartasDoJogador, jogador1.quantidadeCartas, jogador2.quantidadeCartas, mesaDeCartas.cartasNaMesa, mesaDeCartas.quantidadeCartasNaMesa);
                        mesaDeCartas.quantidadeCartasNaMesa+=2;
                        jogador1.quantidadeCartas--;
                        jogador2.quantidadeCartas--;
                        break;
                    }

                }


            }else{//jogador2 escolhe
                if(verificaVitoria(jogador2,jogador1)==1){
                    break;
                }
                int atributoEscolhido = escolheAtributo(jogador2.cartasDoJogador[0]);
                printf("Quantidade de cartas jogador1: %d\n", jogador1.quantidadeCartas);
                printf("Quantidade de cartas jogador2: %d\n", jogador2.quantidadeCartas);
                printf("Quantidade de cartas na mesa: %d\n", mesaDeCartas.quantidadeCartasNaMesa);

                printf("\nCarta do Jogador 2:\n");
                printaCarta(jogador2.cartasDoJogador[0]);
                printf("\n");

                printf("Carta do Jogador 1:\n");
                printaCarta(jogador1.cartasDoJogador[0]);
                printf("\n");
                int resultado = comparaCartas(jogador2, jogador1, atributoEscolhido);
                printf("\n");
                system("pause");
                system("cls");

                switch(resultado){
                case 1:
                    adicionaCartaAoGanhador(jogador2.cartasDoJogador, jogador1.cartasDoJogador, jogador2.quantidadeCartas, jogador1.quantidadeCartas);
                    jogador2.quantidadeCartas++;
                    jogador1.quantidadeCartas--;
                    jogador2.proximoAJogar=1;
                    jogador1.proximoAJogar=0;
                    if(mesaDeCartas.temCartasNaMesa==1){
                        adicionaMesaAoGanhador(jogador2.cartasDoJogador, mesaDeCartas.cartasNaMesa, jogador2.quantidadeCartas, mesaDeCartas.quantidadeCartasNaMesa);
                        jogador2.quantidadeCartas+=mesaDeCartas.quantidadeCartasNaMesa;
                        mesaDeCartas.quantidadeCartasNaMesa=0;
                        mesaDeCartas.temCartasNaMesa=0;
                    }
                    break;
                case 2:
                    adicionaCartaAoGanhador(jogador1.cartasDoJogador, jogador2.cartasDoJogador, jogador1.quantidadeCartas, jogador2.quantidadeCartas);
                    jogador1.quantidadeCartas++;
                    jogador2.quantidadeCartas--;
                    jogador1.proximoAJogar=1;
                    jogador2.proximoAJogar=0;
                    if(mesaDeCartas.temCartasNaMesa==1){
                        adicionaMesaAoGanhador(jogador1.cartasDoJogador, mesaDeCartas.cartasNaMesa, jogador1.quantidadeCartas, mesaDeCartas.quantidadeCartasNaMesa);
                        jogador1.quantidadeCartas+=mesaDeCartas.quantidadeCartasNaMesa;
                        mesaDeCartas.quantidadeCartasNaMesa=0;
                        mesaDeCartas.temCartasNaMesa=0;
                    }
                    break;
                case 3:
                    //caso de empate com um dos jogadores com apenas uma carta:
                    if(jogador1.quantidadeCartas==1 || jogador2.quantidadeCartas==1){
                        printf("Empate com apenas uma carta, outro atributo sera escolhido!\n");
                        break;
                    }else{
                        mesaDeCartas.temCartasNaMesa=1;
                        adicionaCartasAMesa(jogador1.cartasDoJogador, jogador2.cartasDoJogador, jogador1.quantidadeCartas, jogador2.quantidadeCartas, mesaDeCartas.cartasNaMesa, mesaDeCartas.quantidadeCartasNaMesa);
                        mesaDeCartas.quantidadeCartasNaMesa+=2;
                        jogador1.quantidadeCartas--;
                        jogador2.quantidadeCartas--;
                        break;
                    }
                }

            }
    }


    return 0;
}
