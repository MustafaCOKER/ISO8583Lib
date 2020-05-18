#include <iostream>
#include <cstring>

#include <iostream>
#include <memory>
#include <type_traits>
#include <sstream>
#include <iomanip>
#include <ostream>


#include "IsoMessageField.h"
#include "IsoMessage.h"
#include "Types.h"
#include "Bitmap.h"
#include "Util.h"

void generateEchoResponse(void);

int main()
{
    generateEchoResponse();
    return 0;
}

void generateEchoResponse(void)
{
    IsoMessage echoMessage("6000000000", 810);
    std::string hexMessage;

    echoMessage.setField(11, 123);
    echoMessage.setField(7, 123);
    echoMessage.setField(1, 123);
    echoMessage.setField(70, 123);
    echoMessage.setField(125, 123);

    echoMessage.generateIsoMessage(hexMessage);

    std::cout << "Echo Message : " << hexMessage << std::endl;
}
