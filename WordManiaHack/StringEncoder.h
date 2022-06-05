#pragma once

#include <string>
#include <vector>

#define ALPHABET_SIZE 33

class StringEncoder
{
public:
	const char ConsoleSample[ALPHABET_SIZE] =
	{ -96, -95, -94, -93, -92, -91, -15, -90,
		-89, -88, -87, -86, -85, -84, -83, -82,
		-81, -32, -31, -30, -29, -28, -27, -26,
		-25, -24, -23, -20, -21, -22, -19, -18, -17 };

	const char FstreamSample[ALPHABET_SIZE] =
	{ -32, -31, -30, -29, -28, -27, -72, -26, -25,
		-24, -23, -22, -21, -20, -19, -18, -17, -16,
		-15, -14, -13, -12, -11, -10, -9, -8, -7, -4,
		-5, -6, -3, -2, -1 };

	std::string encodeString(std::string& S, const char Sample[]);
};

