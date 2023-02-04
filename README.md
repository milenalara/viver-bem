# Clínica Viver Bem

- Linguagem: C
- Tipo de aplicação: console

## Autoria
- Ana Corina Damas Batista
- Davi Gonçalves Brandão
- Milena Lara Reis Ferreira 

## Professores Orientadores
- Ana Luiza do Nascimento Guercy
-  Roberto Felipe Dias Ferreira da Rocha

## Resumo
O sistema desenvolvido tem como objetivo atender à Viver Bem, uma clínica fictícia que oferece atendimento nas especialidades de cardiologia, dermatologia e clínica médica, melhorando a sua forma de organizar registros de médicos, pacientes e consultas, que até então eram feitos à mão ou em tabelas do excel. Trata-se de uma aplicação de console feita utilizando-se a linguagem C desenvolvida como trabalho interdisciplinar para as disciplinas Fundamentos de Engenharia de Software
e Algoritmos e Estruturas de Dados I da graduação emaEngenharia de Software da PUC Minas.



## Lista de assinaturas das funções e parâmetros

### void menuPrincipal();

Procedimento que exibe no console o menu principal, que oferece opções de executar subprogramas, exibir menu de subprogramas ou encerrar o programa.


### void menuProgramas();

Procedimento que exibe no console o menu de subprogramas para cadastrar, exibir, alterar ou excluir registros de pacientes, médicos e consultas, entre outros.


### int localizaPaciente(FILE *fPacientes, int codigoPaciente);

Função que verifica se existe paciente com o código informado nos registros, recebendo como parâmetros um ponteiro para endereço do arquivo onde os pacientes estão registrados e o código do paciente.


### void cadastraPaciente(FILE *fPacientes);

Procedimento que adiciona um paciente aos registros. Recebe como parâmetro um ponteiro para o endereço do arquivo onde os pacientes serão registrados.

### void alteraPaciente(FILE *fPacientes);

Procedimento que modifica os dados de um paciente que está nos registros. Recebe como parâmetro um ponteiro para o endereço do arquivo onde os pacientes estão registrados. O código do paciente é passado via input do teclado.

### void imprimePacientes(FILE *fPacientes);

Procedimento que imprime no console todos os registros de pacientes. Recebe como parâmetro um ponteiro para o endereço do arquivo onde os pacientes estão registrados.


### int localizaMedico(FILE *fMedicos, int codigoMedico);

Função que verifica se existe médico com o código informado nos registros, recebendo como parâmetros um ponteiro para endereço do arquivo onde os médicos estão registrados e o código do médico.


### void cadastraMedico(FILE *fMedicos);

Procedimento que acrescenta um novo registro de médico ao arquivo, que é passado como parâmetro por referência (ponteiro para o endereço do arquivo onde os registros estão salvos).

### void alteraMedico(FILE *fMedicos);

Procedimento que modifica os dados de um médico que está nos registros. Recebe como parâmetro um ponteiro para o endereço do arquivo onde os médicos estão registrados. O código do médico é passado via input do teclado.


### void imprimeMedicos(FILE *fMedicos);

Procedimento que imprime no console os registros de médicos, recebendo como parâmetro um ponteiro para o endereço do arquivo onde os registros estão salvos 

### void calculaPagamentoMedico(FILE *fConsultas);

Função que calcula quanto um médico deve receber a partir da quantidade de consultas realizadas. Recebe como parâmetros os ponteiros para os endereços na memória dos que contém os registros de consultas, médicos e de pagamentos.

### int localizaConsulta(FILE *fConsultas, int codigoConsulta);

Função que verifica se existe consulta com o código informado nos registros, recebendo como parâmetros um ponteiro para endereço do arquivo onde as consultas estão registradas e o código da consulta.


### int localizaConsultasPorMedico(FILE *fConsultas, int codigoMedico, int dia, int mes,  int ano);

Função para buscar o registro das consultas de um médico por data, recebendo como parâmetros um ponteiro para endereço do arquivo onde as consultas estão registradas, o código do médico, o dia, o mês e o ano da data a ser exibida.


### int localizaQtdConsultasPorMedico(FILE *fConsultas, int codigoMedico, int dia, int  , int ano);

Função que retorna a quantidade de consultas de um médico, recebendo como parâmetros um ponteiro para endereço do arquivo onde as consultas estão registradas, o código do médico, o dia, o mês e o ano da data a ser exibida.


### void cadastraConsulta(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);

Procedimento que adiciona uma consulta aos registros.  Recebe como parâmetros os ponteiros para os endereços na memória dos arquivos que contém os registros dos médicos, dos pacientes e das consultas.

### void cancelaConsulta(FILE *fConsultas);

Procedimento que exclui uma consulta dos registros. Recebe como parâmetro um ponteiro para o endereço na memória do arquivo que contém os registros de consultas. Recebe o código da consulta por input no teclado.

### void alteraConsulta(FILE *fConsultas);

Procedimento que modifica os dados de uma consulta que está nos registros. Recebe como parâmetro um ponteiro para o endereço do arquivo onde as consultas estão registradas. O código do paciente é passado via input do teclado.


### void imprimeConsultas(FILE *fConsultas);

Procedimento que imprime no console os registros de consultas, recebendo como parâmetro um ponteiro para o endereço do arquivo onde os registros estão salvos.


### void imprimeConsultasPorData(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);

Procedimento que imprime no console as consultas de uma determinada data, recebida por input do teclado. Recebe como parâmetros os ponteiros para os endereços na memória dos arquivos que contém os registros dos médicos, dos pacientes e das consultas. 

### void imprimeConsultasPorMedico(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);

Procedimento que imprime as consultas de um médico, que pode ser localizado através do nome ou do código, recebidos por input do teclado.  Recebe como parâmetros os ponteiros para os endereços na memória dos arquivos que contém os registros dos médicos, dos pacientes e das consultas.

### void imprimeConsultasPorPaciente(FILE *fPacientes, FILE *fMedicos, FILE *fConsultas);

Procedimento que imprime as consultas de um paciente, que pode ser localizado através do nome ou do código, recebidos por input do teclado. Recebe como parâmetros os ponteiros para os endereços na memória dos arquivos que contém os registros dos médicos, dos pacientes e das consultas.
