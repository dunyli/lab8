#pragma once
#include "Storehouse.h"
#include "memory"

// Определение контруктора класса Storehouse
Storehouse::Storehouse()
{
    num_products = 0;
    capacity = 1;
    products = new shared_ptr<Product>[capacity]; // Инициализируем массив указателей
}

//Определение функции-члена класса Storehouse для вывода списка товаров
void Storehouse::listStorehouse(Product& productCopy, int count) {
    for (int i = 0; i < num_products; ++i) {
        if (i == count) products[i]->copyTo(productCopy); // Копируем данные в переданный объект; 
    }
}

void Storehouse::addProduct(Product& newProduct) {
        if (num_products >= capacity) {
            capacity++;
            // Увеличиваем вместимость
            shared_ptr<Product>* new_products = new shared_ptr<Product>[capacity]; // Создаем новый массив
            // Копируем старые указатели в новый массив
            for (int i = 0; i < num_products; ++i) {
                new_products[i] = products[i];
            }
            delete[] products; // Освобождаем старый массив
            products = new_products; // Обновляем указатель на массив
        }
        // Создаем новый объект Product и добавляем его в массив
        products[num_products] = make_shared<Product>(newProduct);
        num_products++; // Увеличиваем количество продуктов
}


void Storehouse::editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id) {
    products[product_id]->set(name, price, volume, category_id, supplier_id);
}
