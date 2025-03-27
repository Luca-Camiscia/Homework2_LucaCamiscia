#include <iostream>

using namespace std;

class CuentaBase {
protected:
    string userId;
    double balance;

private:

    virtual void mostrarinfo() = 0;

public:
    CuentaBase(double initial_balance, string name);
    virtual void ingresar(double income) = 0;
    virtual void retirar(double withdrawal) = 0;
};

class CajadeAhorro : public CuentaBase {
private:
    unsigned ask_count;
    void mostrarinfo() override;

public:
    CajadeAhorro(double initial_balance, string name);
    void ingresar(double income) override;
    void retirar(double withdrawal) override;
    
    friend class CuentaCorriente;
};

class CuentaCorriente : public CuentaBase {
private:
    CajadeAhorro caja;
    void mostrarinfo() override;

public:
    CuentaCorriente(double initial_balance, string name);
    void ingresar(double income) override;
    void ingresar_a_caja(double income);
    void retirar(double withdrawal) override;

    void illegal_mostrar();
    
    
};

