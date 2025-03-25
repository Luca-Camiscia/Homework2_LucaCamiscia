using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#define MAX_CAPACITY 20
unsigned gen_legajo() {
        srand(time(0));
        return 1000 + rand() % 9000; // Generates a random 4-digit number
    
    }


class Alumno{ 
    private:
    string name;
    unsigned legajo;
    // Lista de cursos con nota final???

    public:
    Alumno(string new_name, unsigned new_legajo): name(new_name), legajo(new_legajo){
    }

    string get_name(){ 
        return name;
    }
    unsigned get_legajo(){
        return legajo;
    }

};



class Curso {
    private:
    vector<Alumno> listado;
    
    public:
    bool legajo_exists(unsigned new_legajo){
        for (Alumno alumno : listado) {
            if (alumno.get_legajo() == new_legajo) {
            return true;
            }
        }
        return false;

    }
    void InscribirAlumno(Alumno new_alumno) {
        if (listado.size() >= MAX_CAPACITY) {
            cout << "ERROR -> El curso ha alcanzado su capacidad máxima" << endl;
            return;
        }

        if (legajo_exists(new_alumno.get_legajo())) {
            cout << "ERROR -> DOS LEGAJOS IGUALES" << endl;
            return;
        }
        listado.push_back(new_alumno);
        return;
    }
    void DesinscribirAlumno(Alumno bad_alumno){
        unsigned bad_legajo = bad_alumno.get_legajo();
        for (auto it = listado.begin(); it != listado.end(); ++it) {
            if (it->get_legajo() == bad_legajo) {
                listado.erase(it);
                return;
            }
        }
        cout << "Error -> El alumno no se encuentra en el curso" << endl;

    }

    void alphabetical_print(){
        sort(listado.begin(), listado.end(), [](Alumno a, Alumno b) {
            return a.get_name() < b.get_name();
        });
        //Imprimo
        cout << "Nombre \t Legajo" << endl;
        for(Alumno alumno :listado){
            cout << "." << alumno.get_name() <<"\t"<<  alumno.get_legajo() << endl;
        }
    }

};

