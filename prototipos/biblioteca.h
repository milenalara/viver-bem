#ifndef BIBLIOTECAVIVERBEM_H_INCLUDED
#define BIBLIOTECAVIVERBEM_H_INCLUDED

int localizaMedico(FILE* f, int* codigo);
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

struct CConsulta
{
    int codigoPaciente;
    int codigoMedico;
    int codigoConsulta;
    char data[10];
    char hora[10];


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


int localizaMedico(FILE* f, int* codigo)
{
    int encontrado=-1;
    medico med;
    fseek(f,0,SEEK_SET);
    fread(&med, sizeof(med),1,f);
    while(!feof(f) && encontrado==-1)
    {
        if(*codigo==med.codigo)
        {
            encontrado=1;


        }
        fread(&med,sizeof(med),1,f);


    }


    return encontrado;
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

    posicao = localizaPaciente(f, p.codigo);

    if (posicao = -1)
    {
        p.codigo = rand() % (9999) + 1;

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

        fwrite(&p, sizeof(p), 1, f);
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
    consulta agendamento;
    agendamento.codigoConsulta=rand()%9000+1000;
    do
    {
        printf("\nCodigo do medico: \n");
        scanf("%d",&agendamento.codigoMedico);

    }
    while(localizaMedico(arqmedico,agendamento.codigoMedico)==-1);

    do
    {
        printf("\nCodigo do paciente: \n");
        scanf("%d",&agendamento.codigoPaciente);
    }
    while(localizaPaciente(arqpaciente,agendamento.codigoPaciente)==-1);

    printf("\nDada: (Formato DD/MM/AAAA)\n");
    gets(agendamento.data);
    printf("\Hora (Formato HH:MM)\n");
    gets(agendamento.hora);
    fseek(arqconsulta,0,SEEK_END);
    fwrite(&agendamento,sizeof(agendamento),1,arqconsulta);







}


#endif // BIBLIOTECAVIVERBEM_H_INCLUDED
