#pragma once
#include <iostream>
#include <string>
#include "Supplier.h"
#include "Client.h"
#include "Category.h"
#include <vector>
using namespace std;

//Класс для хранения информации о магазине
class Store {
private:
    vector<Client> clients;
    int num_clients;
    vector<Category> categories;
    int num_categories;
    vector<Supplier> suppliers;
    int num_suppliers;
public:
    Store(); //конструктор
    void addClient(Client& newClient);
    void addCategory(Category& newCategory);
    void addSupplier(Supplier& newSupplier);
    void listClients(Client* client, int count);
    void listCategories(Category* category, int count);
    void listSuppliers(Supplier* supplier, int count);
    int listnum_categories() {
        return num_categories;
    };
    int listnum_suppliers() {
        return num_suppliers;
    };
    int listnum_clients() {
        return num_clients;
    };
    // Метод для получения списка всех категорий
    vector<Category> getCategories() {
        return categories;
    }
};