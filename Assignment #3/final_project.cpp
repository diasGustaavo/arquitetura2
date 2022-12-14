#include <stdio.h>
#include <omp.h>
#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;

static long N = 10;
int main(int argc, char const *argv[])
{
    double array_1[N], array_2[N];
    int i, j;
    auto t1 = chrono::high_resolution_clock::now();

    // Inicialização do array resto_linhas
    for (j = 0; j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            array_1[i] = (i + j + 1) * 0.73;
        }
    }

    // Inicialização do array diagonal
    for (j = 0; j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            array_2[i] = (4.6 + i) * (25.8 - j);
        }
    }

    // Região paralela
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

    for (i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++) {
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
