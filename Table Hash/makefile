tableHash: Elemento.o TableHash.o tableHash.o
	g++ -o tableHash Elemento.o TableHash.o tableHash.o

Elemento.o: Elemento.cpp Elemento.h
	g++ -c Elemento.cpp

TableHash.o: TableHash.cpp TableHash.h
	g++ -c TableHash.cpp
	
tableHash.o: tableHash.cpp TableHash.h Elemento.h
	g++ -c tableHash.cpp
	
clean:
	rm *.o tableHash
