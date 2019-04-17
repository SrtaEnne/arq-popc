#ifndef REGS_H_
#define REGS_H_

using namespace std;

/* Index - Variable
 * 0 - number
 * 1 - guess
 * 2 - auxiliary
 */

class REGS {    
    private:
        float *regs;
    
    public:
        REGS();    
        float readR(int addR);    
        void writeR(int _adress, float _v);
};

#endif