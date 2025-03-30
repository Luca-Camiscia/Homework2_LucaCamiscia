#include "Ej2.hpp"

int main(void){
    //Creo Alumnos iniciales

    auto alumno1 = make_shared<Alumno>("Euclid", 1000);
    auto alumno2 = make_shared<Alumno>("Archimedes", 1001);
    auto alumno3 = make_shared<Alumno>("Pythagoras", 1002);
    auto alumno4 = make_shared<Alumno>("Descartes", 1003);
    auto alumno5 = make_shared<Alumno>("Newton", 1004);
    auto alumno6 = make_shared<Alumno>("Leibniz", 1005);
    auto alumno7 = make_shared<Alumno>("Kant", 1006);
    auto alumno8 = make_shared<Alumno>("Plato", 1007);
    auto alumno9 = make_shared<Alumno>("Aristotle", 1008);
    auto alumno10 = make_shared<Alumno>("Socrates", 1009);
    auto alumno11 = make_shared<Alumno>("Spinoza", 1010);
    auto alumno12 = make_shared<Alumno>("Hume", 1011);
    auto alumno13 = make_shared<Alumno>("Locke", 1012);
    auto alumno14 = make_shared<Alumno>("Russell", 1013);
    auto alumno15 = make_shared<Alumno>("Wittgenstein", 1014);
    auto alumno16 = make_shared<Alumno>("Pascal", 1015);
    auto alumno17 = make_shared<Alumno>("Gauss", 1016);
    auto alumno18 = make_shared<Alumno>("Euler", 1017);
    auto alumno19 = make_shared<Alumno>("Turing", 1018);
    auto alumno20 = make_shared<Alumno>("Gödel", 1019);


    // Creo cursos iniciales
    Curso analisis = Curso("Analisis Matematico");
    Curso algebra = Curso("Algebra lineal");
    Curso historia = Curso("Historia sociopolitica");

    //Inscribo los Alumnos iniciales a algunos cursos

    analisis.InscribirAlumno(alumno1);
    analisis.InscribirAlumno(alumno2);
    analisis.InscribirAlumno(alumno3);
    algebra.InscribirAlumno(alumno4);
    algebra.InscribirAlumno(alumno5);
    algebra.InscribirAlumno(alumno6);
    historia.InscribirAlumno(alumno7);
    historia.InscribirAlumno(alumno8);
    historia.InscribirAlumno(alumno9);
    historia.InscribirAlumno(alumno10);
    analisis.InscribirAlumno(alumno11);
    algebra.InscribirAlumno(alumno12);
    historia.InscribirAlumno(alumno13);
    analisis.InscribirAlumno(alumno14);
    algebra.InscribirAlumno(alumno15);
    historia.InscribirAlumno(alumno16);
    analisis.InscribirAlumno(alumno17);
    algebra.InscribirAlumno(alumno18);
    historia.InscribirAlumno(alumno19);
    analisis.InscribirAlumno(alumno20);
    // Agrego los cursos a un vector de cursos disponibles
    vector<Curso> cursos_disponibles;
    cursos_disponibles.push_back(analisis);
    cursos_disponibles.push_back(algebra);
    cursos_disponibles.push_back(historia);
    // Agrego a los alumno a un vector de alumnos existentes
    vector<shared_ptr<Alumno>> alumnos_vivos;
    alumnos_vivos.push_back(alumno1);
    alumnos_vivos.push_back(alumno2);
    alumnos_vivos.push_back(alumno3);
    alumnos_vivos.push_back(alumno4);
    alumnos_vivos.push_back(alumno5);
    alumnos_vivos.push_back(alumno6);
    alumnos_vivos.push_back(alumno7);
    alumnos_vivos.push_back(alumno8);
    alumnos_vivos.push_back(alumno9);
    alumnos_vivos.push_back(alumno10);
    alumnos_vivos.push_back(alumno11);
    alumnos_vivos.push_back(alumno12);
    alumnos_vivos.push_back(alumno13);
    alumnos_vivos.push_back(alumno14);
    alumnos_vivos.push_back(alumno15);
    alumnos_vivos.push_back(alumno16);
    alumnos_vivos.push_back(alumno17);
    alumnos_vivos.push_back(alumno18);
    alumnos_vivos.push_back(alumno19);
    alumnos_vivos.push_back(alumno20);
    // Menu

    menu(&cursos_disponibles, &alumnos_vivos);
    




    return 0;
}