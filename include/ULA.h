#ifndef ULA_H_
#define ULA_H_

using namespace std;

class ULA {
    private:
        float a, b, s;
        bool c;
   
    public:
        ULA();
        void readA(float _a);
        void readB(float _b);
        float writeResult();
        void op(int ulaOP);
        bool getCond();
};

#endif