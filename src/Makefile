CC=g++
RM=rm
VERSION=-std=c++11
THREAD=-pthread

main: server.o client.o communication.o error.o tasks.o
	$(CC) server.o communication.o error.o tasks.o -o server $(VERSION) $(THREAD)
	$(CC) client.o communication.o error.o -o tasks.o client $(VERSION) $(THREAD)

server.o: server.cpp
	$(CC) -c server.cpp -o server.o $(VERSION)

client.o: client.cpp
	$(CC) -c client.cpp -o client.o $(VERSION)

communication.o: communication.cpp communication.h
	$(CC) -c communication.cpp -o communication.o $(VERSION)

error.o: error.cpp error.h
	$(CC) -c error.cpp -o error.o $(VERSION)

tasks.o: tasks.cpp tasks.h
	$(CC) -c tasks.cpp -o tasks.o $(VERSION) $(THREAD)

clean:
	$(RM) *.o 
