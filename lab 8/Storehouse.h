#pragma once
#include <iostream>
#include <string>
#include "Product.h"

//Класс для хранения информации о количестве товара
class Storehouse {
private:
    shared_ptr<Product>* products; // Массив указателей на объекты Product
    int num_products;
    int num_animals;
    int capacity; // Вместимость массива
public:
    Storehouse(); //конструктор
    void addProduct(Product& newProduct);
    void editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id);
    void listStorehouse(Product& productCopy, int count);
    void get(int num_products); //Получение данных класса
    int listnum_products() {
        return num_products;
    };
};
