#include "and.h"
#include "or.h"
#include "gate.h"
#include <iostream>
#include <vector>

int main()
{
    //Initializing OR Gate
    Or or_gate;

    //Initializing AND gate -> and1
    And and1;

    //Initializing AND gate -> and2
    And and2;

    int i, j, k, l;

    std::cout << "A  "
              << "B  "
              << "C  "
              << "D    "
              << "Q" << std::endl;
    std::cout << "=  "
              << "=  "
              << "=  "
              << "=    "
              << "=  " << std::endl;
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            for (k = 0; k <= 1; k++)
            {
                for (l = 0; l <= 1; l++)
                {
                    and1.input(1, i);
                    and1.input(2, j);
                    and2.input(1, k);
                    and2.input(2, l);
                    //Connecting output of and1 to pin1 of or_gate
                    and1.connect(or_gate, 1);

                    //Connecting output of and2 to pin2 of or_gate
                    and2.connect(or_gate, 2);
                    std::cout << i << "  "
                              << j << "  "
                              << k << "  "
                              << l << "    "
                              << or_gate.output() << std::endl;
                }
            }
        }
    }

    return 0;
}