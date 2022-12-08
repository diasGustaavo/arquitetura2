#include "main.h"

using namespace std::chrono;

int programaOtimizado(int arraySize) {
    auto start = high_resolution_clock::now();

    int items[arraySize][arraySize];
    int items2[arraySize][arraySize];

    // CRIACAO
    for(int k = 0; k < arraySize; k++) {
        for(int i = 0; i < arraySize; i++){
            for(int j = 0; j < arraySize; j++) {
                items[i][j] = (k + i + j) / 1000;
                items2[i][j] = (k * i * j) / 1000;
            }
        }
    }
    
    // MODIFICACAO
    for(int k = 0; k < arraySize; k++) {
        for(int i = 0; i < arraySize; i++){
            for(int j = 0; j < arraySize; j++) {
                items[i][j] = 2 * k * items[i][j];
                items2[i][j] = 89 * k * items2[i][j];
            }
        }
    }
    
    return duration_cast<microseconds>(high_resolution_clock::now() - start).count();
}

int programaNaoOtimizado(int arraySize) {
    auto start = high_resolution_clock::now();

    int items[arraySize][arraySize];
    int items2[arraySize][arraySize];
    
    // CRIACAO
    for(int k = 0; k < arraySize; k++) {
        for(int j = 0; j < arraySize; j++){
            for(int i = 0; i < arraySize; i++) {
                items[i][j] = (k + i + j) / 1000;
            }
        }
    }
    
    // MODIFICACAO
    for(int k = 0; k < arraySize; k++) {
        for(int j = 0; j < arraySize; j++){
            for(int i = 0; i < arraySize; i++) {
                items[i][j] = 2 * k * items[i][j];
            }
        }
    }

    // CRIACAO
    for(int k = 0; k < arraySize; k++) {
        for(int i = 0; i < arraySize; i++){
            for(int j = 0; j < arraySize; j++) {
                items2[i][j] = (k * i * j) / 1000;
            }
        }
    }
    
    // MODIFICACAO
    for(int k = 0; k < arraySize; k++) {
        for(int i = 0; i < arraySize; i++){
            for(int j = 0; j < arraySize; j++) {
                items2[i][j] = 89 * k * items2[i][j];
            }
        }
    }

    return duration_cast<microseconds>(high_resolution_clock::now() - start).count();
}