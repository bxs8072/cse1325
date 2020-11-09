#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "customer.h"
#include "order.h"
#include "item.h"
#include <istream>
#include <ostream>
#include <vector>

class Store {
  public:
    Store(std::string name);
    Store(std::istream& ist);
    void save(std::ostream& ost);
    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    void add_customer(const Customer& customer);
    int products();
    const Product& product(int index);
    int customers();
    const Customer& customer(int index);
    int add_order(Customer& customer);
    void add_item(int order, Product& product, int quantity);
    int orders();
    const Order& order(int index);
  private:
    std::string _name;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
    std::vector<Order*> _orders;
};

#endif
