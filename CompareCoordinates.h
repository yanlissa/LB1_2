#pragma once

#include <array>

struct CompareCoordinates {
public:
	bool operator()(const std::array<double, 3> a, const std::array<double, 3> b);
};
