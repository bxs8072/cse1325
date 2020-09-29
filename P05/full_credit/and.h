#ifndef _AND_H
#define _AND_H
#include "gate.h"

class And : public Gate
{
public:
    And() : Gate(){};

    Signal output() override
    {
        return _input1 == true && _input2 == true ? true : false;
    };
};

#endif