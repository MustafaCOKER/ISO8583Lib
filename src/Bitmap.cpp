#include <sstream>
#include <iostream>
#include <iomanip>

#include "Bitmap.h"
#include "Util.h"

#define CHECK_DECREMENT_INDEX                                               \
    if (index < 1 || index > 64)                                            \
        throw std::out_of_range("index number must be under the 64-1");     \
                                                                            \
    --index;

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
    CHECK_DECREMENT_INDEX;

    _bitmap[index/8] |= (0x01 << ( 7 - index%8 ) );
}

void Bitmap::unset(int index)
{
    CHECK_DECREMENT_INDEX;

    _bitmap[index/8] &= ( 0x01 << ( 7 - index%8 )) ^ 0xFF;
}

bool Bitmap::get(int index) const
{
    CHECK_DECREMENT_INDEX;

    return _bitmap[index/8] & (0x01 << ( 7 - index%8 ) );
}

void Bitmap::flip(int index)
{
    CHECK_DECREMENT_INDEX;

    _bitmap[index/8] ^= ( (0x01 << ( 7 - index%8 )));
}

std::string Bitmap::toHex(void) const
{
    std::stringstream ss;
    int i = 0;

    for (auto item : _bitmap )
        ss << Util::uchar2hex( item );

    return ss.str();
}
