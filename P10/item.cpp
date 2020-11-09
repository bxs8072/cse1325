#include "item.h"

Item::Item(Product& product, int quantity): _product{new Product{product}}, _quantity{quantity} {

}

Item::Item(std::istream& ist): _product{new Product{ist}} {
    ist >> _quantity;
    ist.ignore(65535, '\n');
}

void Item::save(std::ostream& ost) {
     ost << "item\n";
     _product->save(ost);
     ost << _quantity << std::endl;
}

double Item::subtotal() {
    return _quantity * _product->get_price();
}

void Item::quantity(int quantity) {
    _quantity = quantity;
}

std::string Item::to_string() const {
 return "\nquantity: " + std::to_string(_quantity) + "\nSubTotal: " +
  std::to_string(round(_quantity * _product->get_price() * 100/100)) + "\n";
}

std::ostream& operator<<(std::ostream& ost, const Item& item) 
{
    ost << "\n";
    ost << *item._product;
    ost << item.to_string();
    return ost;
}