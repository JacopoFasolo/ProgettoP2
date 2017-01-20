#include "campo.h"

Campo::Campo(int n): numero(n)
{
	if(n>numCampi)
		numero=numCampi;
	if(numero==0)
		++numero;
}

int Campo::numCampi=12;	

int Campo::getNumero() const {return numero;}

void Campo::setNumero(int n){numero=n;}

int Campo::getNumCampi() {return numCampi;}

bool Campo::operator<(const Campo& c) const {return numero<c.numero;}

bool Campo::operator>(const Campo& c) const {return numero>c.numero;}

bool Campo::operator==(const Campo& c) const {return numero==c.numero;}