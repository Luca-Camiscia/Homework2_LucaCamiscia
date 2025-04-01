#include "ej4.hpp"
CajadeAhorro::CajadeAhorro(double initial_balance, string name) 
    : CuentaBase(initial_balance, name), ask_count(0) {}

void CajadeAhorro::mostrarinfo() {
    if (ask_count == 2) {
        try {retirar(20);}
        catch(out_of_range){
            cout << "No hay saldo suficiente para ver el saldo :( " << endl;
            return;
        }
        ask_count = -1;
    }
    cout << "========================= Caja de Ahorros =========================" << endl;
    cout << "Usuario: " << this->get_name() << endl;
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "===================================================================" << endl;
    ask_count++;
}



void CajadeAhorro::retirar(double withdrawal) {
    if (withdrawal < 0) {
        throw invalid_argument("No se puede retirar una cantidad negativa de dinero");
    }
    if (withdrawal > balance) {
        throw out_of_range("No hay suficiente saldo en la caja de ahorros");
    }
    balance -= withdrawal;
}
