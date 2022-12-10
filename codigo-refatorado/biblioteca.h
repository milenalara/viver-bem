#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// STRUCTS
struct TDataHora
{
  int hora;
  int minuto;
  int dia;
  int mes;
  int ano;
};
typedef struct TDataHora dataHora;

struct Tpaciente
{
  int codigo;
  char nome[100];
  char telefone[20];
  char endereco[200];
  char dataNascimento[10];
};
typedef struct Tpaciente paciente;

struct Tmedico
{
  int codigo;
  char nome[40];
  char telefone[20];
  char especialidade[20];
};
typedef struct Tmedico medico;

struct Tconsulta
{
  int codigoPaciente;
  int codigoMedico;
  int codigoConsulta;
  dataHora data;
};
typedef struct Tconsulta consulta;

// M�TODOS DO SISTEMA

void menuPrincipal()
{
  printf("\n-----------MENU PRINCIPAL-----------\n");
  printf("Digite o c�digo do programa que deseja executar\n");
  printf("OU digite 0 para ver as op��es de programas\n");
  printf("OU digite -1 para sair\n");
}

void menuProgramas()
{
  printf("\n-----------MENU PROGRAMAS-----------\n");
  printf("\nDigite uma das op��es abaixo:\n");

  printf("\nPACIENTE\n");
  printf("1 - Cadastrar paciente\n");
  printf("2 - Alterar paciente\n");
  printf("3 - Imprimir todos os pacientes\n");

  printf("\nM�DICO\n");
  printf("4 - Cadastrar m�dico\n");
  printf("5 - Alterar m�dico\n");
  printf("6 - Imprimir todos os m�dicos\n");

  printf("\nCONSULTA\n");
  printf("7 - Cadastrar consulta\n");
  printf("8 - Alterar consulta\n");
  printf("9 - Imprimir todas as consultas\n");
}

// M�TODOS DE PACIENTE

int localizaPaciente(FILE *fPacientes, int codigoPaciente)
{
  int posicao = -1, achou = 0;
  paciente pac;
  fseek(fPacientes, 0, SEEK_SET);
  fread(&pac, sizeof(pac), 1, fPacientes);
  while (!feof(fPacientes) && !achou)
  {
    posicao++;
    if (pac.codigo == codigoPaciente)
    {
      achou = 1;
    }
    fread(&pac, sizeof(pac), 1, fPacientes);
  }
  if (achou)
  {
    return posicao;
  }
  else
  {
    return -1;
  }
}

void cadastraPaciente(FILE *fPacientes)
{
  paciente pac;
  int posicao, codigo;

  codigo = 1000;
  posicao = localizaPaciente(fPacientes, codigo);

  while (posicao != -1)
  {
    codigo++;
    posicao = localizaPaciente(fPacientes, codigo);
  }

  pac.codigo = codigo;

  printf("Informe o nome do paciente:\n");
  fflush(stdin);
  gets(pac.nome);

  printf("Informe o telefone(Formato: (00)00000-0000):\n");
  fflush(stdin);
  gets(pac.telefone);

  printf("Informe o endere�o (Formato: Logradouro, numero, bairro, cidade):\n");
  fflush(stdin);
  gets(pac.endereco);

  printf("Informe a data de nascimento (Formato: DD/MM/AAAA):\n");
  fflush(stdin);
  gets(pac.dataNascimento);

  fseek(fPacientes, 0, SEEK_END);
  fwrite(&pac, sizeof(pac), 1, fPacientes);
  fflush(fPacientes);
}

void alteraPaciente(FILE *fPaciente)
{
  int codigo, posicao;
  paciente pac;
  printf("Informe o c�digo do paciente para altera��o de registro:\n");
  fflush(stdin);
  scanf("%i", &codigo);

  posicao = localizaPaciente(fPaciente, codigo);

  if (posicao != -1)
  {
    fseek(fPaciente, sizeof(pac) * (posicao), SEEK_SET);
    fread(&pac, sizeof(pac), 1, fPaciente);

    printf("Informe o nome atualizado:\n");
    fflush(stdin);
    gets(pac.nome);

    printf("Informe o telefone atualizado, com DDD sem 0 na frente:\n");
    fflush(stdin);
    scanf("%", pac.telefone);

    printf("Informe o endere�o atualizado no formato (Logradouro), (numero), (bairro), (cidade):\n");
    fflush(stdin);
    gets(pac.endereco);

    printf("Informe a data de nascimento atualizada no formato DD/MM/AAAA:\n");
    fflush(stdin);
    gets(pac.dataNascimento);

    fseek(fPaciente, sizeof(pac) * (posicao), SEEK_SET);
    fwrite(&pac, sizeof(pac), 1, fPaciente);
    fflush(fPaciente);
  }
  else
  {
    printf("c�digo n�o encontrado.\n");
  }
}

void imprimePacientes(FILE *fPacientes)
{
  paciente pac;
  fseek(fPacientes, 0, SEEK_SET);
  fread(&pac, sizeof(pac), 1, fPacientes);
  while (!feof(fPacientes))
  {
    printf("\n\n");
    printf("C�digo: %i\n", pac.codigo);
    printf("Nome: %s\n", pac.nome);
    printf("Telefone: %s\n", pac.telefone);
    printf("Endere�o: %s\n", pac.endereco);
    printf("Data de nascimento: %s\n", pac.dataNascimento);

    fread(&pac, sizeof(pac), 1, fPacientes);
  }
}

// M�TODOS DE M�DICO

int localizaMedico(FILE *fMedicos, int codigoMedico)
{
  int posicao = -1, achou = 0;
  medico med;
  fseek(fMedicos, 0, SEEK_SET);
  fread(&med, sizeof(med), 1, fMedicos);
  while (!feof(fMedicos) && !achou)
  {
    posicao++;
    if (med.codigo == codigoMedico)
    {
      achou = 1;
    }
    fread(&med, sizeof(med), 1, fMedicos);
  }
  if (achou)
  {
    return posicao;
  }
  else
  {
    return -1;
  }
}

void cadastraMedico(FILE *fMedicos)
{
  medico med;
  int posicao, codigo;

  codigo = 2000;
  posicao = localizaMedico(fMedicos, codigo);

  while (posicao != -1)
  {
    codigo++;
    posicao = localizaMedico(fMedicos, codigo);
  }

  med.codigo = codigo;

  printf("Informe o nome do m�dico:\n");
  fflush(stdin);
  gets(med.nome);

  printf("Informe a especialidade:\n");
  fflush(stdin);
  gets(med.especialidade);

  printf("Informe o telefone com DDD sem 0 na frente:\n");
  fflush(stdin);
  gets(med.telefone);

  fseek(fMedicos, 0, SEEK_END);
  fwrite(&med, sizeof(med), 1, fMedicos);
  fflush(fMedicos);
}

void alteraMedico(FILE *fMedicos)
{
  int codigo, posicao;
  medico med;
  printf("Informe o c�digo do m�dico para altera��o de registro:\n");
  fflush(stdin);
  scanf("%i", &codigo);

  posicao = localizaMedico(fMedicos, codigo);

  if (posicao != -1)
  {
    fseek(fMedicos, sizeof(med) * (posicao), SEEK_SET);
    fread(&med, sizeof(med), 1, fMedicos);

    printf("Informe o nome atualizado:\n");
    fflush(stdin);
    gets(med.nome);

    printf("Informe o telefone atualizado, com DDD sem 0 na frente:\n");
    fflush(stdin);
    scanf("%", med.telefone);

    fseek(fMedicos, sizeof(med) * (posicao), SEEK_SET);
    fwrite(&med, sizeof(med), 1, fMedicos);
    fflush(fMedicos);
  }
  else
  {
    printf("c�digo n�o encontrado.\n");
  }
}

void imprimeMedicos(FILE *fMedicos)
{
  medico med;
  fseek(fMedicos, 0, SEEK_SET);
  fread(&med, sizeof(med), 1, fMedicos);
  while (!feof(fMedicos))
  {
    printf("\n\n");
    printf("C�digo: %d\n", med.codigo);
    printf("Nome: %s\n", med.nome);
    printf("Telefone: %s\n", med.telefone);
    printf("Especialidade: %s\n", med.especialidade);

    fread(&med, sizeof(med), 1, fMedicos);
  }
}

// M�TODOS DE CONSULTA

int localizaConsulta(FILE *fConsultas, int codigoConsulta)
{
  int posicao = -1, achou = 0;
  consulta cons;
  fseek(fConsultas, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  while (!feof(fConsultas) && !achou)
  {
    posicao++;
    if (cons.codigoConsulta == codigoConsulta)
    {
      achou = 1;
    }
    fread(&cons, sizeof(cons), 1, fConsultas);
  }
  if (achou)
  {
    return posicao;
  }
  else
  {
    return -1;
  }
}

int localizaConsultasMedico(FILE *fConsultas, int codigoMedico, int dia, int mes, int ano)
{
  int posicao = -1, achou = 0;
  consulta cons;
  fseek(fConsultas, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  while (!feof(fConsultas) && !achou)
  {
    posicao++;
    if (cons.codigoMedico == codigoMedico && cons.data.dia == dia && cons.data.mes == mes && cons.data.ano == ano)
    {
      achou = 1;
    }
    fread(&cons, sizeof(cons), 1, fConsultas);
  }
  if (achou)
  {
    return posicao;
  }
  else
  {
    return -1;
  }
}

int localizaQtdConsultasMedico(FILE *fConsultas, int codigoMedico, int dia, int mes, int ano)
{
  int achou = 0;
  consulta cons;
  fseek(fConsultas, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  while (!feof(fConsultas))
  {

    if (cons.codigoMedico == codigoMedico && cons.data.dia == dia && cons.data.mes == mes && cons.data.ano == ano)
    {
      achou++;
    }
    fread(&cons, sizeof(cons), 1, fConsultas);
  }
  return achou;
}

void cadastraConsulta(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas)
{
  consulta cons, consAux;
  int posicao, codigo, diferencaHoras, controleHora = 0, controleData = 0, controleQtd = 0;

  codigo = 3000;
  posicao = localizaConsulta(fConsultas, codigo);

  while (posicao != -1)
  {
    codigo++;
    posicao = localizaConsulta(fConsultas, codigo);
  }

  cons.codigoConsulta = codigo;

  // variaveis de controle
  cons.data.minuto = -1;
  cons.data.hora = -1;
  cons.data.dia = -1;
  cons.data.mes = -1;
  cons.data.ano = -1;

  do
  {
    printf("Informe o c�digo do m�dico:\n");
    fflush(stdin);
    scanf("%d", &cons.codigoMedico);

  } while (localizaMedico(fMedicos, cons.codigoMedico) == -1);

  do
  {
    printf("Informe o c�digo do paciente:\n");
    fflush(stdin);
    scanf("%d", &cons.codigoPaciente);
  } while (localizaPaciente(fPacientes, cons.codigoPaciente) == -1);

  do
  {
    do
    {
      printf("Informe a data da consulta (DD/MM/AAAA):\n");
      fflush(stdin);
      scanf("%d/%d/%d", &cons.data.dia, &cons.data.mes, &cons.data.ano);
      if (localizaQtdConsultasMedico(fConsultas, cons.codigoMedico, cons.data.dia, cons.data.mes, cons.data.ano) >= 2)
      {
        printf("\nEste m�dico j� possui 2 consultas nesta data, favor escolher outra data\n");
        controleData = 1;
      }
      else
        controleData = 0;
      // printf("%d\n%d\n%d\n",agendamento.data.dia,agendamento.data.mes,agendamento.data.ano);
    } while (cons.data.dia < 1 || cons.data.dia > 31 || cons.data.mes < 1 || cons.data.mes > 12 || cons.data.ano < 2000 || cons.data.ano > 2100 || controleData);
    // printf("%d", localizaQtdConsulta(arqconsulta,agendamento.codigoMedico,agendamento.data.dia,agendamento.data.mes,agendamento.data.ano));
    do
    {
      printf("\nInforme o hor�rio da consulta, entre 7:00 - 21:00 (HH:MM):\n");
      fflush(stdin);
      scanf("%d:%d", &cons.data.hora, &cons.data.minuto);
      // printf("%d\n%d\n",agendamento.data.hora,agendamento.data.minuto);
    } while (cons.data.hora < 7 || cons.data.hora > 21 || cons.data.minuto < 0 || cons.data.minuto > 60);

    int posicaoMed = localizaConsultasMedico(fConsultas, cons.codigoMedico, cons.data.dia, cons.data.mes, cons.data.ano);

    if (posicaoMed != -1)
    {
      // printf("\nDENTRO DO IF POSICAO=%d",posicaoMed);
      fseek(fConsultas, sizeof(consAux) * (posicaoMed), SEEK_SET);
      fread(&consAux, sizeof(consAux), 1, fConsultas);

      if (consAux.data.ano == cons.data.ano && consAux.data.dia == cons.data.dia && consAux.data.mes == cons.data.mes)
      {
        diferencaHoras = abs((((consAux.data.hora * 60) + consAux.data.minuto) - ((cons.data.hora * 60) + cons.data.minuto)));
        printf("\nDiferenca%d", diferencaHoras);
        if ((diferencaHoras) < 30)
        {
          printf("\nDiferen�a menor do que 30 minutos da consulta: %02d:%02d", consAux.data.hora, consAux.data.minuto);
          controleHora = 1;
        }
        else
          controleHora = 0;
      }
      else
        controleHora = 0;
    }
    else
      controleHora = 0;
  } while (controleHora);

  fseek(fConsultas, 0, SEEK_END);
  fwrite(&cons, sizeof(cons), 1, fConsultas);
}

void imprimeConsultas(FILE *fConsultas)
{
  consulta cons;
  fseek(fConsultas, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  while (!feof(fConsultas))
  {
    printf("\n");
    printf("C�digo da consulta: %d\n", cons.codigoConsulta);
    printf("C�digo do m�dico: %d\n", cons.codigoMedico);
    printf("Codigo do paciente: %d\n", cons.codigoPaciente);
    printf("Data: %02d/%02d/%04d\n", cons.data.dia, cons.data.mes, cons.data.ano);
    printf("Horario: %02d:%02d\n", cons.data.hora, cons.data.minuto);
    fread(&cons, sizeof(cons), 1, fConsultas);
  }
}

#endif // BIBLIOTECA_H_INCLUDED