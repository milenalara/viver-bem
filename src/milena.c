#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct Tpaciente
{
  int codigo;
  int telefone;
  char nome[100];
  char endereco[200];
  char dataNascimento[10];
};
typedef struct Tpaciente paciente;

int localizaPaciente(FILE *f, int codigo);
void incluiPaciente(FILE *f);
void alteraPaciente(FILE *f);
void listaPacientes(FILE *f);

int main()
{
  printf("\n\nCADASTRO DE PACIENTE\n\n");

  FILE *fPacientes;
  int op;

  if ((fPacientes = fopen("pacientes.dat", "r+b")) == NULL)
  {
    if ((fPacientes = fopen("pacientes.dat", "w+b")) == NULL)
    {
      printf("Erro na criação do arquivo\n");
      exit(1);
    }
    system("pause");
  }

  do
  {
    printf("Escolha:\n");
    printf("1 - incluir registro");
    printf("2 - alterar registro");
    printf("3 - listar registros");
    printf("4 - sair do sistema");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
      incluiPaciente(fPacientes);
      break;
    case 2:
      alteraPaciente(fPacientes);
      break;
    case 3:
      listaPacientes(fPacientes);
      break;
    default:
      break;
    }
  } while (op != 4);
  fclose(fPacientes);

  return 0;
}

int localizaPaciente(FILE *f, int codigo)
{
  int posicao = -1, achou = 0;
  paciente p;
  fseek(f, 0, SEEK_SET);
  fread(&p, sizeof(p), 1, f);
  while (!feof(f) && !achou)
  {
    posicao++;
    if (p.codigo == codigo)
    {
      achou = 1;
    }
    fread(&p, sizeof(p), 1, f);
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

void incluiPaciente(FILE *f)
{
  paciente p;
  int posicao;

  p.codigo = rand() % (9999) + 1;

  posicao = localizaPaciente(f, p.codigo);
  if (posicao = -1)
  {
    printf("Informe o telefone no formato (__)_____-____:\n");
    fflush(stdin);
    scanf("%i", p.telefone);

    printf("Informe o nome:\n");
    fflush(stdin);
    gets(p.nome);

    printf("Informe o endereço no formato (Logradouro), (numero), (bairro), (cidade):\n");
    fflush(stdin);
    gets(p.endereco);

    printf("Informe a data de nascimento no formato DD/MM/AAAA:\n");
    fflush(stdin);
    gets(p.dataNascimento);
  }
  else
  {
    printf("ERRO: código já existe no arquivo. Inclusão não realizada\n");
  }
}

void alteraPaciente(FILE *f)
{
  int codigo, posicao;
  paciente p;
  printf("Informe o código do paciente para alteração de registro:\n");
  scanf("%i", &codigo);
  posicao = localizaPaciente(f, codigo);

  if (posicao != -1)
  {
    fseek(f, sizeof(p) * (posicao), SEEK_SET);
    fread(&p, sizeof(p), 1, f);

    printf("Informe o nome atualizado:\n");
    fflush(stdin);
    gets(p.nome);

    printf("Informe o endereço atualizado no formato (Logradouro), (numero), (bairro), (cidade):\n");
    fflush(stdin);
    gets(p.endereco);

    printf("Informe a data de nascimento atualizada no formato DD/MM/AAAA:\n");
    fflush(stdin);
    gets(p.dataNascimento);
  }
  else
  {
    printf("Código não encontrado.\n");
  }
}

void listaPacientes(FILE *f)
{
}