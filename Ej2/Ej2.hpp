#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <tuple>
#include <limits> 
using namespace std;
#define MAX_CAPACITY 20


class Alumno {
private:
    string name;
    unsigned legajo;
    vector<tuple<string, float>> cursos_terminados;

public:
    Alumno(string new_name, unsigned new_legajo);
    Alumno(string new_name, unsigned new_legajo, vector<tuple<string, float>> finished_cursos);
    string get_name();
    unsigned get_legajo();
    void add_course(string course_name, unsigned final_note);
    unsigned get_promedio();
    void print_datos();
};

class Curso {
private:
    string name_curso;
    vector<shared_ptr<Alumno>> listado;
    bool legajo_exists(unsigned new_legajo);

public:
    Curso(string curso_name);
    void InscribirAlumno(shared_ptr<Alumno> new_alumno);
    void DesinscribirAlumno(shared_ptr<Alumno> bad_alumno);
    void RegistrarResultado(shared_ptr<Alumno> good_alumno, unsigned nota_final); //Como desinscribir pero le agrega al objeto alumno el curso correspondiente
    void alphabetical_print();
    void print_size();
    string get_name();
    Curso Create_copy();
    shared_ptr<Alumno> find_alumno(unsigned legajo);
};


//Funciones menu

shared_ptr<Alumno> buscar_alumno_por_legajo(vector<shared_ptr<Alumno>>* alumnos_vivos, unsigned legajo) ;
shared_ptr<Curso> buscar_curso_por_nombre(vector<Curso> *cursos_disponibles, string name);


void mostrar_cursos_disponibles(vector<Curso> cursos_disponibles);
void mostrar_alumnos_vivos(vector<shared_ptr<Alumno>> alumnos_vivos);
void menu(vector<Curso>*cursos_disponibles,vector<shared_ptr<Alumno>>*alumnos_vivos);
void Crear_Alumno(vector<shared_ptr<Alumno>>* alumnos_vivos) ;
void Mostrar_datos_Alumno(vector<shared_ptr<Alumno>>* alumnos_vivos);
void mostrar_curso(vector<Curso> *cursos_disponibles) ;
void InscribirAlumno(vector<shared_ptr<Alumno>>* alumnos_vivos, vector<Curso>*cursos_disponibles);
void Desincribir_alumno(vector<Curso> *cursos_disponibles);
void Crear_nuevo_curso(vector<Curso> *cursos_disponibles);

