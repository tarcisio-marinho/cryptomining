CC=g++
RM=rm
VERSION=-std=c++11
THREAD=-pthread
OUTPUT= cryptominer


main: client.o error.o tasks.o utils.o base64.o
	$(CC) client.o utils.o error.o tasks.o base64.o -o $(OUTPUT) $(VERSION) $(THREAD)

client.o: client.cpp
	$(CC) -c client.cpp -o client.o $(VERSION)

error.o: error.cpp error.h
	$(CC) -c error.cpp -o error.o $(VERSION)

tasks.o: tasks.cpp tasks.h
	$(CC) -c tasks.cpp -o tasks.o $(VERSION) $(THREAD)

utils.o: utils.cpp utils.h
	$(CC) -c utils.cpp -o utils.o $(VERSION)

base64.o: base64.cpp base64.h
	$(CC) -c base64.cpp -o base64.o

clean:
	$(RM) *.o 
