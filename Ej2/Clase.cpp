#include "Ej2.hpp"



Curso::Curso(string curso_name) : name_curso(curso_name), listado(vector<shared_ptr<Alumno>>()) {}

Curso::Curso(string curso_name, Curso CursoBase){
    this->name_curso = curso_name;
    this->listado = CursoBase.Create_copy();
}

bool Curso::legajo_exists(unsigned new_legajo) {
    for (shared_ptr<Alumno> alumno : listado) {
        if (alumno->get_legajo() == new_legajo) {
            return true;
        }
    }
    return false;
}

void Curso::InscribirAlumno(shared_ptr<Alumno> new_alumno) {
    if (listado.size() >= MAX_CAPACITY) {
        throw out_of_range("El curso ha alcanzado su capacidad máxima");
        return;
    }

    if (legajo_exists(new_alumno->get_legajo())) {
        throw invalid_argument("Ya existe un alumno con ese legajo");
        return;
    }
    listado.push_back(new_alumno);
}

void Curso::DesinscribirAlumno(shared_ptr<Alumno> bad_alumno) {
    unsigned bad_legajo = bad_alumno->get_legajo();
    for (auto it = listado.begin(); it != listado.end(); ++it) {
        if ((*it)->get_legajo() == bad_legajo) {
            listado.erase(it);
            return;
        }
    }
    cout << "Error -> El alumno no se encuentra en el curso" << endl;
}
void Curso::RegistrarResultado(shared_ptr<Alumno> alumno, unsigned nota_final){
    unsigned legajo = alumno->get_legajo();
    for (auto it = listado.begin(); it != listado.end(); ++it) {
        if ((*it)->get_legajo() == legajo) {

            // Antes de sacarlo, registro el resultado del curso
            (*it)->add_course(name_curso, nota_final);
            listado.erase(it);
            return;
        }
    }
}

void Curso::alphabetical_print() {
    sort(listado.begin(), listado.end(), [](shared_ptr<Alumno> a, shared_ptr<Alumno> b) {
        return *a < *b;
    });

    cout << "=============================" << endl;
    cout << "   Listado de Alumnos" << endl;
    cout << "=============================" << endl;
    cout << left << setw(20) << "Nombre" << "Legajo" << endl;
    cout << "-----------------------------" << endl;

    for (shared_ptr<Alumno> alumno : listado) {
        cout << left << setw(20) << alumno->get_name() << alumno->get_legajo() << endl;
    }

    cout << "=============================" << endl;
}
void Curso::print_size(){
    cout << "La cantida de alumnos en la clase es -> " << listado.size() << endl;
}

string Curso::get_name(){
    return name_curso;
}
vector<shared_ptr<Alumno>> Curso::Create_copy(){  //Devuelve una copia del listado
    return listado;
}
shared_ptr<Alumno> Curso::find_alumno(unsigned legajo) { 
    for (shared_ptr<Alumno> alumno : listado) {
        if (alumno->get_legajo() == legajo) {
            return alumno;
        }
    }
    return nullptr; // Si no se encuentra, retorna nullptr
}
