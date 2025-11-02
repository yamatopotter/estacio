//
// Created by Matheus Barreto on 02/11/25.
//
#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10

// Definição de território
struct Territorio {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
};

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função principal
int main() {
    struct Territorio territorios[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;

    //Laço principal do menu
    do {
        printf("-------- WAR --------\n");
        printf("1 - Cadastrar novo território\n");
        printf("2 - Listar todos os territórios\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção\n");

        //escolha da opção
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            //Inserção de território na lista
            case 1:
                printf("Cadastro de novo território\n");
                if (totalTerritorios < MAX_TERRITORIOS) {
                    printf("Digite o nome do território\n");
                    fgets(territorios[totalTerritorios].nome, TAM_NOME, stdin);

                    printf("Digite a cor do território\n");
                    fgets(territorios[totalTerritorios].cor, TAM_COR, stdin);

                    printf("Digite a quantidade de tropas\n");
                    scanf("%d", &territorios[totalTerritorios].tropas);

                    territorios[totalTerritorios].nome[strcspn(territorios[totalTerritorios].nome, "\n")] = '\0';
                    territorios[totalTerritorios].cor[strcspn(territorios[totalTerritorios].cor, "\n")] = '\0';

                    limparBufferEntrada();

                    totalTerritorios++;

                    printf("\nTerritório cadastrado com sucesso!\n");
                } else {
                    printf("Lista de territórios cheia! Não é possível cadastrar mais territórios.\n");
                }
                printf("Pressione enter para continuar\n");
                getchar();
                break;

            //Listagem de territórios cadastrados
            case 2:
                printf("Lista de territórios cadastrados\n");

                if (totalTerritorios == 0) {
                    printf("Nenhum território cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < totalTerritorios; i++) {
                        printf("---------------------\n");
                        printf("TERRITÓRIO %d\n", i + 1);
                        printf("Nome %s\n", territorios[i].nome);
                        printf("Cor %s\n", territorios[i].cor);
                        printf("Tropas %d\n", territorios[i].tropas);
                    }
                    printf("---------------------\n");
                }

                printf("Pressione enter para continuar\n");
                getchar();
                break;

            //Opção de saida do sistema
            case 0:
                printf("\nSaindo do sistema\n");
                break;

            //Opção caso o usuário escolha a opção errada
            default:
                printf("\nOpcao invalida!\n");
                printf("Pressione enter para continuar");
                getchar();
                break;
        }
    } while (opcao != 0);
    return 0;
}
