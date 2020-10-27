#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name} { }

Store::Store(std::istream& ist) {
    ist >> _name;
    while(ist)
     _products.push_back(new Product{ist});
}


void Store::save(std::ostream& ost) {
    ost << _name << "\n";
    for(Product* product: _products) {
        product->save(ost); 
    }
}

void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

