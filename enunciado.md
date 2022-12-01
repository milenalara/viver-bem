# Instru��es
- Entrega: 04/12/2022�s 23:59

## Observa��es:
- Linguagem de programa��o C.
- As informa��es dever�o ser armazenadas em arquivo(s) acesso direto
- Entregar:
  - arquivo de apresenta��o gravada com a participa��o de todos os seus componentes demonstrando todas as funcionalidades do software.
  - projeto completo do programa
  - documenta��o
  - arquivos contendo os testes realizados.

## Cl�nica Viva Bem
Viva Bem � uma cl�nica m�dica que tem como principal objetivo atender bem aos seus pacientes. Ela est� localizada no centro de Belo Horizonte e possui m�dicos das seguintes especialidades:
  - cardiologia,
  - dermatologia,
  - cl�nica m�dica.

## PROBLEMA:
 - Viva Bem faz seus controles de m�dico, paciente e consulta em planilhas do Excel e cadernos,
 - O controle da quantidade de consultas para cada m�dico n�o est� sendo feito e muitas vezes, consultas s�o marcadas e depois t�m que ser desmarcadas.
 

## SOLU��O = FUN��ES!!!!

OBS: Tem que validar as restri��es = testes

### CADASTRAR PACIENTE
- PACIENTE
  - c�digo
  - nome
  - endere�o
  - telefone
  - data de nascimento
- Garantir que n�o haver� mais de um paciente com o mesmo c�digo. Se quiser pode gerar o c�digo do paciente automaticamente. --> usar random()!

### CADASTRAR M�DICO
- MEDICO
  - c�digo
  - nome
  - telefone
  - especialidade
- Garantir que n�o haver� mais de um m�dico com o mesmo c�digo. Se quiser pode gerar o c�digo do m�dico automaticamente.

### CADASTRAR CONSULTA
- CONSULTA
  - c�digo da consulta
  - data
  - hora
  - receber o C�DIGO do paciente que deseja se consultar
  - receber o C�DIGO do m�dico.
- As consultas devem ser marcadas com intervalos de 30 minutos entre elas.
- Para cadastrar uma consulta, primeiro o m�dico e o paciente devem estar cadastrados.
- cada m�dico s� pode atender, no m�ximo, duas consultas por dia.

### CANCELAR CONSULTA
- Implemente uma fun��o que permita cancelar uma determinada consulta.

### MOSTRAR CONSULTAS DO DIA
- Receba uma data e mostre na tela todas as consultas daquele dia.

### MOSTRAR CONSULTAS DO PACIENTE
- Receba o nome OU o c�digo de um paciente e mostre suas consultas j� realizadas at�
a data corrente.

### MOSTRAR CONSULTAS DO M�DICO
- Implemente uma fun��o que mostre na tela todas as consultas de um determinado m�dico
(a consulta poder� ser realizada pelo nome OU pelo c�digo do m�dico).

### FUN��O EXTRA
- Implemente uma fun��o extra, criada pelo grupo. Sejam criativos!
- Para fazer esse programa pode ser necess�rio criar mais fun��es do que as que est�o descritas.

### MENU
- Finalmente, fa�a uma fun��o main() que teste o software descrito acima
- Exibir um menu na tela, com as op��es
  - cadastrar um paciente,
  - cadastrar um m�dico
  - cadastrar uma consulta
  - realizar pesquisas
- Esse menu deve ficar em loop at� o usu�rio selecionar a op��o SAIR.

### ARMAZENAMENTO
- Todas as informa��es dever�o ser persistidas/armazenadas em
arquivo(s) texto. Portanto, dever� ser feita leitura e escrita em arquivos.

## Metodologia
- planejar, analisar, projetar, implementar e testar uma solu��o de software
- utilizar o Scrum para gerenciar seu progresso.
  - Inicialmente organize o backlog do produto com as fun��es b�sicas do sistema. Cada uma das fun��es ser� de responsabilidade de um membro do grupo e ser� desenvolvida em sprints de 3 a 4 dias.
  - Definir a assinatura da(s) fun��o(�es). Reflita sobre os par�metros de entrada e sa�da da fun��o e comunique aos seus colegas de projeto.
  - Documentar a fun��o indicando seu prop�sito, e os par�metros de entrada e sa�da. O nome da fun��o deve ser escolhido sob o ponto de vista de quem usa a fun��o ou de quem vai chamar a fun��o e deve refletir o que a fun��o faz.
  - Implementar o caso de sucesso da fun��o.
  - Selecionar casos de teste para verificar o funcionamento da fun��o. Um caso de teste deve conter os valores de entrada para a fun��o e a sa�da esperada.
  - Executar os casos de teste planejados para a fun��o. Inicie fazendo a execu��o manual de alguns poucos casos de teste. Em seguida implemente a automatiza��o dos testes da fun��o usando a biblioteca munit.
  - Criar um relat�rio de execu��o de testes que contenha os casos de teste, a sa�da retornada durante sua execu��o e uma indica��o se a fun��o passou ou n�o no teste. Isso � feito comparando-se a sa�da esperada, documentada no caso de teste, com a sa�da retornada durante a
execu��o da fun��o (esperado x real).
7- Implementar os casos especiais, exce��es que possam existir na fun��o. Em seguida, executar
os casos de teste anteriores para garantir que as mudan�as n�o quebraram o c�digo anterior que
j� funcionava. Pense tamb�m nos novos casos de teste necess�rios para a nova vers�o da fun��o.
O que deve ser entregue para os professores no Canvas
1- A evolu��o do backlog do produto a cada semana. Indique quais tarefas encontravam-se
inicialmente no backlog do produto, e em qual sprint cada tarefa foi alocada, juntamente com seu
respons�vel.
2- A documenta��o das funcionalidades do software.
3- O planejamento dos casos de teste (entradas, procedimento de teste e sa�das esperadas), a
implementa��o dos casos de teste automatizados e o relat�rio de execu��o dos testes.
4- O c�digo, em C, das fun��es e do programa principal, juntamente com o projeto completo do
software.
5- Arquivos contendo dados j� inclu�dos para teste das funcionalidades.
6- Apresenta��o gravada em v�deo (pitch) mostrando todas as funcionalidades do sistema