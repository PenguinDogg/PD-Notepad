#include "format.h"
#include <cstdlib>

Format::Format()
{
    bold = false;
    italics = false;
    underlined = false;
}

Format::~Format(){

}

bool Format::isBold(){ return bold; }
bool Format::isUnderlined(){ return underlined; }
bool Format::isItalics(){ return italics; }

void Format::setBold(bool _bold){ bold = _bold; }
