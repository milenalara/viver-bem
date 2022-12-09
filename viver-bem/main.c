#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "bibliotecaviverbem.h"



int main()
{

    FILE *fConsultas;
    FILE *fMedicos;
    FILE *fPacientes;
    int op;

    setlocale(LC_ALL,"portuguese");
    if ((fConsultas = fopen("consulta.dat", "r+b"))==NULL)
    {
        printf("Criando arquivo!\n");
        if((fConsultas = fopen("consulta.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!");
            exit(1);
        }
        system("pause");
    }
    if ((fMedicos = fopen("medico.dat", "r+b"))==NULL)
    {
        printf("Criando arquivo!\n");
        if((fMedicos = fopen("medico.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!");
            exit(1);
        }
        system("pause");
    }
    if ((fPacientes = fopen("paciente.dat", "r+b"))==NULL)
    {
        printf("Criando arquivo!\n");
        if((fPacientes = fopen("paciente.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!");
            exit(1);
        }
        system("pause");
    }



  srand(time(NULL));

  do
  {
    printf("\n-----------MENU PRINCIPAL-----------\n");
    printf("Digite o código do programa que deseja executar\n");
    printf("OU digite 0 para ver as opções de programas\n");
    printf("OU digite -1 para sair\n");
    scanf("%i", &op);

    switch (op)
    {
    case -1:
      break;
    case 0:
      menu();
      break;
    case 1:
        //Implemente uma função para cadastrar um paciente
      incluiPaciente(fPacientes);
      break;
    case 2:
        //Implemente uma função para cadastrar um médico
      addMedico(fMedicos);
      break;
    case 3:
        //Implemente uma função que cadastre uma consulta
      cadastraConsulta(fMedicos,fPacientes,fConsultas);
      break;
    case 4:
        //a) Receba uma data e mostre na tela todas as consultas daquele dia.

      imprimeConsultaPorData(fConsultas,fPacientes,fMedicos);
      break;
    case 5:
        //Implemente uma função que mostre na tela todas as consultas de um determinado médico
      imprimeConsultaPorMedico(fConsultas,fPacientes,fMedicos);
      break;
    case 6:
         //b) Receba o nome OU o código de um paciente e mostre suas consultas já realizadas até a data corrente.
        imprimeConsultaPorPaciente(fConsultas,fPacientes,fMedicos);
        break;
    case 7:
        //Implemente uma função que permita cancelar uma determinada consulta
        cancelaConsulta(fConsultas);
        break;
    case 8:
        //função extra, pagamento do medico
        pagamentoMedico(fConsultas);
        break;

    default:
      printf("Programa não encontrado\n");
      break;
    }

  } while (op != -1);

  return 0;
}
