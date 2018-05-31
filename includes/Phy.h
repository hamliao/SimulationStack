#pragma once

#include "Protocol.h"
#include <vector>
#include <iostream>

class Phy : public Protocol
{ 

public:
	explicit Phy():Protocol(PHY){}

	virtual bool encode(Packet &data) const;
	virtual bool decode(Packet &data) const;
};

bool Phy::encode(Packet &data) const
{
	data.insert(data.begin(), data.size());
	data.insert(data.begin(), getType());

	return true;
}

bool Phy::decode(Packet &data) const
{
	Protocoltype phytype = static_cast<Protocoltype>(data[0]);
	int  dataSize = static_cast<int>(data.size() - 2);

	if (phytype != getType() || data[1] != dataSize)
	{
		std::cout <<"phytype decode false" <<std::endl;
		return false;
	}

	data.erase(data.begin());
	data.erase(data.begin());
	return true;
}

