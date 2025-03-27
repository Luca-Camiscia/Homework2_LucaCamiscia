#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <memory>
using namespace std;
#define MAX_CAPACITY 20

unsigned gen_legajo();

class Alumno {
private:
    string name;
    unsigned legajo;
    unsigned promedio;
    vector<string> cursos_terminados;

public:
    Alumno(string new_name, unsigned new_legajo);
    string get_name();
    unsigned get_legajo();
};

class Curso {
private:
    vector<shared_ptr<Alumno>> listado;
    bool legajo_exists(unsigned new_legajo);

public:
    Curso();
    void InscribirAlumno(shared_ptr<Alumno> new_alumno);
    void DesinscribirAlumno(shared_ptr<Alumno> bad_alumno);
    void alphabetical_print();
    void print_size();
    Curso Create_copy();
};;

