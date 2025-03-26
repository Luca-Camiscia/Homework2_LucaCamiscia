#include "ej4.hpp"

int main() {
    //pruebaaa con cuenta corriente

    CuentaCorriente Cuenta1 = CuentaCorriente(100, "Tomi");
    Cuenta1.illegal_mostrar();

    cout << "Ingreso 50 pesos a la cuenta corriente" << endl;
    Cuenta1.ingresar(50);
    Cuenta1.illegal_mostrar();

    cout << "Ingreso 500 a la caja de ahorro asociada a la cosa esa" << endl;
    Cuenta1.ingresar_a_caja(50);

    cout << "Retiro 190 lo cual va a sacar de la caja de ahorro" << endl;
    
    Cuenta1.retirar(190);
    Cuenta1.illegal_mostrar();

    cout << "Ahora intento sacar una cantidad absurda de plata jijiji" << endl;
    Cuenta1.retirar(100000);
    


}