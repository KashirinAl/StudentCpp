﻿// Рассматриваемые темы:
// Разница между указателями и ссылками

#pragma once
#include <iostream>
using namespace std;

namespace ReferencesVsPointers
{
   /*
    * Рассмотрим подробнее разницу применения указателей и ссылок
    * на примере передачи параметров в функцию.
    * 
    * Создадим 3 ф-ции.
    */

   // Ф-ция с передачей параметра по значению
   void funcWithValue(int a)
   /*
    * При передаче параметра по значению создается копия переменной.
    * Допустим, вызов ф-ции выглядит примерно так:
    * 
    * int var1 = 1;
    * funcWithValue(var1);
    * 
    * Тогда когда ф-ция вызовется состояние памяти будет следующее:
    * 
    *          var1              a
    *       |--------|       |--------|  
    *       |    1   |       |    1   |
    *       |--------|       |--------| 
    *       
    * Изначальная переменная var1 была скопирована, а новой ячейке
    * было присвоено имя параметра - a.
    */
   {
      a++;

      /*
       * Переменная а была увеличена на 1. А изначальная переменная осталась без изменений.
       * 
       *          var1              a
       *       |--------|       |--------|
       *       |    1   |       |    2   |
       *       |--------|       |--------|
       */
   }
   /*
    * Ф-ция завершилась и все ее локальные переменные, которой и является параметр ф-ции уничтожаются.
    * 
    *          var1
    *       |--------|
    *       |    1   |
    *       |--------|
    *       
    * Изначальная переменная никак не изменилась.
    */


   // Ф-ция с передачей параметра по ссылке
   void funcWithReference(int& a)
   /*
   * При передаче параметра по ссылке изначальной переменной дается альтернативное имя.
   * Допустим, вызов ф-ции выглядит примерно так:
   *
   * int var2 = 1;
   * funcWithReference(var2);
   *
   * Тогда когда ф-ция вызовется состояние памяти будет следующее:
   *
   *        var2, a
   *       |--------|
   *       |    1   |
   *       |--------|
   *
   * Изначальная переменная var2 получила второе имя - а, через которое к ней можно обращаться
   */
   {
      a++;

      /*
      * Переменная а была увеличена на 1.
      *
      *        var2, a
      *       |--------|
      *       |    2   |
      *       |--------|
      *       
      * Т.к. имена a и var2 - это одна и та же ячейка в памяти, то именно она и была изменена.
      */
   }
   /*
   * Ф-ция завершилась и все ее локальные переменные, которой и является параметр ф-ции уничтожаются.
   * Т.к. a - это просто ссылка, то уничтожение переменной-ссылки, это просто убирание второго имени
   * у переменной.
   *
   *          var2
   *       |--------|
   *       |    2   |
   *       |--------|
   *
   * Второе имя у ячейки пропало. Но значение-то уже было изменено.
   */

   // Ф-ция с параметром-указателем
   void funcWithPointer(int* a)
   /*
    * Как думаете, какая это передача параметра: 
    * по ссылке или по значению?
    * 
    * Это просто. Ответьте на другой вопрос:
    * Параметр является ссылкой?
    * Ответ: нет.
    * 
    * Значит, это передача параметра по значению!
    * 
    * Теперь допустим, что вызов ф-ции выглядит следующий образом:
    * int var3 = 1;
    * funcWithPointer(&var3);
    * 
    * Чтобы вызов был корретным и совпали типы параметра и передаваемого значения,
    * нам пришлось использовать оператор & - взятие адреса у переменной.
    * 
    * Т.е. в памяти это выглядит следующим образом:
    * 
    *      0xFFF1, var3          a
    *       |--------|       |--------|
    *       |    1   |       | 0xFFF1 |
    *       |--------|       |--------|
    *       
    * где число 0xFFF1 - адрес переменной var3.
    * 
    * А теперь давайте посмотрим, если вызов ф-ции выглядел по-другому:
    * int var4 = 1;
    * int* ptr = &var4;
    * funcWithPointer(ptr);
    * 
    * Тогда после вызова ф-ции состояние памяти следующее:
    * 
    *      0xFFF2, var4          ptr               a
    *       |--------|       |--------|       |--------|
    *       |    1   |       | 0xFFF2 |       | 0xFFF2 |
    *       |--------|       |--------|       |--------|
    *       
    * На этом примере видно, что в этой ф-ции на самом деле 
    * идет передача параметра именно по значению
    * 
    * В первом случае это не было так очевидно, потому что адрес переменной
    * вычислялся прямо во время вызова ф-ции, он не сохранялся в отдельную переменную,
    * а сразу сохранился в созданный параметр ф-ции.
    * 
    * Здесь же переменная с адресом существовует еще до вызова ф-ции,
    * а при вызове ф-ции создается копия передаваемой переменной.
    * 
    * Казалось бы, какая разница. Но передача параметра-указателя - 
    * это не то же самое, что передача параметра по ссылке.
    * 
    * Да, мы будем работать с изначальной ячейкой памяти, через адрес этой ячейки,
    * но "под капотом" все выглядит совсем по-другому, чем с сссылками
   */
   {
      (*a)++;

      /*
       * Значение ячейки, находящейся по адресу из указателя а, было увеличено на 1.
       * 
       *      0xFFF2, var4          ptr               a
       *       |--------|       |--------|       |--------|
       *       |    2   |       | 0xFFF2 |       | 0xFFF2 |
       *       |--------|       |--------|       |--------|
       *           ^                                  ^
       *           |                                  |
       *           |                         взяли адрес отсюда
       *           |               и пошли по этому адрес менять значение
       *           |                                  |
       *           -----------------------------------
       */
   }
   /*
    * Ф-ция завершилась. Уничтожение локальных переменных.
    * 
    *      0xFFF2, var4          ptr
    *       |--------|       |--------|
    *       |    2   |       | 0xFFF2 |
    *       |--------|       |--------|
    */

   // TODO funcWithPointerReference

   /*
    * Ну а теперь разберем самый упоротый вариант, которые некоторые личности иногда
    * используют за что огребают от меня по первое число, потому что даже объяснить не могут
    * зачем творят эту дичь.
    */

   void funcWithPointerReference(int*& a)
   /*
    * На первый взгляд заголовок этой ф-ции абсолютно такой же, как и в преедыдущем варианте funcWithPointer.
    * Да, такое же. За искллюючением того, что указатель здесь - ссылка.
    * 
    * Ага. Указателль и ссылка в одном флаконе. 
    * 
    * Допустим, вызов будет таким:
    * 
    * int var4 = 1;
    * int* ptr = &var4;
    * funcWithPointer(ptr);
    * 
    * Тогда в памяти получим:
    * 
    * 
    *      0xFFF3, var3        ptr, a
    *       |--------|       |--------|
    *       |    1   |       | 0xFFF3 |
    *       |--------|       |--------|
    *       
    * Иногда в указателе-ссылке есть смысл. Например, если вам нужно хранить постоянно изменяющийся
    * адрес на какой-то объект, причем чтобы изменялся этот адрес сразу в нескольких местах.
    * 
    * Тогда да, это как раз то, что нужно. Но обычно начинающие по незнания начинают пихать ссылку
    * во все ф-ции просто потому что "ну это типа хорошо, не будет копирования данных", а задуматься
    * о целесообразности ссылки и что копирование не всегда плохо, а только при больших объемах
    * данных - забывают.
    * 
    */
   {
      (*a)++;
   }

   /*
    * Теперь надеюсь всем предельно ясно, что ссылки и указатели
    * совершенно разные в применении механизмы языка С++.
    * 
    * Поэтому не надо их путать.
    */

   void main()
   {
      int var1 = 1;
      funcWithValue(var1);

      int var2 = 1;
      funcWithReference(var2);

      int var3 = 1;
      funcWithPointer(&var3);

      int var4 = 1;
      int* ptr = &var4;
      funcWithPointer(ptr);
   }
}