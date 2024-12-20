#pragma once
#include "Product.h"
#include <vector>

//Класс для хранения информации о заказе
class Order {
private:
    int client_id;
    vector<Product> products; // Массив объектов Product
    int num_products;
    int total_price;
public:
    Order(); //конструктор
    void addProduct(Product& newProduct); //Выделение места под Products
    void get(int* client_id, int* num_products, int* total_price); //Получение данных класса
    void set(int client_id, int num_products, int total_price); //Получение данных класса
    void listProducts(Product* product, int count);
    int getTotalprice() {
        return total_price;
    }
};
