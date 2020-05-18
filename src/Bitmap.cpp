#include <sstream>
#include <iostream>
#include <iomanip>

#include "Bitmap.h"
#include "Util.h"

Bitmap::Bitmap()
{
    this->clear();
}

void Bitmap::clear(void)
{
    for (auto &item : this->_bitmap)
        item = 0x00;
}

void Bitmap::printBits() const
{
    std::stringstream ss;
    int i = 0;

    for (auto item : _bitmap ) {
        ss << std::hex << std::uppercase << (int) item;
    }

    std::cout << i++ << " " << ss.str() << std::endl;
}

void Bitmap::set(int index)
{
    _bitmap[index/8] |= (0x01 << ( 8 - index%8 ) );
}

bool Bitmap::get(int index) const
{
    return _bitmap[index/8] & (0x01 << ( 8- index%8 ) );
}

void Bitmap::flip(int index)
{
    _bitmap[index/8] ^= (0x01 << index%8);
}

std::string Bitmap::toHex(void) const
{
    std::stringstream ss;
    int i = 0;

    for (auto item : _bitmap )
        ss << Util::uchar2hex( item );

    return ss.str();
}

Bitmap::~Bitmap()
{
    //dtor
}
