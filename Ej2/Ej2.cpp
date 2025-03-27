#include "Ej2.hpp"
int main (void){

    auto alumno1 = make_shared<Alumno>("Anakin Skywalker", 1001);
    auto alumno2 = make_shared<Alumno>("Han Solo", 1002);
    auto alumno3 = make_shared<Alumno>("Leia Organa", 1003);
    auto alumno5 = make_shared<Alumno>("Obi-Wan Kenobi", 1005);
    auto alumno6 = make_shared<Alumno>("Padmé Amidala", 1006);
    auto alumno7 = make_shared<Alumno>("Yoda", 1007);
    auto alumno8 = make_shared<Alumno>("Mace Windu", 1008);

    Curso Star_Wars = Curso();
    Star_Wars.InscribirAlumno(alumno1);
    Star_Wars.InscribirAlumno(alumno2);
    Star_Wars.InscribirAlumno(alumno3);
    Star_Wars.InscribirAlumno(alumno5);
    Star_Wars.InscribirAlumno(alumno6);
    Star_Wars.InscribirAlumno(alumno7);
    Star_Wars.InscribirAlumno(alumno8);
    Star_Wars.alphabetical_print();
    //elimino algunos
    Star_Wars.DesinscribirAlumno(alumno3);
    Star_Wars.DesinscribirAlumno(alumno5); 
    Star_Wars.alphabetical_print();

    cout << "pruebo insertar un alumno que tenga un legajo repetido" << endl;
    auto alumno9 = make_shared<Alumno>("Darth Veide", 1001);
    Star_Wars.InscribirAlumno(alumno9);

    //voy a llenar la clase para probar cuando esta llena 
    auto alumno10 = make_shared<Alumno>("Qui-Gon Jinn", 1009);
    auto alumno11 = make_shared<Alumno>("Lando Calrissian", 1010);
    auto alumno12 = make_shared<Alumno>("Chewbacca", 1011);
    auto alumno13 = make_shared<Alumno>("R2-D2", 1012);
    auto alumno14 = make_shared<Alumno>("C-3PO", 1013);
    auto alumno15 = make_shared<Alumno>("Boba Fett", 1014);
    auto alumno16 = make_shared<Alumno>("Jango Fett", 1015);
    auto alumno17 = make_shared<Alumno>("Palpatine", 1016);
    auto alumno18 = make_shared<Alumno>("Jar Jar Bins", 1017);
    auto alumno19 = make_shared<Alumno>("Finn", 1018);
    auto alumno20 = make_shared<Alumno>("Poe Dameron", 1019);
    auto alumno21 = make_shared<Alumno>("Kylo Ren", 1020);
    auto alumno22 = make_shared<Alumno>("Ahsoka Tano", 1021);
    Star_Wars.InscribirAlumno(alumno3);
    Star_Wars.InscribirAlumno(alumno5);
    Star_Wars.InscribirAlumno(alumno10);
    Star_Wars.InscribirAlumno(alumno11);
    Star_Wars.InscribirAlumno(alumno12);
    Star_Wars.InscribirAlumno(alumno13);
    Star_Wars.InscribirAlumno(alumno14);
    Star_Wars.InscribirAlumno(alumno15);
    Star_Wars.InscribirAlumno(alumno16);
    Star_Wars.InscribirAlumno(alumno17);
    Star_Wars.InscribirAlumno(alumno18);
    Star_Wars.InscribirAlumno(alumno19);
    Star_Wars.InscribirAlumno(alumno20);
    Star_Wars.InscribirAlumno(alumno21);
    Star_Wars.InscribirAlumno(alumno22);
    Star_Wars.alphabetical_print();
    Star_Wars.print_size();

    auto alumno23 = make_shared<Alumno>("Juan", 1022);

    Star_Wars.InscribirAlumno(alumno23);
}