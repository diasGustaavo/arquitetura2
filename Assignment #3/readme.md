# Arquitetura de Computadores 2 - Assignment #3

## Descrição

Escolha um programa de código aberto na internet ou escreva um código novo. Recomenda-se que seja utilizado C++, porque será utilizando o OpenMP, que só é compatível com C++

O seu trabalho deverá conter:
1) Trechos de código que acessam memória de forma não otimizada;
2) Otimização de memória e a apresentação de uma comparação no tempo de execução, com análise do código em busca dos trechos que mais utilizam recursos de CPU;
3) Otimização através de diretivas de compilação;
4) Otimização através da paralelização com diversos núcleos, apresentando resultados para a utilização de 1 a 8 núcleos;
5) Uma comparação através de um gráfico entre o desempenho dos resultados encontrados em cada etapa (1 a 4).

Elabore um relatório técnico onde você apresenta:

- Código-fonte de cada etapa
- Mudanças aplicadas em cada trecho de código, apresentando a justifica para a elas
- Quais pontos de melhoria em tempo de execução e uso de memória cache foram atingidos
- Imagens do gerenciador de tarefas demonstrando a utilização por vários núcleos
- Um gráfico apresentando resultados para um tamanho crescente no volume de dados acessado pelo programa.