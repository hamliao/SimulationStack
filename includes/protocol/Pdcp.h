#pragma once

#include "Protocol.h"

class Pdcp : public Protocol
{ 
public:
	explicit Pdcp():Protocol(PDCP){}
};

