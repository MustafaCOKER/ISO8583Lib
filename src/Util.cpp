#include <sstream>
#include <iomanip>

#include "Util.h"

std::string Util::uchar2hex(unsigned char inchar)
{
    std::ostringstream oss (std::ostringstream::out);
    oss << std::setw(2) << std::setfill('0') << std::hex << (int)(inchar);

    return oss.str();
}
