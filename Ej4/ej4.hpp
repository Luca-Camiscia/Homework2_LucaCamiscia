#include <iostream>
#include <iomanip>

using namespace std;

class CuentaBase {
protected:
    string userId;
    double balance;

private:


public:
    CuentaBase(double initial_balance, string name);
    virtual void ingresar(double income) = 0;
    virtual void retirar(double withdrawal) = 0;
    virtual void mostrarinfo() = 0;

};

class CajadeAhorro : public CuentaBase {
private:
    unsigned ask_count;

public:
    CajadeAhorro(double initial_balance, string name);
    void ingresar(double income) override;
    void retirar(double withdrawal) override;
    void mostrarinfo() override;
    friend class CuentaCorriente;
};

class CuentaCorriente : public CuentaBase {
private:
    CajadeAhorro caja;

public:
    CuentaCorriente(double initial_balance, string name);
    void ingresar(double income) override;
    void retirar(double withdrawal) override;

    void ingresar_a_caja(double income);
    void retirar_de_caja(double income);
    void mostrarinfo_caja();
    void mostrarinfo() override;

    
    
};

