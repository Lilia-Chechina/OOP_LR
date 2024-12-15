#include "include/Thirteen_Class.h"
#include <sstream>
#include <iostream>
#include <limits>


void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Сложение\n";
    std::cout << "2. Вычитание\n";
    std::cout << "3. Сравнение (==)\n";
    std::cout << "4. Сравнение (!=)\n";
    std::cout << "5. Сравнение (<)\n";
    std::cout << "6. Сравнение (>)\n";
    std::cout << "7. Выход\n";
    std::cout << "Выберите операцию: ";
}

int main() {
    try {
        std::cout << "Введите первое число (13-ричная система): ";
        std::string input1;
        std::cin >> input1;
        std::stringstream ss1(input1);
        Thirteen num1(ss1);

        std::cout << "Введите второе число (13-ричная система): ";
        std::string input2;
        std::cin >> input2;
        std::stringstream ss2(input2);
        Thirteen num2(ss2);

        int choice = 0;
        while (true) {
            displayMenu();
            std::cin >> choice;
            if (std::cin.fail() || choice < 1 || choice > 7) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный выбор. Введите число от 1 до 7.\n";
                continue;
            }

            std::stringstream output;
            switch (choice) {
                case 1: {
                    num1 += num2;
                    num1.print(output);
                    std::cout << "Результат сложения: " << output.str() << "\n";
                    break;
                }
                case 2: {
                    num1 -= num2;
                    num1.print(output);
                    std::cout << "Результат вычитания: " << output.str() << "\n";
                    break;
                }
                case 3: {
                    if (num1 == num2) {
                        std::cout << "Числа равны\n";
                    } else {
                        std::cout << "Числа не равны\n";
                    }
                    break;
                }
                case 4: {
                    if (num1 != num2) {
                        std::cout << "Числа не равны\n";
                    } else {
                        std::cout << "Числа равны\n";
                    }
                    break;
                }
                case 5: {
                    if (num1 < num2) {
                        std::cout << "Первое число меньше второго\n";
                    } else {
                        std::cout << "Первое число не меньше второго\n";
                    }
                    break;
                }
                case 6: {
                    if (num1 > num2) {
                        std::cout << "Первое число больше второго\n";
                    } else {
                        std::cout << "Первое число не больше второго\n";
                    }
                    break;
                }
                case 7: {
                    std::cout << "Выход из программы...\n";
                    return 0;
                }
                default: {
                    std::cout << "Неверный выбор. Попробуйте снова.\n";
                    break;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Неизвестная ошибка.\n";
    }

    return 0;
}
