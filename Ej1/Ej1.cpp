#include "Ej1.hpp"
int main (void){

 cout << "Creo momento ejemplo" << endl;

 momento almuerzo = momento(1, 23, 3, "p.m");

cout << "Imprimo todos los datos" << endl << almuerzo.GetTime() << endl;

cout << "Imprimo datos por separado" << endl << "Hora -> " << almuerzo.GetHour() << endl <<
"Minutos -> " << almuerzo.GetMinutes() << endl << "Segundos -> " << almuerzo.GetSeconds() << endl <<
"Tiempo -> " << almuerzo.GetMorning() << endl;;

cout << "Imprimo en formato 24 hs" << endl;
almuerzo.print_24hour();

cout << "Cambio la hora" << endl << "Antes -> " << almuerzo.GetTime() << endl;
almuerzo.SetHour(4);
cout << "Ahora -> " << almuerzo.GetTime() << endl;

cout << "Cambio los minutos" << endl << "Antes -> " << almuerzo.GetTime() << endl;
almuerzo.SetMinutes(45);
cout << "Ahora -> " << almuerzo.GetTime() << endl;

cout << "Cambio los segundos" << endl << "Antes -> " << almuerzo.GetTime() << endl;
almuerzo.SetSeconds(30);
cout << "Ahora -> " << almuerzo.GetTime() << endl;

cout << "Cambio a a.m" << endl << "Antes -> " << almuerzo.GetTime() << endl;
almuerzo.SetMorning("a.m");
cout << "Ahora -> " << almuerzo.GetTime() << endl;

cout << "Ejemplo ingresado por el usario: " << endl << "----------------------------------------------" << endl;

int hour, minutes, seconds;
string morning;
bool correct_input = false;
bool asking = true;
momento userMomento(0, 0, 0, "a.m"); //para que no explote
while (asking){ 
    asking = false;
cout << "Ingrese la hora: ";
cin >> hour;

cout << "Ingrese los minutos: ";
cin >> minutes;

cout << "Ingrese los segundos: ";
cin >> seconds;

cout << "Ingrese a.m o p.m: ";
cin >> morning;



try {
    userMomento = momento(hour, minutes, seconds, morning); 
    correct_input = true; 
}
catch(invalid_argument){
    cout << "Los datos no son correctos\nDesea volver a intentar? (Ingrese YES o NO)" << endl;
    string salir;
    cin >> salir;
    if (salir == "YES"){
        asking = true;
        cout << "Ingrese nuevamente los datos" << endl;

    }
    else{
        correct_input = false;
    }
}
}

if (correct_input){ 
cout << "Datos ingresados por el usuario:" << endl;
cout << "Hora -> " << userMomento.GetHour() << endl;
cout << "Minutos -> " << userMomento.GetMinutes() << endl;
cout << "Segundos -> " << userMomento.GetSeconds() << endl;
cout << "Tiempo -> " << userMomento.GetMorning() << endl;

cout << "Formato 24 hs:" << endl;
userMomento.print_24hour();

}
}