#include <iostream>
#include <cmath> // Для математических функций

int main() {
    // Дано
    double S = 147.34;           // Длина линии, м
    double m_S = 0.07;           // Погрешность длины, м
    double alpha_deg = 83.0 + 47.0 / 60.0; // Угол в градусах
    double m_alpha_min = 0.5;    // Погрешность угла в минутах

    // Преобразуем углы в радианы
    double alpha = alpha_deg * M_PI / 180.0; // Угол в радианах
    double m_alpha = m_alpha_min * M_PI / (180.0 * 60.0); // Погрешность угла в радианах

    // Вычисляем косинус и синус угла
    double cos_alpha = std::cos(alpha);
    double sin_alpha = std::sin(alpha);

    // Формула для предельной погрешности
    double m_Dx = std::sqrt(
        std::pow(cos_alpha * m_S, 2) +
        std::pow(S * sin_alpha * m_alpha, 2)
    );

    // Вывод результата
    std::cout << "Предельная погрешность приращения координат по оси абсцисс: "
              << m_Dx << " м" << std::endl;

    return 0;
}