#ifndef ISOMESSAGEFIELDBASE_H
#define ISOMESSAGEFIELDBASE_H

#include <string>
#include <functional>

using std::string;
using std::function;

class IsoMessageFieldBase
{
    public:
        IsoMessageFieldBase();
        IsoMessageFieldBase(std::string sName);

        inline std::string getName() const { return _fieldSpecialName; };

        virtual string getField() = 0;

        virtual ~IsoMessageFieldBase();

    protected:
        const std::string _fieldSpecialName;
        function<string(string)> _formatter;

};

#endif // ISOMESSAGEFIELDBASE_H
