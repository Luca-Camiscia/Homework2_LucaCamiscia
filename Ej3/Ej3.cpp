#include "Ej3.hpp"

#include <string> // Added for std::string

int main (void){

    cout << "==================== PRUEBAS SOLO CON ENTEROS ====================" << endl;

    shared_ptr<class Numero> A_ptr = make_shared<Entero>(3);
    shared_ptr<class Numero> B_ptr = make_shared<Entero>(8);
    shared_ptr<class Numero> C_ptr = make_shared<Entero>(10);
    shared_ptr<class Numero> D_ptr = make_shared<Entero>(0);

    cout << "Imprimo A-> " << A_ptr->Get_as_int() << endl;    
    cout << "Imprimo B-> " << B_ptr->Get_as_int() << endl;
    cout << "Ahora a A le sumo B " << endl;

    A_ptr->suma(B_ptr);
    cout << "Imprimo A devuelta-> " << A_ptr->toString() << endl;

    cout << "Ahora a B le resto A" << endl;
    B_ptr->resta(A_ptr);
    cout << "B-> " << B_ptr->toString() << endl;

    cout << "Ahora voy a multiplicar B por lo que tengo en C (10)" << endl;
    B_ptr->mult(C_ptr);
    cout << "B-> " << B_ptr->toString() << endl;

    cout << "Ahora divido B por C para que me quede lo que tenia antes" << endl;
    B_ptr->div(C_ptr);
    cout << "B-> " << B_ptr->toString() << endl;

    cout << "Divido por D (0) para probar si se detecta el error correctamente" << endl;
    try{
        A_ptr->div(D_ptr);
    }
    catch(invalid_argument){
        cout << "Encontro el error correctamente" << endl;
    }

    cout << "=================================================================" << endl;
    cout << "==================== PRUEBAS SOLO CON REALES ====================" << endl;

    shared_ptr<class Numero> E_ptr = make_shared<Real>(3.5);
    shared_ptr<class Numero> F_ptr = make_shared<Real>(8.2);
    shared_ptr<class Numero> G_ptr = make_shared<Real>(10.0);
    shared_ptr<class Numero> H_ptr = make_shared<Real>(0.0);

    cout << "Imprimo E-> " << E_ptr->toString() << endl;    
    cout << "Imprimo F-> " << F_ptr->toString() << endl;

    cout << "Ahora a E le sumo F " << endl;

    E_ptr->suma(F_ptr);
    cout << "Imprimo E devuelta-> " << E_ptr->toString() << endl;

    cout << "Ahora a F le resto E" << endl;
    F_ptr->resta(E_ptr);
    cout << "F-> " << F_ptr->toString() << endl;

    cout << "Ahora voy a multiplicar F por lo que tengo en G (10.0)" << endl;
    F_ptr->mult(G_ptr);
    cout << "F-> " << F_ptr->toString() << endl;

    cout << "Ahora divido F por G para que me quede lo que tenia antes" << endl;
    F_ptr->div(G_ptr);
    cout << "F-> " << F_ptr->toString() << endl;

    cout << "Divido por H (0.0) para probar si se detecta el error correctamente" << endl;
    try{
        E_ptr->div(H_ptr);
    }
    catch(invalid_argument){
        cout << "Encontro el error correctamente" << endl;
    }

    cout << "=================================================================" << endl;
    cout << "==================== PRUEBAS SOLO CON COMPLEJOS =================" << endl;

    shared_ptr<class Numero> I_ptr = make_shared<Complejo>(3.0, 4.0);
    shared_ptr<class Numero> J_ptr = make_shared<Complejo>(1.0, 2.0);
    shared_ptr<class Numero> K_ptr = make_shared<Complejo>(0.0, 0.0);

    cout << "Imprimo I-> " << I_ptr->toString() << endl;
    cout << "Imprimo J-> " << J_ptr->toString() << endl;

    cout << "Ahora a I le sumo J " << endl;
    I_ptr->suma(J_ptr);
    cout << "Imprimo I devuelta-> " << I_ptr->toString() << endl;

    cout << "Ahora a J le resto I" << endl;
    J_ptr->resta(I_ptr);
    cout << "J-> " << J_ptr->toString() << endl;

    cout << "Ahora voy a multiplicar J por lo que tengo en I" << endl;
    J_ptr->mult(I_ptr);
    cout << "J-> " << J_ptr->toString() << endl;

    cout << "Ahora divido J por I para que me quede lo que tenia antes" << endl;
    try {
        J_ptr->div(I_ptr);
        cout << "J-> " << J_ptr->toString() << endl;
    } catch (invalid_argument) {
        cout << "Encontro el error correctamente" << endl;
    }

    cout << "Divido por K (0+0i) para probar si se detecta el error correctamente" << endl;
    try {
        I_ptr->div(K_ptr);
    } catch (invalid_argument) {
        cout << "Encontro el error correctamente" << endl;
    }

    cout << "=================================================================" << endl;
    cout << "==================== MEZCLANDO COSAS ============================" << endl;

    shared_ptr<class Numero> Entero_ptr = make_shared<Entero>(15);
    shared_ptr<class Numero> Real_ptr = make_shared<Real>(87.912);
    shared_ptr<class Numero> Complex_ptr = make_shared<Complejo>(12.3, 652.9);

    cout << "Imprimo Entero_ptr-> " << Entero_ptr->toString() << endl;
    cout << "Imprimo Real_ptr-> " << Real_ptr->toString() << endl;
    cout << "Imprimo Complex_ptr-> " << Complex_ptr->toString() << endl;

    cout << "Ahora a Entero_ptr le sumo Real_ptr" << endl;
    Entero_ptr->suma(Real_ptr);
    cout << "Entero_ptr-> " << Entero_ptr->toString() << endl;

    cout << "Ahora a Real_ptr le resto Complex_ptr" << endl;
    Real_ptr->resta(Complex_ptr);
    cout << "Real_ptr-> " << Real_ptr->toString() << endl;

    cout << "Ahora a Complex_ptr lo multiplico por Entero_ptr" << endl;
    Complex_ptr->mult(Entero_ptr);
    cout << "Complex_ptr-> " << Complex_ptr->toString() << endl;

    cout << "Ahora divido Complex_ptr por Real_ptr" << endl;
    try {
        Complex_ptr->div(Real_ptr);
        cout << "Complex_ptr-> " << Complex_ptr->toString() << endl;
    } catch (invalid_argument) {
        cout << "Encontro el error correctamente" << endl;
    }

    cout << "=================================================================" << endl;
}
