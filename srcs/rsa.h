#include <NTL/ZZ.h>
#include "primes.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace NTL;

class RSA
{
private:
	ZZ d;

public:
	ZZ n, e;
	long numBits;
	long numTests;

	RSA(const long numBits, const long numTests);
	void genKey();
	ZZ encrypt(ZZ plainText, const ZZ &n, const ZZ &e);
	ZZ decrypt(ZZ ciperText);
	void writeKeyToFile(string fileName);
	void printKeys();
};