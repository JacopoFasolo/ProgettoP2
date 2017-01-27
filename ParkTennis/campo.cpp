#include "campo.h"

Campo::Campo(unsigned int n): numero(n){} //conversione im

double Campo::prezzoCampo=5.00;

double Campo::noleggioCampo(){return Campo::prezzoCampo;}

int Campo::getNumero() const {return numero;}

bool Campo::operator<(const Campo& c) const {return numero<c.numero;}

bool Campo::operator>(const Campo& c) const {return numero>c.numero;}

bool Campo::operator==(const Campo& c) const {return numero==c.numero;}

bool Campo::operator!=(const Campo& c) const {return numero!=c.numero;}

Campo& Campo::operator--() {numero--;return *this;}

Campo Campo::operator+(int i) {return Campo(numero+i);}
