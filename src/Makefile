CC=g++
RM=rm
VERSION=-std=c++11

main: server.o client.o communication.o rsa.o
	$(CC) server.o -o server $(VERSION)
	$(CC) client.o -o client $(VERSION)

server.o: server.cpp
	$(CC) -c server.cpp -o server.o $(VERSION)

client.o: client.cpp
	$(CC) -c client.cpp -o client.o $(VERSION)

communication.o: communication.cpp communication.h
	$(CC) -c communication.cpp -o communication.o $(VERSION)

rsa.o: rsa.cpp rsa.h
	$(CC) -c rsa.cpp -o rsa.o $(VERSION)

clean:
	$(RM) *.o $(OUTPUT)
