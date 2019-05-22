
REGS.o: REGS.cpp REGS.h
	g++ REGS.cpp -c

ULA.o: ULA.cpp ULA.h
	g++ ULA.cpp -c

PC.o: PC.cpp PC.h
	g++ PC.cpp -c

MEM.o: MEM.cpp MEM.hpp
	g++ MEM.cpp -c

main.o: PO_PC.cpp
	g++ PO_PC.cpp MEM.o PC.o ULA.o REGS.o -o main

all: REGS.o ULA.o PC.o MEM.o main.o


clear:
	rm *.o
	rm main
