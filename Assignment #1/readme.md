# Assignment

Faça um programa para demonstrar as técnicas de otimização de memória cache vistas nas aulas (slides 73-80). Apresente em um arquivo único: 1) código-fonte antes; 2) apresentação de quais otimizações foram realizadas; 3) código fonte após as otimizações; 4) tabela ou gráfico apresentando as melhorias alcançadas com as otimizações. Dica: execute com diferentes tamanho de dados. Quanto maiores as estruturas de dados, mais visível a otimização se torna.

# Tempos de execucao Dart

Tempos obtidos em um setup com 16GB de RAM, i7-9700f.

```
tempo decorrido (programa nao otimizado adicionando no array 10000): 5 milisegundos
tempo decorrido (programa nao otimizado alterando o array 10000): 2 milisegundos
tempo decorrido (programa otimizado adicionando no array 10000): 3 milisegundos
tempo decorrido (programa otimizado alterando o array 10000): 1 milisegundos


tempo decorrido (programa nao otimizado adicionando no array 1000000): 76 milisegundos
tempo decorrido (programa nao otimizado alterando o array 1000000): 36 milisegundos
tempo decorrido (programa otimizado adicionando no array 1000000): 68 milisegundos
tempo decorrido (programa otimizado alterando o array 1000000): 57 milisegundos


tempo decorrido (programa nao otimizado adicionando no array 10000000): 544 milisegundos
tempo decorrido (programa nao otimizado alterando o array 10000000): 353 milisegundos
tempo decorrido (programa otimizado adicionando no array 10000000): 737 milisegundos
tempo decorrido (programa otimizado alterando o array 10000000): 674 milisegundos


tempo decorrido (programa nao otimizado adicionando no array 100000000): 5013 milisegundos
tempo decorrido (programa nao otimizado alterando o array 100000000): 3572 milisegundos
tempo decorrido (programa otimizado adicionando no array 100000000): 9588 milisegundos
tempo decorrido (programa otimizado alterando o array 100000000): 10175 milisegundos

```

# Tempos de execucao C++

Tempos obtidos em um setup com 16GB de RAM, i7-9700f.

```
Tempo execucao programa otimizado (tamanho: 5999): 997 microsegundos
Tempo execucao programa otimizado (tamanho: 9999): 1995 microsegundos
Tempo execucao programa otimizado (tamanho: 99999): 19971 microsegundos
Tempo execucao programa nao otimizado (tamanho: 5999): 998 microsegundos
Tempo execucao programa nao otimizado (tamanho: 9999): 1995 microsegundos
Tempo execucao programa nao otimizado (tamanho: 99999): 19967 microsegundos
