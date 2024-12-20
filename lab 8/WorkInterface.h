#pragma once
#include <stdio.h>

//Интерфейсы действий
class ProjectManagement {
public:
    virtual void manageProject() = 0; // Метод для управления проектом
};

class Testing {
public:
    virtual void spendTesting() = 0; // Метод для проведения тестирования
};

//Классы делегатов
class MainManager : public ProjectManagement { // класс поведения для работников, которые руководят проектом
public:
    void manageProject() {
        printf("Я управляю разработчиками!\n");
    }
};

class AssistentManager : public ProjectManagement { // класс поведения для работников, которые управля проектом
public:
    void manageProject() {
        printf("Я управляю проектом!\n");
    }
};

class NoManager : public ProjectManagement { // класс поведения для работников, которые управля проектом
public:
    void manageProject() {
        printf("Я не управляю проектом!\n");
    }
};

class MainTester : public Testing { // класс поведения для работников, которые тестируют программу
public:
    void spendTesting() {
        printf("Я занимаюсь тестировкой готового проекта!\n");
    }
};

class AssistentTester : public Testing { // класс поведения для работников, которые тестируют программу
public:
    void spendTesting() {
        printf("Я занимаюсь первичной тестировкой проекта, на этапе реализации!\n");
    }
};

class NoTester : public Testing { // класс поведения для работников, которые тестируют программу
public:
    void spendTesting() {
        printf("Я не занимаюсь тестировкой проекта!\n");
    }
};

// абстрактный класс функции работников
class WorkInterface {
public:
    ProjectManagement* management;
    Testing* testing;
    // делегируем выполнение операции классам поведения :
    void performManage() { management->manageProject(); }
    void performTesting() { testing->spendTesting(); }
};