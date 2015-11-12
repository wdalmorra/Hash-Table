#ifndef ELEMENTO_H_
#define ELEMENTO_H_

#include <iostream>

class Elemento
{

	int dado;
	int chave;
	
public:

	Elemento(int chave, int dado);
	int getDado();
	void setDado( int x );
	int getChave();
	void setChave( int c );
};
#endif
