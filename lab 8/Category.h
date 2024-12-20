#pragma once
#include <iostream>
#include "Product.h"

// Класс для хранения данных о категории товара
class Category {
private:
    string name;   // Название категории ("Корм", "Игрушки", "Аксессуары")
    int num_products;
public:
    Category() {};
    Category(string name); //конструктор с параметрами
    std::string get(); //Получение данных класса
    void set(string name); //Получение значений переменных-членов класса
    // Перегрузка оператора вывода
    friend ostream& operator << (ostream& os, Category& c);
};

