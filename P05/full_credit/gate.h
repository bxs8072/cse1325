#ifndef _GATE_H
#define _GATE_H

typedef int Pin;
typedef bool Signal;

class Gate
{
protected:
    Signal _input1;
    Signal _input2;

private:
    Gate *_to_gate;
    Pin _to_pin;

public:
    Gate() : _input1{true}, _input2{true} {};

    void connect(Gate &gate, Pin input_pin)
    {
        gate.input(input_pin, output());
        _to_gate = &gate;
        _to_pin = input_pin;
    };

    void input(Pin pin, Signal signal)
    {
        pin == 1 ? _input1 = signal : _input2 = signal;
    };

    Signal input(Pin pin)
    {
        return pin == 1 ? _input1 : _input2;
    };

    virtual Signal output() = 0;
};

#endif