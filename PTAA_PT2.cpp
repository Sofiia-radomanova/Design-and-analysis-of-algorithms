#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#define N 20 

//Part 2
int fibXOR(int n)
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

//  кейс 2 (класична формула з масивом)
int fib1(int k, int mas1[47])
{
    if (mas1[k] != -1)
        return mas1[k];
    else if (k <= 1)
        return k;
    else if (mas1[k - 1] != -1 && mas1[k - 2] != -1) 
    {
        mas1[k] = fib1(k - 1, mas1) + fib1(k - 2, mas1);
        return mas1[k];
    }
    else 
    {
        int prev = 0;
        int current = 1;
        int next;
        for (int i = 2; i <= k; i++) 
        {
            next = prev + current;
            prev = current;
            current = next;
        }
        mas1[k] = current;
        return mas1[k];
    }
}





// кейс 3 (рекуррентна формула)
long double fib_rec(int k1)
{
        // Ініціалізація значень для перших двох чисел Фібоначчі
        long double prev = 0;
        long double current = 1;

        if (k1 == 0) return prev; // Якщо n = 0, повертаємо перше число Фібоначчі
        if (k1 == 1 || k1 == 2) return current; // Якщо n = 1, повертаємо друге число Фібоначчі

        // Обчислення чисел Фібоначчі для n+1 за вказаною формулою
        for (int i = 3; i <= k1; i++)
        {
            long double Fn = current;
            long double root = sqrt(5 * pow(Fn, 2) + 4);
            if ((int)root == root) 
            {
                current = (Fn + root) / 2;
            }
            else 
            {
                root = sqrt(5 * pow(Fn, 2) - 4);
                current = (Fn + root) / 2;
            }
            prev = Fn;
        }

        // Повернення значення числа Фібоначчі
        return current;
    }






int main()
{

    // ініціалізація допоміжного масиву
    int mas1[47];
    for (int i = 0; i < 47; i++)
        mas1[i] = -1;


    std::cout << "Task 1, Part 1: ";
    int n;
    std::cout << "Enter the Fibonacci number to generate: ";
    std::cin >> n;
    if (n == 0) {
        std::cout << "Fibonacci number at position 0: 0\n";
    }
    else if (n == 1) {
        std::cout << "Fibonacci number at position 1: 1\n";
    }
    else {
        std::cout << "Fibonacci number at position " << n << ": " << fibXOR(n) << '\n';
    }





    std::cout << "Task 1, Part 2: ";
    int k;
    std::cout << "Enter the Fibonacci number to generate: ";
    std::cin >> k;

    int fib_array[48] = { 2, 0, 1 };
    std::cout << "Fibonacci number at position " << k << ": " << fib1(k, mas1) << '\n';




    std::cout << "Task 1, Part 3: ";
    int k1;

    std::cout << "Enter the Fibonacci number to generate: ";
    std::cin >> k1;
    double fib_value = fib_rec(k1);
    std::cout << "Fibonacci number at position " << k1 << ": " << std::fixed << std::setprecision(6) << fib_value << " (дійсне) / " << static_cast<int>(fib_value) << " (ціле)" << '\n'; //static_cast<int> оператор статичного приведення типу
  





    std::cout << "Task 2: \n";
    // Ініціалізація та заповнення масиву унікальних випадкових чисел
    int RandFib[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        bool isUnique;
        int randomNum;

        do {
            // Генерація випадкового числа
            randomNum = rand() % 47; // Випадкове число від 0 до 46

            // Перевірка на унікальність
            isUnique = true;
            for (int j = 0; j < i; j++)
            {
                if (RandFib[j] == randomNum) {
                    isUnique = false;
                    break;
                }
            }
        } while (isUnique == false);

        // Додавання унікального числа до масиву
        RandFib[i] = randomNum;
    }



    for (int i = 0; i < N; i++) //виведення масиву RandFib
    {
        std::cout << std::setw(10) << "A [" << i << "]: " << RandFib[i] << '\n'; //setw (ширина поля)
    }




    std::cout << "Task 3\n";
    std::cout << "Порядковий номер " << std::setw(20) << "Метод 1" << std::setw(20) << "Метод 2" << std::setw(25) << "Метод 3" << '\n';
    std::cout << "числа Фібоначчі" << std::setw(75) << "Дійсне   /   Ціле \n";
    for (int i = 0; i < 20; i++)
    {
        std::cout << std::setw(10) << RandFib[i] << std::setw(20) << fibXOR(RandFib[i]) << std::setw(15) << fib1(RandFib[i], mas1)  << std::fixed << std::setprecision(6) << std::setw(20) << fib_rec(RandFib[i]) << std::setw(15);
        int fib_value1 = fib_rec(RandFib[i]);
        std::cout << std::setprecision(6) << fib_value1 << '\n';
    }



    return 0;
}
