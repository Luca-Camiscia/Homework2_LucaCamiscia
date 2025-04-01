#include "Ej3.hpp"



Complejo::Complejo(complex<float> input_num) : Numero("Complejo"), num(input_num) {}


int Complejo::Get_as_int() {

    return static_cast<int>(num.real()); //esto me da solo la parte real 
}

float Complejo::Get_as_Real() {
    return static_cast<float>(num.real());
}

complex<float> Complejo::Get_as_Complex() {
    return num;
}

void Complejo::suma(shared_ptr<class Numero> adding_num) {
    num += adding_num->Get_as_Complex();
}

void Complejo::resta(shared_ptr<class Numero> substracting_num) {
    num -= substracting_num->Get_as_Complex();
}

void Complejo::mult(shared_ptr<class Numero> mult_num) {
    num *= mult_num->Get_as_Complex();
}

void Complejo::div(shared_ptr<class Numero> div_num) {
    complex<float> divider = div_num->Get_as_Complex(); // Use the magnitude of the complex number
    if (divider == complex<float>(0.0, 0.0)) {
        throw invalid_argument("Impossible to divide by 0");
    }
    num /= div_num->Get_as_Complex(); // Divide by the complex number directly
}

string Complejo::getType() {
    return tag;
}

string Complejo::toString() {
    return "(" + to_string(num.real()) + " + " + to_string(num.imag()) + "i)";
}
