#pragma once
#include "WorkInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Worker {
protected:
    string name_worker;
    int id_worker;
    int yearsOfExperience; //Общее количество лет опыта
public:
    // Запрет конструктора по умолчанию
    Worker() = delete;
    //Конструктор с параметрами
    Worker(string name, int id, int yearsOfExperience) {
        if (name.empty()) {
            throw invalid_argument("Имя не может быть пустым.");
        }
        if (id < 0) {
            throw invalid_argument("ID не может быть отрицательным.");
        }
        if (yearsOfExperience < 0) {
            throw invalid_argument("Опыт не может быть отрицательным.");
        }
        this->name_worker = name;
        this->id_worker = id;
        this->yearsOfExperience = yearsOfExperience;
    }

    // Конструктор поверхностного клонирования
    Worker(Worker* other) {
        if (other == nullptr) {
            throw invalid_argument("Указатель на объект не может быть нулевым.");
        }
        name_worker = other->name_worker;
        id_worker = other->id_worker;
        yearsOfExperience = other->yearsOfExperience;
    }

    //Деструктор
    virtual ~Worker() {};

    // Метод для отображения информации о работнике
    virtual void displayInfo() {
        cout << "Работник: " << name_worker << ", ID: " << id_worker << ", Опыт: " << yearsOfExperience << " лет" << endl;
    }

    //Метод для вывода зарплаты после оплаты налогов
    int getSalary() {
        int cash = getCash();
        if (cash < 20000) cash = cash - (cash % 10);
        else if (cash < 40000) cash = cash - (cash % 15);
        else if (cash < 80000) cash = cash - (cash % 18);
        else cash = cash - (cash % 20);
        return cash;
    }
    // Метод для изменения имени работника
    virtual void changeName(string& newName) {
        if (newName.empty()) {
            throw invalid_argument("Новое имя не может быть пустым.");
            name_worker = newName;
        }
        cout << "Имя работника изменено:: " << name_worker << endl;
    }

    // Метод для подсчета зарплаты работника
    virtual int getCash() {
        return yearsOfExperience * 1000;
    }

    int getYears() {
        return yearsOfExperience;
    }

    // Метод для получения идентификационного номера
    int getId() {
        return id_worker;
    }

    // Метод для получения имени работника
    string getName(){
        return name_worker;
    }
};

class Tester : public Worker, public WorkInterface {
private:
    int yearsAsTester; 
public:
    // Конструктор
    Tester(string name, int id, int yearsOfExperience, int yearsAsTester)
        : Worker(name, id, yearsOfExperience), yearsAsTester(yearsAsTester) {
        testing = new AssistentTester;
        management = new NoManager;
    }

    // Реализация метода управления проектом
    void manageProject(string projectName) {
        cout << "Тестировщик " << name_worker << " управляет тестированием проекта: " << projectName << endl;
    }

    // Реализация метода тестирования
    void conductTesting(string projectName) {
        cout << "Тестировщик " << name_worker << " проводит тестирование для проекта: " << projectName << endl;
    }

    // Переопределение метода displayInfo
    void displayInfo() {
        cout << "Тестировщик: " << name_worker << ", ID: " << id_worker << ", Опыт: " << yearsOfExperience << " лет" << endl;
    }

};

class TeamLead : public Worker, public WorkInterface {
private:
    int yearsAsTeamLead;
    int teamSize; // Размер команды
public:
    // Конструктор
    TeamLead(string name, int id, int yearsOfExperience, int yearsAsTester, int teamSize)
        : Worker(name, id, yearsOfExperience), yearsAsTeamLead(yearsAsTeamLead), teamSize(teamSize) {
        management = new AssistentManager;
        testing = new MainTester;
    }

    // Реализация метода управления проектом
    void manageProject(string projectName){
        cout << "Тимлид " << name_worker << " управляет проектом: " << projectName << " с размером команды: " << teamSize << endl;
    }

    // Переопределение метода displayInfo
    void displayInfo() {
        cout << "Тимлид: " << name_worker << ", ID: " << id_worker << ", Опыт: " << yearsOfExperience << " лет, Размер команды: " << teamSize << endl;
    }
};

// Класс для менеджера, унаследованный от Worker
class Manager : public Worker{
private:
    string department;
    vector<string> teamMembers; // Указатель на динамический массив членов команды
    int teamSize; // Размер команды
    int yearsAsManager; // Количество лет опыта в качестве менеджера
public:
    //Конструктор
    Manager(string name, int id, int yearsOfExperience) : Worker(name, id, yearsOfExperience){
        teamSize = 0;
    }

    // Запрет конструктора по умолчанию
    Manager() = delete;

    // Конструктор менеджера, вызывающий конструктор базового класса
    Manager(string name, int id, int yearsOfExperience, string department, int yearsAsManager, int teamSize)
        : Worker(name, id, yearsOfExperience), department(department), yearsAsManager(yearsAsManager), teamSize(teamSize) {
        if (department.empty()) {
            throw invalid_argument("Отдел не может быть пустым.");
        }
        if (yearsAsManager < 0) {
            throw invalid_argument("Опыт не может быть отрицательным.");
        }
    }

    // Конструктор клонирования
    Manager(Manager& other) : Worker(other) {
        department = other.department;
        yearsAsManager = other.yearsAsManager;
        teamSize = other.teamSize;
        for (int i = 0; i < teamSize; ++i) {
            teamMembers[i] = other.teamMembers[i]; // Копируем строки
        }
    }

    // Функция для получения количества лет опыта в качестве менеджера
    int getCash() override {
        int years;
        years = yearsOfExperience - yearsAsManager;
        return yearsAsManager * 5000 + years * 1000;
    }

    //Возможна перегрузка метода в производном классе, с такими же параметрами как в базовом классе. 
    void displayInfo() override {
        cout << "Менеджер: " << name_worker << ", ID: " << id_worker << ", Опыт: " << yearsAsManager << 
            " лет в качестве менеджера" << endl;
        cout << "Члены команды: ";
        for (int i = 0; i < teamSize; ++i) {
            cout << teamMembers[i] <<  ", ";
        }
        cout << endl;
    }
    
    // Метод для добавления члена команды
    void addTeamMember(string& member) {
        teamMembers.push_back(member);
        teamSize++;
    }

    // Перегрузка метода changeName, вызывая метод базового класса
    void changeName(string& newName) override {
        Worker::changeName(newName); // Вызов метода базового класса
        cout << "Имя менеджера изменено на: " << name_worker << endl;
    }

    void setYears(int year) {
        yearsAsManager = year;
    }

    // Метод для получения информации о департаменте
    string getDepartment() {
        return department;
    }

    // Метод для получения информации о 
    int getTeamSize() {
        return teamSize;
    }

    //Метод для получения Отдела
    void setDepartment(string department) {
        this->department = department;
    }

    // Перегрузка оператора присваивания объекту производного класса объектов базового класса
    void operator=(Worker other) {
        this->name_worker = other.getName();
        this->id_worker = other.getId();
        this->yearsOfExperience = other.getYears();
        // Задание значений недостающим полям
        department = "Неизвестный отдел"; // Устанавливаем значения по умолчанию
        teamSize = 0; // Обнуляем размер команды
        yearsAsManager = 0;
    }

};


// Класс для хранения работников
class WorkerDatabase {
private:
    vector<unique_ptr<Worker>> workers; // Вектор уникальных указателей на работников
    int num_workers;
public:
    WorkerDatabase() { num_workers = 0; }

    // Метод для добавления работника
    void addWorker(unique_ptr<Worker> worker) {
        workers.push_back(move(worker)); // Добавляем работника в базу
        num_workers++;
    }

    // Метод для отображения всех работников
    void displayAllWorkers() {
        for (int i = 0; i < num_workers; i++) {
            workers[i]->displayInfo(); // Вызываем виртуальную функцию displayInfo
        }
    }

    //Метод для проверки ID
    int checkID(int id) {
        for (int i = 0; i < num_workers; i++) {
            if (id == workers[i]->getId()) return 1;
        }
        return 0;
    }

    // Метод для поиска работника по ID
    void findWorkerById(int id, Worker& worker) {
        for (int i = 0; i < num_workers; i++) {
            if (worker.getId() == id) {
                worker = *workers[i];
            }
        }
    }

    // Метод для демонстрации вызова виртуальной функции
    void showWorkerInfo(Worker* worker) {
        cout << "Информация о работнике:\n";
        worker->displayInfo(); // Вызов виртуальной функции
    }

    int getnum_workers() {
        return num_workers;
    }
};