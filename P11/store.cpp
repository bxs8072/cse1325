#include "store.h"
#include <iostream>
#include <algorithm>

Store::Store(std::string name) : _name{name}
{
}

Store::Store(std::istream &ist)
{
    std::getline(ist, _name);
    int size;
    std::string name;
    ist >> size;
    ist.ignore(32767, '\n');

    while (size-- > 0)
    {
        std::getline(ist, name);
        if (name == "tool")
            _products.push_back(new Tool(ist));
        else if (name == "plant")
            _products.push_back(new Plant(ist));
        else if (name == "mulch")
            _products.push_back(new Mulch(ist));
        else if (name.size())
            throw std::runtime_error{"Invalid product type input: " + name};
    }

    ist >> size;
    ist.ignore(32767, '\n');
    while (size-- > 0)
    {
        _customers.push_back(new Customer(ist));
    }

    ist >> size;
    ist.ignore(32767, '\n');
    if (ist.eof())
        return;
    while (size-- > 0)
    {
        _orders.push_back(new Order(ist));
    }
}

void Store::save(std::ostream &ost)
{
    ost << _name << '\n';
    ost << _products.size() << '\n';
    for (Product *product : _products)
    {
        product->save(ost);
    }
    ost << _customers.size() << '\n';
    for (Customer *customer : _customers)
    {
        customer->save(ost);
    }
    ost << _orders.size() << '\n';
    for (Order *order : _orders)
    {
        order->save(ost);
    }
}

std::string Store::name()
{
    return _name;
}

int Store::products() { return _products.size(); }
Product &Store::product(int index) { return *_products.at(index); }
void Store::add_product(const Tool &product) { _products.push_back(new Tool{product}); }
void Store::add_product(const Plant &product) { _products.push_back(new Plant{product}); }
void Store::add_product(const Mulch &product) { _products.push_back(new Mulch{product}); }

int Store::customers() { return _customers.size(); }
Customer &Store::customer(int index) { return *_customers.at(index); }
void Store::add_customer(const Customer &customer) { _customers.push_back(new Customer{customer}); }
void Store::edit_customer(int index, std::string name, std::string phone, std::string email)
{
    customer(index) = Customer{name, phone, email};
}

void Store::delete_customer(int &index)
{
}

bool compare(Customer *a, Customer *b)
{
    return a->get_name().compare(b->get_name()) < 0;
}

void Store::get_sorted_customers()
{
    std::sort(_customers.begin(), _customers.end(), compare);
}

int Store::orders() { return _orders.size(); }
Order &Store::order(int index) { return *_orders.at(index); }

std::vector<Order *> Store::order_list()
{
    return _orders;
}

int Store::add_order(Customer &customer)
{
    _orders.push_back(new Order{customer});
    if (_orders.size() <= 0)
    {
        return 0;
    }
    return _orders.size() - 1;
}

void Store::add_item(int order, Product &product, int quantity)
{
    _orders.at(order)->add_item(Item{product, quantity});
}
