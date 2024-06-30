

#include <iostream>
#include <ctime>

int main()
{

    std::cout << "Task 1" << '\n';
    int i = 1;
    for (i = 1; i < 20; i++)
    {

        int A = rand();
        std::cout << A << '\n';
    }

    std::cout << '\n';



    std::cout << "Task 2" << '\n';
    srand(20);
    for (i = 1; i < 20; i++)
    {

        int A = rand();
        std::cout << A << '\n';

    }
    std::cout << '\n';


    std::cout << "Task 3" << '\n';
    srand(time(NULL));
    for (i = 1; i < 20; i++)
    {

        int A = rand();
        std::cout << A << '\n';

    }
    std::cout << '\n';



    std::cout << "Task 4" << '\n';
    for (i = 1; i < 20; i++)
    {

        int A = rand() % 50 + 20;
        std::cout << A << '\n';

    }
    std::cout << '\n';


    ///Part 2 
    std::cout << "Part 2 " << '\n';

    clock_t start_time = clock();

    int N = 50000;
    double x = 1.7;
    double y = 3;

    // Обчислення складного математичного виразу
    for (int i = 0; i <= N; i++)
    {
        double result = sin(x * y) * sin(i * y) + sqrt(fabs(x - y)) * exp(x + y);
        if (i > 49980)
        {
            std::cout << "Результат обчислення складного виразу при і = " << i << ":" << result << '\n';
        }
    }

    clock_t end_time = clock();
    double time = double(end_time - start_time);
    std::cout << "Час, затрачений на виконання програми(у тіках): " << time;
    return 0;
}

