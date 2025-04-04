#include <iostream>
#include <memory>
#include <complex>
#include <tuple>
using namespace std;

class Numero {
    protected:
    string tag;

    public:
    Numero(string tag);
    virtual void suma(shared_ptr<class Numero> adding_num) = 0;
    virtual void resta(shared_ptr<class Numero> substracting_num) = 0;
    virtual void mult(shared_ptr<class Numero> mult_num) = 0;
    virtual void div(shared_ptr<class Numero> Dividing_num) = 0;
    virtual int Get_as_int() = 0;
    virtual float Get_as_Real() = 0;
    virtual tuple<float,float> Get_as_Complex() = 0; 
    virtual string getType() = 0;
    virtual string toString() = 0;
};

class Entero: public Numero{
    private:
    int num;
    
    public:
    Entero(int num);
    void suma(shared_ptr<class Numero> adding_num) override;
    void resta(shared_ptr<class Numero> substracting_num) override;
    void mult(shared_ptr<class Numero> mult_num)override;
    void div(shared_ptr<class Numero> Dividing_num)override;
    int Get_as_int() override;
    float Get_as_Real() override;
    tuple<float,float> Get_as_Complex() override; 

    string getType()override;
    string toString()override;
};

class Real: public Numero{
    private:
    float num;
    
    public:
    Real(float num);
    void suma(shared_ptr<class Numero> adding_num) override;
    void resta(shared_ptr<class Numero> substracting_num) override;
    void mult(shared_ptr<class Numero> mult_num)override;
    void div(shared_ptr<class Numero> Dividing_num)override;
    int Get_as_int() override;
    float Get_as_Real() override;
    tuple<float,float> Get_as_Complex()override; 

    string getType()override;
    string toString()override;

 };

 class Complejo: public Numero{
    private:
    complex<float> num;
    float real;
    float imagi;
    
    public:
    Complejo(float real_input, float imagi_input);
    void suma(shared_ptr<class Numero> adding_num) override;
    void resta(shared_ptr<class Numero> substracting_num) override;
    void mult(shared_ptr<class Numero> mult_num)override;
    void div(shared_ptr<class Numero> Dividing_num)override;
    int Get_as_int() override;
    float Get_as_Real() override;
    tuple<float,float> Get_as_Complex()override; 

    string getType()override;
    string toString()override;
 };