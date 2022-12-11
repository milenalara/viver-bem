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

// MÉTODOS DO SISTEMA

void menuPrincipal()
{
  printf("\n-----------MENU PRINCIPAL-----------\n");
  printf("Digite o código do programa que deseja executar\n");
  printf("OU digite 0 para ver as opções de programas\n");
  printf("OU digite -1 para sair\n");
}

void menuProgramas()
{
  printf("\n-----------MENU PROGRAMAS-----------\n");
  printf("\nDigite uma das opções abaixo:\n");

  printf("\nPACIENTE\n");
  printf("1 - Cadastrar paciente\n");
  printf("2 - Alterar cadastro de paciente\n");
  printf("3 - Exibir lista de pacientes\n");

  printf("\nMÉDICO\n");
  printf("4 - Cadastrar médico\n");
  printf("5 - Alterar cadastro de médico\n");
  printf("6 - Exibir lista de médicos\n");
  printf("7 - Calcular pagamento de um médico\n");

  printf("\nCONSULTA\n");
  printf("8 - Cadastrar consulta\n");
  printf("9 - Alterar dados de consulta\n");
  printf("10 - Cancelar consulta\n");
  printf("11 - Exibir lista de consultas\n");
  printf("12 - Pesquisar consultas por data\n");
  printf("13 - Pesquisar consultas por médico\n");
}

// MÉTODOS DE PACIENTE

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

  printf("Informe o endereço (Formato: Logradouro, numero, bairro, cidade):\n");
  fflush(stdin);
  gets(pac.endereco);

  printf("Informe a data de nascimento (Formato: DD/MM/AAAA):\n");
  fflush(stdin);
  gets(pac.dataNascimento);

  fseek(fPacientes, 0, SEEK_END);
  fwrite(&pac, sizeof(pac), 1, fPacientes);
  fflush(fPacientes);
}

void alteraPaciente(FILE *fPacientes)
{
  int codigo, posicao;
  paciente pac;
  printf("Informe o código do paciente para alteração de registro:\n");
  fflush(stdin);
  scanf("%i", &codigo);

  posicao = localizaPaciente(fPacientes, codigo);

  if (posicao != -1)
  {
    fseek(fPacientes, sizeof(pac) * (posicao), SEEK_SET);
    fread(&pac, sizeof(pac), 1, fPacientes);

    printf("Informe o nome atualizado:\n");
    fflush(stdin);
    gets(pac.nome);

    printf("Informe o telefone atualizado, com DDD sem 0 na frente:\n");
    fflush(stdin);
    scanf("%", pac.telefone);

    printf("Informe o endereço atualizado no formato (Logradouro), (numero), (bairro), (cidade):\n");
    fflush(stdin);
    gets(pac.endereco);

    printf("Informe a data de nascimento atualizada no formato DD/MM/AAAA:\n");
    fflush(stdin);
    gets(pac.dataNascimento);

    fseek(fPacientes, sizeof(pac) * (posicao), SEEK_SET);
    fwrite(&pac, sizeof(pac), 1, fPacientes);
    fflush(fPacientes);
  }
  else
  {
    printf("código não encontrado.\n");
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
    printf("Código: %i\n", pac.codigo);
    printf("Nome: %s\n", pac.nome);
    printf("Telefone: %s\n", pac.telefone);
    printf("Endereço: %s\n", pac.endereco);
    printf("Data de nascimento: %s\n", pac.dataNascimento);

    fread(&pac, sizeof(pac), 1, fPacientes);
  }
}

// MÉTODOS DE MÉDICO

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

  printf("Informe o nome do médico:\n");
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

  printf("Informe o código do médico para alteração de registro:\n");
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
    printf("código não encontrado.\n");
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
    printf("Código: %d\n", med.codigo);
    printf("Nome: %s\n", med.nome);
    printf("Telefone: %s\n", med.telefone);
    printf("Especialidade: %s\n", med.especialidade);

    fread(&med, sizeof(med), 1, fMedicos);
  }
}

void calculaPagamentoMedico(FILE *fConsultas)
{
  consulta cons;
  int codigo, qtdConsultas = 0;
  float salarioMedico = 0, precoConsulta = 50;

  fseek(fConsultas, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);

  printf("Informe o código do médico:\n");
  fflush(stdin);
  scanf("%d", &codigo);

  while (!feof(fConsultas))
  {
    if (cons.codigoMedico == codigo)
    {
      qtdConsultas++;
    }

    salarioMedico = precoConsulta * qtdConsultas;
    fread(&cons, sizeof(cons), 1, fConsultas);
  }
  if (qtdConsultas == 0)
  {
    printf("Código do médico inválido ou nenhuma consulta realizada");
  }

  printf("\nSalário: R$%.2f\n", salarioMedico);
}

// MÉTODOS DE CONSULTA

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

int localizaConsultasPorMedico(FILE *fConsultas, int codigoMedico, int dia, int mes, int ano)
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

int localizaQtdConsultasPorMedico(FILE *fConsultas, int codigoMedico, int dia, int mes, int ano)
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
    printf("Informe o código do médico:\n");
    fflush(stdin);
    scanf("%d", &cons.codigoMedico);

  } while (localizaMedico(fMedicos, cons.codigoMedico) == -1);

  do
  {
    printf("Informe o código do paciente:\n");
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
      if (localizaQtdConsultasPorMedico(fConsultas, cons.codigoMedico, cons.data.dia, cons.data.mes, cons.data.ano) >= 2)
      {
        printf("\nEste médico já possui 2 consultas nesta data, favor escolher outra data\n");
        controleData = 1;
      }
      else
        controleData = 0;
      // printf("%d\n%d\n%d\n",agendamento.data.dia,agendamento.data.mes,agendamento.data.ano);
    } while (cons.data.dia < 1 || cons.data.dia > 31 || cons.data.mes < 1 || cons.data.mes > 12 || cons.data.ano < 2000 || cons.data.ano > 2100 || controleData);
    // printf("%d", localizaQtdConsulta(arqconsulta,agendamento.codigoMedico,agendamento.data.dia,agendamento.data.mes,agendamento.data.ano));
    do
    {
      printf("\nInforme o horário da consulta, entre 7:00 - 21:00 (HH:MM):\n");
      fflush(stdin);
      scanf("%d:%d", &cons.data.hora, &cons.data.minuto);
      // printf("%d\n%d\n",agendamento.data.hora,agendamento.data.minuto);
    } while (cons.data.hora < 7 || cons.data.hora > 21 || cons.data.minuto < 0 || cons.data.minuto > 60);

    int posicaoMed = localizaConsultasPorMedico(fConsultas, cons.codigoMedico, cons.data.dia, cons.data.mes, cons.data.ano);

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
          printf("\nDiferença menor do que 30 minutos da consulta: %02d:%02d", consAux.data.hora, consAux.data.minuto);
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

void cancelaConsulta(FILE *fConsultas)
{
  FILE *consultasNew = fopen("consulta_new.dat", "w+b");
  consulta cons;
  int codigo, control = 0;

  fseek(consultasNew, 0, SEEK_SET);
  fseek(fConsultas, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);

  printf("Digite o código da consulta...:");
  fflush(stdin);
  scanf("%d", &codigo);

  while (!feof(fConsultas))
  {
    if (codigo != cons.codigoConsulta)
    {
      fseek(consultasNew, 0, SEEK_END);
      fwrite(&cons, sizeof(cons), 1, consultasNew);
    }
    else
      control++;
    fread(&cons, sizeof(cons), 1, fConsultas);
  }

  remove("consulta.dat");
  rename("consultas_new", "consulta.dat");

  if (control == 0)
  {
    printf("Consulta não encontrada. Cancelamento não realizado!\n");
  }
}

void alteraConsulta(FILE *fConsultas)
{
}

void imprimeConsultas(FILE *fConsultas)
{
  consulta cons;
  fseek(fConsultas, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  while (!feof(fConsultas))
  {
    printf("\n");
    printf("Código da consulta: %d\n", cons.codigoConsulta);
    printf("Código do médico: %d\n", cons.codigoMedico);
    printf("Codigo do paciente: %d\n", cons.codigoPaciente);
    printf("Data: %02d/%02d/%04d\n", cons.data.dia, cons.data.mes, cons.data.ano);
    printf("Horario: %02d:%02d\n", cons.data.hora, cons.data.minuto);
    fread(&cons, sizeof(cons), 1, fConsultas);
  }
}

void imprimeConsultasPorData(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas)
{
  consulta cons;
  medico med;
  paciente pac;

  int controle = 0, dia = -1, mes = -1, ano = -1;

  fseek(fConsultas, 0, SEEK_SET);
  fseek(fMedicos, 0, SEEK_SET);
  fseek(fPacientes, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  fread(&med, sizeof(med), 1, fMedicos);
  fread(&pac, sizeof(pac), 1, fPacientes);

  printf("\nExibir consultas da data: (Formato DD/MM/AAAA)\n");
  fflush(stdin);
  scanf("%d/%d/%d", &dia, &mes, &ano);

  while (!feof(fConsultas))
  {
    if (cons.data.dia == dia && cons.data.mes == mes && cons.data.ano == ano)
    {
      fseek(fMedicos, sizeof(med) * (localizaMedico(fMedicos, cons.codigoMedico)), SEEK_SET);
      fseek(fPacientes, sizeof(pac) * (localizaPaciente(fPacientes, cons.codigoPaciente)), SEEK_SET);
      fread(&med, sizeof(med), 1, fMedicos);
      fread(&pac, sizeof(pac), 1, fPacientes);

      printf("Código da consulta: %d\n", cons.codigoConsulta);
      printf("Código do médico: %d\n", cons.codigoMedico);
      printf("Nome do médico:  %s\n", med.nome);
      printf("Codigo do paciente: %d\n", cons.codigoPaciente);
      printf("Nome do paciente: %s\n", pac.nome);
      printf("Horario: %02d:%02d\n", cons.data.hora, cons.data.minuto);

      controle++;
    }

    fread(&cons, sizeof(cons), 1, fConsultas);
  }
  if (controle == 0)
  {
    printf("\nNenhuma consulta nesta data\n");
  }
}

void imprimeConsultasPorMedico(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas)
{
  consulta cons;
  medico med;
  paciente pac;
  char nomeAux[30], nome[20];
  int controle = 0, codigo = 0, op = 0;

  fseek(fConsultas, 0, SEEK_SET);
  fseek(fMedicos, 0, SEEK_SET);
  fseek(fPacientes, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  fread(&med, sizeof(med), 1, fMedicos);
  fread(&pac, sizeof(pac), 1, fPacientes);
  do
  {
    printf("\nExibir consultas de um medico:\n1 - por codigo\n2 - por nome\n");
    fflush(stdin);
    scanf("%d", &op);
    if (op == 1)
    {
      printf("\nDigite o codigo: ");
      fflush(stdin);
      scanf("%d", &codigo);
    }
    else if (op == 2)
    {
      printf("\nDigite o nome do medico: ");
      fflush(stdin);
      gets(nome);
    }
    else
      printf("\nDigite uma opção correta\n");

  } while (op < 1 || op > 2);

  if (op == 2)
  {

    while (!feof(fMedicos))
    {
      strcpy(nomeAux, med.nome);
      strlwr(nomeAux);
      strlwr(nome);
      if (strcmp(nome, nomeAux) == 0)
      {
        codigo = med.codigo;
      }

      fread(&med, sizeof(med), 1, fMedicos);
    }
  }

  while (!feof(fConsultas))
  {

    if (cons.codigoMedico == codigo)
    {
      fseek(fMedicos, sizeof(med) * (localizaMedico(fMedicos, cons.codigoMedico)), SEEK_SET);
      fseek(fPacientes, sizeof(pac) * (localizaPaciente(fPacientes, cons.codigoPaciente)), SEEK_SET);
      fread(&med, sizeof(med), 1, fMedicos);
      fread(&pac, sizeof(pac), 1, fPacientes);
      printf("\nCódigo da consulta: %d\n", cons.codigoConsulta);
      printf("Código do médico: %d\n", cons.codigoMedico);
      printf("Nome do médico: %s\n", med.nome);
      printf("Codigo do paciente: %d\n", cons.codigoPaciente);
      printf("Nome do paciente: %s\n", pac.nome);
      printf("Data: %02d/%02d/%04d\n", cons.data.dia, cons.data.mes, cons.data.ano);
      printf("Horario: %02d:%02d\n", cons.data.hora, cons.data.minuto);
      controle++;
    }

    fread(&cons, sizeof(cons), 1, fConsultas);
  }
  if (controle == 0)
  {
    printf("\nNenhuma consulta para este medico ou informação incorreta\n");
  }
}

void imprimeConsultasPorPaciente(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas)
{
  consulta cons;
  medico med;
  paciente pac;

  char nome[20], nomeAux[30];
  int controle = 0, codigo = 0;
  fseek(fConsultas, 0, SEEK_SET);
  fseek(fMedicos, 0, SEEK_SET);
  fseek(fPacientes, 0, SEEK_SET);
  fread(&cons, sizeof(cons), 1, fConsultas);
  fread(&med, sizeof(med), 1, fMedicos);
  fread(&pac, sizeof(pac), 1, fPacientes);
  int op = 0;
  int dia, mes, ano;
  printf("Quantidade de consultas realizadas ate a data:");
  scanf("%d/%d/%d", &dia, &mes, &ano);
  do
  {
    printf("\nExibir consultas realizadas de um paciente ate a data:\n1 - por codigo\n2 - por nome\n");
    fflush(stdin);
    scanf("%d", &op);
    if (op == 1)
    {
      printf("\nDigite o codigo: ");
      fflush(stdin);
      scanf("%d", &codigo);
    }
    else if (op == 2)
    {
      printf("\nDigite o nome do paciente: ");
      fflush(stdin);
      gets(nome);
    }
    else
      printf("\nDigite uma opção correta\n");

  } while (op < 1 || op > 2);

  if (op == 2)
  {

    while (!feof(fPacientes))
    {
      strcpy(nomeAux, pac.nome);
      strlwr(nomeAux);
      strlwr(nome);
      if (strcmp(nome, nomeAux) == 0)
      {
        codigo = pac.codigo;
      }

      fread(&pac, sizeof(pac), 1, fMedicos);
    }
  }

  while (!feof(fConsultas))
  {

    if (cons.codigoPaciente == codigo)
    {
      if (cons.data.ano < ano)
      {

        fseek(fMedicos, sizeof(med) * (localizaMedico(fMedicos, cons.codigoMedico)), SEEK_SET);
        fseek(fPacientes, sizeof(pac) * (localizaPaciente(fPacientes, cons.codigoPaciente)), SEEK_SET);
        fread(&med, sizeof(med), 1, fMedicos);
        fread(&pac, sizeof(pac), 1, fPacientes);
        printf("\nCódigo da consulta: %d\n", cons.codigoConsulta);
        printf("Código do médico: %d\n", cons.codigoMedico);
        printf("Nome do médico: %s\n", med.nome);
        printf("Codigo do paciente: %d\n", cons.codigoPaciente);
        printf("Nome do paciente: %s\n", pac.nome);
        printf("Data: %02d/%02d/%04d\n", cons.data.dia, cons.data.mes, cons.data.ano);
        printf("Horario: %02d:%02d\n", cons.data.hora, cons.data.minuto);
        controle++;
      }
      else if (cons.data.ano == ano)
      {
        if (cons.data.mes < mes)
        {
          fseek(fMedicos, sizeof(med) * (localizaMedico(fMedicos, cons.codigoMedico)), SEEK_SET);
          fseek(fPacientes, sizeof(pac) * (localizaPaciente(fPacientes, cons.codigoPaciente)), SEEK_SET);
          fread(&med, sizeof(med), 1, fMedicos);
          fread(&pac, sizeof(pac), 1, fPacientes);
          printf("\nCódigo da consulta:  %d \n", cons.codigoConsulta);
          printf("Código do médico:    %d \n", cons.codigoMedico);
          printf("Nome do médico:      %s \n", med.nome);
          printf("Codigo do paciente:  %d \n", cons.codigoPaciente);
          printf("Nome do paciente:    %s \n", pac.nome);
          printf("Data:                %02d/%02d/%04d\n", cons.data.dia, cons.data.mes, cons.data.ano);
          printf("Horario:             %02d:%02d\n", cons.data.hora, cons.data.minuto);
          controle++;
        }
        else if (cons.data.mes == mes)
        {

          if (cons.data.dia <= dia)
          {
            fseek(fMedicos, sizeof(med) * (localizaMedico(fMedicos, cons.codigoMedico)), SEEK_SET);
            fseek(fPacientes, sizeof(pac) * (localizaPaciente(fPacientes, cons.codigoPaciente)), SEEK_SET);
            fread(&med, sizeof(med), 1, fMedicos);
            fread(&pac, sizeof(pac), 1, fPacientes);
            printf("\nCódigo da consulta: %d\n", cons.codigoConsulta);
            printf("Código do médico: %d\n", cons.codigoMedico);
            printf("Nome do médico: %s\n", med.nome);
            printf("Codigo do paciente: %d\n", cons.codigoPaciente);
            printf("Nome do paciente: %s\n", pac.nome);
            printf("Data: %02d/%02d/%04d\n", cons.data.dia, cons.data.mes, cons.data.ano);
            printf("Horario: %02d:%02d\n", cons.data.hora, cons.data.minuto);
            controle++;
          }
        }
      }
    }
    fread(&cons, sizeof(cons), 1, fConsultas);
  }
  if (controle == 0)
  {
    printf("\nNenhuma consulta para este paciente ou informação incorreta\n");
  }
}

#endif // BIBLIOTECA_H_INCLUDED