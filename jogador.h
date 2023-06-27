
typedef struct Jogador
{
    int quantidadeCartas;
    Carta cartasDoJogador[16];
    char nome[20];
    int proximoAJogar;//se for 0 nao eh o proximo se for 1 eh o proximo
} Jogador;

int verificaVitoria(Jogador jogador, Jogador oponente)
{
    if(jogador.quantidadeCartas==16 || oponente.quantidadeCartas == 0)
    {
        printf("O %s ganhou o jogo!\n", jogador.nome);
        return 1;
    }
    else if(jogador.quantidadeCartas<=0){
        printf("O %s ganhou o jogo!\n", oponente.nome);
        return 1;
    }
    {
        return 0;
    }
}



int comparaCartas(Jogador jogador, Jogador oponente, int atributo)
{
    int oponenteTemNecrofago = strcmp(oponente.cartasDoJogador[0].grupo,"Necrofagos");
    int jogadorTemNecrofago = strcmp(jogador.cartasDoJogador[0].grupo,"Necrofagos");

    //casos de SuperTrunfo
    if(jogador.cartasDoJogador[0].isSuperTrunfo==1 && oponenteTemNecrofago != 0)
    {
        printf("O %s possui o SuperTrunfo e o %s nao possui um Necrofago.\nVitoria do %s!\n", jogador.nome, oponente.nome, jogador.nome);
        return 1;
    }
    else if(jogador.cartasDoJogador[0].isSuperTrunfo==1 && oponenteTemNecrofago == 0)
    {
        printf("O %s possui o SuperTrunfo, mas o %s possui um Necrofago.\nVitoria do %s!", jogador.nome, oponente.nome, oponente.nome);
        return 2;
    }
    else if(oponente.cartasDoJogador[0].isSuperTrunfo==1 && jogadorTemNecrofago != 0)
    {
        printf("O %s possui o SuperTrunfo e o %s nao possui um Necrofago.\nVitoria do %s!\n", oponente.nome, jogador.nome, oponente.nome);
        return 2;
    }
    else if(oponente.cartasDoJogador[0].isSuperTrunfo==1 && jogadorTemNecrofago == 0)
    {
        printf("O %s possui o SuperTrunfo, mas o %s possui um Necrofago. \nVitoria do %s!", oponente.nome, jogador.nome, jogador.nome);
        return 1;
    }
    //--------Fim  dos casos de SuperTrunfo-------


    else if(jogador.cartasDoJogador[0].atributos[atributo] > oponente.cartasDoJogador[0].atributos[atributo])
    {
        atributosQueSeraoComparados(atributo);
        printf("O %s ganhou essa rodada!\n", jogador.nome);
        return 1;
    }
    else if(jogador.cartasDoJogador[0].atributos[atributo] < oponente.cartasDoJogador[0].atributos[atributo])
    {
        atributosQueSeraoComparados(atributo);
        printf("O %s ganhou essa rodada!\n",oponente.nome);
        return 2;
    }
    else if(jogador.cartasDoJogador[0].atributos[atributo] == oponente.cartasDoJogador[0].atributos[atributo])
    {
        atributosQueSeraoComparados(atributo);
        printf("Houve um empate as cartas serao colocadas na mesa!");
        return 3;
    }
}


