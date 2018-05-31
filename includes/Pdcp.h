#pragma once

#include "Protocol.h"
#include <vector>
#include <iostream>

class Pdcp : public Protocol
{ 

public:
	explicit Pdcp():Protocol(PDCP){}

	virtual bool encode(Packet &data) const;
	virtual bool decode(Packet &data) const;
};

bool Pdcp::encode(Packet &data) const
{
	data.insert(data.begin(), getType());
	return true;
}

bool Pdcp::decode(Packet &data) const
{
	Protocoltype layertype = static_cast<Protocoltype>(data[0]);

	if (layertype != getType())
	{
		std::cout <<"pdcp decode false" <<std::endl;
		return false;
	}

	data.erase(data.begin());
	return true;
}

