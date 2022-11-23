#include <iostream>
#include <chrono>
#include <math.h>
using namespace std::chrono;


struct Aluno{
    int mat;
    float notas[3];
    float media;
};

struct AlunoOtimizado{
    int mat;
    float notas[3];
    float media;
    bool situacaoAprovada = media >=  7;
};

struct SituacaoAlunos{
    int mat;
    std::string situacao;
};

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

void programaInverso(unsigned int tamanhoArray) {
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
        if(alunos[i].media < 7) {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "REPROVADO";
        }
        else {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "APROVADO";
        }
    }
}

void programaOtimizadoInverso(unsigned int tamanhoArray) {
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
        if(!alunos[i].situacaoAprovada) {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "REPROVADO";
        }
        else {
            listaSituacaoAlunos[i].mat = alunos[i].mat;
            listaSituacaoAlunos[i].situacao = "APROVADO";
        }
    }
}

int main() {
    unsigned int tamanhoArray = 999999;
    auto start = high_resolution_clock::now();
    programaOriginal(tamanhoArray);
    std::cout << "Tempo execucao programa original: " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " millisegundos " << std::endl;

    start = high_resolution_clock::now();
    programaOtimizado(tamanhoArray);
    std::cout << "Tempo execucao programa otimizado: " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " millisegundos " << std::endl;
    
    start = high_resolution_clock::now();
    programaInverso(tamanhoArray);
    std::cout << "Tempo execucao programa inverso: " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " millisegundos " << std::endl;
    
    start = high_resolution_clock::now();
    programaOtimizadoInverso(tamanhoArray);
    std::cout << "Tempo execucao programa otimizado inverso: " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " millisegundos " << std::endl;
}