#include <chrono>
#include <cstdint>
#include <iostream>

using namespace std;

class Stopwatch {
private:
	std::chrono::time_point<std::chrono::system_clock> tp1, tp2;
//	std::chrono::duration<uint64_t, std::microseconds> duration;
    std::chrono::duration<uint64_t,std::ratio<1,1000000> > duration;
public:
	/// Constructor
	Stopwatch();

	/// Destructor
	~Stopwatch();

	/// Methods
	void start();
	void stop();
	void peek();
	void reset();
	uint64_t getValue();
};
