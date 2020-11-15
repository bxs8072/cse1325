#include "mulch.h"

Mulch::Mulch(std::string name, double price, std::string description, int volume, Material material)
    : Product(name, price, description), _volume{volume}, _material{material} {}

Mulch::Mulch(std::istream &ist) : Product(ist)
{
    ist >> _volume;
    ist.ignore(65535, '\n');
    std::string material;
    std::getline(ist, material);
    _material = material_from_string(material);
}

void Mulch::save(std::ostream &ost) const
{
    ost << "mulch\n";
    Product::save(ost);
    ost << _volume << '\n'
        << ::to_string(_material) << std::endl;
}

std::string Mulch::to_string() const
{
    return Product::to_string() + '\n' +
           "Volume: " + std::to_string(_volume) + " ft³ " + '\n' +
           "Material: " + ::to_string(_material);
}

std::ostream &operator<<(std::ostream &ost, const Material &material)
{
    ost << to_string(material);
    return ost;
}

std::string to_string(Material material)
{
    return material == Material::RUBBER ? "Rubber" : material == Material::PINE ? "Pine" : material == Material::CEDAR ? "Cedar" : material == Material::HARDWOOD ? "Hardwood" : throw std::out_of_range("Invalid Material value");
}

Material material_from_string(std::string material)
{
    return material == "Rubber" ? Material::RUBBER : material == "Pine" ? Material::PINE : material == "Cedar" ? Material::CEDAR : material == "Hardwood" ? Material::HARDWOOD : throw std::runtime_error("Invalid Material value");
}
