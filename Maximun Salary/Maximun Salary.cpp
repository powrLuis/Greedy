// Maximun Salary.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isbetter(std::string a, std::string b)
{
    int an = a.size(), bn = b.size();
    for (size_t i = 0; i < 4; i++)
    {
        if (i == an && i == bn)
        {
            return false;
        }
        if (i == an)
        {
            return isbetter(b.substr(0, i),b.substr(i, b.size()) );
        }
        if (i == bn)
        {
            return isbetter(a.substr(i, a.size()), a.substr(0, i));
        }
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    //entrada de los números
    std::vector<std::string> entrada;
    for (size_t i = 0; i < n; i++)
    {
        std::string a;
        std::cin >> a;
        entrada.push_back(a);
    }
    //ordenamiento usando is_better
    std::sort(entrada.begin(), entrada.end(),isbetter);
    //imprimiendo salario
    for (size_t i = 0; i < n; i++)
    {
        std::cout << entrada[i];
    }
    
    std::cout << "Hello World!\n";
}