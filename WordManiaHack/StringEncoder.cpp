#include "StringEncoder.h"



void StringEncoder::encodeString(std::string& S, const char Sample[])
{
    for (auto& stringToken : S)
    {
        for (char j = 0; j != ALPHABET_SIZE; j++)
        {
            if (stringToken == Sample[j])
            {
                stringToken = j;
                break;
            }
        }
    }
}
