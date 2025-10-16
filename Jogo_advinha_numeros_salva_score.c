#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Numero_Secreto 11 // Define o número que o jogador deve adivinhar

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Permite acentuação e caracteres da língua portuguesa
    FILE *arquivo;                   // Ponteiro para manipulação de arquivo
    int tentativa = -1;              // Armazena a tentativa do jogador (inicializado para evitar lixo de memória)
    int contador = 0;                // Contador de tentativas
    char vulgo[51];                  // Nome (apelido) do jogador

    // Mensagem inicial do jogo
    printf("Adivinhe o número entre (0 - 100): ");

    // Loop principal — continua até o jogador acertar o número
    while (tentativa != Numero_Secreto)
    {
        scanf("%d", &tentativa); // Lê a tentativa do jogador

        if (tentativa < Numero_Secreto)
        {
            printf("\nO %d é MENOR que o número escolhido\n", tentativa);
        }
        if (tentativa > Numero_Secreto)
        {
            printf("\nO %d é MAIOR que o número escolhido\n", tentativa);
        }

        contador++;
        printf("Tente outro número: ");
    }

    // Limpa o terminal (funciona tanto no Windows quanto no Linux)
    system("clear||cls");

    printf("Parabéns, você acertou em %d tentativas, %d era o número secreto!\n", contador, tentativa);

    // Limpa o buffer de entrada para evitar conflito com fgets()
    getchar();
    printf("Escolha um vulgo para salvar seu score: ");
    fgets(vulgo, sizeof(vulgo), stdin);

    // Remove o caractere '\n' deixado pelo fgets
    vulgo[strcspn(vulgo, "\n")] = 0;

    // Abre o arquivo de resultados no modo "append" (adiciona sem apagar o conteúdo anterior)
    arquivo = fopen("resultados.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1; // Encerra o programa caso o arquivo não seja aberto corretamente
    }

    // Registra o nome e o número de tentativas no arquivo
    fprintf(arquivo, "%8s - %d tentativas\n", vulgo, contador);
    fclose(arquivo);

    printf("Score salvo com sucesso!\n");

    return 0;
}
