#include <NTL/ZZ.h>

using namespace NTL;

bool isEven(const ZZ &n)
{
	// n&1 is 1, then odd, else even
	return ((n & 1) == 0);
}

ZZ powerMod(ZZ x, ZZ y, ZZ p)
{
	ZZ res = conv<ZZ>(1);

	x = x % p; // Update x if it is more than or
		   // equal to p

	if (x == 0)
		return conv<ZZ>(0); // In case x is divisible by p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (!isEven(y))
		{
			res = (res * x) % p;
		}

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

//Euclidean expansion algorithm
ZZ Exgcd(ZZ m, ZZ n, ZZ &x)
{
	ZZ x1, y1, x0, y0, y;
	x0 = 1;
	y0 = 0;
	x1 = 0;
	y1 = 1;
	x = 0;
	y = 1;
	ZZ r = m % n;
	ZZ q = (m - r) / n;

	while (r != 0)
	{
		x = x0 - q * x1;
		y = y0 - q * y1;
		x0 = x1;
		y0 = y1;
		x1 = x;
		y1 = y;
		m = n;
		n = r;
		r = m % n;
		q = (m - r) / n;
	}
	return n;
}
