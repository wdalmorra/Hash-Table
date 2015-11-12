#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "Elemento.h"
#include "TableHash.h"
#include <sys/time.h>

using namespace std;

// Metodo do Vacaria para pegar o tempo (não é padrao!)
/*struct timeval start, stop;
unsigned diffsec, diffusec;

struct nodo_fibo {
	int counterEsq, counterDir;
	unsigned long int n;
};
void time_log_start() {
	gettimeofday(&start, NULL);
}
void compute_time_and_flush() {
	diffsec = stop.tv_sec - start.tv_sec;
	diffusec = (stop.tv_usec - start.tv_usec) >= 0 ? (stop.tv_usec - start.tv_usec) : 1000000 - stop.tv_usec;
	std::cout<< diffusec/1000 << endl;
}
void time_log_stop() {
	gettimeofday(&stop, NULL);
	compute_time_and_flush();
}*/


int main (){

	int i;
	TableHash *tabela;
	tabela = new TableHash();
	//time_log_start();
	clock_t inicio = clock();
	int cont = 0;
	int key,data;
	for(i = 0 ; i < 30000000 ; i++)
	{
		if ((i%100000 == 0 && i != 0) || i == 29999999)
		{
			//time_log_stop();
			//time_log_start();
			clock_t fim = clock() - inicio;
			cout<< ((double)fim / CLOCKS_PER_SEC) * 1000 << endl;
			inicio = clock();
			cont++;
		}

		key = rand();
		data = rand();
		Elemento elem(key,data);
		tabela = tabela->addElemento(elem);
	}
	cout << "Numero de conflitos: " << tabela->getConflitos() << "\n";
	//tabela->print();
	return 0;
}
