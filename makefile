E1:
	g++ Ej1/Ej1.cpp Ej1/momento.cpp -o e1.exe
	valgrind ./e1.exe
	rm e1.exe

E2:
	g++ Ej2/Ej2.cpp Ej2/menu.cpp Ej2/Clase.cpp Ej2/Alumno.cpp -o e2.exe
	valgrind ./e2.exe
	rm e2.exe

E3:
	g++ Ej3/Ej3.cpp Ej3/entero.cpp Ej3/real.cpp Ej3/nums.cpp Ej3/complejo.cpp -o e3.exe
	valgrind ./e3.exe
	rm e3.exe
E4:
	g++ Ej4/ej4.cpp Ej4/CuentaBase.cpp Ej4/CajaAhorro.cpp Ej4/CuentaCorriente.cpp -o E4.exe
	valgrind ./E4.exe
	rm E4.exe