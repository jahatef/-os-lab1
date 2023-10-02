LDFLAGS=-pthread
all: simulation

simulation:
	gcc simulation.c -o simulation
	

