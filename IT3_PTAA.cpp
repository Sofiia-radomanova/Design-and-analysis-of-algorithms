#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

int shellComparisons = 0;
int quickComparisons = 0;
int heapComparisons = 0;

void printArray(std::vector<int>& arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

bool isSorted(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

std::vector<int> generateRandomArray(int size)
{
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    return arr;
}

void shellSort(std::vector<int>& arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) // Починаємо з великого розриву і зменшуємо його
    {
        for (int i = gap; i < n; i++) // Виконуємо сортування вставкою для цього розриву
        {
            int temp = arr[i]; // Зберігаємо поточний елемент
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) // Зсуваємо елементи, щоб знайти місце для arr[i]
            {
                arr[j] = arr[j - gap];
                shellComparisons++; // Збільшуємо кількість порівнянь
            }
            arr[j] = temp; // Вставляємо arr[i] на його місце
        }
    }
}

void quickSort(std::vector<int>& arr, int first, int last)
{
    int middle = arr[(first + last) / 2];
    int i = first;
    int j = last;

    do
    {
        while (arr[i] < middle) //йдемо з початку масиву до середини поки значення зліва менше опорного елементу
            i++;
        while (arr[j] > middle) //йдемо з кінця масиву до середини поки значення справа більше опорного елементу
           j--;
        if (i <= j) //поки i "не дійшло" до j (коли умови while вже не виконуються)
        {
            std::swap(arr[i], arr[j]); 
            i++;
            j--;
        }
    } while (i <= j);
    if (j > first) //якщо j не доходить до першого елементу
        quickSort(arr, first, j); //рекурсивно викликаємо функцію для підмасиву [first; j] (лівої половини)
    if (i < last) //якщо і не дійшов до кінця
        quickSort(arr, i, last);

}

void heapify(std::vector<int>& arr, int n, int i) // n кількість елементів в масиві
{
    int largest = i; // Ініціалізуємо найбільший елемент як корінь
    int left = 2 * i + 1; // Лівий дочірній елемент
    int right = 2 * i + 2; // Правий дочірній елемент
    if (left < n && arr[left] > arr[largest])
    {
        largest = left; // Якщо лівий дочірній елемент більший за корінь
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right; // Якщо правий дочірній елемент більший за корінь
    }
    if (largest != i) //переміщуємо найбільший елемент в корінь
    {
        int temp = arr[i]; // Обмінюємо arr[i] та arr[largest]
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest); // Рекурсивно перетворюємо піддерево на купу
        heapComparisons++; // Збільшуємо кількість порівнянь
    }
}

void heapSort(std::vector<int>& arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) // Побудова купи (перегрупування масиву) //n / 2 - 1 - батько останнього листя
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0]; // Обмінюємо корінь (максимальний елемент) з останнім елементом
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0); // Викликаємо heapify на зменшеній купі
    }
}

int main()
{
    srand(time(0)); // Ініціалізуємо генератор випадкових чисел
    int number;
    std::vector<int> arrSize = { 100, 1000, 1500, 2000 }; // Розміри масивів для тестування
    std::cout << "Enter the number of test (1/2/3): ";
    std::cin >> number;

    switch (number)
    {
    case 1:
        std::cout << "Test 1 for sorted array \n";
        for (int size : arrSize)
        {
            std::vector<int> arrSorted(size);
            for (int i = 0; i < size; i++)
            {
                arrSorted[i] = i + 1; // Заповнюємо масив від 1 до size
            }
            std::vector<int> arrSorted1(arrSorted); // Використання конструктора копіювання для arrSorted1
            std::vector<int> arrSorted2(arrSorted);

            std::cout << "Array for shell sort for size " << size << ": ";
            // printArray(arrSorted);

            auto start = std::chrono::steady_clock::now(); //auto - компілятор самостійно визначає тип даних 
            shellSort(arrSorted);
            auto end = std::chrono::steady_clock::now();
            std::cout << "Shell sort for sorted array of size " << size << ": ";
            // printArray(arrSorted);
            std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
            //перетворення різниці між end і start у мікросекунди. count() повертає кількість одиниць цієї одиниці часу.
            std::cout << '\n';



            std::cout << "Array for quick sort of size  " << size << ": ";
            //printArray(arrSorted);

            auto start1 = std::chrono::steady_clock::now();
            quickSort(arrSorted, 0, size - 1);
            auto end1 = std::chrono::steady_clock::now();
            std::cout << "Quick sort for sorted array of size " << size << ": ";
            //printArray(arrSorted);
            std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds\n";
            std::cout << '\n';



            std::cout << "Array for heap sort of size  " << size << ": ";
            // printArray(arrSorted);

            auto start2 = std::chrono::steady_clock::now();
            heapSort(arrSorted);
            auto end2 = std::chrono::steady_clock::now();
            std::cout << "Heap sort for sorted array of size " << size << ": ";
            //printArray(arrSorted);
            std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds\n";
            std::cout << '\n';

            std::cout << "Size: " << size << " Shell Comparisons: " << shellComparisons << " Quick Comparisons: " << quickComparisons << " Heap Comparisons: " << heapComparisons << '\n';

        }
        break;

    case 2:
        std::cout << "Test 2 for random array \n";
        for (int size : arrSize)
        {
            std::vector<int> arrRandom = generateRandomArray(size);
            std::vector<int> arrRandom1 = arrRandom;
            std::vector<int> arrRandom2 = arrRandom;

            std::cout << "Array for shell sort for size " << size << ": ";
            //printArray(arrRandom);

            auto start = std::chrono::steady_clock::now();
            shellSort(arrRandom);
            auto end = std::chrono::steady_clock::now();
            //std::cout << "Shell sort for random array of size " << size << ": ";
            ////printArray(arrRandom);
            //std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
            //std::cout << '\n';



            std::cout << "Array for quick sort of size " << size << ": ";
            // printArray(arrRandom1);

            auto start1 = std::chrono::steady_clock::now();
            quickSort(arrRandom1, 0, size - 1);
            auto end1 = std::chrono::steady_clock::now();
            //std::cout << "Quick sort for random array of size " << size << ": ";
            ////printArray(arrRandom1);
            //std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds\n";
            //std::cout << '\n';



            std::cout << "Array for heap sort of size " << size << ": ";
            // printArray(arrRandom2);

            auto start2 = std::chrono::steady_clock::now();
            heapSort(arrRandom2);
            auto end2 = std::chrono::steady_clock::now();
            //std::cout << "Heap sort for random array of size " << size << ": ";
            ////printArray(arrRandom2);
            //std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds\n";
            //std::cout << '\n';


            std::cout << '\n' << "Size: " << size << " Shell Comparisons: " << shellComparisons << " Quick Comparisons: " << quickComparisons << " Heap Comparisons: " << heapComparisons << '\n';
        }
        break;

    case 3:
        std::cout << "Test 3 for reverse array \n";
        for (int size : arrSize)
        {
            std::vector<int> arrSorted(size);
            for (int i = 0; i < size; ++i)
            {
                arrSorted[i] = i + 1; // Заповнюємо масив від 1 до size
            }
            std::vector<int> arrReverse(arrSorted.rbegin(), arrSorted.rend()); // Реверсований відсортований масив
            std::vector<int> arrReverse1 = arrReverse;
            std::vector<int> arrReverse2 = arrReverse;


            std::cout << "Array for shell sort for size " << size << ": ";
            //printArray(arrReverse);

            auto start = std::chrono::steady_clock::now(); //auto - компілятор самостійно визначає тип даних 
            shellSort(arrReverse);
            auto end = std::chrono::steady_clock::now();
            //std::cout << "Shell sort for reverse array of size " << size << ": ";
            ////printArray(arrReverse);
            //std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";//перетворення різниці між end і start у мікросекунди. count() повертає кількість одиниць цієї одиниці часу.
            //std::cout << '\n';


            std::cout << "Array for quick sort of size " << size << ": ";
            // printArray(arrReverse1);

            auto start1 = std::chrono::steady_clock::now();
            quickSort(arrReverse1, 0, size - 1);
            auto end1 = std::chrono::steady_clock::now();
            // std::cout << "Quick sort for reverse array of size " << size << ": ";
            ////printArray(arrReverse1);
            // std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds\n";
            // std::cout << '\n';


            std::cout << "Array for heap sort of size " << size << ": ";
            //printArray(arrReverse2);

            auto start2 = std::chrono::steady_clock::now();
            heapSort(arrReverse2);
            auto end2 = std::chrono::steady_clock::now();
            //std::cout << "Heap sort for reverse array of size " << size << ": ";
            ////printArray(arrReverse2);
            //std::cout << "Sorted array: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds\n";
            //std::cout << '\n';


            std::cout << '\n' << "Size: " << size << " Shell Comparisons: " << shellComparisons << " Quick Comparisons: " << quickComparisons << " Heap Comparisons: " << heapComparisons << '\n';
        }
        break;

    default:
        std::cout << "Invalid choice\n";
        break;
    }
    return 0;
}