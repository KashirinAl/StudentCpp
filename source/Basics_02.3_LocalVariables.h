﻿// Рассматриваемые темы:
// Локальные переменные

#pragma once

#include <iostream>
using namespace std;

namespace LocalVariables
{
    void Func()
    { // <-- Начало блока кода фун-ции Func
        int c = 3;

        // cout << a; // Ошибка: Идентификатор 'а' не найден
        // cout << b; // Ошибка: Идентификатор 'b' не найден
        cout << c << endl; // Ошибки не будет
    } // <-- Конец блока кода фун-ции Func

    void main()
    { // <-- Начало блока кода фун-ции main
        int a = 1;
        for(int i = 0; i < 3; i++)
        { // <-- Начало блока кода цикла for
            int b = 2;
            b = b+1;

            cout << "a = " << a << endl; // Ошибки не будет
            cout << "b = "  << b << endl; // Ошибки не будет
            // cout << c; // Ошибка: Идентификатор 'с' не найден
            cout << "i = "  << i << endl; // Ошибки не будет
        } // <-- Конец блока кода цикла for

        cout << a << endl; // Ошибки не будет
        // cout << b; // Ошибка: Идентификатор 'b' не найден
        // cout << c; // Ошибка: Идентификатор 'с' не найден
        // cout << i; // Ошибка: Идентификатор 'i' не найден
    } // <-- Конец блока кода фун-ции main
}