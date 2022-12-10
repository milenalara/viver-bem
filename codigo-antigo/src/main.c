#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "biblioteca.h"

void menu();

void cadastraConsulta(FILE *arqmedico, FILE *arqpaciente, FILE *arqconsulta);
void imprime_Consulta(FILE *f);
// void imprimeConsultaPorData(FILE *f, FILE *p, FILE *m);
// void imprimeConsultaPorMedico(FILE *f, FILE *p, FILE *m);
// int localizaConsulta(FILE *f, int codigo);
// int localizaQtdConsulta(FILE *f, int codigo, int dia, int mes, int ano);
// int localizaQtdConsulta(FILE *f, int codigo, int dia, int mes, int ano);
// void excluiConsulta(FILE *f, int codigo);
// void cancelaConsulta(FILE *arqconsulta);

// int localizaMedicoConsulta(FILE *f, int codigo, int dia, int mes, int ano);
// int localizaMedico(FILE *f, int codigo);
void addMedico(FILE *f);
void imprime_Medico(FILE *f);

// int localizaPaciente(FILE *f, int codigo);
void incluiPaciente(FILE *f);
// void alteraPaciente(FILE *f);
void listaPacientes(FILE *f);

int pagamentoMedico(FILE *arqconsulta, FILE *arqmedico, FILE *f);

FILE *fPacientes, *fMedicos, *fConsultas;

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  int op;

  do
  {
    printf("-----------MENU PRINCIPAL-----------\n");
    printf("Digite o código do programa que deseja executar\n");
    printf("OU digite 0 para ver as opções de programas\n");
    printf("OU digite -1 para sair");
    scanf("%i", &op);

    switch (op)
    {
    case -1:
      break;
    case 0:
      menu();
      break;
    case 1:
      incluiPaciente(&fPacientes);
      break;
    case 2:
      addMedico(&fMedicos);
      break;
    case 3:
      cadastraConsulta(&fMedicos, &fPacientes, &fConsultas);
      break;
    case 4:
      listaPacientes(&fPacientes);
      break;
    case 5:
      imprime_Medico(&fMedicos);
      break;
    case 6:
      imprime_Consulta(&fConsultas);
      break;
    default:
      printf("Programa não encontrado\n");
      break;
    }

  } while (op != -1);

  return 0;
}

void menu()
{
  printf("1 - cadastrar um paciente\n");
  printf("2 - cadastrar um médico\n");
  printf("3 - cadastrar uma consulta\n");
  printf("4 - mostra pacientes\n");
  printf("5 - mostra médicos\n");
  printf("6 - mostra consultas\n");
}