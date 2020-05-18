#include <iostream>
#include <memory>
#include <type_traits>
#include <sstream>
#include <iomanip>

#include "IsoMessage.h"

IsoMessage::IsoMessage(std::string header, int mti, int mtiVersion)
    :_header(header), _mti(mti), _mtiVersion(mtiVersion)
{ /* */ }

void IsoMessage::setMti(int mti)
{
    _mti = mti;
}

void IsoMessage::generateIsoMessage(std::string& hexMessage) const
{
    auto ToHex = [](const std::string& s) -> std::string {
            std::ostringstream ret;
            for (std::string::size_type i = 0; i < s.length(); ++i)
                ret << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << (int)s[i];
            return ret.str();
    };

    hexMessage.clear();
    hexMessage += std::to_string( _mtiVersion );
    hexMessage += std::to_string( _mti );

    hexMessage = ToHex(hexMessage);
    hexMessage.insert(0, _header);

    for (auto item : _bitmap )
    {
        hexMessage += item.toHex();

        if (!item.get(1))
            break;
    }
}

void IsoMessage::parseIsoMessage(const std::string& hexMessage)
{

}

void IsoMessage::setField(int index, int field)
{
    std::shared_ptr<IsoMessageField<int, 255> > isoField(new IsoMessageField<int, 255>(field, "Stan"));

    _fields.insert( std::pair<int, std::shared_ptr<IsoMessageFieldBase> >(index, isoField) );

    _bitmap[ index / 64 ].set(index % 64);

}
