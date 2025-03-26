#include "ej4.hpp"

//clase abstracta

CuentaBase::CuentaBase(double initial_balance, string name) 
    : balance(initial_balance), userId(name) {
    if (initial_balance < 0) {
        throw invalid_argument("El balance debe ser mayor a 0");
    }
}

CajadeAhorro::CajadeAhorro(double initial_balance, string name) 
    : CuentaBase(initial_balance, name), ask_count(0) {}

void CajadeAhorro::mostrarinfo() {
    if (ask_count == 2) {  // Corregido: usaba = (asignación) en lugar de == (comparación)
        retirar(20);
        ask_count = -1;
    }
    cout << "Nombre de usuario -> " << userId << endl;
    cout << "Balance total -> " << balance << endl;
    ask_count++;
}

void CajadeAhorro::ingresar(double income) {
    if (income < 0) {
        throw invalid_argument("No se puede ingresar una cantidad negativa de dinero");
    }
    balance += income;
}

void CajadeAhorro::retirar(double withdrawal) {
    if (withdrawal < 0) {
        throw invalid_argument("No se puede retirar una cantidad negativa de dinero");
    }
    if (withdrawal > balance) {
        throw invalid_argument("No hay suficiente saldo en la caja de ahorros");
    }
    balance -= withdrawal;
}


CuentaCorriente::CuentaCorriente(double initial_balance, string name) 
    : CuentaBase(initial_balance, name), caja(0, name) {}

void CuentaCorriente::mostrarinfo() {
    cout << "Nombre de usuario -> " << userId << endl;
    cout << "Balance total -> " << balance << endl;
}

void CuentaCorriente::ingresar(double income) {
    if (income < 0) {
        throw invalid_argument("No se puede ingresar una cantidad negativa de dinero");
    }
    balance += income;
}

void CuentaCorriente::ingresar_a_caja(double income) {
    caja.ingresar(income);
}

void CuentaCorriente::retirar(double withdrawal) {
    if (withdrawal < 0) {
        throw invalid_argument("No se puede retirar una cantidad negativa de dinero");
    }
    if (withdrawal > balance) {
        double remaining_with = withdrawal - balance;
        try {
            caja.retirar(remaining_with);
        } catch (const invalid_argument& e) {
            cout << "Saldo insuficiente" << endl;
        }
        balance = 0;
        return;
    }
    balance -= withdrawal;
}

void CuentaCorriente::illegal_mostrar() {
    mostrarinfo();
}