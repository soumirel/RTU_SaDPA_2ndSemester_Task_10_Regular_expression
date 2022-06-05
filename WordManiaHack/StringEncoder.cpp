#include "StringEncoder.h"



std::string StringEncoder::encodeString(std::string& S, const char Sample[])
{
    std::string result = "";

    for (auto& stringToken : S)
    {
        for (char j = 0; j != ALPHABET_SIZE; j++)
        {
            if (stringToken == Sample[j])
            {
                result += j;
                break;
            }
        }
    }

    return result;
}
