#include "Ej2.hpp"

//ESTO ESTA HECHO CON MUCHO AMOR

void mostrar_cursos_disponibles(vector<Curso> cursos_disponibles) {
    cout << "===== Cursos Disponibles =====" << endl;
    for (auto curso : cursos_disponibles) {
        cout << "- " << curso.get_name() << endl;
    }
    cout << "==============================" << endl;
}

void mostrar_alumnos_vivos(vector<shared_ptr<Alumno>> alumnos_vivos) {
    cout << "===== Alumnos Inscritos =====" << endl;
    for (auto alumno : alumnos_vivos) {
        cout << "- " << alumno->get_name() << " (Legajo: " << alumno->get_legajo() << ")" << endl;
    }
    cout << "=============================" << endl;
}


void menu(vector<Curso>*cursos_disponibles,vector<shared_ptr<Alumno>>*alumnos_vivos) { 
    unsigned choice;

    cout << "Bienvenido al sistema de la facultad \nPor favor ingrese la opcion que desea utilizar" << endl;

    while (true) {
        cout << "1. Ver cursos disponibles" << endl;
        cout << "2. Mostrar alumnos existentes" << endl;
        cout << "3. Mostrar alumnos anotados a un curso" << endl;
        cout << "4. Crear un alumno" << endl;
        cout << "5. Inscribir un alumno" << endl;
        cout << "6. Desinscribir a un Alumno" << endl;
        cout << "7. Ver información de un alumno" << endl;
        cout << "8. Crear un nuevo Curso" << endl;
        cout << "9. Salir" << endl;

        cout << "Ingrese su opción: ";
        if (cin >> choice && choice >= 1 && choice <= 9) {
            if (choice == 9) {
                cout << "Saliendo del sistema. ¡Hasta luego!" << endl;
                break; // Salir del bucle si selecciona la opción 7
            }

            // Aquí puedes manejar la opción seleccionada
            cout << "Opción seleccionada: " << choice << endl;

            switch (choice)
            {
            case 1:
                mostrar_cursos_disponibles(*cursos_disponibles);
                break;
            case 2:
                mostrar_alumnos_vivos(*alumnos_vivos);
                break;
            case 3:
                mostrar_curso(cursos_disponibles);
                break;                
            case 4:
                Crear_Alumno(alumnos_vivos);
                break;

            case 5:
                InscribirAlumno(alumnos_vivos, cursos_disponibles);
                break;
            case 6:
                
                Desincribir_alumno(cursos_disponibles);
                break;

            case 7:
                Mostrar_datos_Alumno(alumnos_vivos);
                break;
            
            case 8:
                Crear_nuevo_curso(cursos_disponibles);

            default:
                cout << "Funcionalidad no implementada aún." << endl;
                break;
            }
        } else {
            cout << "Entrada inválida. Por favor, intente de nuevo." << endl;
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
        }
    
    }


}


void Crear_Alumno(vector<shared_ptr<Alumno>>* alumnos_vivos) { 
    string name;
    cout << "Ingrese el nombre del alumno: " << endl;
    cin >> name;
    unsigned legajo;
    cout << "Ingrese el legajo del alumno: " << endl;
    cin >> legajo;

    //comrobacion de que no haya ya uno con ese legajo
    auto it = buscar_alumno_por_legajo(alumnos_vivos,legajo);
    if (it){
        cout << "Ya existe un alumno con ese legajo" << endl;
        return;
    }

    vector<tuple<string, float>> cursos_completados;
    char tiene_cursos;
    cout << "¿El alumno ya tiene cursos completados? (s/n): ";
    cin >> tiene_cursos;

    if (tiene_cursos == 's' || tiene_cursos == 'S') {
        while (true) {
            string curso_nombre;
            float nota_final;

            cout << "Ingrese el nombre del curso (o 'fin' para terminar): ";
            cin >> curso_nombre;

            if (curso_nombre == "fin") {
                break;
            }

            cout << "Ingrese la nota final del curso: ";
            cin >> nota_final;

            cursos_completados.push_back(make_tuple(curso_nombre, nota_final));
        }
    }
    // Crear un nuevo alumno y agregarlo al vector
    
    try {
        shared_ptr<Alumno> nuevo_alumno;
        if (tiene_cursos == 'n' || tiene_cursos == 'N') {
            nuevo_alumno = make_shared<Alumno>(name, legajo);
        } else {
            nuevo_alumno = make_shared<Alumno>(name, legajo, cursos_completados);
        }
        alumnos_vivos->push_back(nuevo_alumno);

    } catch (const invalid_argument& e) {
        cerr << "Error al crear el alumno: " << e.what() << endl;
    }


    cout << "Alumno creado exitosamente." << endl;
}

void Mostrar_datos_Alumno(vector<shared_ptr<Alumno>>* alumnos_vivos) {
    unsigned legajo;
    cout << "Ingrese el legajo de alumno que desea consultar" << endl;
    cin >> legajo;
    
    auto it = buscar_alumno_por_legajo(alumnos_vivos, legajo);

    if (it != nullptr) {
        cout << "Alumno encontrado: " << it->get_name() << endl;
        it->print_datos();
    } else {
        cout << "No se encontró un alumno con el legajo: " << legajo << endl;
    }
}

void mostrar_curso(vector<Curso> *cursos_disponibles) {
    string name;
    cout << "Ingrese el nombre del curso que desea buscar: ";
    cin >> name;
    auto it = find_if(cursos_disponibles->begin(), cursos_disponibles->end(), [&name](Curso curso) {
        return curso.get_name() == name;
    });

    if (it != cursos_disponibles->end()) {
        cout << "Curso encontrado: " << it->get_name() << endl;
        it->alphabetical_print();
    } else {
        cout << "No se encontró un curso con el nombre: " << name << endl;
    }
}

void InscribirAlumno(vector<shared_ptr<Alumno>>* alumnos_vivos, vector<Curso>*cursos_disponibles){
    unsigned legajo;
    cout << "Ingrese el legajo del alumno que desea inscribir a un curso" << endl;
    cin >> legajo;

    auto alumno_it = buscar_alumno_por_legajo(alumnos_vivos, legajo);
    string name_curso;
    cout << "Ingrese el nombre del curso donde quiere inscribir al alumno" << endl;
    mostrar_cursos_disponibles(*cursos_disponibles);
    cin >> name_curso;

    auto curso_ptr = buscar_curso_por_nombre(cursos_disponibles, name_curso);

    if (curso_ptr != nullptr) {
        cout << "Curso encontrado: " << curso_ptr->get_name() << endl;

        if (alumno_it != nullptr) {
            cout << "Alumno encontrado: " << alumno_it->get_name() << endl;

            try {
                curso_ptr->InscribirAlumno(alumno_it);
                cout << "Alumno inscrito correctamente en el curso." << endl;
            } catch (const exception& e) {
                cerr << "Error al inscribir al alumno: " << e.what() << endl;
            }
        } else {
            cout << "No se encontró un alumno con el legajo: " << legajo << endl;
        }
    } else {
        cout << "No se encontró un curso con el nombre: " << name_curso << endl;
    }
    

    

}

void Desincribir_alumno(vector<Curso> *cursos_disponibles) {
    string name_curso;
    cout << "Ingrese el nombre del curso donde se encuentra el alumno" << endl;
    cin >> name_curso;
    unsigned legajo;
    char terminado;
    cout << "Ingrese el legajo de alumno que desea trabajar" << endl;
    cin >> legajo;
    cout << "El alumno ha realizado el curso en su totalidad? (s/n)" << endl;
    cin >> terminado;

    auto curso_ptr = buscar_curso_por_nombre(cursos_disponibles, name_curso);

    if (curso_ptr != nullptr) {
        cout << "Curso encontrado: " << curso_ptr->get_name() << endl;

        auto alumno_it = curso_ptr->find_alumno(legajo); 
        if (alumno_it != nullptr) { // Verifica si el alumno fue encontrado
            cout << "Alumno encontrado: " << alumno_it->get_name() << endl;

            if (terminado == 's' || terminado == 'S') {
                float nota_final;
                cout << "Ingrese la nota final del estudiante" << endl;
                cin >> nota_final;
                curso_ptr->RegistrarResultado(alumno_it, nota_final);
                cout << "Se ha registrado el curso en el historial del alumno" << endl;
                return;
            } else {
                curso_ptr->DesinscribirAlumno(alumno_it);
                cout << "Alumno desinscripto correctamente" << endl;
            }
        } else {
            cout << "No se encontró un alumno con el legajo: " << legajo << " en el curso." << endl;
        }
    } else {
        cout << "No se encontró un curso con el nombre: " << name_curso << endl;
        return;
    }
}

shared_ptr<Alumno> buscar_alumno_por_legajo(vector<shared_ptr<Alumno>>* alumnos_vivos, unsigned legajo) {
    for (auto alumno : *alumnos_vivos) {
        if (alumno->get_legajo() == legajo) {
            return alumno; // Retorna el alumno encontrado
        }
    }
    return nullptr; // Retorna nullptr si no se encuentra el alumno
}

Curso* buscar_curso_por_nombre(vector<Curso>* cursos_disponibles, string name) {
    for (auto& curso : *cursos_disponibles) {
        if (curso.get_name() == name) {
            return &curso; // Retorna un puntero al curso
        }
    }
    return nullptr; // Retorna nullptr si no se encuentra el curso
}



void Crear_nuevo_curso(vector<Curso>*cursos_disponibles){

    string name;
    cout << "Ingrese el nombre del nuevo curso" << endl;
    cin >> name;
    auto curso_existente = buscar_curso_por_nombre(cursos_disponibles, name);
    if (curso_existente != nullptr){
        cout << "Ya existe un curso con ese nombre. Intente otro" << endl;
        return;
    }
    char choice;
    cout << "Desea crearlo a paritr de los estudiantes de otro curso? (s/n)";
    cin >> choice;
    
    Curso new_curso(name); 

    if (choice == 's' || choice == 'S') {
        
        string cursoBase;
        cout << "Ingrese el nombre del curso de donde provienen los estudiantes" << endl;
        cin >> cursoBase;

        Curso* from_curso = buscar_curso_por_nombre(cursos_disponibles, cursoBase);

        if (from_curso != nullptr) {
            new_curso = from_curso->Create_copy(name);
        } else {
            cout << "No se encontró el curso base. Creando un curso vacío." << endl;
        }
    }
    cursos_disponibles->push_back(new_curso);
    cout << "Nuevo curso creado exitosamente" << endl;
    return;
}