

#include <iostream>
#include <cmath>

void func (int A, int B )
{
	
	for (int i = A; i+3 <= B; i++)
		if ((i + i+3) % 4 == 0 && ((i + 1) * (i + 2)) % 4 == 2)
		{
			std::cout << i << ', ' << i + 1 << ', ' << i + 2 << ', ' << i + 3 << '\n';
		}
}


int main()
{
	int V = (20 % 14) ? 20 % 14 : 14;
	std::cout << "Радоманова Софія, АнД-11, Варіант " << V << '\n';
	std::cout << "Введіть початок проміжку ";
	int A{};
	std::cin >> A;
	std::cout << "Введіть кінець проміжку ";
	int B{};
	std::cin >> B;
	func(A, B);
	
	return 0;
}


