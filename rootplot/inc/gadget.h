#ifndef GADGET_H
#define GADGET_H

#include <vector>
#include <string>
#include <sys/stat.h> 
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unistd.h>

#include "TString.h"

std::string gadget_MakeSafeName(std::string safe_name);

void buildfolder( std::string name);

bool boolreader( const char* text);

std::vector< TString > tokenizer( const char* text);

#endif
