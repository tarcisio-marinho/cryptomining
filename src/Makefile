CC=g++
OUTPUT=main
RM=rm
VERSION=-std=c++11

main: main.o 
	$(CC) main.o -o $(OUTPUT) $(VERSION)

main.o: main.cpp 
	$(CC) -c main.cpp -o main.o $(VERSION)

clean:
	$(RM) *.o $(OUTPUT)

run:
	./$(OUTPUT)