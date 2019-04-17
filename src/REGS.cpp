#include "REGS.h"

REGS::REGS() {
    regs = new float[13];
    writeR(1, 1.0);
}
    
float REGS::readR(int addR) {
    return regs[addR];
}
    
void REGS::writeR(int _adress, float _v) {
    regs[_adress] = _v;
}    
