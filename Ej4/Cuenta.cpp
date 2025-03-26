#include "ej4.hpp"

class CajadeAhorro{
    
    private:

    double balance;
    public:
    CajadeAhorro(double initial_balance): balance(initial_balance){
        if (initial_balance < 0){
            throw(invalid_argument("Balance inicial debe ser mayor a 0"));
        }
    }

    void retirar(double withdrawal){
        if (withdrawal < 0){
            throw (invalid_argument("No se puede retirar una cantidad negativa de dinero"));
        }
        if (withdrawal > balance){
            throw (invalid_argument("No se puede retirar esa cantidad de dinero"));
        }
        else {
            balance -= withdrawal;
        }
       }
    void ingresar(double income){
        if (income < 0){
            throw (invalid_argument ("Income tiene que ser mayor a -"));
        }
        balance+=income;
    }
    void retirar(double withdrawal){
        if (withdrawal < 0){
            throw (invalid_argument("No se puede retirar una cantidad negativa de dinero"));
        }
        if (withdrawal > balance){
            throw (invalid_argument("No se puede retirar esa cantidad de dinero"));
        }
        else {
            balance -= withdrawal;
        }
       }
};
class Cuenta_corriente {
private:
    CajadeAhorro* savings; 

public:
    double balance;

    Cuenta_corriente(double initial_balance, CajadeAhorro* associated_savings)
        : balance(initial_balance), savings(associated_savings) {
        if (initial_balance < 0) {
            throw(invalid_argument("Balance inicial debe ser mayor a 0"));
        }
    }

    void ingresar(double income) {
        if (income < 0) {
            throw(invalid_argument("Income tiene que ser mayor a -"));
        }
        balance += income;
    }

    void retirar(double withdrawal) {
        if (withdrawal < 0) {
            throw(invalid_argument("No se puede retirar una cantidad negativa de dinero"));
        }
        if (withdrawal > balance) {
            // Intento sacar el dinero de la caja de ahorros
            double remaining_withdrawal = withdrawal - balance;
            if (savings != nullptr) {
                try {
                    savings->retirar(remaining_withdrawal);
                    balance = 0; // Lo dejo en 0
                } catch (const invalid_argument& e) {
                    throw(invalid_argument("No se puede retirar esa cantidad de dinero ni de la caja de ahorros"));
                }
            } else {
                throw(invalid_argument("No se puede retirar esa cantidad de dinero"));
            }
        } else {
            balance -= withdrawal;
        }
    }
};
class Cuenta {

    protected:
    string user_name;
    private:
    Cuenta_corriente curr_account;
    CajadeAhorro savings;
    double balance;
    void mostrar_info(){
        cout << "Nombre de usuario -> " << user_name << endl;
        cout << "Balance -> " << balance << endl;
    }

    public:
    Cuenta(string name, double inicial_balance)
        : user_name(name), balance(inicial_balance), savings(CajadeAhorro(0)), curr_account(Cuenta_corriente(0, &savings)) {}

    void depositar(double income){
        balance += income;
    }
    void retirar(double income){
        balance -= income;
    }



};