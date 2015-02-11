#include "Meter.h"

Meter::Meter() {}

Meter::~Meter() {}

/// This function writes the measured data to an output file
void Meter::saveDataToFile(string filename, string unit) {
	fstream fs;
	if (!fileExists(filename)) {
		writeHeadlineToFile(filename, unit);
	}
	fs.open(filename, ios::app);
	if (fs != NULL) {
//		if (argument < 10) fs << " ";
		fs << argument << setw(22) << min << setw(23) << max << setw(23) << mean << setw(23) << sd << setw(15);
		for (unsigned int i = 0; i < repetitions; i++) {
			fs << data[i] << "\t";
		}
		fs << endl;
	}else{
        cout << "Datei '" << filename << "' konnte nicht geöffnet werden (Daten schreiben)." << endl;
	}
	fs.close();
	data.clear();
}

// This function checks if a file with the given name exists by trying to open it
bool Meter::fileExists(string filename) {
	fstream fs;
	fs.open(filename, ios::in);
	if (fs != NULL) {
		fs.close();
		return true;
	}
	fs.close();
	return false;
}

void Meter::writeHeadlineToFile(string filename, string unit) {
	fstream fs;
	fs.open(filename, ios::app);
	if (fs != NULL) {
		fs << "n" << setw(20) << "min [" << unit.c_str() << "]"
			<< setw(20) << "max [" << unit.c_str() << "]"
			<< setw(20) << "mean [" << unit.c_str() << "]"
			<< setw(20) << "sd [" << unit.c_str() << "]"
			<< setw(20) << "measurements [" << unit.c_str() << "]" << endl;
	}else{
        cout << "Datei '" << filename << "' konnte nicht geöffnet werden (Überschrift schreiben)." << endl;
	}
}
