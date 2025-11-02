//
// Created by Matheus Barreto on 31/10/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100

// Definição de livro
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função principal
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    //Laço principal do menu
    do {
        printf("Biblioteca - PT 1\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção\n");

        //escolha da opção
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                printf("Cadastro de novo livro\n");
                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro\n");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o autor do livro\n");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite o editora do livro\n");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edição\n");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    totalLivros++;

                    printf("\nLivro cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");
                }
                printf("Pressione enter para continuar");
                getchar();
                break;

            case 2:
                printf("Lista de livros cadastrados\n");

                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("---------------------\n");
                        printf("LIVRO %d\n", i + 1);
                        printf("Nome %s\n", biblioteca[i].nome);
                        printf("Autor %s\n", biblioteca[i].autor);
                        printf("Editora %s\n", biblioteca[i].editora);
                        printf("Edição %d\n", biblioteca[i].edicao);
                    }
                    printf("---------------------\n");
                }

                printf("Pressione enter para continuar");
                getchar();
                break;

            case 0:
                printf("\nSaindo do sistema\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                printf("Pressione enter para continuar");
                getchar();
                break;
        }
    } while (opcao != 0);
    return 0;
}
