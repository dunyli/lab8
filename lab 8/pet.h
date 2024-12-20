#pragma once
#include "PetStoreService.h"

typedef PetStoreService* ptrService;

class Pet {
private:
	string name;
	int years;
	vector <ptrService> items;
public:
	void performAllServices();
	void performAllServiceInfo();
	void addService(PetStoreService* newService);

	Pet(string name, int years) {
		this->name = name;
		this->years = years;
		items.clear();
	}
	~Pet() {};

	void edit_name(string name) {
		this->name = name;
	}

	string get_name() {
		return name;
	}

	void edit_years(int years) {
		this->years = years;
	}
	int get_years() {
		return years;
	}
};

void Pet::performAllServices() {
	for (vector<ptrService>::iterator it = items.begin(); it != items.end(); it++) {
		(*it)->doService();
	}
}

void Pet::addService(PetStoreService* newService) {
	items.push_back(newService);
}

void Pet::performAllServiceInfo() {
	for (vector<ptrService>::iterator it = items.begin(); it != items.end(); it++) {
		(*it)->displayServiceInfo();
	}
}
