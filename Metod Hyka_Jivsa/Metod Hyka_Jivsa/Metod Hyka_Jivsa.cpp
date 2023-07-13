// Metod Hyka_Jivsa.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <locale> 
#include <cmath>
#include <iomanip>
// �������, ��� ������� �� ����� ����� �������
double targetFunction(double x, double y) {
    return pow(x, 4) + pow(y, 4) - 4 * x * y;
}
// ������� ��� ����������� � ����� ����� ����� ����� �� ����
double moveCoordinate(double coordinate, double stepSize, bool positiveDirection){
    if (positiveDirection)
        return coordinate + stepSize;
    else
        return coordinate - stepSize;
}
// �������� �������, ����������� ����� ����-������
void hookJeevesMethod(double& x, double& y, double stepSize, double precision){
    double bestX = x;
    double bestY = y;
    double currentValue = targetFunction(x, y);
    while (stepSize > precision){
        // ��������� ������� ��������
        double prevValue = currentValue;
        // ������������ � ������������� ����������� �� ��� X
        double newX = moveCoordinate(x, stepSize, true);
        double newValue = targetFunction(newX, y);
        // ���� ����� �������� ����� ��������, ��������� ���
        if (newValue < currentValue){
            x = newX;
            currentValue = newValue;
        }
        else{
            // ������������ � ������������� ����������� �� ��� X
            newX = moveCoordinate(x, stepSize, false);
            newValue = targetFunction(newX, y);
            // ���� ����� �������� ����� ��������, ��������� ���
            if (newValue < currentValue) {
                x = newX;
                currentValue = newValue;
            }
        }
        // ������������ � ������������� ����������� �� ��� Y
        double newY = moveCoordinate(y, stepSize, true);
        newValue = targetFunction(x, newY);
        // ���� ����� �������� ����� ��������, ��������� ���
        if (newValue < currentValue) {
            y = newY;
            currentValue = newValue;
        }
        else {
            // ������������ � ������������� ����������� �� ��� Y
            newY = moveCoordinate(y, stepSize, false);
            newValue = targetFunction(x, newY);
            // ���� ����� �������� ����� ��������, ��������� ���
            if (newValue < currentValue) {
                y = newY;
                currentValue = newValue;
            }
        }
        // ���� �� ������� �������� �������� �������, ��������� ���
        if (currentValue >= prevValue)
            stepSize /= 2.0;
    }
    // ������� ���������
    std::cout << "������� ������� ����������� � ����� (" << bestX
              << ", " << bestY << ")" << std::endl;
    std::cout << "�������� ������� � ���� �����: " << currentValue << std::endl;
}

int main(int argc, TCHAR* argv[]) {
	setlocale (LC_ALL, "Russian_Russia.1251");
    // ��������� �����������
    double x ;
    double y ;
	std::cout<<"������� � � � �� �������� :x=1.0 "<<std::endl;
	std::cout<<"x = ";
	std::cin >> x;
	std::cout<<std::endl<<"y = ";
	std::cin >> y;
    // ��� � ��������
    double stepSize ;
    double precision ;
	std::cout<<"������� �������� ���� =";
	std::cin>>stepSize;
	std::cout<<std::endl<<"������� �������� �������� ,������������� = 0.00001";
	std::cout<<"�������� = ";
	std::cin>>precision;
	std::cout<<"�������� ������� f(x,y) = "<<targetFunction( x,  y)<<std::endl;
    // ��������� ����� ����-������
    hookJeevesMethod(x, y, stepSize, precision);

    system("pause");
}

