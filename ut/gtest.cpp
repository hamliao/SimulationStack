#include "Protocol.h"
#include "Phy.h"
#include "Mac.h"
#include "Rlc.h"
#include "Pdcp.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(phyEncodeTest, intData)
{
	Packet packet{1, 2, 3};
	Packet testResult{0, 3, 1, 2, 3};

	Phy myPhy;
	myPhy.encode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(phyDecodeTest, intData)
{
	Packet packet{0, 5, 1, 2, 3, 4, 5};
	Packet testResult{1, 2, 3, 4, 5};

	Phy myPhy;
	myPhy.decode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(phyEnDecodeTest, intData)
{
	Packet packet{1, 2, 3};
	Packet testResult{1, 2, 3};

	Phy myPhy;
	myPhy.encode(packet);
	myPhy.decode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(macEncodeTest, intData)
{
	Packet packet{1, 2, 3};
	Packet testResult{1, 1, 2, 3};

	Mac myMac;
	myMac.encode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(macDecodeTest, intData)
{
	Packet packet{1, 1, 2, 3, 8};
	Packet testResult{1, 2, 3, 8};

	Mac myMac;
	myMac.decode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(rlcEncodeTest, intData)
{
	Packet packet{0, 0, 0, 0, 0};
	Packet testResult{2, 0, 0, 0, 0, 0};

	Rlc myRlc;
	myRlc.encode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(rlcDecodeTest, intData)
{
	Packet packet{2, 0, 0, 0, 0, 0};
	Packet testResult{0, 0, 0, 0, 0};

	Rlc myRlc;
	myRlc.decode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(pdcpEncodeTest, intData)
{
	Packet packet{0, 0, 0, 0, 0};
	Packet testResult{3, 0, 0, 0, 0, 0};

	Pdcp myPdcp;
	myPdcp.encode(packet);
	EXPECT_EQ(testResult, packet);
}

TEST(pdcpDecodeTest, intData)
{
	Packet packet{3, 0, 0, 0, 0, 0};
	Packet testResult{0, 0, 0, 0, 0};

	Pdcp myPdcp;
	myPdcp.decode(packet);
	EXPECT_EQ(testResult, packet);
}
