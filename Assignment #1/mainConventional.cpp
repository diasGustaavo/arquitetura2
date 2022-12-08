#include "main.cpp"

int main() {
    std::cout << "Tempo execucao programa não otimizado (tamanho: 9): " << programaNaoOtimizado(9) << " microsegundos " << std::endl;
    std::cout << "Tempo execucao programa não otimizado (tamanho: 99): " << programaNaoOtimizado(99) << " microsegundos " << std::endl;
    std::cout << "Tempo execucao programa não otimizado (tamanho: 999): " << programaNaoOtimizado(999) << " microsegundos " << std::endl;
}