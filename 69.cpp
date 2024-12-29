#include <iostream>
#include <cmath> // Для математических функций

int main() {
    // Дано
    double S = 171.534;           // Расстояние, м
    double m_S = 0.008;           // Погрешность расстояния, м
    double alpha_deg = 132.0 + 47.0 / 60.0 + 18.5 / 3600.0; // Дирекционный угол в градусах
    double beta_deg = 73.0 + 24.0 / 60.0 + 51.7 / 3600.0;   // Угол поворота в градусах
    double m_alpha_sec = 1.2;     // Погрешность дирекционного угла, сек
    double m_beta_sec = 2.0;      // Погрешность угла поворота, сек

    // Перевод углов и их погрешностей в радианы
    double alpha = alpha_deg * M_PI / 180.0;
    double beta = beta_deg * M_PI / 180.0;
    double m_alpha = m_alpha_sec * M_PI / 648000.0;
    double m_beta = m_beta_sec * M_PI / 648000.0;

    // Сумма углов
    double sum_angle = alpha + beta;

    // Вычисление тригонометрических функций
    double cos_sum = std::cos(sum_angle);
    double sin_sum = std::sin(sum_angle);

    // Формула для предельной погрешности
    double m_Dx = std::sqrt(
        std::pow(cos_sum * m_S, 2) +
        std::pow(S * sin_sum * m_alpha, 2) +
        std::pow(S * sin_sum * m_beta, 2)
    );

    // Вывод результата
    std::cout << "Предельная погрешность приращения координат по оси абсцисс: "
              << m_Dx << " м" << std::endl;

    return 0;
}