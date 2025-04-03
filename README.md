# Homework2_LucaCamiscia
## Tabla de Contenidos
1. [Ejercicio 1](#ejercicio-1)
2. [Ejercicio 2](#ejercicio-2)
3. [Ejercicio 3](#ejercicio-3)
4. [Ejercicio 4](#ejercicio-4)

## Ejercicio 1
### Archivos
- Ej1.cpp 
Este programa implementa la clase llamada `momento` que representa un momento del día en formato de 12 horas (a.m./p.m.) y permite realizar diversas operaciones sobre este.

El programa incluye ejemplos de uso de la clase `momento`, como la creación de instancias, la impresión de datos en diferentes formatos y la modificación de atributos como hora, minutos, segundos y el indicador de tiempo (a.m./p.m.). Además, permite al usuario ingresar un momento personalizado y valida los datos ingresados, manejando posibles errores.

-Ej1.hpp 
Header con definiciones de funciones de la clase momento
-momento.cpp
Contiene las funciones de el objeto momento.

## Ejercicio 2
Este ejercicio implementa un sistema de gestión de alumnos y clases siendo ambos objetos. Se puede afirmar que la relacion entre los objetos es de "Agregacion" ya que tal como en el ejemplo de la diaposiva 5 del sexto ppt, el "todo" (en este caso el curso) mantiene una relacion con las partes (alumnos) sin una dependencia total al sus ciclos de vida no depender del otro. Puedo tener un alumno que no este inscripto en ningun curso de la misma manera que puedo tener un curso vacio.  
### Archivos

1. Alumno.cpp

Este archivo define la implementación de la clase Alumno, que representa a un estudiante. Incluye métodos para gestionar la información del alumno y sus interacciones con las clases. 

2. Clase.cpp

Contiene la implementación de la clase Clase, que representa un curso o materia. Gestiona la inscripción de alumnos y otras funcionalidades relacionadas. 

3. Ej2.cpp

Archivo principal del programa, donde se inicializa y ejecuta la lógica del sistema. Contiene la función main y la interacción con los usuarios. Se ejecuta un estado inicial con varios cursos y alumnos ya inscriptos. El curso general comienza ya con 20 integrante para probar ya un curso lleno. A la hora de Desinscribir a un Alumno, de seleccionarse la opcion de que termino el curso se le podra modificar dentro del objeto Alumno para sumarle a sus cursos_completados el curso el cual termino.

4. Ej2.hpp

Encabezado que declara las clases y funciones utilizadas en Ej2.cpp y de los objetos Alumno y Curso.

5. menu.cpp

Implementa la funcionalidad del menú de usuario, permitiendo la navegación y selección de opciones en el programa.

6. makefile

Archivo de configuración para compilar el proyecto con make. Define las reglas de compilación y dependencias de los archivos fuente.


## Ejercicio 3
### Consigna
Descripción del ejercicio 3.

### Archivos
Lista de archivos relacionados con el ejercicio 3.

### Implementación
Explicación de la implementación del ejercicio 3.

## Ejercicio 4
### Consigna
Descripción del ejercicio 4.

### Archivos
Lista de archivos relacionados con el ejercicio 4.

### Implementación
Explicación de la implementación del ejercicio 4.
