#include <math.h>

#include "CompareCoordinates.h"

bool
CompareCoordinates::operator()(const std::array<double, 3> a, const std::array<double, 3> b)
{
	double rA = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	double rB = sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
	if (rA < rB) {
		return true;
	} else if (rA > rB) {
		return false;
	} else if (a[0] > b[0]) {
		return true;
	} else if (a[0] < b[0]) {
		return false;
	} else if (a[1] > b[1]) {
		return true;
	}
	return false;
}
