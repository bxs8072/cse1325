#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name} { }

Store::Store(std::istream& ist) {
    std::getline(ist, _name);
    std::string name;
    while(ist) {
        std::getline(ist, name);
        if(name == "tool") _products.push_back(new Tool(ist));
        else if(name == "plant") _products.push_back(new Plant(ist));
        else if(name == "mulch") _products.push_back(new Mulch(ist));
        else if(name == "customer") _customers.push_back(new Customer(ist));
        else if(name.size()) throw std::runtime_error{"Invalid product type input: " + name};
    }
}


void Store::save(std::ostream& ost) {
    ost << _name << "\n";
    for(Product* product: _products) {
        product->save(ost); 
    }
    for(Customer* customer: _customers) {
        customer->save(ost); 
    }

}

void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
void Store::add_customer(const Customer& customer) {_customers.push_back(new Customer{customer});}

int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

int Store::customers() {return _customers.size();}
const Customer& Store::customer(int index) {return *_customers.at(index);}

