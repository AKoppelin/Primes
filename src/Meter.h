#ifndef _METER_H
#define _METER_H

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <fstream>
#include <vector>
#include <math.h>
#include "Cycles.h"
#include "Stopwatch.h"

using namespace std;

class Meter{

private:
	Stopwatch watch;
	Cycles cycle;
	unsigned int argument, repetitions;
	vector<uint64_t> data;
	uint64_t min, max, mean, sum;
	double dev, sd, dsum;  /// deviation, standard deviation, sum of deviations
	bool fileExists(string filename);
	void writeHeadlineToFile(string filename, string unit);

public:
	/// Constructor
	Meter();

	/// Destructor
	~Meter();

	/// Methods
	void saveDataToFile(string filename, string unit);

	template<typename T, typename ...PAR>
	void measureTime(unsigned int n, unsigned int repetitions, string label, T (*pFunc)(PAR...), PAR... arg) {
        this->repetitions = repetitions;
        this->argument = n;
        // run the tests using the committed function
        // (added three repetitions and discarded the first three because the written files usually showed
        // much higher values for the first three repetitions)
        for (unsigned int i = 0; i < repetitions + 3; i++) {
            watch.start();
            pFunc(arg...); // call the committed function passing the committed argument
            watch.stop();
            if(i > 2) data.push_back(watch.getValue());
            watch.reset();
        }
        // statistics
        min = max = data[0];
        sum = 0;

        for (unsigned int i = 0; i < repetitions; i++) {
            if (data[i] < min) min = data[i];
            if (data[i] > max) max = data[i];
            sum += data[i];
        }
        mean = sum / repetitions;

        dsum = 0;

        for (unsigned int i = 0; i < repetitions; i++){
            dev = mean - (double) data[i];
            dsum += (dev * dev);
        }
        sd = sqrt((double)dsum / (repetitions - 1));

        string filename = "TimeMeasurements_" + label + ".dat";
        saveDataToFile(filename, "us");
    }

    template<typename T, typename ...PAR>
    void measureCycles(unsigned int n, unsigned int repetitions, string label, T (*pFunc)(PAR...), PAR... arg) {
    	this->repetitions = repetitions;
    	this->argument = n;
        // run the tests using the committed function
        // (added three repetitions and discarded the first three because the written files usually showed
        // much higher values for the first three repetitions)
        for (unsigned int i = 0; i < repetitions + 3; i++) {
            cycle.start();
            pFunc(arg...); // call the committed function with the committed argument
            cycle.stop();
            if(i > 2) data.push_back(cycle.getValue());
            cycle.reset();
        }
        // statistics
        min = max = data[0];
        sum = 0;

        for (unsigned int i = 0; i < repetitions; i++) {
            if (data[i] < min) min = data[i];
            if (data[i] > max) max = data[i];
            sum += data[i];
        }
        mean = sum / repetitions;

        for (unsigned int i = 0; i < repetitions; i++){
            dev = mean - (double)data[i];
            dsum += (dev * dev);
        }
        sd = sqrt((double)dsum / (repetitions - 1));

        string filename = "CycleMeasurements_" + label + ".dat";
        saveDataToFile(filename, "cycles");
    }
};

#endif
