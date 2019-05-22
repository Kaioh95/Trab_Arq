#include "AC.h"

AC::AC(){
    ac= new float[1];
};
    
float AC::get(int _adress){
    return (ac[_adress]);
};
    
void AC::set(int _adress, float _v){
    ac[_adress]= _v;
};
