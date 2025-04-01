#include "Ej3.hpp"



Real::Real(float input_num) : Numero("Real"), num(input_num) {}


int Real::Get_as_int() {
    return static_cast<int>(num);
}

float Real::Get_as_Real() {
    return num;
}

complex<float> Real::Get_as_Complex() {
    return static_cast<complex<float>>(num);
}

void Real::suma(shared_ptr<class Numero> adding_num) {
    num += adding_num->Get_as_Real();
}

void Real::resta(shared_ptr<class Numero> substracting_num) {
    num -= substracting_num->Get_as_Real();
}

void Real::mult(shared_ptr<class Numero> mult_num) {
    num *= mult_num->Get_as_Real();
}

void Real::div(shared_ptr<class Numero> div_num) {
    float divider = div_num->Get_as_Real(); // Cambiado a float
    if (divider == 0.0f) {
        throw invalid_argument("Impossible to divide by 0");
    }
    num /= divider;
}

string Real::getType() {
    return tag;
}

string Real::toString() {
    return to_string(num);
}
