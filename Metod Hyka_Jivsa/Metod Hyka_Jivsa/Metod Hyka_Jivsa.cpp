// Metod Hyka_Jivsa.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <locale> 
#include <cmath>
#include <iomanip>
// Функция, для которой мы хотим найти минимум
double targetFunction(double x, double y) {
    return pow(x, 4) + pow(y, 4) - 4 * x * y;
}
// Функция для перемещения к новой точке вдоль одной из осей
double moveCoordinate(double coordinate, double stepSize, bool positiveDirection){
    if (positiveDirection)
        return coordinate + stepSize;
    else
        return coordinate - stepSize;
}
// Основная функция, реализующая метод Хука-Дживса
void hookJeevesMethod(double& x, double& y, double stepSize, double precision){
    double bestX = x;
    double bestY = y;
    double currentValue = targetFunction(x, y);
    while (stepSize > precision){
        // Сохраняем текущее значение
        double prevValue = currentValue;
        // Перемещаемся в положительном направлении по оси X
        double newX = moveCoordinate(x, stepSize, true);
        double newValue = targetFunction(newX, y);
        // Если новое значение лучше текущего, принимаем его
        if (newValue < currentValue){
            x = newX;
            currentValue = newValue;
        }
        else{
            // Перемещаемся в отрицательном направлении по оси X
            newX = moveCoordinate(x, stepSize, false);
            newValue = targetFunction(newX, y);
            // Если новое значение лучше текущего, принимаем его
            if (newValue < currentValue) {
                x = newX;
                currentValue = newValue;
            }
        }
        // Перемещаемся в положительном направлении по оси Y
        double newY = moveCoordinate(y, stepSize, true);
        newValue = targetFunction(x, newY);
        // Если новое значение лучше текущего, принимаем его
        if (newValue < currentValue) {
            y = newY;
            currentValue = newValue;
        }
        else {
            // Перемещаемся в отрицательном направлении по оси Y
            newY = moveCoordinate(y, stepSize, false);
            newValue = targetFunction(x, newY);
            // Если новое значение лучше текущего, принимаем его
            if (newValue < currentValue) {
                y = newY;
                currentValue = newValue;
            }
        }
        // Если не удалось улучшить значение функции, уменьшаем шаг
        if (currentValue >= prevValue)
            stepSize /= 2.0;
    }
    // Выводим результат
    std::cout << "Минимум функции достигается в точке (" << bestX
              << ", " << bestY << ")" << std::endl;
    std::cout << "Значение функции в этой точке: " << currentValue << std::endl;
}

int main(int argc, TCHAR* argv[]) {
	setlocale (LC_ALL, "Russian_Russia.1251");
    // Начальное приближение
    double x ;
    double y ;
	std::cout<<"введите х и у по аналогии :x=1.0 "<<std::endl;
	std::cout<<"x = ";
	std::cin >> x;
	std::cout<<std::endl<<"y = ";
	std::cin >> y;
    // Шаг и точность
    double stepSize ;
    double precision ;
	std::cout<<"укажите величину шага =";
	std::cin>>stepSize;
	std::cout<<std::endl<<"укажите значение точности ,рекомендуемая = 0.00001";
	std::cout<<"точность = ";
	std::cin>>precision;
	std::cout<<"значение функции f(x,y) = "<<targetFunction( x,  y)<<std::endl;
    // Применяем метод Хука-Дживса
    hookJeevesMethod(x, y, stepSize, precision);

    system("pause");
}

