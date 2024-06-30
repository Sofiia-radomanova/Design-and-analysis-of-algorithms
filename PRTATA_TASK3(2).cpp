#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>


#define N 200000


//Лабораторна робота з чисел Фібоначчі, 3 етап, 2 завдання
// кейс 1 
int fibXOR_int(int n)
{
    if (n <= 0)
        return 0;

    else if (n == 1)
        return 1; // базові випадки

    int last = 1, curr = 1, result;
    for (int i = 2; i <= n; i++)
    {
        result = last + curr; // 1 + 1 = 2
        curr = curr ^ last; // 1 || 1 = 0
        last = curr ^ last; // 0 || 1 = 1
        curr = curr ^ last; // 0 || 1 = 1
        last = result;
    }
    return curr;
}



long int fibXOR_longint( long int n)
{
    if (n <= 0)
        return 0;

    else if (n == 1)
        return 1; // базові випадки

     int last = 1, curr = 1, result;
    for (long i = 2; i <= n; i++)
    {
        result = last + curr; // 1 + 1 = 2
        curr = curr ^ last; // 1 || 1 = 0
        last = curr ^ last; // 0 || 1 = 1
        curr = curr ^ last; // 0 || 1 = 1
        last = result;
    }
    return curr;
}


double fibXOR_double(double n)
{
    if (n <= 0)
        return 0;

    else if (n == 1)
        return 1; // базові випадки

    int last = 1, curr = 1, result;
    for (int i = 2; i <= n; i++)
    {
        result = last + curr; // 1 + 1 = 2
        curr = curr ^ last; // 1 || 1 = 0
        last = curr ^ last; // 0 || 1 = 1
        curr = curr ^ last; // 0 || 1 = 1
        last = result;
    }
    return curr;
}

int main() 
{

    // Ініціалізація та заповнення масиву унікальних випадкових чисел
    int RandFib_1[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) 
    {
        RandFib_1[i] = rand() % 47;
    }

    // ініціалізація допоміжного масиву
    int mas1[47];
    for (int i = 0; i < 47; i++)
    {
        mas1[i] = -1;
    }

    // Виведення таблиці з числами Фібоначчі
    std::cout << std::endl << std::setw(10) << "int" << std::setw(12) << "long int" << std::setw(12) << "double" << '\n';

    // Ініціалізація змінних для визначення часу виконання різних методів
    int start;
    int stop;

    std::cout << "Час:";


    // Визначення часу виконання для типу даних int
    start = clock();
    for (int i = 0; i < N; i++)
    {
        fibXOR_int(RandFib_1[i]);
    }
    stop = clock();
    std::cout << std::setw(6) << (stop - start);

    // Визначення часу виконання для типу даних long int
    start = clock();
    for (int i = 0; i < N; i++)
    {
        fibXOR_longint(RandFib_1[i]);
    }
    stop = clock();
    std::cout << std::setw(12) << (stop - start);

    // Визначення часу виконання для типу даних double
    start = clock();
    for (int i = 0; i < N; i++)
    {
        fibXOR_double(RandFib_1[i]);
    }
    stop = clock();
    std::cout << std::setw(12) << (stop - start);

    return 0;
}