#ifndef CAMPO_H
#define CAMPO_H

//La classe campo rappresenta i campi da tennis in cui si svolgono le ore di tennis.
//Un campo da tennis è contraddistinto da un numero che va da 1 a numCampi.

class Campo
{
private:
	unsigned short int numero;
    static double prezzoCampo;
public:
    Campo(unsigned int n =1);
	int getNumero() const;
    static double noleggioCampo();
	bool operator<(const Campo&) const;
	bool operator>(const Campo&) const;
	bool operator==(const Campo&) const;
    bool operator!=(const Campo&) const;
    Campo operator+(int);
    Campo& operator--();
};

#endif // CAMPO_H
