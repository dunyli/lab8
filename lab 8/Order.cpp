#pragma once
#include "Order.h"
#include "Product.h"

// Определение контруктора класса Order
Order::Order()
{
    client_id = 0;
    num_products = 0;
    total_price = 0;
}

//Получение значений переменных-членов класса и данных класса Order
void Order::get(int* client_id, int* num_products, int* total_price) {
    *client_id = this->client_id;
    *num_products = this->num_products;
    *total_price = this->total_price;
}

//Функция для получения значений переменных-членов класса
void Order::set(int client_id, int num_products, int total_price) {
    this->client_id = client_id;
    this->num_products = num_products;
    this->total_price = total_price;
}

//Определение функции-члена класса Order для вывода истории заказов
void Order::listProducts(Product* product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

// Определение функции - члена класса Order - функции addProduct()
void Order::addProduct(Product& newProduct) {
    products.push_back(newProduct); // Добавляем клиента
    num_products++;
}