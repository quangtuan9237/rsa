#include "rsa.h"

RSA::RSA(const long numBits, const long numTests)
{
	this->numBits = numBits;
	this->numTests = numTests;
}

void RSA::genKey()
{
	ZZ p = genPrime(this->numBits, this->numTests);
	ZZ q = genPrime(this->numBits, this->numTests);

	this->n = p * q;
	ZZ phi = (p - 1) * (q - 1);
	ZZ k;

	do
	{
		RandomBnd(this->e, phi);

		k = Exgcd(this->e, phi, this->d);
	} while (!(k == 1 && this->d > 0));
}

ZZ RSA::encrypt(ZZ plainText, const ZZ &n, const ZZ &e)
{
	return powerMod(plainText, e, n);
}

ZZ RSA::decrypt(ZZ ciperText)
{
	return powerMod(ciperText, this->d, this->n);
}

void RSA::writeKeyToFile(string fileName)
{
	ofstream myfile;
	myfile.open(fileName);
	myfile << this->n << "\n";
	myfile << this->d;
	myfile.close();

	myfile.open(fileName + ".pub");
	myfile << this->n << "\n";
	myfile << this->e;
	myfile.close();
}

void RSA::printKeys()
{
	cout << "n: " << this->n << endl;
	cout << "d: " << this->d << endl;
	cout << "e: " << this->e << endl;
}