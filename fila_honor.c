#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    struct Aluno *proximo;
} Aluno;

void enfileiraAluno(int matricula, Aluno **comeco, Aluno **fim) {
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro de alocação do nó.\n");
    } else {
        novo->matricula = matricula;
        novo->proximo = NULL;
        if (*comeco == NULL) {
            *comeco = novo;
        } else {
            (*fim)->proximo = novo;
        }
        *fim = novo;
    }
}

int desenfileiraAluno(Aluno **comeco, Aluno **fim) {
    Aluno *auxiliar = *comeco;
    int matricula;
    if (auxiliar != NULL) {
        *comeco = auxiliar->proximo;
        matricula = auxiliar->matricula;
        auxiliar->proximo = NULL;
        free(auxiliar);
        if (*comeco == NULL) {
            *fim = NULL;
        }
        return matricula;
    } else {
        printf("Fila vazia\n");
        return -1;
    }
}

void imprimeFilaAlunos(Aluno **comeco) {
    Aluno *aluno = *comeco;
    if (aluno != NULL) {
        while (aluno != NULL) {
            printf("Matricula: %d\n", aluno->matricula);
            aluno = aluno->proximo;
        }
    } else {
        printf("Fila vazia\n");
    }
}

int main() {
    Aluno *comeco = NULL;
    Aluno *fim = NULL;
    int opcao, matricula;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Adicionar aluno na fila\n");
        printf("2. Atender próximo aluno\n");
        printf("3. Imprimir fila de alunos\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                enfileiraAluno(matricula, &comeco, &fim);
                printf("Aluno adicionado na fila.\n");
                break;
            case 2: {
                int alunoMatricula = desenfileiraAluno(&comeco, &fim);
                if (alunoMatricula != -1) {
                    printf("Aluno com matricula %d atendido.\n", alunoMatricula);
                } else {
                    printf("Sem aluno para atender.\n");
                }
                break;
            }
            case 3:
                imprimeFilaAlunos(&comeco);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 4);

    return 0;
}