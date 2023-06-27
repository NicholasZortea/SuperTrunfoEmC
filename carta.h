#include <stdio.h>
#include <string.h>

typedef struct Carta{
    /*
    agilidade = 0;
    inteligencia = 1;
    resistencia = 2;
    forca = 3;
    magia = 4;*/
    int atributos[5];
    char nomeDaCarta[50];
    char grupo[50];
    int isSuperTrunfo;
}Carta;

void distribuiCartasAosJogadores(Carta jogador1[], Carta jogador2[], Carta baralho[16])
{
    for(int i=0; i <=7; i++)
    {
        jogador1[i] = baralho[i];
    }
    for(int i=8; i <=15; i++)
    {
        jogador2[i-8] = baralho[i];
    }
}

int escolheAtributo(Carta carta){
    return rand()%5;
}

void adicionaCartaAoGanhador(Carta vetorGanhador[], Carta vetorPerdedor[], int qtdCartasGanhador, int qtdCartasPerdedor){
    Carta cartaNaFrenteGanhador=vetorGanhador[0];
    Carta cartaNaFrentePerdedor=vetorPerdedor[0];

    int ultimainteracao = 0;
    for(int i = 0; i<qtdCartasGanhador-1;i++){
        vetorGanhador[i]=vetorGanhador[i+1];
        ultimainteracao = i;
    }

    vetorGanhador[qtdCartasGanhador-1]=cartaNaFrenteGanhador;
    vetorGanhador[qtdCartasGanhador]=cartaNaFrentePerdedor;

    for(int i=0; i<qtdCartasPerdedor-1;i++){
        vetorPerdedor[i] = vetorPerdedor[i+1];
        ultimainteracao = i;
    }


}

void adicionaCartasAMesa(Carta jogador1[], Carta jogador2[], int qtdJogador1, int qtdJogador2, Carta vetorMesa[], int qtdCartasMesa){
    vetorMesa[qtdCartasMesa]=jogador1[0];
    vetorMesa[qtdCartasMesa+1]=jogador2[0];
    for(int i=0; i < qtdJogador2-1;i++){
        jogador2[i] = jogador2[i+1];
    }
    for(int i=0; i < qtdJogador1-1 ;i++){
        jogador1[i] = jogador1[i+1];
    }
}

void adicionaMesaAoGanhador(Carta vetorGanhador[], Carta mesa[], int qtdCartasGanhador, int qtdCartasMesa){
    for(int i=0; i<qtdCartasMesa;i++){
        vetorGanhador[qtdCartasGanhador+i]=mesa[i];
    }

}

void atributosQueSeraoComparados(int pos){
    if(pos == 0){
        printf("Os atributos comparados serao agilidade!\n");
    }
    if(pos == 1){
        printf("Os atributos comparados serao inteligencia!\n");
    }
    if(pos == 2){
        printf("Os atributos comparados serao resistencia!\n");
    }
    if(pos == 3){
        printf("Os atributos comparados serao forca!\n");
    }
    if(pos == 4){
        printf("Os atributos comparados serao magia!\n");
    }
}

void printaCarta(Carta carta){
    printf("\n\tGrupo da Carta: ");
    printf("%s", carta.grupo);
    printf("\n\tNome da Carta: ");
    puts(carta.nomeDaCarta);
    if(carta.isSuperTrunfo==1){
        printf("\tSupertrunfo!\n");
    }
    printf("\tAgilidade: %d\n", carta.atributos[0]);
    printf("\tInteligencia: %d\n", carta.atributos[1]);
    printf("\tResistencia: %d\n", carta.atributos[2]);
    printf("\tForca: %d\n", carta.atributos[3]);
    printf("\tMagia: %d\n", carta.atributos[4]);

}


void adicionaCartasAoBaralho(Carta vetor[]){

//----Amaldicoados----

//bruxo
Carta bruxo;
bruxo.atributos[0]=7;
strcpy(bruxo.grupo,"Amaldicoados");
bruxo.atributos[3]=6;
bruxo.atributos[1]=8;
bruxo.isSuperTrunfo=1;
bruxo.atributos[4]=6;
bruxo.atributos[2]=5;
strcpy(bruxo.nomeDaCarta, "Bruxo");

//Lobisomem
Carta lobisomem;
lobisomem.atributos[0]=8;
strcpy(lobisomem.grupo,"Amaldicoados");
lobisomem.atributos[3]=6;
lobisomem.atributos[1]=7;
lobisomem.isSuperTrunfo=0;
lobisomem.atributos[4]=5;
lobisomem.atributos[2]=6;
strcpy(lobisomem.nomeDaCarta, "Lobisomem");

//Berserker
Carta berserker;
berserker.atributos[0]=8;
strcpy(berserker.grupo,"Amaldicoados");
berserker.atributos[3]=7;
berserker.atributos[1]=6;
berserker.isSuperTrunfo=0;
berserker.atributos[4]=5;
berserker.atributos[2]=6;
strcpy(berserker.nomeDaCarta, "Berserker");

//Fetulho
Carta fetulho;
fetulho.atributos[0]=5;
strcpy(fetulho.grupo,"Amaldicoados");
fetulho.atributos[3]=6;
fetulho.atributos[1]=9;
fetulho.isSuperTrunfo=0;
fetulho.atributos[4]=6;
fetulho.atributos[2]=5;
strcpy(fetulho.nomeDaCarta, "Fetulho");

//----Necrofagos-----

//afogador
Carta afogador;
afogador.atributos[0]=8;
strcpy(afogador.nomeDaCarta, "Afogador");
afogador.atributos[3]=5;
afogador.atributos[1]=5;
afogador.isSuperTrunfo=0;
afogador.atributos[4]=5;
afogador.atributos[2]=5;
strcpy(afogador.grupo, "Necrofagos");

//carniçal
Carta carnical;
carnical.atributos[0]=6;
strcpy(carnical.nomeDaCarta, "Carnical");
carnical.atributos[3]=7;
carnical.atributos[1]=5;
carnical.isSuperTrunfo=0;
carnical.atributos[4]=5;
carnical.atributos[2]=6;
strcpy(carnical.grupo, "Necrofagos");

//nevoloso
Carta nevoloso;
nevoloso.atributos[0]=8;
strcpy(nevoloso.nomeDaCarta, "Nevoloso");
nevoloso.atributos[3]=5;
nevoloso.atributos[1]=6;
nevoloso.isSuperTrunfo=0;
nevoloso.atributos[4]=7;
nevoloso.atributos[2]=5;
strcpy(nevoloso.grupo, "Necrofagos");

//Bruxa Aquatica
Carta bruxaAquatica;
bruxaAquatica.atributos[0]=6;
strcpy(bruxaAquatica.nomeDaCarta, "Bruxa Aquatica");
bruxaAquatica.atributos[3]=7;
bruxaAquatica.atributos[1]=7;
bruxaAquatica.isSuperTrunfo=0;
bruxaAquatica.atributos[4]=7;
bruxaAquatica.atributos[2]=5;
strcpy(bruxaAquatica.grupo, "Necrofagos");

//----Draconideos----

//Basilisco
Carta basilisco;
basilisco.atributos[0]=7;
strcpy(basilisco.nomeDaCarta, "Basilisco");
basilisco.atributos[3]=7;
basilisco.atributos[1]=5;
basilisco.isSuperTrunfo=0;
basilisco.atributos[4]=6;
basilisco.atributos[2]=8;
strcpy(basilisco.grupo, "Draconideos");

//Wyvern
Carta wyvern;
wyvern.atributos[0]=6;
strcpy(wyvern.nomeDaCarta, "Wyvern");
wyvern.atributos[3]=6;
wyvern.atributos[1]=6;
wyvern.isSuperTrunfo=0;
wyvern.atributos[4]=8;
wyvern.atributos[2]=7;
strcpy(wyvern.grupo, "Draconideos");

//Tordo
Carta tordo;
tordo.atributos[0]=7;
strcpy(tordo.nomeDaCarta, "Tordo");
tordo.atributos[3]=6;
tordo.atributos[1]=5;
tordo.isSuperTrunfo=0;
tordo.atributos[4]=6;
tordo.atributos[2]=7;
strcpy(tordo.grupo, "Draconideos");

//Cocatriz
Carta cocatriz;
cocatriz.atributos[0]=7;
strcpy(cocatriz.nomeDaCarta, "Cocatriz");
cocatriz.atributos[3]=6;
cocatriz.atributos[1]=7;
cocatriz.isSuperTrunfo=0;
cocatriz.atributos[4]=5;
cocatriz.atributos[2]=7;
strcpy(cocatriz.grupo, "Draconideos");

//----Construtos----

//Golem
Carta golem;
golem.atributos[0]=5;
strcpy(golem.nomeDaCarta, "Golem");
golem.atributos[3]=7;
golem.atributos[1]=5;
golem.isSuperTrunfo=0;
golem.atributos[4]=5;
golem.atributos[2]=9;
strcpy(golem.grupo, "Construtos");

//Djinn
Carta djinn;
djinn.atributos[0]=6;
strcpy(djinn.nomeDaCarta, "Djinn");
djinn.atributos[3]=6;
djinn.atributos[1]=7;
djinn.isSuperTrunfo=0;
djinn.atributos[4]=10;
djinn.atributos[2]=5;
strcpy(djinn.grupo, "Construtos");

//Gargula
Carta gargula;
gargula.atributos[0]=5;
strcpy(gargula.nomeDaCarta, "Gargula");
gargula.atributos[3]=6;
gargula.atributos[1]=6;
gargula.isSuperTrunfo=0;
gargula.atributos[4]=5;
gargula.atributos[2]=10;
strcpy(gargula.grupo, "Construtos");

//Elemental do Fogo
Carta elementalDoFogo;
elementalDoFogo.atributos[0]=5;
strcpy(elementalDoFogo.nomeDaCarta, "Elemental do Fogo");
elementalDoFogo.atributos[3]=6;
elementalDoFogo.atributos[1]=6;
elementalDoFogo.isSuperTrunfo=0;
elementalDoFogo.atributos[4]=8;
elementalDoFogo.atributos[2]=7;
strcpy(elementalDoFogo.grupo, "Construtos");

vetor[0]=bruxo;
vetor[1]=bruxaAquatica;
vetor[2]=lobisomem;
vetor[3]=tordo;
vetor[4]=carnical;
vetor[5]=fetulho;
vetor[6]=wyvern;
vetor[7]=cocatriz;
vetor[8]=elementalDoFogo;
vetor[9]=gargula;
vetor[10]=djinn;
vetor[11]=golem;
vetor[12]=afogador;
vetor[13]=nevoloso;
vetor[14]=berserker;
vetor[15]=basilisco;
}
