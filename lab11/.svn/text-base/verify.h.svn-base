#ifndef VERIFY_H
#define VERIFY_H

namespace _global_cs225_lab11_verifier
{

const char* getNetid();
unsigned int getSeed();

class Verifier
{
	public:
	Verifier(unsigned int seed);
	bool operator()(int item);

	private:
	int mySeed;
	int i;
};

}
using namespace _global_cs225_lab11_verifier;

#endif
