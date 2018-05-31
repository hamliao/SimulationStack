#pragma once

#include "Protocol.h"
#include <vector>
#include <iostream>

class Rlc : public Protocol
{ 

public:
	explicit Rlc():Protocol(RLC){}

	virtual bool encode(Packet &data) const;
	virtual bool decode(Packet &data) const;
};

bool Rlc::encode(Packet &data) const
{
	data.insert(data.begin(), getType());
	return true;
}

bool Rlc::decode(Packet &data) const
{
	Protocoltype layertype = static_cast<Protocoltype>(data[0]);

	if (layertype != getType())
	{
		std::cout <<"rlc decode false" <<std::endl;
		return false;
	}

	data.erase(data.begin());
	return true;
}

