#include "Ej2.hpp"


Alumno::Alumno(string new_name, unsigned new_legajo) : name(new_name), legajo(new_legajo), cursos_terminados(vector<tuple<string, unsigned>>()) {}
Alumno::Alumno(string new_name, unsigned new_legajo, vector<tuple<string,unsigned>> finished_cursos) : name(new_name), legajo(new_legajo), cursos_terminados(finished_cursos) {}

string Alumno::get_name() {
    return name;
}

unsigned Alumno::get_legajo() {
    return legajo;
}
    
void Alumno::add_course(string course_name, unsigned final_note) {
    // Compruebo que el alumno no tenga ya el curso
    for (const auto& curso : cursos_terminados) {
        if (get<0>(curso) == course_name) {
            // Si el curso ya existe mando un thros
            throw invalid_argument("El estudiante ya tiene registrado este curso");

        }
    }
    // Si no existe, lo agrego al vector
    tuple<string, unsigned> nuevo_curso = make_tuple(course_name, final_note);
    cursos_terminados.push_back(nuevo_curso);
}

unsigned Alumno::get_promedio() {
    if (cursos_terminados.empty()){
        return 0;
    }
    unsigned total_sum = 0;
    for (const auto& curso : cursos_terminados) {
        total_sum += get<1>(curso); // Sum the final notes
    }
    
    return total_sum/cursos_terminados.size();
    }  


