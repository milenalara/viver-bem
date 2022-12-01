# Instruções
- Entrega: 04/12/2022às 23:59

## Observações:
- Linguagem de programação C.
- As informações deverão ser armazenadas em arquivo(s) acesso direto
- Entregar:
  - arquivo de apresentação gravada com a participação de todos os seus componentes demonstrando todas as funcionalidades do software.
  - projeto completo do programa
  - documentação
  - arquivos contendo os testes realizados.

## Clínica Viva Bem
Viva Bem é uma clínica médica que tem como principal objetivo atender bem aos seus pacientes. Ela está localizada no centro de Belo Horizonte e possui médicos das seguintes especialidades:
  - cardiologia,
  - dermatologia,
  - clínica médica.

## PROBLEMA:
 - Viva Bem faz seus controles de médico, paciente e consulta em planilhas do Excel e cadernos,
 - O controle da quantidade de consultas para cada médico não está sendo feito e muitas vezes, consultas são marcadas e depois têm que ser desmarcadas.
 

## SOLUÇÃO = FUNÇÕES!!!!

OBS: Tem que validar as restrições = testes

### CADASTRAR PACIENTE
- PACIENTE
  - código
  - nome
  - endereço
  - telefone
  - data de nascimento
- Garantir que não haverá mais de um paciente com o mesmo código. Se quiser pode gerar o código do paciente automaticamente. --> usar random()!

### CADASTRAR MÉDICO
- MEDICO
  - código
  - nome
  - telefone
  - especialidade
- Garantir que não haverá mais de um médico com o mesmo código. Se quiser pode gerar o código do médico automaticamente.

### CADASTRAR CONSULTA
- CONSULTA
  - código da consulta
  - data
  - hora
  - receber o CÓDIGO do paciente que deseja se consultar
  - receber o CÓDIGO do médico.
- As consultas devem ser marcadas com intervalos de 30 minutos entre elas.
- Para cadastrar uma consulta, primeiro o médico e o paciente devem estar cadastrados.
- cada médico só pode atender, no máximo, duas consultas por dia.

### CANCELAR CONSULTA
- Implemente uma função que permita cancelar uma determinada consulta.

### MOSTRAR CONSULTAS DO DIA
- Receba uma data e mostre na tela todas as consultas daquele dia.

### MOSTRAR CONSULTAS DO PACIENTE
- Receba o nome OU o código de um paciente e mostre suas consultas já realizadas até
a data corrente.

### MOSTRAR CONSULTAS DO MÉDICO
- Implemente uma função que mostre na tela todas as consultas de um determinado médico
(a consulta poderá ser realizada pelo nome OU pelo código do médico).

### FUNÇÃO EXTRA
- Implemente uma função extra, criada pelo grupo. Sejam criativos!
- Para fazer esse programa pode ser necessário criar mais funções do que as que estão descritas.

### MENU
- Finalmente, faça uma função main() que teste o software descrito acima
- Exibir um menu na tela, com as opções
  - cadastrar um paciente,
  - cadastrar um médico
  - cadastrar uma consulta
  - realizar pesquisas
- Esse menu deve ficar em loop até o usuário selecionar a opção SAIR.

### ARMAZENAMENTO
- Todas as informações deverão ser persistidas/armazenadas em
arquivo(s) texto. Portanto, deverá ser feita leitura e escrita em arquivos.

## Metodologia
- planejar, analisar, projetar, implementar e testar uma solução de software
- utilizar o Scrum para gerenciar seu progresso.
  - Inicialmente organize o backlog do produto com as funções básicas do sistema. Cada uma das funções será de responsabilidade de um membro do grupo e será desenvolvida em sprints de 3 a 4 dias.
  - Definir a assinatura da(s) função(ões). Reflita sobre os parâmetros de entrada e saída da função e comunique aos seus colegas de projeto.
  - Documentar a função indicando seu propósito, e os parâmetros de entrada e saída. O nome da função deve ser escolhido sob o ponto de vista de quem usa a função ou de quem vai chamar a função e deve refletir o que a função faz.
  - Implementar o caso de sucesso da função.
  - Selecionar casos de teste para verificar o funcionamento da função. Um caso de teste deve conter os valores de entrada para a função e a saída esperada.
  - Executar os casos de teste planejados para a função. Inicie fazendo a execução manual de alguns poucos casos de teste. Em seguida implemente a automatização dos testes da função usando a biblioteca munit.
  - Criar um relatório de execução de testes que contenha os casos de teste, a saída retornada durante sua execução e uma indicação se a função passou ou não no teste. Isso é feito comparando-se a saída esperada, documentada no caso de teste, com a saída retornada durante a
execução da função (esperado x real).
7- Implementar os casos especiais, exceções que possam existir na função. Em seguida, executar
os casos de teste anteriores para garantir que as mudanças não quebraram o código anterior que
já funcionava. Pense também nos novos casos de teste necessários para a nova versão da função.
O que deve ser entregue para os professores no Canvas
1- A evolução do backlog do produto a cada semana. Indique quais tarefas encontravam-se
inicialmente no backlog do produto, e em qual sprint cada tarefa foi alocada, juntamente com seu
responsável.
2- A documentação das funcionalidades do software.
3- O planejamento dos casos de teste (entradas, procedimento de teste e saídas esperadas), a
implementação dos casos de teste automatizados e o relatório de execução dos testes.
4- O código, em C, das funções e do programa principal, juntamente com o projeto completo do
software.
5- Arquivos contendo dados já incluídos para teste das funcionalidades.
6- Apresentação gravada em vídeo (pitch) mostrando todas as funcionalidades do sistema