#pragma once
#include <iostream>
#include <string>
#include "Product.h"
#include <vector>

//Класс для хранения информации о количестве товара
class Storehouse {
private:
    vector<Product> products; // Массив объектов Product
    int num_products;
public:
    Storehouse(); //конструктор
    void addProduct(Product& newProduct);
    void editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id);
    void listStorehouse(Product* productCopy, int count);
    void get(int num_products); //Получение данных класса
    int listnum_products() {
        return num_products;
    };
    // Метод для получения списка всех продуктов
    vector<Product> getProducts(){
        return products;
    }
};
