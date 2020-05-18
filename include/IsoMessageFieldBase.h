#ifndef ISOMESSAGEFIELDBASE_H
#define ISOMESSAGEFIELDBASE_H

#include <string>

class IsoMessageFieldBase
{
    public:
        IsoMessageFieldBase();
        IsoMessageFieldBase(std::string sName);

        virtual const std::string getName() const = 0;

        virtual ~IsoMessageFieldBase();

    protected:
        const std::string _fieldSpecialName;
};

#endif // ISOMESSAGEFIELDBASE_H
