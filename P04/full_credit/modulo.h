#ifndef _MODULO
#define _MODULO
#include <iostream>

class Modulo
{
public:
    Modulo(int modulo = 10, int value = 0, int offset = 0) : _modulo(modulo), _value(value), _offset(offset){};
    void set_nmsd(Modulo* nmsd)
    {
        _nmsd = nmsd;
    }

    int value() { return _value; };

    Modulo &operator+=(int rhs)
    {
        _value += rhs;
        if(_modulo == 12) {
            if (_value > _modulo)
        {
            ++(*_nmsd);
            _value = _offset;
        }
        } else {
            if (_value > _modulo)
        {
            ++(*_nmsd);
            _value = _value - _modulo;
        }
        else if (_value == _modulo)
        {
            ++(*_nmsd);
            _value = _offset;
        } 
        }

        
        return *this;
    };

    Modulo operator+(int rhs)
    {
        _value += rhs;
         if(_modulo == 12) {
            if (_value > _modulo)
        {
            ++(*_nmsd);
            _value = _offset;
        }
        } else {
            if (_value > _modulo)
        {
            ++(*_nmsd);
            _value = _value - _modulo;
        }
        else if (_value == _modulo)
        {
            ++(*_nmsd);
            _value = _offset;
        } 
        }

        return *this;
    };

    Modulo &operator++()
    {
        ++_value;
       if(_modulo == 12) {
           if (_value > _modulo)
        {  
            _value = _offset;
        } 
       } else {
            if (_value >= _modulo)
        {  
            _value = _offset;
            ++(*_nmsd);
        } 
       }
        return *this;
    };

    Modulo operator++(int ignored)
    {
       ++_value;
       if(_modulo == 12) {
           if (_value > _modulo)
        {  
            _value = _offset;
        } 
       } else {
            if (_value >= _modulo)
        {  
            _value = _offset;
            ++(*_nmsd);
        } 
       }
        
        return *this;
    };

    inline bool operator==(int rhs)
    {
        return _value == rhs;
    };
    inline bool operator!=(int rhs)
    {
        return _value != rhs;
    };
    inline bool operator<(int rhs)
    {
        return compare(rhs) < 0;
    };
    inline bool operator<=(int rhs)
    {
        return compare(rhs) <= 0;
    };
    inline bool operator>(int rhs)
    {
        return compare(rhs) > 0;
    };
    inline bool operator>=(int rhs)
    {
        return compare(rhs) >= 0;
    };
    
    friend std::ostream &operator<<(std::ostream &ost, Modulo &m)
    {
        ost << m._value;
        return ost;
    }
    friend std::istream &operator>>(std::istream &ost, Modulo &m)
    {
        ost >> m._value;
        return ost;
    }

private:
    int _value;
    int _modulo;
    int _offset;
    Modulo* _nmsd;
    int compare(const int rhs)
    {
        if (_value < rhs)
            return -1;
        if (_value > rhs)
            return 1;
        if (_value <= rhs)
            return -1;
        if (_value >= rhs)
            return 1;
        return 0;
    }
};

#endif