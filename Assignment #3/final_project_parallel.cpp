#include <stdio.h>
#include <omp.h>
#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;

static long N = 10000;
int main(int argc, char const *argv[])
{
    double array_1[N], array_2[N];
    int i, j;
    auto t1 = chrono::high_resolution_clock::now();

// no shared vai para cache L3, que será uma unica versão de cada compartilhada

    // no private vai ter cópias para as caches locais(L2) em cada núcleo
    #pragma omp parallel default(none) shared(N, array_1, array_2) private(i, j)
        {
        // Só pode avançar se todos as compartilhadas estiverem livres
        // Inicialização do array resto_linhas
        #pragma omp for
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                array_1[i] = (i + j + 1) * 0.73;
                array_2[i] = (4.6 + i) * (25.8 - j);
            }
        }

        #pragma omp for nowait
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (i == j)
                {
                    array_1[i] += (i + j) / 3.15;
                }
            }
        }

        #pragma omp for nowait
        for (i = 0; i < N; i++)
        {
            array_2[i] = 6.4 + i / (j+1.5);
        }
    }

    auto t2 = chrono::high_resolution_clock::now();

    auto duration(chrono::duration_cast<chrono::microseconds>(t2 - t1).count());
    float time = (float)duration / 1000000;

    cout << "Tempo de processamento = " << time << " segundos"
         << "\n";

    cout << "Valores dos array -> array_1[0][0]: " << array_1[0] << " | array_2[0][0]: " << array_2[0] << "\n";

    return 0;
}
