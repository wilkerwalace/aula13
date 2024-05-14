#include <stdio.h>
struct Informacoes {
    int idade;
    float altura;
};

int main(){

    struct Informacoes pessoa;

    int dados_carregados = 0;

    int opcao = 0;
    do {
        printf("1 - Carregar dados\n");
        printf("2 - Em desenvolvimento\n");
        printf("3 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite a idade: ");
                FILE *arquivo;
                arquivo = fopen("arquivo.txt", "w");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo\n");
                    return 1;
                }
                scanf("%d", &pessoa.idade);

                printf("Digite a altura: ");
                scanf("%f", &pessoa.altura);
                fprintf(arquivo, "%d\n", pessoa.idade);
                fprintf(arquivo, "%.2f\n", pessoa.altura);
                fwrite(&pessoa, sizeof(struct Informacoes), 1, arquivo);

                fclose(arquivo);
                dados_carregados = 1;
                break;
            case 2:
                if (dados_carregados == 0) {
                    printf("Dados não carregados\n");
                    break;
                }
                break;
            case 3:

                break;
            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 3);

    }