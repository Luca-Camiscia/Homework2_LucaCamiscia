#include "Ej2.hpp"
int main (void){

    Alumno alumno1 = Alumno("Anakin Skywalker", 1001);
    Alumno alumno2 = Alumno("Han Solo", 1002);
    Alumno alumno3 = Alumno("Leia Organa", 1003);
    Alumno alumno5 = Alumno("Obi-Wan Kenobi", 1005);
    Alumno alumno6 = Alumno("Padmé Amidala", 1006);
    Alumno alumno7 = Alumno("Yoda", 1007);
    Alumno alumno8 = Alumno("Mace Windu", 1008);
    Alumno alumno9 = Alumno ("Darth Veider", 1001);

    Curso Star_Wars = Curso();
    Star_Wars.InscribirAlumno(alumno1);
    Star_Wars.InscribirAlumno(alumno2);
    Star_Wars.InscribirAlumno(alumno3);
    Star_Wars.InscribirAlumno(alumno5);
    Star_Wars.InscribirAlumno(alumno6);
    Star_Wars.InscribirAlumno(alumno7);
    Star_Wars.InscribirAlumno(alumno8);
    Star_Wars.InscribirAlumno(alumno9);
    Star_Wars.alphabetical_print();
    //elimino algunos
    Star_Wars.DesinscribirAlumno(alumno3);
    Star_Wars.DesinscribirAlumno(alumno5); 
    Star_Wars.alphabetical_print();

}