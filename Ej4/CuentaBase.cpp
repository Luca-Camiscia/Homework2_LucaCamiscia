#include "ej4.hpp"

//clase abstracta

CuentaBase::CuentaBase(double initial_balance, string name) 
    : balance(initial_balance), userId(name) {
    if (initial_balance < 0) {
        throw invalid_argument("El balance debe ser mayor a 0");
    }
}

string CuentaBase::get_name(){
    return userId;
}

void CuentaBase::ingresar(double income) {
    if (income < 0) {
        throw invalid_argument("No se puede ingresar una cantidad negativa de dinero");
    }
    balance += income;
}

