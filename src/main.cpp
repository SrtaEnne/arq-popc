#include <iostream>
#include <string>

#include "ULA.h"
#include "REGS.h"
#include "PC.h"

int main (int argc, char *argv[]) {
    float number;

    try {
        number = std::stof(argv[1]);
    } catch (exception &e) {
        std::cout << "Error: invalid input!" << std::endl;
        return 0;
    }
    

    if(argc != 2) {
        std::cout << "Error: invalid input!" << std::endl;
        return 0;
    }

    ULA ula;
    REGS regs;
    PC pc(ula, regs);
    regs.writeR(0, number);

    for (int i = 0; i < 100; i++) {
        pc.FS();
        pc.FTE();
        pc.updateState();

        if (pc.getLastState() == true)
            break;

        if(i == 99)
            std::cout << "CLOSED BY EXAUSTION" << std::endl;
    }

    std::cout << regs.readR(1) << std::endl;
    
    return 0;
} 
