#include "IsoMessageFieldBase.h"

IsoMessageFieldBase::IsoMessageFieldBase()
    : _fieldSpecialName(""), _formatter( {} )
{ /* */ }

IsoMessageFieldBase::IsoMessageFieldBase(std::string sName)
    : _fieldSpecialName(sName), _formatter( {} )
{ /* */ }

IsoMessageFieldBase::~IsoMessageFieldBase()
{ /* */ }
