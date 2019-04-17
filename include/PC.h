#ifndef PC_H_
#define PC_H_

#include "ULA.h"
#include "REGS.h"

using namespace std;
class PC {    
    private:
        int EA, PE;  // estado atual, proximo estado
        bool lastState;

    public:
        ULA ula;
        REGS regs;
        PC (ULA _ula, REGS _regs);
        void FTE(); // Função de Transferência de Estados
        void FS();  // Função de Saída
        void updateState();        
        bool getLastState();
        float absolute(float value);
};

#endif
