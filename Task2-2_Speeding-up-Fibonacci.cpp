// Задача 2. Ускоряем Фибоначчи
// Ваша задача — изменить алгоритм вычисления n - го числа Фибоначчи так, 
// чтобы сложность алгоритма по скорости составляла O(n) и по памяти тоже была порядка O(n).

#include <iostream>

long long fibonacci_sequence(long long* memory, long long number)
{
    // Базовый случай рекурсии
    if (number <= 1) {
        memory[number] = number;
        return number;
    }

    // Проверка, было ли вычислено это число Фибоначчи ранее.
    if (memory[number] != -1)
        return memory[number];  

    // Рекурсивное вычисление
    memory[number] = fibonacci_sequence(memory, number - 2) + fibonacci_sequence(memory, number - 1);
    return memory[number];
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int quantity_of_numbers = 0;
    while (true)
    {
        std::cout << "Введите количество чисел Фибоначчи: ";
        std::cin >> quantity_of_numbers;
        if (quantity_of_numbers <= 0)
        {
            std::cout << "Просьба ввести корректное количество чисел" << std::endl;
        }
        else break;
    }

    long long* memory = new long long[quantity_of_numbers + 1];
    for (int i = 0; i <= quantity_of_numbers; i++)
        memory[i] = -1;

    std::cout << fibonacci_sequence(memory, quantity_of_numbers) << std::endl;

    delete[] memory;
    return 0;
}