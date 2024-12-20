#pragma once
#include "Storehouse.h"
#include "memory"

// Определение контруктора класса Storehouse
Storehouse::Storehouse()
{
    num_products = 0;
}

//Определение функции-члена класса Storehouse для вывода списка товаров
void Storehouse::listStorehouse(Product *product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

void Storehouse::addProduct(Product& newProduct) {
    products.push_back(newProduct); // Добавляем заказ
    num_products++;
}


void Storehouse::editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id) {
    products[product_id].set(name, price, volume, category_id, supplier_id);
}
