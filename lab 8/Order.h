#pragma once
#include "Product.h"
#include <vector>

//����� ��� �������� ���������� � ������
class Order {
private:
    int client_id;
    vector<Product> products; // ������ �������� Product
    int num_products;
    int total_price;
public:
    Order(); //�����������
    void addProduct(Product& newProduct); //��������� ����� ��� Products
    void get(int* client_id, int* num_products, int* total_price); //��������� ������ ������
    void set(int client_id, int num_products, int total_price); //��������� ������ ������
    void listProducts(Product* product, int count);
    int getTotalprice() {
        return total_price;
    }
};
