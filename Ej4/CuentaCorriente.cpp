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
    try {
        caja.ingresar(income);
    } catch (const invalid_argument& e) {
        cout << "Ingreso no válido: " << e.what() << endl;
    }
}

void CuentaCorriente::retirar(double withdrawal) {
    if (withdrawal < 0) {
        throw invalid_argument("No se puede retirar una cantidad negativa de dinero");
    }
    if (withdrawal > balance) {
        double remaining_with = withdrawal - balance;
        //Con el try ya puedo ver si la cuentaAhorro no tiene dinero ya que tira un throw
        //Si quiero tambien probar el funcionamiento de friend uso la siguiente linea
        if(caja.balance < remaining_with){ 
        //A pesar de que balance sea una variable protected, puedo acceder gracias a que CuentaCorriente es friend                                    
            cout << "Saldo insuficiente" << endl;
            return;
        }
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
        caja.retirar(income);
    }
    catch(const invalid_argument& e){
        cout << "Ingreso no valido" << endl;
    }
}

