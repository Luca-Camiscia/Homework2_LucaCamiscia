#include <iostream>
using namespace std;
class Cuenta{
    
  protected:
  string user_name;
  private:
  double balance;
  void mostrar_info();
  public:
  void depositar(double income);
  void retirar(double income);

  
};