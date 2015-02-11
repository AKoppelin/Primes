#ifndef _CYCLES_H
#define CYCLES_H
#include <cstdint>

class Cycles
{
private:
	uint64_t startCycles, stopCycles, duration;
	uint64_t getCycles(unsigned int loword, unsigned int hiword);

public:
	// Constructor
	Cycles();

	// Destructor
	~Cycles();

	// Methods
	void start();
	void stop();
	void peek();
	void reset();
	uint64_t getValue();
};

#endif