#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <locale.h>

int main()
{
    FILE *f;
    char op;
    setlocale(LC_ALL,"portuguese");
    if ((f = fopen("teste.dat", "r+b"))==NULL)
    {
        printf("Criando arquivo!\n");
        if((f = fopen("teste.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!");
            exit(1);
        }
        system("pause");
    }

    addMedico(f);



}

struct CMedico
{
    int codigo;
    char nome[40];
    char numero[20];
    char especialidade[20];

};
typedef struct CMedico medico;
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
/*
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

*/
