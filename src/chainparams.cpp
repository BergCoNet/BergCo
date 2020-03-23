// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bergco developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"
#include "checkpoints.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"
//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xd2;
        pchMessageStart[1] = 0xf8;
        pchMessageStart[2] = 0x1b;
        pchMessageStart[3] = 0xce;
        vAlertPubKey = ParseHex("04eb0d13c016edcfa502316e6fbeba2f2229897694be1a241b4b3bd5679be1753cd9f16a9a2894b91528f017d55bad5eb9fbd3d2d10cdb679228c91e26e26900e");
        nDefaultPort = 12088;
        nRPCPort = 12089;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
		
        const char* pszTimestamp = "https://www.bbc.co.uk/news/science-environment-49756260"; // Climate change: Scientists to report on ocean 'emergency' caused by warming
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 4865792 << CBigNum(52) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1569325920, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1569325920;
        genesis.nBits    = 0x1f00ffff; 
        genesis.nNonce   = 549831;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0xf86a0f02ff6b75072c1a642dce76030730b93dee682c3221d80a15ad9c916741"));
        assert(genesis.hashMerkleRoot == uint256("0x71c2695b09ba5c4e77b9eb3cf8aceced67c4f4ff09184076b8e6aa9292d2b2e8"));

        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,37);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,95);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x22)(0xE5)(0x8A).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x22)(0xD7)(0xF2).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPOSStartBlock = 52;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xe2;
        pchMessageStart[1] = 0x3d;
        pchMessageStart[2] = 0x55;
        pchMessageStart[3] = 0x9C;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("04194be1a4bd2d10cdb679228c2697eb053cd016ed99d55b9ff16a9a29892894ad5e91d13c1528241bcf3bd55023679be17f0bd3a16e26ebbe6fbeba2f227600e");
        nDefaultPort = 22088;
        nRPCPort = 22089;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = 53794937; 
        genesis.nNonce = 67912;

        //assert(hashGenesisBlock == uint256(""));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,10);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,74);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,99);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0x4D)(0xF1).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0x9D)(0x1A).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nPOSStartBlock = 52;

    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
