#include <stdio.h>  // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaços na memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuida das string.

int registro() // funcao responsavel por cadastrar o usuario;
{
  setlocale(LC_ALL, "Portuguese");
//inicio criação de variaveis.
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
//final criação de variaveis.

  printf("Digite o CPF a ser cadastrado");//coletando informações do usuario
  scanf("%s", cpf);

  strcpy(arquivo, cpf);//responsavel por copiar os valores da string

  FILE *file;                 // cria o arquivo
  file = fopen(arquivo, "w"); // w para escrever 
  fprintf(file, cpf);//salva o valor da variavel
  fclose(file);//fecha o arquivo;

  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);

  printf("Digite o nome a ser cadastrado: ");
  scanf("%s", nome); // %s refere-se a string

  file = fopen(arquivo, "a");
  fprintf(file, nome);
  fclose(file);

  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);

  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s", sobrenome);

  file = fopen(arquivo, "a");
  fprintf(file, sobrenome);
  fclose(file);

  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);

  printf("Digite o cargo a ser cadastrado: ");
  scanf("%s", cargo);

  file = fopen(arquivo, "a");
  fprintf(file, cargo);
  fclose(file);

  getchar(); // pausa até que o usuário pressione Enter
}
int consulta()
{
  setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

  char cpf[40];
  char conteudo[200];

  printf("Digite o CPF a ser consultado: ");
  scanf("%s", cpf);

  FILE *file;
  file = fopen(cpf, "r");// r para ler 

  if (file == NULL)
  {
    printf("Não foi possivel abrir o arquivo, não localizado!.\n");
  }

  while (fgets(conteudo, 200, file) != NULL)
  {
    printf("\nEssas são as informações do usuário: ");
    printf("%s", conteudo);
    printf("\n\n");
  }


  getchar(); // pausa até que o usuário pressione Enter
}

int deletar()
{
  char cpf[40];
  printf("Digite o CPf a ser deletado: ");
  scanf("%s", cpf); 

  remove(cpf);

  FILE * file;
  file = fopen(cpf, "r");

  if (remove(cpf) == 0) {
        printf("Usuário removido com sucesso!\n");
    } else {
        printf("Não foi possível remover o usuário ou o usuário não encontrado!\n");
    }

    getchar(); // pausa até que o usuário pressione Enter
}

int main()
{
  int opcao = 0;
  int laco = 1;

  for (laco = 1; laco == 1;)
  {
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    printf("### Cartório da EBAC ###\n\n");
    printf("Escolha a opção desejada do menu: \n\n");
    printf("\t 1 - Registrar nomes \n");
    printf("\t 2 - Consultar nomes \n");
    printf("\t 3 - Deletar  nomes \n\n");

    scanf("%d", &opcao);
    system("cls");

    switch (opcao)
    {
    case 1:
      registro();
      break;

    case 2:
      consulta();
      break;

    case 3:
      deletar();
      break;

    default:
      printf("Esta opção não está disponível\n");
      system("pause");
      break;
    };
  }

  printf("\t Este software é de livre uso pelos alunos \n");

  return 0;
}
