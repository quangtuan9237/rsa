#include "rsa.h"
#define _TIME int starts, finishs;
#define STARTS_TIME starts = clock();
#define FINISHS_TIME       \
	finishs = clock(); \
	cout << (double)(finishs - starts) / CLOCKS_PER_SEC << endl;
_TIME

int main()
{
	while (true)
	{
		STARTS_TIME
		RSA rsaAlice(500, 100);
		rsaAlice.genKey();
		FINISHS_TIME
	}
	return 0;
}