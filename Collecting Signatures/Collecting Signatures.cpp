// Collecting Signatures.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
struct Linea
{
    int left = 0, right = 0;
    bool contiene(int e) { return left <= e && e <= right; }
};

bool right_line(Linea a, Linea b)
{
    return a.right < b.right;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<Linea> entrada;
    std::string line;
    for (size_t i = 0; i < n; i++)
    {
        Linea temp;
        std::cin >> temp.left;
        std::cin >> temp.right;
        entrada.push_back(temp);
    }

    //ordenar por su lado derecho
    std::sort(entrada.begin(), entrada.end(), right_line);
    //removemos mientras exista elementos
    std::vector<int> respuesta;
    while (entrada.size() > 0)
    {
        int temp = entrada[0].right;
        respuesta.push_back(temp);
        int i = 0;
        auto iterator = entrada.begin();
        while (i<entrada.size())
        {
            if (entrada[i].contiene(temp))
            {
                entrada.erase(entrada.begin()+i);
            }
            else
            {
                i++;
            }
        }
    }

    //imprimimos la respuesta
    std::cout << respuesta.size() << std::endl;
    for (size_t i = 0; i < respuesta.size(); i++)
    {
        std::cout << respuesta[i] << " ";
    }
}