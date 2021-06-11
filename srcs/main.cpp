#include "rsa.h"

void AliceToBob(RSA &rsaAlice, RSA &rsaBob)
{
	auto plainText = conv<ZZ>("123456789");
	cout << "Alice's message: " << plainText << endl
	     << endl;

	auto cipherText = rsaAlice.encrypt(plainText, rsaBob.n, rsaBob.e);

	cout << "Alice's enscrypted message using Bob pubkey: " << cipherText << endl
	     << endl;

	auto deCryptText = rsaBob.decrypt(cipherText);

	cout << "Bob's received decrypted message: " << deCryptText << endl
	     << endl;
};

void BobToAlice(RSA &rsaAlice, RSA &rsaBob)
{
	auto plainText = conv<ZZ>("987654321");
	cout << "Bob's message: " << plainText << endl
	     << endl;

	auto cipherText = rsaBob.encrypt(plainText, rsaAlice.n, rsaAlice.e);

	cout << "Bob's enscrypted message using Alice pubkey: " << cipherText << endl
	     << endl;

	auto deCryptText = rsaAlice.decrypt(cipherText);

	cout << "Alice's received decrypted message: " << deCryptText << endl
	     << endl;
};

int main()
{
	RSA rsaAlice(1024, 100);
	rsaAlice.genKey();
	rsaAlice.writeKeyToFile("alice");
	// rsaAlice.printKeys();

	RSA rsaBob(2048, 100);
	rsaBob.genKey();
	rsaBob.writeKeyToFile("bob");
	// rsaBob.printKeys();

	AliceToBob(rsaAlice, rsaBob);
	BobToAlice(rsaAlice, rsaBob);
}