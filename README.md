# Homework 2 - Luca Camiscia

## Tabla de Contenidos
1. [Ejercicio 1](#ejercicio-1)
2. [Ejercicio 2](#ejercicio-2)
3. [Ejercicio 3](#ejercicio-3)
4. [Ejercicio 4](#ejercicio-4)

---

## Ejercicio 1

### Descripción
Este ejercicio implementa la clase `momento`, que representa un momento del día en formato de 12 horas (a.m./p.m.). La clase permite realizar diversas operaciones, como:
- Crear instancias de momentos.
- Imprimir datos en diferentes formatos.
- Modificar atributos como hora, minutos, segundos y el indicador de tiempo (a.m./p.m.).
- Validar datos ingresados por el usuario y manejar posibles errores.

### Archivos
- **Ej1.cpp**: Programa principal que incluye ejemplos de uso de la clase `momento`.
- **Ej1.hpp**: Archivo de encabezado con las definiciones de las funciones de la clase `momento`.
- **momento.cpp**: Implementación de las funciones de la clase `momento`.

---

## Ejercicio 2

### Descripción
Este ejercicio desarrolla un sistema de gestión de alumnos y clases, implementados como objetos. La relación entre los objetos es de "Agregación", ya que:
- Un curso puede existir sin alumnos inscritos.
- Un alumno puede no estar inscrito en ningún curso.

Tipo de Copia -> DEEP COPY

Cuando se hace un copia del curso se realiza una deep copy al solicitar nuevo espacio de memoria para almacenar en un nuevo vector perteniecente al nuevo curso los esutidiantes. Quiero que ambos vectores sean independientes ya que por mas que cree una copia de alumnos de un curso distinto, quiero poder inscribir alumnos a uno sin escribirlo a otro. A continuacion se muestra un ejemplo donde se intenta hacer una copia de un Curso con 2 estudiantes:

Quiero crear una copia de:
CursoBase -> (&Maria, &Carla)

Uso la funcion copy y ahora tengo
CursoNuevo ->(&Maria, &Carla)

Ahora tengo dos cursos distintos con vectores distintos pero con el mismo contenido. Se considera
deep copy ya que es una copia profunda donde copio cada alemento dentro de Curso. Por mas que los punteros sean los mismos, dentro de la memoria se encuentran almacenados dos veces. En este ejemplo tengo un total de 4 punteros (2 a Maria y 2 a Carla). Esto tambien se ve reflejado cuando analizamos el estado de memoria antes y despues de crear una copia. Si tenemos un cursoBase que ocupa N y creo una copia, la copia tambien ocupa N. Uno podria interpretar que cuando llamo al metodo .Create_Copy() se realiza una copia superficial pero como esto es tan solo pero como lo que se esta analizando es la copia del Curso como un Todo y se crea un vector nuevo en lugar de referenciar al otro podemos afirmar que el tipo de copia es Deep. 


El sistema incluye funcionalidades como:
- Inscripción y desinscripción de alumnos.
- Gestión de cursos llenos.
- Actualización de cursos completados por los alumnos.

### Archivos
1. **Alumno.cpp**: Implementación de la clase `Alumno`, que gestiona la información de los estudiantes.
2. **Clase.cpp**: Implementación de la clase `Clase`, que representa un curso o materia.
3. **Ej2.cpp**: Archivo principal que inicializa y ejecuta la lógica del sistema. Incluye un estado inicial con cursos y alumnos predefinidos.
4. **Ej2.hpp**: Archivo de encabezado que declara las clases y funciones utilizadas.
5. **menu.cpp**: Implementación del menú de usuario para interactuar con el programa.
6. **makefile**: Archivo de configuración para compilar el proyecto con `make`.

---

## Ejercicio 3

### Descripción
Este ejercicio implementa un sistema de números que incluye las clases `complejo`, `entero` y `real`. Cada clase hereda de una clase base `Numero`. Los métodos de los objetos modifican sus valores directamente y no devuelven resultados.

### Archivos
- **complejo.cpp**: Implementación de la clase `complejo`.
- **entero.cpp**: Implementación de la clase `entero`.
- **real.cpp**: Implementación de la clase `real`.
- **ej3.hpp**: Archivo de encabezado con las definiciones de todas las clases.
- **ej3.cpp**: Archivo principal que realiza pruebas para verificar el funcionamiento de las clases.
- **makefile**: Archivo de configuración para compilar el proyecto con `make`.

---

## Ejercicio 4

### Descripción

En el ejercicio se define una clase Abstracta CuentaBase de la cual derivan CajaAhorro y CuentaCorriente. CuentaAhorro puede ingresar y retirar dinero. CuentaCorriente es como cuentaAhorro pero ademas contiene CajadeAhorro la cual tiene metodos aparte para ingresar y retirar dinero. Cuando se intenta retirar dinero de una CuentaCorriente, de no tener suficiente intenta retirar de la CajaAhorroAsociada

El programa incluye ejemplos para verificar el correcto funcionamiento del sistema.

### Archivos
- **CajaAhorro.cpp**: Implementación de la clase `CajaAhorro`.
- **CuentaBase.cpp**: Implementación de la clase abstracta `CuentaBase`.
- **CuentaCorriente.cpp**: Implementación de la clase `CuentaCorriente`.
- **ej4.hpp**: Archivo de encabezado con las definiciones de las clases.
- **ej4.cpp**: Archivo principal que crea e imprime ejemplos del sistema.

---

