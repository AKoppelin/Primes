#include "Cycles.h"


Cycles::Cycles()
{
}


Cycles::~Cycles()
{
}

void Cycles::start() {
	unsigned int lo = 0, hi = 0;
	startCycles = getCycles(lo, hi);
}

void Cycles::stop() {
	unsigned int lo = 0, hi = 0;
	stopCycles = getCycles(lo, hi);
}

void Cycles::peek() {
	duration = stopCycles - startCycles;
}

void Cycles::reset() {
	duration = 0;
}

uint64_t Cycles::getValue() {
	peek();
	return duration;
}

uint64_t Cycles::getCycles(unsigned int cycles_high, unsigned int cycles_low) //function that measures the current CPU-cycles
{
	// asm{
		// cpuid
			// _emit 0x0f // insert rtdsc opcode
			// _emit 0x31
			// mov hiword, edx
			// mov loword, eax
	// }
	asm volatile("CPUID\n\t"
				"RDTSC\n\t"
				"mov %%edx, %0\n\t"
				"mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
	"%rax", "%rbx", "%rcx", "%rdx");
	return ((uint64_t)cycles_high << 32) + cycles_low;
}
