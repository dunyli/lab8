#pragma once
#include "Store.h"
#include <string>

// Определение контруктора класса Store
Store::Store()
{
    num_clients = 0;
    num_categories = 0;
    num_suppliers = 0;
}

//Определение функции-члена класса Store для вывода списка клиентов
void Store::listClients(Client* client, int count) {
    for (int i = 0; i < num_clients; i++) {
        if (i == count) *client = clients[i];
    }
}

//Определение функции-члена класса Store для вывода списка категорий
void Store::listCategories(Category* category, int count) {
    for (int i = 0; i < num_categories; i++) {
        if (i == count) *category = categories[i];
    }
}

//Определение функции-члена класса Store для вывода списка поставщиков
void Store::listSuppliers(Supplier* supplier, int count) {
    for (int i = 0; i < num_suppliers; i++) {
        if (i == count) *supplier = suppliers[i];
    }
}

void Store::addClient(Client& newClient) {
    clients.push_back(newClient); // Добавляем клиента
    num_clients++;
}

void Store::addCategory(Category& newCategory) {
    categories.push_back(newCategory); // Добавляем категорию
    num_categories++;
}

void Store::addSupplier(Supplier& newSupplier) {
    suppliers.push_back(newSupplier); // Добавляем поставщика
    num_suppliers++;
}
