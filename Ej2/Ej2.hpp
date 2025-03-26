#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MAX_CAPACITY 20

unsigned gen_legajo();

class Alumno {
private:
    std::string name;
    unsigned legajo;

public:
    Alumno(std::string new_name, unsigned new_legajo);
    std::string get_name();
    unsigned get_legajo();
};

class Curso {
private:
    std::vector<Alumno> listado;

public:
    Curso();
    bool legajo_exists(unsigned new_legajo);
    void InscribirAlumno(Alumno new_alumno);
    void DesinscribirAlumno(Alumno bad_alumno);
    void alphabetical_print();
};

