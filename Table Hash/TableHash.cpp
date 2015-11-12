#include "TableHash.h"
#include "Elemento.h"
#include <stdlib.h>
#include <iostream>
TableHash::TableHash(int tam)
{
	conflitos = 0;
	numElementos = 0;
	tamHash = tam;
	int i;
	flagHash = (int*)malloc(tamHash * sizeof(int));
	for (i = 0 ; i < tamHash ; i++)
	{
		flagHash[i] = 0;
	}
	tableHash = (Elemento*) malloc (tamHash * sizeof(Elemento));
}

int TableHash::hash( int chave )
{
	return chave % tamHash;
}

TableHash* TableHash::addElemento (Elemento el)
{
	int pos = hash(el.getChave());
	int posAux;
	if (pos == tamHash-1)
	{
		posAux = 0;
	}
	else
	{
		posAux = pos+1;
	}
	
	if (flagHash[pos] == 1)
	{
		if (tableHash[pos].getChave() == el.getChave())
		{
			tableHash[pos] = el;
		}
		else
		{
			while (flagHash[posAux] == 1 && tableHash[posAux].getChave() != el.getChave())
			{
				conflitos++;
				if (posAux != tamHash-1)
					posAux++;
				else
					posAux = 0;
			}
			tableHash[posAux] = el;
		}
	}
	else
	{
		tableHash[pos] = el;
		flagHash[pos] = 1;
	}

	numElementos++;

	float fcAtual =  ((float)numElementos) / tamHash;

	if (fcAtual >= fatorCarga)
	{
		return duplicaTable();
	}
	return this;
}

int TableHash::getConflitos()
{
	return conflitos;
}

TableHash* TableHash::duplicaTable()
{
	TableHash *tabela;
	tabela = new TableHash(tamHash*2);
	int j;
	for (j = 0 ; j < tamHash ; j++)
	{
		if (flagHash[j] == 1)
		{
			tabela->addElemento(tableHash[j]);
		}
	}
	free(tableHash);
	return tabela;
	
}
void TableHash::print()
{
	int i;
	std::cout<< "TABELA";
	for (i = 0 ; i < tamHash ; i++)
	{
		if (flagHash[i]==1)
			std::cout<< tableHash[i].getDado() << " ";
	}
	
}