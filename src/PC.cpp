#include "PC.h"

PC::PC (ULA _ula, REGS _regs) {
    ula= _ula; 
    regs= _regs;
    lastState= false;
    EA = 0;
}
    
//Função de Transferência de Estados
void PC::FTE() {  
    switch (EA){               
        case 0: 
        PE = 1;
        break;

        case 1:
        PE = 2; 
        break;

        case 2:        
        if (ula.getCond() == true)
            PE = 3;
        else {
            PE = 6;
            lastState = true;
        }
        break;

        case 3:
        PE = 4;
        break;

        case 4:
        PE = 5;
        break;

        case 5:
        PE = 0;
        break;

        default:
        break;
    }
}    
    
//Função de Saída
void PC::FS() {       
    switch (EA) {            
        case 0:
        ula.readA(regs.readR(0));
        ula.readB(regs.readR(1));
        ula.op(2);
        regs.writeR(2, ula.writeResult());
        break;
            
        case 1:
        ula.readA(regs.readR(2));
        ula.readB(regs.readR(1));
        ula.op(1);
        regs.writeR(2, ula.writeResult());
        break;

        case 2:
        ula.readA(absolute(regs.readR(2)));
        ula.readB(0.000001);
        ula.op(3);
        break;

        case 3:
        ula.readA(regs.readR(0));
        ula.readB(regs.readR(1));
        ula.op(2);
        regs.writeR(2, ula.writeResult());
        break;

        case 4:
        ula.readA(regs.readR(2));
        ula.readB(regs.readR(1));
        ula.op(0);
        regs.writeR(2, ula.writeResult());
        break;

        case 5:
        ula.readA(regs.readR(2));
        ula.readB(2.0);
        ula.op(2);
        regs.writeR(1, ula.writeResult());
        break;

        default:
        break;                
    }       
}
    
void PC::updateState() {
    EA = PE;  
}
        
bool PC::getLastState() {
    return (lastState);
}

float PC::absolute(float value) {
    return value < 0.0 ? -1.0 * value : value;
}
