#pragma once
#include "OrderHistory.h"

// Определение контруктора класса OrderHistory
OrderHistory::OrderHistory()
{
    orderCount = 0;
}

// Определение функции - члена класса OrderHistory для вывода истории заказов
void OrderHistory::listOrders(Order* order, int count) {
    for (int i = 0; i < orderCount; i++) {
        if (i == count) *order = orders[i];
    }
}

// Определение функции - члена класса OrderHistory - функции addOrder()
void OrderHistory::addOrder(Order& newOrder) {
    orders.push_back(newOrder); // Добавляем заказ
    orderCount++;
}
