#include "order.h"

Order::Order(Customer customer) : _customer{customer} {
}

Order::Order(std::istream& ist): _customer{ist} {
    int items;
    ist >> items; ist.ignore(32767, '\n');
    while(items--) _items.push_back(Item{ist});
}

void Order::save(std::ostream& ost) const {
    _customer.save(ost);
    ost << _items.size() << '\n';
    for(Item item: _items) item.save(ost);   
}

std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "For Customer " <<order._customer << " $" << order.total() << std::endl << "\n";
    for(Item item: order._items) ost << item;
    return ost;
}

void Order::add_item(Item item) {
    _items.push_back(item);
}

double Order::total() const {
    double _total = 0.0;
    for(Item item: _items) _total += item.subtotal();
    return _total;
}