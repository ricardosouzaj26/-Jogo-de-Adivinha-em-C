#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Numero_Secreto 11 // Define o n�mero que o jogador deve adivinhar

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Permite acentua��o e caracteres da l�ngua portuguesa
    FILE *arquivo;                   // Ponteiro para manipula��o de arquivo
    int tentativa = -1;              // Armazena a tentativa do jogador (inicializado para evitar lixo de mem�ria)
    int contador = 0;                // Contador de tentativas
    char vulgo[51];                  // Nome (apelido) do jogador

    // Mensagem inicial do jogo
    printf("Adivinhe o n�mero entre (0 - 100): ");

    // Loop principal � continua at� o jogador acertar o n�mero
    while (tentativa != Numero_Secreto)
    {
        scanf("%d", &tentativa); // L� a tentativa do jogador

        if (tentativa < Numero_Secreto)
        {
            printf("\nO %d � MENOR que o n�mero escolhido\n", tentativa);
        }
        if (tentativa > Numero_Secreto)
        {
            printf("\nO %d � MAIOR que o n�mero escolhido\n", tentativa);
        }

        contador++;
        printf("Tente outro n�mero: ");
    }

    // Limpa o terminal (funciona tanto no Windows quanto no Linux)
    system("clear||cls");

    printf("Parab�ns, voc� acertou em %d tentativas, %d era o n�mero secreto!\n", contador, tentativa);

    // Limpa o buffer de entrada para evitar conflito com fgets()
    getchar();
    printf("Escolha um vulgo para salvar seu score: ");
    fgets(vulgo, sizeof(vulgo), stdin);

    // Remove o caractere '\n' deixado pelo fgets
    vulgo[strcspn(vulgo, "\n")] = 0;

    // Abre o arquivo de resultados no modo "append" (adiciona sem apagar o conte�do anterior)
    arquivo = fopen("resultados.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1; // Encerra o programa caso o arquivo n�o seja aberto corretamente
    }

    // Registra o nome e o n�mero de tentativas no arquivo
    fprintf(arquivo, "%8s - %d tentativas\n", vulgo, contador);
    fclose(arquivo);

    printf("Score salvo com sucesso!\n");

    return 0;
}
