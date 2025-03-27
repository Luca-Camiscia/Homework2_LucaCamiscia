#include "Ej2.hpp"

unsigned gen_legajo() {
    srand(time(0));
    return 1000 + rand() % 9000;
}

Alumno::Alumno(string new_name, unsigned new_legajo) : name(new_name), legajo(new_legajo) {}

string Alumno::get_name() {
    return name;
}

unsigned Alumno::get_legajo() {
    return legajo;
}

Curso::Curso() : listado(vector<shared_ptr<Alumno>>()) {}

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
        cout << "ERROR -> El curso ha alcanzado su capacidad máxima" << std::endl;
        return;
    }

    if (legajo_exists(new_alumno->get_legajo())) {
        cout << "ERROR -> DOS LEGAJOS IGUALES: " << new_alumno->get_name()
                  << " con legajo " << new_alumno->get_legajo() << std::endl;
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

void Curso::alphabetical_print() {
    sort(listado.begin(), listado.end(), [](shared_ptr<Alumno> a, shared_ptr<Alumno> b) {
        return a->get_name() < b->get_name();
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

Curso Curso::Create_copy(){
    Curso new_curso = Curso();
    for (shared_ptr<Alumno> alumno : listado){
        new_curso.InscribirAlumno(alumno);
    } 
    return new_curso;
}