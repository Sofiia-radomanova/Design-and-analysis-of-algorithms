

#include <iostream>

int linearSearch(int arr[], int size, int key, int& iterations)
{
    for (int i = 0; i < size; ++i)
    {
        iterations++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int JumpSearch(int arr[], int size, int key, int jump, int& iterations)
{
    // Змінна для зберігання індексу початку попереднього блоку
    int prevJump = 0;

    // Проходимо через масив з кроком jump
    for (int i = 0; i < size; i += jump)
    {
        iterations++; // Збільшуємо лічильник ітерацій

        // Перевіряємо, чи поточний елемент дорівнює ключу
        if (arr[i] == key)
        {
            return i; // Повертаємо індекс, якщо елемент знайдено
        }
        // Якщо поточний елемент більший за ключ або ми дійшли до останнього блоку елементів
        else if (arr[i] > key || i + jump >= size-1)
        {
            // Перевіряємо останній блок елементів
            for (int j = prevJump; j < i+jump; ++j)
            {
                iterations++; // Збільшуємо лічильник ітерацій
                // Перевіряємо, чи елемент з попереднього блоку дорівнює ключу
                if (arr[j] == key)
                {
                    return j; // Повертаємо індекс, якщо елемент знайдено
                }
            }
            return -1; // Повертаємо -1, якщо елемент не знайдено в поточному блоку
        }
        prevJump = i; // Оновлюємо значення prevJump для наступного блоку
    }
    return -1; // Повертаємо -1, якщо елемент не знайдено в усьому масиві
}

 


void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
       /* if (i == 4567)
        {
            arr[i] = 0;
        }
        else
        {*/
            arr[i] = i;
        /*}*/
    }
}



int main()
{
    const int size = 260000;
    int arr[size];
    int jump = 4;
    fillArray(arr, size);
    int number;
    int key = 457;
    int lineariterations = 0;
    int jumpiterations = 0;

    int linearresult = linearSearch(arr, size, key, lineariterations);
    int jumpresult = JumpSearch(arr, size, key, jump, jumpiterations);

    std::cout << "Enter the case (1-linear search, 2- jump search):";
    std::cin >> number;

    switch (number)
    {
    case 1:


        std::cout << "Key :" << key << '\n';
        if (linearresult != -1)
        {
            std::cout << "Element found in position: " << linearresult << '\n';
        }
        else
        {
            std::cout << "Element not found \n";
        }
        std::cout << "Amount of linear iterations: " << lineariterations << '\n';
        break;

    case 2:

        std::cout << "Key :" << key << '\n';
        std::cout << "Jump :" << jump << '\n';
        if (jumpresult != -1)
        {
            std::cout << "Element found in position: " << jumpresult << '\n';
        }
        else
        {
            std::cout << "Element not found \n";
        }
        std::cout << "Amount of jump iterations: " << jumpiterations << '\n';
        break;

    default: std::cout << "Unacceptable number\n";
        break;
    }


    return 0;
}


