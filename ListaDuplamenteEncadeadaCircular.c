#include <stdio.h>
#include <stdlib.h>


struct No{ // Declaracao dos ponteiros, e da variavel numero, dentro da struct no
    int numero;
    struct No *anterior;
    struct No *proximo;
};

typedef struct No no;

no* inserirFinal (no** cabeca, no** rabo, int numero) { // Funcao que adiciona o elemento no final da lista
    struct No* novoNo = (no*) malloc(sizeof(struct No)); // Cria o espaco na memoria para armazenar a lista

    novoNo->numero = numero;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (*cabeca == NULL) // Verifica se a lista esta vazia e adiciona o primeiro elemento
    {
        *cabeca = novoNo;
        *rabo = novoNo;
    }
    else // Apos adicionar o primeiro elemento, sao adicionados os novos elementos no final da lista.
    {
        novoNo->proximo = *cabeca;
        novoNo->anterior = *rabo;
        (*rabo)->proximo = novoNo;
        (*cabeca)->anterior = novoNo;

        *rabo = novoNo; // O ponteiro rabo (que aponta para o fim da lista) recebe o valor do novoNo (que passa a ser o novo fim da lista)
    }

    return novoNo;
}

no* inserirInicio (no** cabeca, no** rabo, int numero) { // Funcao que adiciona o elemento no inicio da lista
    struct No *novoNo = (no*) malloc(sizeof(struct No)); // Cria o espaco na memoria para armazenar a lista

    novoNo->numero = numero;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (*cabeca == NULL) // Verifica se a lista esta vazia e adiciona o primeiro elemento
    {
        *cabeca = novoNo;
        *rabo = novoNo;
    }
    else // Apos adicionar o primeiro elemento, sao adicionados os novos elementos no incio da lista.
    {
        novoNo->anterior = *rabo;
        novoNo->proximo = *cabeca;
        (*cabeca)->anterior = novoNo;
        (*rabo)->proximo = novoNo;

        *cabeca = novoNo; // O ponteiro cabeca (que aponta para o inicio da lista) recebe o valor do novoNo (que passa a ser o novo inicio da lista)
    }

    return novoNo;
}

void buscar (no* cabeca, no* rabo, int numero) { // Funcao que realiza a busca do elemento desejado por toda a lista
    struct No *ponteiro = cabeca;
    int index = 1, flag = 0;

    if (cabeca == NULL) // Operador que faz a conferencia se a lista esta vazia ou nao.
    {
        printf("****************************\n");
        printf("* A lista esta vazia.      *\n");
        printf("****************************\n");
    }
    else // Caso a lista nao esteja vazia:
    {
        do { // Funcao que realiza a busca do numero desejado na lista ate ponteiro (buscador) ser igual a NULL.
            if (ponteiro->numero == numero)
            {
                printf("O numero %d esta na posicao %d\n", ponteiro->numero, index);
                flag = 1;
            }
            ponteiro = ponteiro->proximo;

            index++;
        } while (ponteiro != NULL);


        if (flag == 0)
        {
            printf("****************************\n");
            printf("* Numero invalido.         *\n");
            printf("****************************\n");
        }
    }
}

void remover (no* cabeca, no* rabo, int numero) { // Funcao que remove um elemento desejado da lista

    if (cabeca == NULL) // Operador que faz a conferencia se a lista esta vazia ou nao.
    {
        printf("****************************\n");
        printf("* A lista esta vazia.      *\n");
        printf("****************************\n");
    }
    else // Caso a lista nao esteja vazia:
    {
        no* apagar = cabeca;
        int encontrado = 0;

        if (apagar->numero == numero)
        {
            if (apagar->proximo == cabeca)
            {
                cabeca = NULL;
                rabo = NULL;
            }
            else
            {
              cabeca = rabo;
              cabeca->proximo = cabeca;
              cabeca->anterior = cabeca;
              rabo->proximo = rabo;
              rabo->anterior = rabo;

            }
            encontrado = 1;
        }
        else if (rabo->numero == numero)
        {
            apagar = rabo;

            rabo = rabo->anterior;
            rabo->proximo = cabeca;
            cabeca->anterior = rabo;

            encontrado = 1;
        }
        else
        {
            no* ponteiro = cabeca;

            while(1)
            {
                if (ponteiro->proximo->numero == numero)
                {
                    apagar = ponteiro->proximo;
                    ponteiro->proximo = ponteiro->proximo->proximo;
                    ponteiro->proximo->anterior = ponteiro;

                    encontrado = 1;
                    break;
                }
                ponteiro = ponteiro->proximo;

                if (ponteiro == cabeca)
                {
                    break;
                }
            }

        }
        if (encontrado == 1) // Condicao onde o numero desejado foi encontrado dentro da lista
        {
            free(apagar); //Espaco de memoria e liberado
            printf("****************************\n");
            printf("* Removido com sucesso.    *\n");
            printf("****************************\n");
        }
        else // Caso a operacao de removao nao tenha sido executada
        {
            printf("****************************\n");
            printf("* Numero nao encontrado.   *\n");
            printf("****************************\n");
        }
    }
}

void imprimir (no** cabeca, no** rabo, int sentido) { // Funcao que imprime a lista (em ambos sentidos)
    struct No *ponteiro;

    if (*cabeca == NULL) // Operador que faz a conferencia se a lista esta vazia ou nao.
    {
        printf("****************************\n");
        printf("* A lista esta vazia.      *\n");
        printf("****************************\n");

    }
    else // Caso a lista nao esteja vazia:
    {

        printf("[ ");

        if (sentido == 1) { // Faz a operacao de acordo com o sentido de impressao desejado (nesse caso, direita)
            ponteiro = *cabeca;
        }
        else // Faz a operacao de acordo com o sentido de impressao desejado (nesse caso, esquerda)
        {
            ponteiro = *rabo;
        }
        while (ponteiro != NULL) // Enquanto buscador for diferente de NULL, ele realiza a impressao da lista no sentido desejado
        {
            printf("%d ", ponteiro->numero);
            if (sentido == 1) // Impressao para direita
            {
                ponteiro = ponteiro->proximo;

                if (ponteiro == *cabeca)
                {
                    break;
                }
            }
            else // Impressao para esquerda
            {
                ponteiro = ponteiro->anterior;

                if (ponteiro == *rabo)
                {
                    break;
                }
            }
        }

        printf("]\n");
    }
}
