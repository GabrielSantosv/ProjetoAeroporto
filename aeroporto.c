#include <stdio.h>
#include <string.h>

#define LIMITE 100

char codigosAero[LIMITE][4];
int voos[LIMITE][LIMITE];  // Guarda o número do voo entre dois aeroportos (0 = sem conexão)
int totalCadastrados = 0;

// Função para adicionar um novo aeroporto ao sistema
void adicionarAeroporto(char sigla[]) {
    if (totalCadastrados < LIMITE) {
        strcpy(codigosAero[totalCadastrados], sigla);
        totalCadastrados++;
    } else {
        printf("Máximo de aeroportos atingido.\n");
    }
}

// Função para localizar o índice correspondente a um aeroporto
int encontrarIndice(char sigla[]) {
    for (int i = 0; i < totalCadastrados; i++) {
        if (strcmp(codigosAero[i], sigla) == 0)
            return i;
    }
    return -1;
}

// Função para registrar um novo voo entre dois aeroportos
void registrarVoo(int idVoo, char partida[], char chegada[]) {
    int i = encontrarIndice(partida);
    int j = encontrarIndice(chegada);
    if (i != -1 && j != -1) {
        voos[i][j] = idVoo;
    } else {
        printf("Erro: aeroporto inexistente.\n");
    }
}

// Função para remover um voo existente com base no número
void excluirVoo(int idVoo) {
    for (int i = 0; i < totalCadastrados; i++) {
        for (int j = 0; j < totalCadastrados; j++) {
            if (voos[i][j] == idVoo) {
                voos[i][j] = 0;
                printf("Voo %d apagado.\n", idVoo);
                return;
            }
        }
    }
    printf("Voo %d não localizado.\n", idVoo);
}

// Função que exibe todos os voos partindo de um aeroporto específico
void mostrarVoosDe(char partida[]) {
    int i = encontrarIndice(partida);
    if (i == -1) {
        printf("Aeroporto não localizado.\n");
        return;
    }

    printf("Voos com saída de %s:\n", partida);
    for (int j = 0; j < totalCadastrados; j++) {
        if (voos[i][j] != 0) {
            printf("Voo %d até %s\n", voos[i][j], codigosAero[j]);
        }
    }
}

// Função recursiva para percorrer rotas possíveis com busca em profundidade
void explorarRotas(int atual, int destino, int visitado[], char percurso[]) {
    visitado[atual] = 1;
    strcat(percurso, codigosAero[atual]);
    strcat(percurso, " -> ");

    if (atual == destino) {
        printf("Rota encontrada: %sFIM\n", percurso);
        return;
    }

    for (int j = 0; j < totalCadastrados; j++) {
        if (voos[atual][j] != 0 && !visitado[j]) {
            char novoPercurso[500];
            strcpy(novoPercurso, percurso);
            explorarRotas(j, destino, visitado, novoPercurso);
        }
    }
    visitado[atual] = 0;
}

// Função para iniciar a busca de rotas entre dois aeroportos
void encontrarRotas(char origem[], char destino[]) {
    int i = encontrarIndice(origem);
    int j = encontrarIndice(destino);
    if (i == -1 || j == -1) {
        printf("Aeroporto inexistente.\n");
        return;
    }
    int visitado[LIMITE] = {0};
    char percurso[500] = "";
    printf("Rotas possíveis de %s até %s:\n", origem, destino);
    explorarRotas(i, j, visitado, percurso);
}

int main() {
    int escolha, idVoo;
    char partida[4], chegada[4];

    // Inserção inicial de alguns aeroportos no sistema
    adicionarAeroporto("CNF");
    adicionarAeroporto("GIG");
    adicionarAeroporto("GRU");
    adicionarAeroporto("SSA");
    adicionarAeroporto("BSB");

    while (1) {
        printf("\n MENU PRINCIPAL \n");
        printf("1. Adicionar aeroporto\n");
        printf("2. Registrar voo\n");
        printf("3. Excluir voo\n");
        printf("4. Mostrar voos de um aeroporto\n");
        printf("5. Encontrar rotas entre aeroportos\n");
        printf("0. Encerrar\n");
        printf("Selecione: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Sigla do aeroporto (ex: CNF): ");
                scanf("%s", partida);
                adicionarAeroporto(partida);
                break;
            case 2:
                printf("Código do voo: ");
                scanf("%d", &idVoo);
                printf("Partida: ");
                scanf("%s", partida);
                printf("Chegada: ");
                scanf("%s", chegada);
                registrarVoo(idVoo, partida, chegada);
                break;
            case 3:
                printf("Código do voo a excluir: ");
                scanf("%d", &idVoo);
                excluirVoo(idVoo);
                break;
            case 4:
                printf("Sigla do aeroporto de origem: ");
                scanf("%s", partida);
                mostrarVoosDe(partida);
                break;
            case 5:
                printf("Origem: ");
                scanf("%s", partida);
                printf("Destino: ");
                scanf("%s", chegada);
                encontrarRotas(partida, chegada);
                break;
            case 0:
                return 0;
            default:
                printf("Escolha inválida.\n");
        }
    }
    return 0;
} 