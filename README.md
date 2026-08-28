# 2048
## Descrição
2048 é um jogo de puzzle numa grelha 4x4 desenvolvido em C no âmbito do projeto final de Programação em C/C++.
O objetivo deste jogo passa por juntar blocos de valores iguais, deslizando-os numa grelha 4x4, até chegar a um bloco com o valor de 2048. A cada movimento, um novo bloco, com o valor de 2 ou 4, surge de forma aleatória numa posição vazia da grelha.

**Controlos:**
Setas direcionais: mover os blocos 

`q` - sair do jogo

## Compilação

Antes de compilar o jogo, é necessário ter instalada a biblioteca do ncurses. Após isso, para compilar o projeto, a partir da raiz do repositório, basta correr:
```bash
make
```
Este comando invoca o `gcc` sobre todos os ficheiros `.c` do projeto, ligando a biblioteva ncurses através da flag `-lncurses` e gera o executável `2048.exe`.

## Execução

Depois de compilado, basta correr o jogo com:

```bash
./2048.exe
```
