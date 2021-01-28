#include "student.h"

Student::Student() : majorLen(10) {
	Personal();
	major = new char[majorLen + 1];
}

Student::Student(char *ssn, char *n, char *c, int y, long s, char *m) : majorLen(11) {
	Personal(ssn, n, c, y, s);
	major = new char[majorLen + 1];
	memcpy(major, m, majorLen);
}

void Student::writeToFile(std::fstream &out) const {
	Personal::writeToFile(out);
	out.write(major, majorLen);
}

void Student::readFromFile(std::fstream &in) {
	Personal::readFromFile(in);
	in.read(major, majorLen);
}

ostream& Student::writeLegibly(std::ostream&out) {
	Personal::writeLegibly(out);
	major[majorLen] = '\0';
	out << ", major = " << major;
	return out;
}

istream& Student::readFromConsole(std::istream&in) {
	Personal::readFromConsole(in);
	char s[80];
	cout << "Major: ";
	in.getline(s, 80);
	memcpy(major, s, 9);
	return in;
}