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

cout << "Ingrese la hora: ";
cin >> hour;

cout << "Ingrese los minutos: ";
cin >> minutes;

cout << "Ingrese los segundos: ";
cin >> seconds;

cout << "Ingrese a.m o p.m: ";
cin >> morning;

momento userMomento = momento(hour, minutes, seconds, morning);

cout << "Datos ingresados por el usuario:" << endl;
cout << "Hora -> " << userMomento.GetHour() << endl;
cout << "Minutos -> " << userMomento.GetMinutes() << endl;
cout << "Segundos -> " << userMomento.GetSeconds() << endl;
cout << "Tiempo -> " << userMomento.GetMorning() << endl;

cout << "Formato 24 hs:" << endl;
userMomento.print_24hour();


}