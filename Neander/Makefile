all: REGS.o ULA.o PC.o MEM.o main.o

REGS.o: AC.cpp AC.h
	g++ AC.cpp -c

ULA.o: ULA.cpp ULA.h
	g++ ULA.cpp -c

PC.o: PC.cpp PC.h
	g++ PC.cpp -c

MEM.o: MEM.cpp MEM.hpp
	g++ MEM.cpp -c

main.o: PO_PC.cpp
	g++ PO_PC.cpp MEM.o PC.o ULA.o AC.o -o main



exe:
	./main > saida.txt

clean:
	rm *.o
	rm main
	rm saida.txt
