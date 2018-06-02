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
	explicit Protocol(Protocoltype layerType):type(layerType){}
	virtual ~Protocol(){}

	virtual bool encode(Packet &data) const;
	virtual bool decode(Packet &data) const;
	
	Protocoltype getType(void) const {return type;}
};

bool Protocol::encode(Packet &data) const
{
	data.insert(data.begin(), getType());
	return true;
}

bool Protocol::decode(Packet &data) const
{
	Protocoltype layertype = static_cast<Protocoltype>(data[0]);

	if (layertype != getType())
	{
		std::cout <<"decode false" <<std::endl;
		return false;
	}

	data.erase(data.begin());
	return true;
}
