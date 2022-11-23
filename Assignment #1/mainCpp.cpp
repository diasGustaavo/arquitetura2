#include <iostream>
#include <chrono>
#include <math.h>
using namespace std::chrono;


struct Prova{
    int mat;
    int nota;
};

int programaOtimizado(int arraySize) {
    auto start = high_resolution_clock::now();

    int matBase = 20190;
    Prova provas[arraySize];

    for(int i = 0; i < arraySize; i++){
        provas[i].mat = matBase + i;
        provas[i].nota = sin(tan(cos(pow((provas[i].mat / 999.0), 4.0))));
    }

    return duration_cast<microseconds>(high_resolution_clock::now() - start).count();
}

int programaNaoOtimizado(int arraySize) {
    auto start = high_resolution_clock::now();

    int matBase = 20190;
    int provasMat[arraySize];
    int provasNota[arraySize];

    for(int i = 0; i < arraySize; i++){
        provasMat[i] = matBase + i;
    }
    
    for(int i = 0; i < arraySize; i++){
        provasNota[i] = sin(tan(cos(pow((provasMat[i] / 999.0), 4.0))));
    }

    return duration_cast<microseconds>(high_resolution_clock::now() - start).count();
}

int main() {
    std::cout << "Tempo execucao programa otimizado (tamanho: 5999): " << programaOtimizado(5999) << " microsegundos " << std::endl;
    std::cout << "Tempo execucao programa otimizado (tamanho: 9999): " << programaOtimizado(9999) << " microsegundos " << std::endl;
    std::cout << "Tempo execucao programa otimizado (tamanho: 99999): " << programaOtimizado(99999) << " microsegundos " << std::endl;
    std::cout << "Tempo execucao programa nao otimizado (tamanho: 5999): " << programaNaoOtimizado(5999) << " microsegundos " << std::endl;
    std::cout << "Tempo execucao programa nao otimizado (tamanho: 9999): " << programaNaoOtimizado(9999) << " microsegundos " << std::endl;
    std::cout << "Tempo execucao programa nao otimizado (tamanho: 99999): " << programaNaoOtimizado(99999) << " microsegundos " << std::endl;
}