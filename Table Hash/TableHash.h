#ifndef TABLEHASH_H_
#define TABLEHASH_H_

#include <iostream>
#include "Elemento.h"
class TableHash
{
	int tamHash;
	Elemento *tableHash;
	int *flagHash;
	int conflitos;
	int numElementos;
	static const float fatorCarga = 0.9;
	int hash( int chave );
	TableHash* duplicaTable();

public:

	TableHash(int tam = 10);
	TableHash* addElemento (Elemento el);
	int getConflitos();
	void print();
};

#endif
