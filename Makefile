run: limpiar grad main

main:
	g++ GradientDescent.o main.cpp -o main

grad:
	g++ GradientDescent.cpp -c

limpiar:
	rm -rf main
	rm -rf *.o