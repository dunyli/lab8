#pragma once
#include <iostream>
#include <string>
#include "Product.h"
#include <vector>

//����� ��� �������� ���������� � ���������� ������
class Storehouse {
private:
    vector<Product> products; // ������ �������� Product
    int num_products;
public:
    Storehouse(); //�����������
    void addProduct(Product& newProduct);
    void editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id);
    void listStorehouse(Product* productCopy, int count);
    void get(int num_products); //��������� ������ ������
    int listnum_products() {
        return num_products;
    };
    // ����� ��� ��������� ������ ���� ���������
    vector<Product> getProducts(){
        return products;
    }
};
