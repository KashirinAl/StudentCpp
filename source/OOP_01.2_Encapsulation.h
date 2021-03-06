﻿// Рассматриваемые темы:
// Инкапсуляция

#pragma once

#include <iostream>
#include <sstream>
using namespace std;

namespace Encapsulation
{
    // Зачем нужны публичные и приватные поля?
    // (Кстати, есть еще модификатор protected, но о нем немного позже)

    // Считается, что вне класса находится жестокий и злой мир,
    // а класс - маленький и беззащитный.
    // Чтобы защитить свой нежный внутренний мир, класс прячет от внешнего мира
    // все свои "потроха", чтобы кто-то случайно или намеренно не сломал
    // информацию внутри класса.

    // Такой механизм называется ИНКАПСУЛЯЦИЕЙ
    // Инкапсуляция - сокрытие сложности и внутренней структуры класса.

    // Если серьезно, то класс представляется в виде "черного ящика":
    // какой алгоритм скрыт в нем, как класс работает, какие поля в нем есть - 
    // недопустимо знать пользователю, а тем более иметь возможость изменять
    // информацию в классе напрямую.

    // Все это делается из рассчета обспечения безопасности.

    // По принципу инкапсуляции принято все поля делать приватными,
    // а доступ к полям организовывать с помощью методов.

    class Server
    {
        short ipAddress[4] = { 0, 0, 0, 0 };

    public:

        // Метод, который позволяет задать значение поля, называют
        // сеттером (от англ. setter).
        void setIpAddress(short array[])
        {
            // Если ip адрес уже был присвоен серверу...
            if (ipAddress[0] != 0 || ipAddress[1] != 0 || ipAddress[2] != 0 || ipAddress[3] != 0)
            {
                // то менять его уже нельзя!
                cout << "Ты кто такой, чтобы менять адрес у сервера?! Гуляй отсюда." << endl;

                // ВАЖНОЕ ЗАМЕЧАНИЕ
                // Т.к. на данном этапе обучения, обработка исключительных ситуаций (ошибок и т.д.)
                // еще темный лес, то сообщения об ошибках выводятся прямо в консоль, НО!!!
                // Работать с интерфейсом (консолью, например) внутри класса считается очень плохим тоном!
                // Но пока... Эх, пока придется делать так. Иначе мозг у кого-то может взорваться.

                return;
            }

            // Внутри сеттера часто помещают проверки на корректность данных
            for (int i = 0; i < 4; i++)
                // проверяем, чтобы все части ip адреса лежали в диапазоне от 1 до 255
                if (array[i] < 0 || array[i] > 255)
                {
                    cout << "IP адрес некорректен!" << endl;
                    return;
                }

            // Если адрес корректен, то сохраняем его
            for (int i = 0; i < 4; i++)
                ipAddress[i] = array[i];
        }

        // Метод, который позволяет получить значение поля, называют
        // геттером (от англ. getter).
        char* getIpAddress()
        {
            // Все любят потоки! 
            stringstream sout; // Поток работы со строкой
                               // Записываем в него данные как в обычный поток
            sout << ipAddress[0] << "." << ipAddress[1] << "." << ipAddress[2] << "." << ipAddress[3] << '\0';

            // Чтобы извлечь данные из потока:
            // sout.str() вернет строку типа данных string
            // если придерживаться правила не использовать, то что сам не можешь написать,
            // то чтобы из string получить char* вызываем метод c_str()
            char* ipString = new char[strlen(sout.str().c_str())];
            strcpy(ipString, sout.str().c_str());

            return ipString;
        }
    };

    void main()
    {
        short ip[4]{ 192, 168, 0, 1 };

        Server s;
        s.setIpAddress(ip);

        cout << s.getIpAddress() << endl;

        // Попробуем изменить ip адрес еще раз
        short ip2[4]{ 192, 168, 0, 100 };
        s.setIpAddress(ip); // А вот фиг вам! Там стоит защита.

        // ИТОГ
        // 1) Инкапсуляция помогает скрыть сложность класса
        // (пользователя не волнует, как мы храним данные внутри класса)
        // 2) Инкапсуляция обеспечивает уровень безопасности доступа к данным
        // 3) Инкапсуляция предоставляет механизм для безопасного изменения данных
        // (проверки на корректность данных и т.д.), вместо того, чтобы писать s.ipAddress = ...
    }
}