#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "biblioteca.h"

// M�TODOS DO SISTEMA
void menuPrincipal();
void menuProgramas();

// M�TODOS DE PACIENTE
void cadastraPaciente(FILE *fPacientes);
void alteraPaciente(FILE *fPaciente);
void imprimePacientes(FILE *fPacientes);

// M�TODOS DE M�DICO
void cadastraMedico(FILE *fMedicos);
void alteraMedico(FILE *fMedicos);
void imprimeMedicos(FILE *fMedicos);

// M�TODOS DE CONSULTA
void cadastraConsulta(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);
void imprimeConsultas(FILE *fConsultas);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  FILE *fPacientes, *fMedicos, *fConsultas;

  int op;

  if ((fPacientes = fopen("pacientes.dat", "r+b")) == NULL)
  {
    printf("Arquivo pacientes.dat criado com sucesso\n");
    if ((fPacientes = fopen("pacientes.dat", "w+b")) == NULL)
    {
      printf("Erro na cria��o do arquivo pacientes.dat\n");
      exit(1);
    }
  }

  if ((fMedicos = fopen("medicos.dat", "r+b")) == NULL)
  {
    printf("Arquivo medicos.dat criado com sucesso\n");
    if ((fMedicos = fopen("medicos.dat", "w+b")) == NULL)
    {
      printf("Erro na cria��o do arquivo medicos.dat\n");
      exit(1);
    }
  }

  if ((fConsultas = fopen("consultas.dat", "r+b")) == NULL)
  {
    printf("Arquivo consultas.dat criado com sucesso\n");
    if ((fConsultas = fopen("consultas.dat", "w+b")) == NULL)
    {
      printf("Erro na cria��o do arquivo consultas.dat\n");
      exit(1);
    }
  }

  do
  {
    menuPrincipal();

    fflush(stdin);
    scanf("%i", &op);

    switch (op)
    {
    case -1:
      break;
    case 0:
      menuProgramas();
      break;
    case 1:
      cadastraPaciente(fPacientes);
      break;
    case 2:
      alteraPaciente(fPacientes);
      break;
    case 3:
      imprimePacientes(fPacientes);
      break;
    case 4:
      cadastraMedico(fMedicos);
      break;
    case 5:
      alteraMedico(fMedicos);
      break;
    case 6:
      imprimeMedicos(fMedicos);
      break;
    case 7:
      cadastraConsulta(fPacientes, fMedicos, fConsultas);
      break;
    case 8:
      break;
    case 9:
      imprimeConsultas(fConsultas);
      break;
    case 10:
      break;
    default:
      printf("Programa n�o encontrado\n");
      break;
    }
  } while (op != -1);

  return 0;
}