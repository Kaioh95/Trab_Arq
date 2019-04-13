#ifndef ULA_H
#define ULA_H

class ULA{
public:
    int a, b, s;
    bool cond1;
     
    ULA();
    void readA(int _a);
    void readB(int _b);
    int writeResult();

    public void op(int ulaOP);
    public boolean getCond();    
};

ULA() { cond1= false; }
void readA(int _a) {a= _a;}
void readB(int _b) {b= _b;}
int writeResult() {return(s);}

void op(int ulaOP){
    switch (ulaOP) {
      case 0 : s= a + b; break;
      case 1 : s= a - b; break;
      case 2 : s= a | b; break;
      case 3 : s= a * b; break;
      case 4 : { if (a < b) cond1= true; else cond1= false; break;}
      default: break;
    }
}
   
bool getCond() { return(cond1); }

#endif


       

    






