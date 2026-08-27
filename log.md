##Sessão 1 - 19/08/2026

Funcionalidades implementadas hoje:
- Escolhi o jogo 2048 como inspiração para o meu projeto
- Fiz um esquema de todas as características do jogo, de forma a saber que ficheiros tenho a criar e quais os próximos passos a seguir
- Programei o menu inicial
- Conectei o github ao vscode

Maior dificuldade encontrada e como resolvi:
- Tive um problema ao incluir o menu.c no meu código, percebi que tinha de associar o ficheiro c a um ficheiro h de forma a o poder referenciar

Próximo passo planeado:
- Vou começar a programar o tabuleiro e tentar trabalhar o visual do mesmo
- Irei utilizar o ncurses para que o tabuleiro permaneça estável no código

Linhas de código escritas: 50

##Sessão 2 - 21/08/2026

Funcionalidades implementadas hoje:
- Implementei o ncurses e usei-o para fazer as bordas do jogo, o tabuleiro principal
- Criei um ficheiro makefile de forma a ser mais fácil de correr o código
- Modifiquei o menu utilizando o ncurses e atualizei as funções de cada tecla (ex: ao clicar no 3, sair do jogo)
- Criei uma nova window onde o jogo vai rodar, como um tabuleiro secundário (esta função ainda não está a funcionar como pretendo)

Maior dificuldade encontrada e como pretendo resolver:
- Fazer com que a window do jogo, ou seja, o tabuleiro em si, apareça dentro da window já criada para o menu
- Para resolver estou a fazer pesquisa na internet de funções a utilizar, vou aprender a utilizar a função derwin e tentar aplicá-la na próxima sessão

Próximo passo planeado:
- Resolver a dificuldade da window secundária dentro da principal
- Criar a estrutura dos blocos e atribuir diferentes cores consoante o número que representam
- Programar o jogo em si: o aparecimento dos blocos em espaços vazios após um movimento de jogo e a junção dos blocos para criar novos 

Linhas de código escritas: 150 - 200

##Sessão 3 - 24/08/2026

Funcionalidades implementadas hoje:
- Coloquei a janela secundária, relativa ao jogo em si, dentro da janela principal
- Criei o tabuleiro do jogo, com uma dimensão de 4 x 4
- Criei os blocos e atribui-lhes diferentes cores
- Associei probabilidades aos blocos de 2 (90%) e de 4 (10%)

Maior dificuldade encontrada e como resolvi:
- Tive alguma dificuldade a atribuir probabilidades aos blocos, no entanto, após ver alguns tutoriais na internet, consegui resolver
- Estou de momento com dificuldade em que as cores atribuídas apareçam no ecrã, ainda não percebi exatamente onde está o erro, se no código ou se o deveria referenciar no game ou no main de forma diferente

Próximo passo planeado:
- Resolver o problema das cores
- Tratar da gameplay em si, para que os controlos comecem a funcionar
- Criar a verificação de vitória
- Criar o score 

Linhas de código escritas: 200 - 220

##Sessão 4 - 27/08/2026

Funcionalidades implementadas hoje:
- Correção de bugs: cores, formato dos blocos (havia sobreposição em relação ao tabuleiro principal)
- Limpei o código e organizei-o de forma a ser mais fácil continuar a desenvolver

Maior dificuldade encontrada e como resolvi:

Próximo passo planeado: