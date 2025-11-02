//
// Created by Matheus Barreto on 31/10/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes globais
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

// Definição de livro
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; //1 para sim, 0 para não
};

struct Emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função principal
int main() {
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    //Laço principal do menu
    do {
        printf("Biblioteca - PT 1\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar empréstimo\n");
        printf("4 - Listar todos os empréstimos\n");
        printf("0 - Sair\n");
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

            case 3:
                printf("Realizar empréstimo\n");
                if (totalEmprestimos >= MAX_EMPRESTIMOS) {
                    printf("Limite de emprestimos atingido.\n");
                } else {
                    printf("Livros disponiveis:\n");
                    int disponiveis = 0;
                    for (int i = 0; i < totalLivros; i++) {
                        if (biblioteca[i].disponivel) {
                            printf("%d - %s", i + 1, biblioteca[i].nome);
                            disponiveis++;
                        }
                    }

                    if (disponiveis == 0) {
                        printf("Nenhum livro para emprestimo disponivel\n");
                    } else {
                        printf("\nDigite o numero do livro que deja emprestar:");
                        int numLivro;
                        scanf("%d", &numLivro);
                        limparBufferEntrada();

                        int indice = numLivro - 1;
                        if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                            printf("Digite o nome do usuário que está pegando o livro: ");
                            fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[totalEmprestimos].nomeUsuario[strcspn(
                                emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                            emprestimos[totalEmprestimos].indiceLivro = indice;
                            biblioteca[indice].disponivel = 0;

                            totalEmprestimos++;
                            printf("\nLivro emprestado com sucesso!\n");
                        } else {
                            printf("\nNumero de livro inválido ou livro indisponível.\n");
                        }
                    }
                }
                printf("Pressione enter para continuar");
                getchar();
                break;

            case 4:
                printf("Lista de empréstimos\n");

                if (totalEmprestimos == 0) {
                    printf("Nenhum empréstimo realizado.\n");
                } else {
                    for (int i = 0; i < totalEmprestimos; i++) {
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("---------------------\n");
                        printf("EMPRÉSTIMO %d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
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

    free(emprestimos);
    free(biblioteca);

    printf("Memória liberada com sucesso.\n");

    return 0;
}
