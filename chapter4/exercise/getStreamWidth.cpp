#include <ios>
#include "getStreamWidth.h"


std::streamsize getStreamWidth(int n)
{
	std::streamsize ans = 1;
    while (n / 10 != 0)
    {
        ans++;
         n /= 10;
    }
    return ans;
}

std::streamsize getStreamWidth(double n)
{
    std::streamsize ans = 1;
    int tmp = int(n);
    while (tmp / 10 != 0)
    {
        ans++;
        tmp /= 10;
    }
    return ans;
}