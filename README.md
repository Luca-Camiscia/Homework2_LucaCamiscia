# Homework 2 – Luca Camiscia

## Tabla de Contenidos
1. [Ejercicio 1](#ejercicio-1)
2. [Ejercicio 2](#ejercicio-2)
3. [Ejercicio 3](#ejercicio-3)
4. [Ejercicio 4](#ejercicio-4)
5. [Compilación y Ejecución](#compilación-y-ejecución)

---

## Ejercicio 1

### Descripción

Este ejercicio consiste en la implementación de la clase `Momento`, la cual representa un instante del día utilizando el formato de 12 horas con indicación a.m./p.m. La clase permite realizar operaciones como:

- Creación de instancias de momento.
- Impresión de datos en distintos formatos.
- Modificación de atributos individuales (hora, minutos, segundos, indicador a.m./p.m.).
- Validación de datos ingresados por el usuario y manejo de errores.

### Archivos

- **Ej1.cpp**: Programa principal con ejemplos de uso de la clase `Momento`.
- **Ej1.hpp**: Archivo de encabezado con las definiciones de la clase.
- **momento.cpp**: Implementación de los métodos de la clase `Momento`.

---

## Ejercicio 2

### Descripción

Este ejercicio desarrolla un sistema de gestión de alumnos y clases, modelado mediante objetos. La relación entre los objetos es de tipo **Agregación**, ya que un curso puede existir sin alumnos y un alumno puede no estar inscrito en ningún curso.

Una de las consignas centrales del ejercicio es la correcta implementación de **deep copy** al copiar un curso. Esto significa que, al duplicar un curso, se crea un nuevo vector dinámico que contiene punteros a los mismos alumnos, pero en estructuras de memoria independientes. De esta manera, ambos cursos pueden modificarse sin afectar al otro.

**Ejemplo:**

- CursoBase: → (&María, &Carla)  
- CursoCopia (tras deep copy): → (&María, &Carla)

Ambos cursos contienen punteros a los mismos objetos, pero almacenados en vectores distintos. Por lo tanto, el curso copiado es una réplica estructural completa, cumpliendo con los requisitos de una copia profunda.

El sistema permite:

- Inscripción y desinscripción de alumnos en cursos.
- Gestión de cupos en cursos.
- Actualización del historial de materias completadas por los alumnos.

### Archivos

1. **Alumno.cpp**: Implementación de la clase `Alumno`.
2. **Clase.cpp**: Implementación de la clase `Clase`.
3. **Ej2.cpp**: Archivo principal que inicializa y ejecuta la lógica del sistema, con instancias predefinidas.
4. **Ej2.hpp**: Definiciones de clases y funciones.
5. **menu.cpp**: Implementación de un menú interactivo para el usuario.
6. **makefile**: Script para la compilación del programa mediante `make`.

---

## Ejercicio 3

### Descripción

Este ejercicio introduce una jerarquía de clases para modelar diferentes tipos de números: `Entero`, `Real` y `Complejo`. Todas las clases derivan de una clase base abstracta `Numero`. Cada objeto opera sobre sus propios datos sin devolver valores, siguiendo un enfoque orientado a objetos.

### Archivos

- **complejo.cpp**: Implementación de la clase `Complejo`.
- **entero.cpp**: Implementación de la clase `Entero`.
- **real.cpp**: Implementación de la clase `Real`.
- **ej3.hpp**: Definiciones de todas las clases utilizadas.
- **ej3.cpp**: Archivo de pruebas para validar el funcionamiento del sistema.
- **makefile**: Script de compilación.

---

## Ejercicio 4

### Descripción

Este ejercicio implementa un sistema bancario con una clase base abstracta `CuentaBase`, de la cual derivan `CajaAhorro` y `CuentaCorriente`.

- `CajaAhorro` hereda de `CuentaBase` permite realizar operaciones básicas de depósito y extracción.
- `CuentaCorriente` hereda de `CuentaBase` y asocia internamente una `CajaAhorro`. Si no dispone de fondos suficientes para un retiro, intenta completar la transacción utilizando el saldo disponible en su `CajaAhorro`.

El diseño permite demostrar el uso de herencia, composición y comportamiento polimórfico.

### Archivos

- **CajaAhorro.cpp**: Implementación de la clase `CajaAhorro`.
- **CuentaBase.cpp**: Implementación de la clase abstracta `CuentaBase`.
- **CuentaCorriente.cpp**: Implementación de la clase `CuentaCorriente`.
- **ej4.hpp**: Definiciones de las clases utilizadas.
- **ej4.cpp**: Ejecución de casos de prueba.

---

## Compilación y Ejecución

Para compilar y ejecutar cada ejercicio, utilizar el comando `make` correspondiente dentro del directorio del proyecto. Por ejemplo:

```bash
# Compilar y ejecutar Ejercicio 1
make E1
# Compilar y ejecutar Ejercicio 2
make E2
# Compilar y ejecutar Ejercicio 3
make Ej3
# Compilar y ejecutar Ejercicio 4
make E4