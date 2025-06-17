#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura para armazenar os dados da cidade
typedef struct {
    char estado[50];
    int codigo;
    char nome[100];
    int populacao;
    double pib;
    double area;
    int pontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
} CartaCidade;

// Fun��o para calcular a densidade populacional
double calcularDensidade(int populacao, double area) {
    if (area == 0) return 0;
    return populacao / area;
}

// Fun��o para calcular o PIB per capita
double calcularPIBPerCapita(double pib, int populacao) {
    if (populacao == 0) return 0;
    return pib / populacao;
}

// Fun��o para registrar uma cidade
void registrarCidade(CartaCidade *cidade) {
    printf("\n--- Registro de Nova Cidade ---\n");

    printf("Estado: ");
    scanf(" %[^\n]", cidade->estado);

    printf("C�digo: ");
    scanf("%d", &cidade->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade->nome);

    printf("Popula��o: ");
    scanf("%d", &cidade->populacao);

    printf("PIB (em milh�es): ");
    scanf("%lf", &cidade->pib);

    printf("�rea (em km�): ");
    scanf("%lf", &cidade->area);

    printf("N�mero de pontos tur�sticos: ");
    scanf("%d", &cidade->pontosTuristicos);

    cidade->densidadePopulacional = calcularDensidade(cidade->populacao, cidade->area);
    cidade->pibPerCapita = calcularPIBPerCapita(cidade->pib, cidade->populacao);
}

// Fun��o para exibir os dados da cidade
void exibirCidade(CartaCidade cidade) {
    printf("\n--- Informa��es da Cidade ---\n");
    printf("Estado: %s\n", cidade.estado);
    printf("C�digo: %d\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("Popula��o: %d\n", cidade.populacao);
    printf("PIB: R$ %.2lf milh�es\n", cidade.pib);
    printf("�rea: %.2lf km�\n", cidade.area);
    printf("Pontos tur�sticos: %d\n", cidade.pontosTuristicos);
    printf("Densidade populacional: %.2lf hab/km�\n", cidade.densidadePopulacional);
    printf("PIB per capita: R$ %.2lf\n", cidade.pibPerCapita);
}

int main() {
    int n, i;
    CartaCidade cidades[MAX];

    printf("Quantas cidades deseja registrar? ");
    scanf("%d", &n);

    if (n > MAX || n < 1) {
        printf("N�mero inv�lido de cidades.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        registrarCidade(&cidades[i]);
    }

    for (i = 0; i < n; i++) {
        exibirCidade(cidades[i]);
    }

    return 0;
}
