#include "Ej3.hpp"

Complejo::Complejo(float input_real, float input_imagi) : Numero("Complejo"), real(input_real), imagi(input_imagi) {}


int Complejo::Get_as_int() {

    return static_cast<int>(num.real()); //esto me da solo la parte real 
}

float Complejo::Get_as_Real() {
    return static_cast<float>(num.real());
}

tuple<float,float> Complejo::Get_as_Complex() {
    return make_tuple(static_cast<float>(real), static_cast<float>(imagi));

}

void Complejo::suma(shared_ptr<class Numero> adding_num) {
    auto converted_num = adding_num->Get_as_Complex();
    real += get<0>(converted_num);
    imagi += get<1>(converted_num);
}

void Complejo::resta(shared_ptr<class Numero> substracting_num) {
    auto converted_num = substracting_num->Get_as_Complex();
    real -= get<0>(converted_num);
    imagi -= get<1>(converted_num);}

void Complejo::mult(shared_ptr<class Numero> mult_num) {
    auto converted_num = mult_num->Get_as_Complex();
    real *= get<0>(converted_num);
    imagi *= get<1>(converted_num);
}


void Complejo::div(shared_ptr<class Numero> div_num) {
    auto converted_num = div_num->Get_as_Complex();

    if (get<0>(converted_num) == 0 || get<1>(converted_num) == 0) {
        throw invalid_argument("Error division por 0");
    }

    real /= get<0>(converted_num);
    imagi /= get<1>(converted_num);
}

string Complejo::getType() {
    return tag;
}

string Complejo::toString() {
    return "(" + to_string(real) + " + " + to_string(imagi) + "i)";
}
