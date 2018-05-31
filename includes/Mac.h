#pragma once

#include "Protocol.h"
#include <vector>
#include <iostream>

class Mac : public Protocol
{ 

public:
	explicit Mac():Protocol(MAC){}

	virtual bool encode(Packet &data) const;
	virtual bool decode(Packet &data) const;
};

bool Mac::encode(Packet &data) const
{
	data.insert(data.begin(), getType());
	return true;
}

bool Mac::decode(Packet &data) const
{
	Protocoltype layertype = static_cast<Protocoltype>(data[0]);

	if (layertype != getType())
	{
		std::cout <<"mac decode false" <<std::endl;
		return false;
	}

	data.erase(data.begin());
	return true;
}

