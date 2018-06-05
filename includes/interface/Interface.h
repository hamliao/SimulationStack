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
	for (auto index = protocolStack.cbegin(); index != protocolStack.cend(); ++index)
	{
		(*index)->encode(userData);
	}

	return true;
}

bool Interface::receiveData(Packet &userData) const
{
	for (auto index = protocolStack.crbegin(); index != protocolStack.crend(); ++index)
	{
		(*index)->decode(userData);
	}
	
	return true;
}

