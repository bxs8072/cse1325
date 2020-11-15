#include "product.h"
#include <cmath>

Product::Product(std::string name, double price, std::string description)
    : _name{name}, _price{price}, _description{description}, _stocknum{++_nextsn} {}

Product::Product(std::istream &ist)
{
    ist >> _nextsn;
    ist.ignore(65535, '\n');
    std::getline(ist, _name);
    ist >> _stocknum;
    ist >> _price;
    ist.ignore(65535, '\n');
    std::getline(ist, _description);
}

void Product::save(std::ostream &ost) const
{
    ost << _nextsn << '\n'
        << _name << '\n'
        << _stocknum << '\n'
        << _price << '\n'
        << _description << std::endl;
}

std::string Product::to_string() const
{
    return "Stock #" + std::to_string(_stocknum) + '\n' + 
           "Name: " + _name + '\n' +
           "Price: $" + std::to_string(round(_price*100)/100) + '\n' +
           "Description: " + _description;
}

double Product::get_price() {
    return _price;
}

std::ostream &operator<<(std::ostream &ost, const Product &product)
{
    ost << product.to_string();
    return ost;
}

int Product::_nextsn = 0;
