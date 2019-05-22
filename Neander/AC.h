#ifndef AC_H
#define AC_H

class AC{
public:
    float* ac;
    
    AC ();
    float get(int _adress);
    void set(int _adress, float _v);  
};

#endif
