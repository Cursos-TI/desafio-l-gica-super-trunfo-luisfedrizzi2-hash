#include <stdio.h>
#include <string.h>

#define NUM_CARTAS 3
#define NUM_ATRIBUTOS 3

typedef struct {
    char nome[20];
    int atributos[NUM_ATRIBUTOS]; // por exemplo: ataque, defesa, velocidade
} Carta;

void mostrarCarta(Carta c){
    printf("Carta: %s\n", c.nome);
    printf("1. Ataque: %d\n", c.atributos[0]);
    printf("2. Defesa: %d\n", c.atributos[1]);
    printf("3. Velocidade: %d\n", c.atributos[2]);
}

int main() {
    Carta cartas[NUM_CARTAS] = {
        {"Dragao", {8, 5, 7}},
        {"Fenix", {6, 7, 8}},
        {"Unicornio", {5, 9, 6}}
    };

    int escolhaJogador, escolhaAtributo;
    Carta cartaJogador, cartaComputador;

    printf("Escolha uma carta (0-Dragao, 1-Fenix, 2-Unicornio): ");
    scanf("%d", &escolhaJogador);
    cartaJogador = cartas[escolhaJogador];

    // Escolha aleatória da carta do computador
    cartaComputador = cartas[(escolhaJogador + 1) % NUM_CARTAS];

    mostrarCarta(cartaJogador);

    printf("Escolha o atributo para batalhar (1-Ataque, 2-Defesa, 3-Velocidade): ");
    scanf("%d", &escolhaAtributo);
    escolhaAtributo--; // ajustar índice

    printf("\nCarta do computador: %s\n", cartaComputador.nome);
    printf("Atributo selecionado: %d\n", cartaComputador.atributos[escolhaAtributo]);

    if(cartaJogador.atributos[escolhaAtributo] > cartaComputador.atributos[escolhaAtributo])
        printf("Voce venceu!\n");
    else if(cartaJogador.atributos[escolhaAtributo] < cartaComputador.atributos[escolhaAtributo])
        printf("Computador venceu!\n");
    else
        printf("Empate!\n");

    return 0;
}
