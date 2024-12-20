#pragma once
#include "Order.h"
#include "vector"

//Класс для хранения истории заказов
class OrderHistory {
private:
    vector<Order> orders; // Массив объектов Order
    int orderCount;
public:
    OrderHistory();
    void addOrder(Order& newOrder);
    void listOrders(Order* order, int count);
    int listorder_count() {
        return orderCount;
    };
};