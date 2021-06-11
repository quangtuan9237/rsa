#include <NTL/ZZ.h>

using namespace NTL;

bool isEven(const ZZ &n);
ZZ Exgcd(ZZ m, ZZ n, ZZ &x);
ZZ powerMod(ZZ x, ZZ y, ZZ p);