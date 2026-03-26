// Задача 2. Поиск в массиве
// Вам нужно написать функцию, которая принимает на вход отсортированный массив целых чисел и целое число.
// Функция должна посчитать количество элементов в массиве, которые больше, чем переданное в функцию целое число.
// Требуемая алгоритмическая сложность: время O(log2n), дополнительная память O(1).

#include <iostream>

// Функция подсчёта элементов, которые больше введённого числа
int higher_elements_counting(int arr[], int entered_number, int size) {
    int left = 0;
    int right = size; // Индекс за пределами массива на случай, если не найдётся чисел больше введённого

    while (left < right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] > entered_number) {
            right = middle;
        }
        else {
            left = middle + 1;
        }
    }

    return size - left; // (left == right) Количество найденных элементов = размер массива - индекс первого подходящего числа
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int entered_number;
    std::cout << "Введите точку отсчёта: ";

    // Проверка правильности ввода
    if (!(std::cin >> entered_number)) {
        std::cerr << "Пожалуйста, введите целое число." << std::endl;
        return 1;
    }

    int count = higher_elements_counting(arr, entered_number, size);
    std::cout << "Количество элементов больше, чем " << entered_number << ": " << count << std::endl;

    return 0;
}