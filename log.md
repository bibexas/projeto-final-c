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

Linhas de código escritas: 150