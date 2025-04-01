#include "Ej3.hpp"


Entero::Entero(int input_num): Numero("Entero"), num(input_num){}


int Entero::Get_as_int(){
    return num;
}

float Entero::Get_as_Real(){
    return static_cast<float>(num); 
}

complex<float> Entero::Get_as_Complex(){
    return static_cast<complex<float>>(num);
}

void Entero::suma(shared_ptr<class Numero> adding_num){
    num += adding_num->Get_as_int();
}
void Entero::resta(shared_ptr<class Numero> substracting_num){
    num -= substracting_num->Get_as_int();
}

void Entero::mult(shared_ptr<class Numero> mult_num){
    num *= mult_num->Get_as_int();
}

void Entero::div(shared_ptr<class Numero> div_num){
    int divider = div_num->Get_as_int();
    if (divider == 0){
        throw invalid_argument("Impossible to divide by 0");
    } 
     num /=divider; 
}

string Entero::getType(){
    return tag;
}
string Entero::toString(){
    return  to_string(num);
}
