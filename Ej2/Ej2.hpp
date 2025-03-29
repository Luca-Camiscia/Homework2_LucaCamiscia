#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <tuple>
using namespace std;
#define MAX_CAPACITY 20


class Alumno {
private:
    string name;
    unsigned legajo;
    vector<tuple<string, unsigned>> cursos_terminados; // Vector of tuples containing a string and an unsigned

public:
    Alumno(string new_name, unsigned new_legajo);
    Alumno(string new_name, unsigned new_legajo, vector<tuple<string, unsigned>> finished_cursos);
    string get_name();
    unsigned get_legajo();
    void add_course(string course_name, unsigned final_note);
    unsigned get_promedio();
};

class Curso {
private:
    string name_curso;
    vector<shared_ptr<Alumno>> listado;
    bool legajo_exists(unsigned new_legajo);

public:
    Curso();
    void InscribirAlumno(shared_ptr<Alumno> new_alumno);
    void DesinscribirAlumno(shared_ptr<Alumno> bad_alumno);
    void RegistrarResultado(shared_ptr<Alumno> good_alumno, unsigned nota_final); //Como desinscribir pero le agrega al objeto alumno el curso correspondiente
    void alphabetical_print();
    void print_size();
    string get_name();
    Curso Create_copy();
};;

