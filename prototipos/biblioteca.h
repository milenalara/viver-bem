#ifndef BIBLIOTECAVIVERBEM_H_INCLUDED
#define BIBLIOTECAVIVERBEM_H_INCLUDED
#include <math.h>

int localizaMedico(FILE* f, int codigo);
void addMedico(FILE*f);
void imprime_Medico(FILE *f);
int localizaPaciente(FILE *f, int codigo);
void incluiPaciente(FILE *f);
void listaPacientes(FILE *f);
void alteraPaciente(FILE *f);
void cadastraConsulta(FILE* arqmedico,FILE* arqpaciente,FILE* arqconsulta);

struct CMedico
{
    int codigo;
    char nome[40];
    char numero[20];
    char especialidade[20];

};
typedef struct CMedico medico;

struct CDataHora
{
    int hora;
    int minuto;
    int dia;
    int mes;
    int ano;
};
typedef struct CDataHora cadData;

struct CConsulta
{
    int codigoPaciente;
    int codigoMedico;
    int codigoConsulta;
    cadData data;


};
typedef struct CConsulta consulta;

struct Tpaciente
{
    int codigo;
    int telefone;
    char nome[100];
    char endereco[200];
    char dataNascimento[10];
};
typedef struct Tpaciente paciente;

int localizaConsulta(FILE* f, int codigo)
{
    int posicao = -1, achou = 0;
    consulta c;
    fseek(f, 0, SEEK_SET);
    fread(&c, sizeof(c), 1, f);
    while (!feof(f) && !achou)
    {
        posicao++;
        if (c.codigoMedico == codigo)
        {
            achou = 1;
        }
        fread(&c, sizeof(c), 1, f);
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
int localizaQtdConsulta(FILE* f, int codigo, int dia, int mes, int ano)
{
    int achou = 0;
    consulta c;
    fseek(f, 0, SEEK_SET);
    fread(&c, sizeof(c), 1, f);
    while (!feof(f))
    {

        if (c.codigoMedico == codigo && c.data.dia==dia && c.data.mes==mes && c.data.ano==ano)
        {
            achou ++;
        }
        fread(&c, sizeof(c), 1, f);
    }
    return achou;
}
int localizaMedico(FILE* f, int codigo)
{
    int posicao = -1, achou = 0;
    medico med;
    fseek(f, 0, SEEK_SET);
    fread(&med, sizeof(med), 1, f);
    while (!feof(f) && !achou)
    {
        posicao++;
        if (med.codigo == codigo)
        {
            achou = 1;
        }
        fread(&med, sizeof(med), 1, f);
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
void addMedico(FILE*f)
{
    medico med;
    int posicao;
    printf("\nDigite o código do medico a ser cadastrado\n");
    fflush(stdin);
    scanf("%d", &med.codigo);
    posicao=localizaMedico(f,&med.codigo);

    if (posicao==-1)
    {
        printf("Nome do medico:\n");
        fflush(stdin);
        gets(med.nome);
        printf("Especialidade\n");
        gets(med.especialidade);
        printf("Numero, formato DDD+Numero (sem 0 do DDD)\n");
        gets(med.numero);
        fseek(f,0,SEEK_END);
        fwrite(&med,sizeof(med),1,f);
        fflush(stdin);




    }
    else
        printf("Codigo do medico ja existente. Nao foi possivel realizar inclusao");




}

void imprime_Medico(FILE *f)
{
    medico m;
    fseek(f,0,SEEK_SET);
    fread(&m, sizeof(m),1, f);
    while (!feof(f))
    {
        printf("Código....:%d \n",m.codigo);
        printf("Nome.:%s \n",m.nome);
        printf("Numero.....:%s\n",m.numero);
        printf("Especialidade.....:%s\n",m.especialidade);

        fread(&m, sizeof(m),1, f);
    }
}
void imprime_Consulta(FILE *f)
{
    consulta cons;
    fseek(f,0,SEEK_SET);
    fread(&cons, sizeof(cons),1, f);
    while (!feof(f))
    {
        printf("Código da consulta %25d \n",cons.codigoConsulta);
        printf("Código do médico %25d \n",cons.codigoMedico);
        printf("Codigo do paciente:%25d \n",cons.codigoPaciente);


        fread(&cons, sizeof(cons),1, f);
    }
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
    srand(time(NULL));
    do
    {
        p.codigo = rand() % (9000)+1000;
    }
    while(localizaPaciente(f, p.codigo)>=0);




    printf("Informe o telefone no com DDD sem 0 na frente:\n");
    fflush(stdin);
    scanf("%", p.telefone);

    printf("Informe o nome:\n");
    fflush(stdin);
    gets(p.nome);

    printf("Informe o endereço no formato (Logradouro), (numero), (bairro), (cidade):\n");
    fflush(stdin);
    gets(p.endereco);

    printf("Informe a data de nascimento no formato DD/MM/AAAA:\n");
    fflush(stdin);
    gets(p.dataNascimento);
    printf("\nCodigo do paciente é: %d", p.codigo);

    fwrite(&p, sizeof(p), 1, f);


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

        fseek(f, sizeof(p) * (posicao), SEEK_SET);
        fwrite(&p, sizeof(p), 1, f);
        fflush(f);
    }
    else
    {
        printf("código não encontrado.\n");
    }
}

void listaPacientes(FILE *f)
{
    paciente p;
    fseek(f, 0, SEEK_SET);
    fread(&p, sizeof(p), 1, f);

    while (!feof(f))
    {
        printf("código: %i\n", p.codigo);
        printf("Nome: %s\n", p.nome);
        printf("endereço: %s\n", p.endereco);
        printf("Telefone: %i\n", p.telefone);
        printf("Data de nascimento: %s\n\n", p.dataNascimento);
        fread(&p, sizeof(p), 1, f);
    }
}


void cadastraConsulta(FILE* arqmedico,FILE* arqpaciente,FILE* arqconsulta)
{

    srand(time(NULL));
    int controleHora=0;
    int controleData=0;
    int controleQtd=0;
    consulta agendamento;
    consulta agendamentoAux;

    //codigo consulta randomico
    do
    {
        agendamento.codigoConsulta=rand()%9000+1000;
    }
    while(localizaConsulta(arqconsulta,agendamento.codigoConsulta )>=0);
    //variaveis de controle
    agendamento.data.minuto=-1;
    agendamento.data.hora=-1;
    agendamento.data.dia=-1;
    agendamento.data.mes=-1;
    agendamento.data.ano=-1;
    do
    {
        printf("\nCodigo do medico: \n");
        fflush(stdin);
        scanf("%d",&agendamento.codigoMedico);


    }
    while(localizaMedico(arqmedico,agendamento.codigoMedico)==-1);


    do
    {
        printf("\nCodigo do paciente: \n");
        fflush(stdin);
        scanf("%d",&agendamento.codigoPaciente);
    }
    while(localizaPaciente(arqpaciente,agendamento.codigoPaciente)==-1);
    do
    {
        do
        {
            printf("\nData: (Formato DD/MM/AAAA)\n");
            scanf("%d/%d/%d",&agendamento.data.dia,&agendamento.data.mes, &agendamento.data.ano);
            if (localizaQtdConsulta(arqconsulta,agendamento.codigoMedico,agendamento.data.dia,agendamento.data.mes,agendamento.data.ano)>=2)
            {
                printf("Este médico já possui 2 consultas nesta data, favor escolher outra data");
                controleData=1;
            }
            else
                controleData=0;
            //printf("%d\n%d\n%d\n",agendamento.data.dia,agendamento.data.mes,agendamento.data.ano);
        }
        while(agendamento.data.dia<1 || agendamento.data.dia>31 || agendamento.data.mes<1 || agendamento.data.mes>12 || agendamento.data.ano<2000 || agendamento.data.ano>2100 || controleData);
        //printf("%d", localizaQtdConsulta(arqconsulta,agendamento.codigoMedico,agendamento.data.dia,agendamento.data.mes,agendamento.data.ano));
        do
        {
            printf("\nHora (entre 7:00 - 21:00) Formato HH:MM\n");
            fflush(stdin);
            scanf("%d:%d",&agendamento.data.hora,&agendamento.data.minuto);
            //printf("%d\n%d\n",agendamento.data.hora,agendamento.data.minuto);
        }
        while(agendamento.data.hora<7 || agendamento.data.hora>21 || agendamento.data.minuto<0 || agendamento.data.minuto>60);
        int posicaoMed=localizaConsulta(arqconsulta,agendamento.codigoMedico);
        if (posicaoMed!=-1)
        {
            fseek(arqconsulta, sizeof(agendamentoAux) * (posicaoMed), SEEK_SET);
            fread(&agendamentoAux, sizeof(agendamentoAux), 1, arqconsulta);


            if (agendamentoAux.data.ano==agendamento.data.ano && agendamentoAux.data.dia==agendamento.data.dia && agendamentoAux.data.mes==agendamento.data.mes)
            {
                int diferencaHoras=abs(((agendamentoAux.data.hora*60)+agendamentoAux.data.minuto-(agendamento.data.hora*60)+agendamento.data.minuto));
                //printf("%d", diferencaHoras);
                if ((diferencaHoras)<30)
                {
                    printf("\nDiferença menor do que 30 minutos da consulta: %02d:%02d", agendamentoAux.data.hora,agendamentoAux.data.minuto);
                    controleHora=1;
                }
                else
                    controleHora=0;



            }
            else
                controleHora=0;





        }
        else
            controleHora=0;
    }
    while(controleHora);

    fseek(arqconsulta,0,SEEK_END);
    fwrite(&agendamento,sizeof(agendamento),1,arqconsulta);







}
void imprimeConsultaPorData(FILE* f, FILE* p, FILE* m)
{
    consulta c;
    medico med;
    paciente pac;
    int controle=0,dia=-1,mes=-1,ano=-1;
    fseek(f,0,SEEK_SET);
    fread(&c, sizeof(c),1, f);
    fread(&med, sizeof(med),1, m);
    fread(&pac, sizeof(pac),1, p);
    printf("\nExibir consultas da data: (Formato DD/MM/AAAA)\n");
    scanf("%d/%d/%d",&dia,&mes, &ano);
    while (!feof(f))
    {
        if(c.data.dia==dia && c.data.mes==mes && c.data.ano==ano)
        {
            printf("\nCódigo da consulta: %d \n",c.codigoConsulta);
            printf("Código do médico:   %d \n",c.codigoMedico);
            printf("Nome do médico:   %s \n",med.nome);
            printf("Codigo do paciente: %d \n",c.codigoPaciente);
            printf("Nome do paciente:   %s \n",pac.nome);
            printf("Horario:            %02d:%02d\n", c.data.hora,c.data.minuto);
            controle++;

        }



        fread(&c, sizeof(c),1, f);
        fread(&med, sizeof(med),1, m);
        fread(&pac, sizeof(pac),1, p);
    }
    if (controle==0)
    {
        printf("\nNenhuma consulta nesta data\n");
    }


}



#endif // BIBLIOTECAVIVERBEM_H_INCLUDED


