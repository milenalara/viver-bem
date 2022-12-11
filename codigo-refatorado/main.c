#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "biblioteca.h"

// MÉTODOS DO SISTEMA
void menuPrincipal();
void menuProgramas();

// MÉTODOS DE PACIENTE
void cadastraPaciente(FILE *fPacientes);
void alteraPaciente(FILE *fPaciente);
void imprimePacientes(FILE *fPacientes);

// MÉTODOS DE MÉDICO
void cadastraMedico(FILE *fMedicos);
void alteraMedico(FILE *fMedicos);
void imprimeMedicos(FILE *fMedicos);
void calculaPagamentoMedico(FILE *fConsultas);

// MÉTODOS DE CONSULTA
void cadastraConsulta(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);
void alteraConsulta(FILE *fConsultas);
void cancelaConsulta(FILE *fConsultas);
void imprimeConsultas(FILE *fConsultas);
void imprimeConsultasPorData(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);
void imprimeConsultasPorMedico(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);
void imprimeConsultasPorPaciente(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);

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
      printf("Erro na criação do arquivo pacientes.dat\n");
      exit(1);
    }
  }

  if ((fMedicos = fopen("medicos.dat", "r+b")) == NULL)
  {
    printf("Arquivo medicos.dat criado com sucesso\n");
    if ((fMedicos = fopen("medicos.dat", "w+b")) == NULL)
    {
      printf("Erro na criação do arquivo medicos.dat\n");
      exit(1);
    }
  }

  if ((fConsultas = fopen("consultas.dat", "r+b")) == NULL)
  {
    printf("Arquivo consultas.dat criado com sucesso\n");
    if ((fConsultas = fopen("consultas.dat", "w+b")) == NULL)
    {
      printf("Erro na criação do arquivo consultas.dat\n");
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
      calculaPagamentoMedico(fConsultas);
      break;
    case 8:
      cadastraConsulta(fPacientes, fMedicos, fConsultas);
      break;
    case 9:
      break;
      alteraConsulta(fConsultas);
    case 10:
      cancelaConsulta(fConsultas);
      break;
    case 11:
      imprimeConsultas(fConsultas);
      break;
    case 12:
      imprimeConsultasPorData(fPacientes, fMedicos, fConsultas);
      break;
    case 13:
      imprimeConsultasPorMedico(fPacientes, fMedicos, fConsultas);
      break;
    case 14:
      imprimeConsultasPorPaciente(fPacientes, fMedicos, fConsultas);
      break;
    default:
      printf("Programa não encontrado\n");
      break;
    }
  } while (op != -1);

  return 0;
}