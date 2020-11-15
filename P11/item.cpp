#include "item.h"

Item::Item(Product& product, int quantity): _product{&product}, _quantity{quantity} {

}

Item::Item(std::istream& ist) {
    ist >> _quantity;
    ist.ignore(32767, '\n');
    std::string output;
    std::getline(ist, output);
    if(output == "tool") _product = new Tool(ist);
    else if(output == "plant") _product = new Plant(ist);
    else if(output == "mulch") _product = new Mulch(ist);
    else if(output.size()) throw std::runtime_error{"Invalid product type: " + output};
}

void Item::save(std::ostream& ost) {
     ost << _quantity << std::endl;
     _product->save(ost);
}

double Item::subtotal() {
    return static_cast<double>(_quantity) * _product->get_price();
}

void Item::quantity(int quantity) {
    _quantity = quantity;
}

std::string Item::to_string() const {
 return "quantity: " + std::to_string(_quantity) + "\nSub-total: " + std::to_string(static_cast<double>(_quantity) * _product->get_price()) + "\n";
}

std::ostream& operator<<(std::ostream& ost, const Item& item) 
{
    ost << *item._product << std::endl;
    ost << item.to_string() << std::endl;
    return ost;
}