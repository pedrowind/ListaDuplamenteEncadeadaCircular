#include "stdio.h"
#include "ListaDuplamenteEncadeadaCircular.c"

int main () {
    struct no *cabeca = NULL;
    struct no *rabo = NULL;

    int numero, operador;

    do
    {
        printf("*****************************************\n");
        printf("** Lista Duplamente Encadeada Circular **\n");
        printf("*****************************************\n");
        printf("\n");

        printf("****************************\n");
        printf("* 1- Inserir Inicio        *\n");
        printf("* 2- Inserir Final         *\n");
        printf("* 3- Buscar                *\n");
        printf("* 4- Imprimir              *\n");
        printf("* 5- Remover               *\n");
        printf("* 6- Saida                 *\n");
        printf("****************************\n");
        printf("\n");

        printf("* Insira a opcao desejada: *\n");
        scanf("%d", &operador);

        system("cls");

        switch (operador) {
            case 1: //Insercao no inicio.
                printf("****************************\n");
                printf(" Numero a ser inserido:    *\n");
                scanf("%d", &numero);
                inserirInicio(&cabeca, &rabo, numero);
                system("cls");
                printf("****************************\n");
                printf("* Valor inserido.          *\n");
                printf("****************************\n");

                system("pause");
                system("cls");
                break;

            case 2: // Insercao no final.
                printf("****************************\n");
                printf("* Numero a ser inserido:   *\n");
                scanf("%d", &numero);
                inserirFinal(&cabeca, &rabo, numero);
                system("cls");
                printf("****************************\n");
                printf("* Valor inserido.          *\n");
                printf("****************************\n");

                system("pause");
                system("cls");
                break;

            case 3: // Buscar numero desejado na lista.
                printf("****************************\n");
                printf("* Numero a ser buscado:    *\n");
                scanf("%d", &numero);
                printf("****************************\n");
                buscar(cabeca, rabo, numero);
                printf("****************************\n");

                system("pause");
                system("cls");
                break;

            case 4: // Imprimir o numero desejado.
                do
                {
                    printf("****************************\n");
                    printf("* Imprimir a lista.        *\n");
                    printf("****************************\n");
                    printf("* 1- Direita               *\n");
                    printf("* 2- Esquerda              *\n");
                    printf("* 3- Sair                  *\n");
                    printf("****************************\n");

                    printf("* Insira a opcao desejada: *\n");
                    scanf("%d", &operador);
                    printf("****************************\n");

                    switch (operador)
                    {
                        case 1: //Imprimir a lista comecando pela direita.
                            imprimir(&cabeca, &rabo, 1);
                            break;

                        case 2: // Imprimir a lista comecando pela esquerda
                            imprimir(&cabeca, &rabo, 2);
                            break;

                        case 3:
                            printf("****************************\n");
                            printf("* Saida efetuada.          *\n");
                            printf("****************************\n");
                    }
                    system ("pause");
                    system("cls");

                } while (operador != 3);
                    break;

            case 5: // Remover o numero desejado.
                if (cabeca == NULL)
                {
                    printf("****************************\n");
                    printf("* A lista esta vazia.      *\n");
                    printf("****************************\n");
                }
                else
                {
                    printf("****************************\n");
                    printf("* Numero a ser removido.   *\n");
                    scanf("%d", &numero);
                    remover(cabeca, rabo, numero);
                }
                system("pause");
                system("cls");
                break;

            case 6: // Saida do codigo.
                printf("****************************\n");
                printf("** Operacoes finalizadas. **\n");
                printf("****************************\n");
                break;

            default: // Caso em que a opcao inserida pelo usuario nao existe.
                printf("****************************\n");
                printf("* Operacao invalida.       *\n");
                printf("****************************\n");

                system("pause");
                system("cls");
                break;
        }
    } while (operador !=6);

    return 0;
}
