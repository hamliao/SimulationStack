#pragma once

#include <memory>
#include "Protocol.h"

using SharedPtrType = std::shared_ptr<Protocol>;

class Interface
{
protected:
	std::vector<SharedPtrType> protocolStack;

public:
	Interface() = default;
	bool sendData(Packet &userData) const;
	bool receiveData(Packet &userData) const;
};

bool Interface::sendData(Packet &userData) const
{
	for (auto index = protocolStack.begin(); index != protocolStack.end(); ++index)
	{
		(*index)->encode(userData);
	}

	return true;
}

bool Interface::receiveData(Packet &userData) const
{
	for (auto index = protocolStack.end()-1; index != protocolStack.begin()-1; --index)
	{
		(*index)->decode(userData);
	}
	
	return true;
}

