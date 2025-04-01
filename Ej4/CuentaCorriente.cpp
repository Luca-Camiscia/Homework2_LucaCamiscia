#include "ej4.hpp"

CuentaCorriente::CuentaCorriente(double initial_balance, string name) 
    : CuentaBase(initial_balance, name), caja(0, name) {}

void CuentaCorriente::mostrarinfo() {
    cout << "========================= Cuenta Corriente =========================" << endl;
    cout << "Usuario: " << this->get_name() << endl;
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "===================================================================" << endl;
}

void CuentaCorriente::mostrarinfo_caja(){
    caja.mostrarinfo();
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
        } catch (const out_of_range& e) {
            cout << "Saldo insuficiente" << endl;
        }
        balance = 0;
        return;
    }
    balance -= withdrawal;
}
void CuentaCorriente::retirar_de_caja(double income){
    try{
        caja.ingresar(income);
    }
    catch(const invalid_argument& e){
        cout << "Ingreso no valido" << endl;
    }
}

