#pragma once
#include <stdio.h>

//���������� ��������
class ProjectManagement {
public:
    virtual void manageProject() = 0; // ����� ��� ���������� ��������
};

class Testing {
public:
    virtual void spendTesting() = 0; // ����� ��� ���������� ������������
};

//������ ���������
class MainManager : public ProjectManagement { // ����� ��������� ��� ����������, ������� ��������� ��������
public:
    void manageProject() {
        printf("� �������� ��������������!\n");
    }
};

class AssistentManager : public ProjectManagement { // ����� ��������� ��� ����������, ������� ������� ��������
public:
    void manageProject() {
        printf("� �������� ��������!\n");
    }
};

class NoManager : public ProjectManagement { // ����� ��������� ��� ����������, ������� ������� ��������
public:
    void manageProject() {
        printf("� �� �������� ��������!\n");
    }
};

class MainTester : public Testing { // ����� ��������� ��� ����������, ������� ��������� ���������
public:
    void spendTesting() {
        printf("� ��������� ����������� �������� �������!\n");
    }
};

class AssistentTester : public Testing { // ����� ��������� ��� ����������, ������� ��������� ���������
public:
    void spendTesting() {
        printf("� ��������� ��������� ����������� �������, �� ����� ����������!\n");
    }
};

class NoTester : public Testing { // ����� ��������� ��� ����������, ������� ��������� ���������
public:
    void spendTesting() {
        printf("� �� ��������� ����������� �������!\n");
    }
};

// ����������� ����� ������� ����������
class WorkInterface {
public:
    ProjectManagement* management;
    Testing* testing;
    // ���������� ���������� �������� ������� ��������� :
    void performManage() { management->manageProject(); }
    void performTesting() { testing->spendTesting(); }
};