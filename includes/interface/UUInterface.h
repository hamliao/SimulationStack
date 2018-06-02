#pragma once

#include "Interface.h"


class UUInterface : public Interface
{
public:
	UUInterface();
};

UUInterface::UUInterface()
{
	std::shared_ptr<Protocol> pdcpPoint(new Pdcp());
	protocolStack.push_back(pdcpPoint);
	
	std::shared_ptr<Protocol> rlcPoint(new Rlc());
	protocolStack.push_back(rlcPoint);

	std::shared_ptr<Protocol> macPoint(new Mac());
	protocolStack.push_back(macPoint);

	std::shared_ptr<Protocol> phyPoint(new Phy());
	protocolStack.push_back(phyPoint);
}
