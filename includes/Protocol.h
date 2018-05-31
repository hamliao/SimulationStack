#pragma once

#include <vector>
#include <iostream>

enum Protocoltype
{
	PHY = 0, MAC, RLC, PDCP
};

using Packet = std::vector<int>;

class Protocol
{
private:
	Protocoltype type;

public:
	Protocol() = delete;
	Protocol(Protocoltype layerType):type(layerType){}
	virtual ~Protocol(){}

	virtual bool encode(Packet &data) const = 0;
	virtual bool decode(Packet &data) const = 0;
	
	Protocoltype getType(void) const {return type;}
};

