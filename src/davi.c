#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void addMedico(FILE *f);
int localizaMedico(FILE *f, int codigo);

int main()
{
    FILE *f;
    char op;
    setlocale(LC_ALL, "portuguese");
    if ((f = fopen("teste.dat", "r+b")) == NULL)
    {
        printf("Arquivo não existia ... criando arquivo!");
        if ((f = fopen("teste.dat", "w+b")) == NULL) // arq não existe
        {
            printf("Erro na criação do arquivo!!");
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
    unsigned long long int numero;
    char especialidade[20];
};
typedef struct CMedico medico;

int localizaMedico(FILE *f, int codigo)
{
    int posicao = -1;
    int encontrado = 0;
    medico med;
    fseek(f, 0, SEEK_SET);
    fread(&med, sizeof(med), 1, f);
    while (!feof(f) && !encontrado)
    {
        if (med.codigo == codigo)
        {
            encontrado = 1;
        }
        fread(&med, sizeof(med), 1, f);
    }
    if (encontrado == 1)
    {
        return posicao;
    }
    else
        return -1;
}

void addMedico(FILE *f)
{
    medico med;
    int posicao;
    printf("\nDigite o código do medico a ser cadastrado\n");
    fflush(stdin);
    scanf("%d", &med.codigo);
    posicao = localizaMedico(f, med.codigo);
    if (posicao == -1)
    {
        printf("Nome do medico:\n");
        fflush(stdin);
        gets(med.nome);
        printf("Especialidade\n");
        gets(med.especialidade);
        printf("Numero, formato DDD+Numero (sem 0 do DDD)\n");
        scanf("%llu", &med.numero);
        fseek(f, 0, SEEK_END);
        fwrite(&med, sizeof(med), 1, f);
        fflush(stdin);
    }
    else
        printf("Codigo do medico ja existente. Nao foi possivel realizar inclusao");
}
