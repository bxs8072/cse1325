#ifndef __ITEM_H
#define __ITEM_H
#include "plant.h"
#include "tool.h"
#include "mulch.h"
#include "product.h"
#include <iostream>
#include <istream>
#include <ostream>

class Item{
    public:
        Item(Product& product, int quantity);
        Item(std::istream& ist); 
        friend std::ostream& operator<<(std::ostream& ost, const Item& item);
        void save(std::ostream& ost);
        void quantity(int quantity);
        double subtotal();
    protected:
        std::string to_string() const;
    private:
        Product* _product;
        int _quantity;
};
#endif