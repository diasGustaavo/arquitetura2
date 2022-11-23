# Arquitetura de Computadores 2 - Assignment #2

## Configuração

Foram utilizados: a linguagem C++ na sua versão C++20, o sistema operacional Ubuntu na sua versão 22.04.1 LTS e o processador Intel i7-9700f cache de 12 MB, até 4,70 GHz.

## Código
Foram as estruturas a seguir para elaborar os diferentes códigos.

```cpp
struct Aluno{
  intmat;
  floatnotas[ 3 ];
  floatmedia;
};

struct AlunoOtimizado{
  intmat;
  floatnotas[ 3 ];
  floatmedia;
  boolsituacaoAprovada= media >= 7 ;
};

struct SituacaoAlunos{
  intmat;
  std::stringsituacao;
};
```

Foram criadas 4 diferentes funções para executar os códigos de acordo com as 4 maneiras diferentes, sendo essas, respectivamente: O programa original, programa otimizado (com o if encapsulado na estrutura), o programa inverso (com o if inverso), e o programa otimizado inverso(com o if encapsulado na estrutura de modo inverso).

```cpp
void programaOriginal(unsigned int tamanhoArray) {
    int matBase = 20190;
    Aluno alunos[tamanhoArray];
    SituacaoAlunos listaSituacaoAlunos[tamanhoArray];

    for(int i = 0; i < tamanhoArray; i++){
        alunos[i].mat = matBase + i;
        alunos[i].notas[0] = sin(tan(cos(pow((alunos[i].mat / 999.0), 88.0))));
        alunos[i].notas[1] = sin(tan(cos(pow((alunos[i].mat / 999.0), 162.0))));
        alunos[i].notas[2] = sin(tan(cos(pow((alunos[i].mat / 999.0), 139.0))));
        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
    }

    for(int i = 0; i < tamanhoArray; i++){
        if(alunos[i].media >= 7) {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "APROVADO";
        }
        else {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "REPROVADO";
        }
    }
}

void programaOtimizado(unsigned int tamanhoArray) {
    int matBase = 20190;
    AlunoOtimizado alunos[tamanhoArray];
    SituacaoAlunos listaSituacaoAlunos[tamanhoArray];

    for(int i = 0; i < tamanhoArray; i++){
        alunos[i].mat = matBase + i;
        alunos[i].notas[0] = sin(tan(cos(pow((alunos[i].mat / 999.0), 88.0))));
        alunos[i].notas[1] = sin(tan(cos(pow((alunos[i].mat / 999.0), 162.0))));
        alunos[i].notas[2] = sin(tan(cos(pow((alunos[i].mat / 999.0), 139.0))));
        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
    }

    for(int i = 0; i < tamanhoArray; i++){
        if(alunos[i].situacaoAprovada) {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "APROVADO";
        }
        else {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "REPROVADO";
        }
    }
}
```

## Resultados

Os Resultados obtidos podem ser verificados abaixo:

| | Original | Diretiva -01 | Diretiva -02 | Diretiva -03
| --- | --- | --- | --- | --- |
Versão Original | 39 ms | 34 ms | 33 ms | 33 ms | 
Versão Inversa | 38 ms | 33 ms | 32 ms | 32 ms | 
Versão Otimizada | 38 ms | 32 ms | 32 ms | 31 ms | 
Versão Otimizada Inversa | 37 ms | 32 ms | 32 ms | 32 ms | 
Tempo Médio | 38 ms | 32,75 ms | 32,25 ms | 32 ms | 
Ganho em relação ao original | - | 16 % | 17,8% | 18,7% | 
