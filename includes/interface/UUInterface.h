#pragma once

#include "Interface.h"


class UUInterface : public Interface
{
public:
	UUInterface();
};

UUInterface::UUInterface()
{
	auto pdcpPoint(std::make_shared<Pdcp>());
	protocolStack.push_back(pdcpPoint);
	
	auto rlcPoint(std::make_shared<Rlc>());
	protocolStack.push_back(rlcPoint);

	auto macPoint(std::make_shared<Mac>());
	protocolStack.push_back(macPoint);

	auto phyPoint(std::make_shared<Phy>());
	protocolStack.push_back(phyPoint);
}
