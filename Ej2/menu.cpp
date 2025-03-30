#include "Ej2.hpp"
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
        cout << "- " << alumno->get_name() << endl;
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
        cout << "5. Desinscribir un alumno" << endl;
        cout << "6. Ver información de un alumno" << endl;
        cout << "7. Salir" << endl;

        cout << "Ingrese su opción: ";
        if (cin >> choice && choice >= 1 && choice <= 7) {
            if (choice == 7) {
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

            case 4:
                Crear_Alumno(alumnos_vivos);

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

