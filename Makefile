PROG = prog
CC = g++
CPPFLAGS = -Wall -std=c++11
OBJS = PO_PC_HW.o PC.o ULA.o REGS.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

PO_PC_HW.o:
	$(CC) $(CPPFLAGS) -c PO_PC_HW.cpp

PC.o: PC.h
	$(CC) $(CPPFLAGS) -c PC.cpp

ULA.o: ULA.h
	$(CC) $(CPPFLAGS) -c ULA.cpp

REGS.o: REGS.h
	$(CC) $(CPPFLAGS) -c REGS.cpp

clean:
	rm -f core $(PROG) $(OBJS)