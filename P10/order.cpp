#include "order.h"

Order::Order(Customer& customer) : _customer{customer} {
}

Order::Order(std::istream& ist): _customer{ist} {
    std::string name;
     while(ist) {
         std::getline(ist, name);
         if(name=="item") _items.push_back(Item{ist});
         else if(name.size()) throw std::runtime_error{"Invalid order type input: " + name};
     }
}

void Order::save(std::ostream& ost) const {
    ost << "order\n";
    _customer.save(ost);
    for(Item item: _items) {
        item.save(ost);   
    }
}

std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << order._customer;
    for(Item item: order._items) {
        ost << item;
    }
    return ost;
}

void Order::add_item(Item item) {
    _items.push_back(item);
}

double Order::total() {
    double _total;
    for(Item item: _items) {
        _total += item.subtotal();
    }
    return _total;
}

Customer& Order::customer() {
    return _customer;
}