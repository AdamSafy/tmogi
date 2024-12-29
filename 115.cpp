#include <iostream>
#include <cmath> // Для математических функций

int main() {
    // Дано
    double n = 5;             // Количество укладок
    double L = 20.0;          // Длина ленты (м)
    double m_L = 0.01;        // Погрешность укладки (м)
    double a = 1.47;          // Рабочая отметка a (м)
    double b = -1.96;         // Рабочая отметка b (м)
    double m_a = 0.02;        // Погрешность отметки a (м)
    double m_b = 0.02;        // Погрешность отметки b (м)

    // Вычисления
    double S = n * L;         // Расстояние S
    double delta_a_b = a - b;
    double sum_a_b = a + b;

    // Погрешность расстояния
    double term1 = n * n * std::pow(m_L, 2);
    double term2 = (std::pow(delta_a_b, 2) / std::pow(sum_a_b, 2)) * (std::pow(m_a, 2) + std::pow(m_b, 2));
    double m_S = std::sqrt(term1 + term2);

    // Вывод результата
    std::cout << "Средняя квадратическая погрешность расстояния: "
              << m_S << " м" << std::endl;

    return 0;
}