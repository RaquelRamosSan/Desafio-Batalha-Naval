# Desafio-Batalha-Naval


Este projeto é uma simulação simplificada do jogo Batalha Naval, implementada em C, com foco na aplicação de diferentes habilidades (áreas de ataque) sobre um tabuleiro fixo com navios.

## Objetivo

Aplicar diferentes formas de ataque (cone, cruz e octaedro) sobre um tabuleiro 10x10, afetando posições ao redor de uma coordenada central e simulando o impacto em um navio posicionado previamente.

## Funcionalidades

- Inicializa um tabuleiro 10x10 com água (valor 0).
- Posiciona um navio fixo 2x2 (valor 3) no centro do tabuleiro.
- Cria e aplica três tipos de habilidades, representadas por matrizes 7x7:
  - Cone
  - Cruz
  - Octaedro (losango)
- Marca áreas atingidas (valor 5) sobre o tabuleiro.
- Imprime o tabuleiro após aplicar cada tipo de habilidade.

## Como funciona

1. O tabuleiro é preenchido com 0 (água).
2. Um navio (grupo de células com valor 3) é colocado nas posições [4][4], [4][5], [5][4], [5][5].
3. Cada habilidade é aplicada centralizada na posição [4][4].
4. O programa imprime o tabuleiro após cada habilidade ser aplicada, mostrando as áreas afetadas (valor 5).

## Exemplo de execução (parcial)

```

Tabuleiro com habilidade CONE:
0 0 0 0 0 0 0 0 0 0
...
0 0 5 5 5 5 5 0 0 0
0 0 0 5 3 3 5 0 0 0
0 0 0 5 3 3 5 0 0 0
0 0 0 5 5 5 5 0 0 0
...

````

## Como compilar e rodar

### Requisitos

- Compilador C (como GCC)
- VS Code (opcional, com a extensão C/C++)

### Compilar via terminal

```bash
gcc batalha_naval.c -o batalha_naval
./batalha_naval
````

## Organização do Código

* `main()` – Ponto de entrada; organiza a execução dos testes.
* `inicializarTabuleiro()` – Preenche com zeros.
* `posicionarNavio()` – Coloca o navio fixo no centro.
* `criarCone()`, `criarCruz()`, `criarOctaedro()` – Geram as matrizes de habilidades.
* `aplicarHabilidade()` – Aplica a forma de ataque no tabuleiro.
* `imprimirTabuleiro()` – Mostra o estado atual do tabuleiro.

## Conceitos aplicados

* Matrizes bidimensionais
* Manipulação de coordenadas
* Simulação de áreas de impacto
* Estruturas condicionais e laços
* Representação visual em texto

## Licença

Este projeto é livre para fins educacionais.
Sinta-se à vontade para modificar, melhorar ou usar como base para estudos.

```
