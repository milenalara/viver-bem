#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

void chooseProgram(int op);
void menu();
void cadastrarPaciente();
void cadastrarMedico();
void cadastrarConsulta();
void realizarPesquisas();

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  int op;

  void chooseProgram(int op);

  do
  {
    printf("-----------MENU PRINCIPAL-----------\n");
    printf("Digite o código do programa que deseja executar\n");
    printf("OU digite 0 para ver as opções de programas\n");
    printf("OU digite -1 para sair");
    scanf("%i", &op);

    void chooseProgram(int op);
  } while (op != -1);

  return 0;
}

void chooseProgram(int op)
{
  switch (op)
  {
  case -1:
    break;
  case 0:
    menu();
    break;
  case 1:
    cadastrarPaciente();
    break;
  case 2:
    cadastrarMedico();
    break;
  case 3:
    cadastrarConsulta();
    break;
  default:
    printf("Programa não encontrado\n");
    break;
  }
}

void menu()
{
  printf("1 - cadastrar um paciente");
  printf("2 - cadastrar um médico");
  printf("3 - cadastrar uma consulta");
  printf("4 - realizar pesquisas");
}

void cadastrarPaciente()
{
}

void cadastrarMedico()
{
}

void cadastrarConsulta()
{
}

void realizarPesquisas()
{
}