#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <iostream>
#include <istream>
#include <ostream>

class Customer {
public:
    Customer(std::string name, std::string phone, std::string email);
    friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
    Customer(std::istream& ist);
    virtual void save(std::ostream& ost) const;
protected:
    std::string to_string() const;
private:
    std::string _name;
    std::string _phone;
    std::string _email;
};
#endif