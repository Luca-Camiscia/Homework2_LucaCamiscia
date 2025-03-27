#include "ej4.hpp"

int main() {

        // Pruebas con Caja de Ahorro
        cout << "=== Pruebas con Caja de Ahorro ===" << endl;

        CajadeAhorro caja1 = CajadeAhorro(0, "Bombi");

        cout << "Creando Caja de Ahorro con titular 'Bombi' y saldo inicial 0." << endl;
        caja1.mostrarinfo();

        int mostrarinfo_count = 1;

        cout << "Ingresando 100 a la Caja de Ahorro." << endl;
        caja1.ingresar(100);
        caja1.mostrarinfo();
        if (++mostrarinfo_count % 3 == 0) {
            cout << "Se han llamado 3 veces a mostrarinfo, retirando 20 de la Caja de Ahorro." << endl;
            caja1.retirar(20);
        }

        cout << "Retirando 50 de la Caja de Ahorro." << endl;
        caja1.retirar(50);
        caja1.mostrarinfo();
        if (++mostrarinfo_count % 3 == 0) {
            cout << "Se han llamado 3 veces a mostrarinfo, retirando 20 de la Caja de Ahorro." << endl;
            caja1.retirar(20);
        }

        cout << "Intentando retirar 10000 de la Caja de Ahorro (debería fallar)." << endl;
        try {
            caja1.retirar(10000);
        } catch (out_of_range) {
            cout << "No pudo retirar porque no había suficiente saldo." << endl;
        }
        caja1.mostrarinfo();
        if (++mostrarinfo_count % 3 == 0) {
            cout << "Se han llamado 3 veces a mostrarinfo, retirando 20 de la Caja de Ahorro." << endl;
            caja1.retirar(20);
        }

        cout << "Intentando ingresar -20 a la Caja de Ahorro (debería fallar)." << endl;
        try {
            caja1.ingresar(-20);
        } catch (invalid_argument) {
            cout << "No puede ingresar cantidades negativas." << endl;
        }
        caja1.mostrarinfo();
        
        cout << "Llamo mas veces a mostrarinfo hasta no tener plata suficiente como para mostrar" << endl;
        caja1.mostrarinfo();


    // Pruebas con Cuenta Corriente
    cout << "\n=== Pruebas con Cuenta Corriente ===" << endl;

    CuentaCorriente corriente1 = CuentaCorriente(0, "Tomi");

    cout << "Creando Cuenta Corriente con titular 'Tomi' y saldo inicial 0." << endl;
    corriente1.mostrarinfo();

    cout << "Ingresando 100 a la Cuenta Corriente." << endl;
    corriente1.ingresar(100);
    corriente1.mostrarinfo();

    cout << "Retirando 50 de la Cuenta Corriente." << endl;
    corriente1.retirar(50);
    corriente1.mostrarinfo();

    cout << "Intentando retirar 200 de la Cuenta Corriente (debería permitir sobregiro)." << endl;
    corriente1.retirar(200);
    corriente1.mostrarinfo();

    cout << "Intentando ingresar -50 a la Cuenta Corriente (debería fallar)." << endl;
    try {
        corriente1.ingresar(-50);
    } catch (invalid_argument) {
        cout << "No puede ingresar cantidades negativas." << endl;
    }

    cout << "Intentando retirar 5000 de la Cuenta Corriente (debería fallar si excede el límite de sobregiro)." << endl;
    try {
        corriente1.retirar(5000);
    } catch (out_of_range) {
        cout << "No pudo retirar porque excedió el límite de sobregiro." << endl;
    }

    return 0;
}