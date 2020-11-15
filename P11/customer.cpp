#include "customer.h"
#include <cmath>

Customer::Customer(std::string name, std::string phone, std::string email)
    : _name{name}, _phone{phone}, _email{email} {}

Customer::Customer(std::istream& ist)
{   
    std::getline(ist, _name);
    std::getline(ist, _phone);
    std::getline(ist, _email);
}

std::string Customer::get_name() {
    return _name;
}

void Customer::save(std::ostream& ost) const
{
    ost << _name << '\n'
        << _phone << '\n'
        << _email << std::endl;
}

std::string Customer::to_string() const
{
    return  _name + " (" + _phone + ", " + _email + ")";
}

std::ostream& operator<<(std::ostream& ost, const Customer& customer)
{
    ost << customer.to_string();
    return ost;
}
