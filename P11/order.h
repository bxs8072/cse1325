#ifndef __ORDER_H
#define __ORDER_H
#include "customer.h"
#include "item.h"
#include "plant.h"
#include "tool.h"
#include "mulch.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

class Order {
    public:
        Order(Customer customer);
        Order(std::istream& ist);
        friend std::ostream& operator<<(std::ostream& ost, const Order& order);
        void save(std::ostream& ost) const;
        void add_item(Item item);
        double total() const;
    private:
        std::vector<Item> _items;
        Customer _customer;
};

#endif