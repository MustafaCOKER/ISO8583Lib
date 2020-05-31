#ifndef ISOMESSAGE_H
#define ISOMESSAGE_H

#include <map>
#include <memory>
#include <bitset>

#include "Types.h"
#include "IsoMessageField.h"
#include "Bitmap.h"

class IsoMessage
{
    public:
        IsoMessage() = default;
        IsoMessage(std::string header, int mti, int mtiVersion = static_cast<int>(Types::IsoTypes::_1987));

        void setMti(int mti);
        void generateIsoMessage(std::string& hexMessage) const;
        void parseIsoMessage(const std::string& hexMessage);

        bool setField(int index, int field);

        virtual ~IsoMessage() = default;

    private:
        std::map<int, std::shared_ptr<IsoMessageFieldBase> > _fields;
        int _mti{0};
        int _mtiVersion {static_cast<int>(Types::IsoTypes::_1987)};
        std::string _header { "" };
        std::array<Bitmap, 3> _bitmap;
};

#endif // ISOMESSAGE_H
