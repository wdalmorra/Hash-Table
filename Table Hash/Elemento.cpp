#include "Elemento.h"


Elemento::Elemento(int chave = 0, int dado = 0)
{
	this->chave = chave;
	this->dado = dado;
}

int Elemento::getDado()
{
return dado;
}

void Elemento::setDado( int x )
{
	dado = x;
}	
int Elemento::getChave()
{
	return chave;
}
void Elemento::setChave( int c )
{
	chave = c;
}
