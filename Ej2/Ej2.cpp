#include "Ej2.hpp"
int main (void){

    Alumno alumno1 = Alumno("Anakin Skywalker", 1001);
    Alumno alumno2 = Alumno("Han Solo", 1002);
    Alumno alumno3 = Alumno("Leia Organa", 1003);
    Alumno alumno5 = Alumno("Obi-Wan Kenobi", 1005);
    Alumno alumno6 = Alumno("Padmé Amidala", 1006);
    Alumno alumno7 = Alumno("Yoda", 1007);
    Alumno alumno8 = Alumno("Mace Windu", 1008);

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
    Alumno alumno9 = Alumno ("Darth Veide", 1001);
    Star_Wars.InscribirAlumno(alumno9);

    //voy a llenar la clase para probar cuando esta llena 
    Alumno alumno10 = Alumno("Qui-Gon Jinn", 1009);
    Alumno alumno11 = Alumno("Lando Calrissian", 1010);
    Alumno alumno12 = Alumno("Chewbacca", 1011);
    Alumno alumno13 = Alumno("R2-D2", 1012);
    Alumno alumno14 = Alumno("C-3PO", 1013);
    Alumno alumno15 = Alumno("Boba Fett", 1014);
    Alumno alumno16 = Alumno("Jango Fett", 1015);
    Alumno alumno17 = Alumno("Palpatine", 1016);
    Alumno alumno18 = Alumno("Rey", 1017);
    Alumno alumno19 = Alumno("Finn", 1018);
    Alumno alumno20 = Alumno("Poe Dameron", 1019);
    Alumno alumno21 = Alumno("Kylo Ren", 1020);
    Alumno alumno22 = Alumno("Ahsoka Tano", 1021);
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

    Alumno alumno23 = Alumno("Juan", 1022);

    Star_Wars.InscribirAlumno(alumno23);
}