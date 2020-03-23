# BergCo Coin

A clean currency to help inspire a cleaner world and way of creating an able asset to function.



# BergCo Coin Specifications
====================

Name: BergCo Coin
Ticker: BERG
Algo: X14
Type: PoW for 2000 Blocks then Pure PoS (so the world can get coins)
Maximum BERG Coin = 200,000,000

# Block Information

Maximum Block Size = 128mb
Expected Block Generation Time = 52 seconds
Block Maturity Confirmations = 52 Confirmations
Modifier Interval = 20 Minutes
Target Timespan interval = 20 Minutes


# Proof Of Work

Block 1 – 2,000 = 1,000 BERG
Block 2,001 & After is 0 BERG as PoW will be Stopped.


# Staking

Start Block Number = 52
Start Reward for 2000 blocks = 0.01 (Total of 20 BERG Coin) After this it is the expected Reward of 64.86% per year
Min Age = 2 hours
Max Age = 21 days
Block Maturity = 52 Confirmations
Reward = 64.86% per annual year


# Ports

Port = 12088
Rpc Port = 12089


# InstantX

Signatures Required = 4
Signatures Total = 12


# Masternodes

Start Date: Monday, 30 September 2019 12:00:00
Collateral Amount = 20,000 BERG Coin
Fee Amount = 0.01 BERG Coin
Confirmations Required = 4
Reward Amount = 2/3rds of the Block Value


# Transactions

Tx Fee Amount = 0.0003 BERG Coin per kilobyte
Tx Confirmations: 4 Blocks for coins to be confirmed


# UNIX BUILD NOTES
====================

To Build Bergco Headless Wallet Daemon.
-----------------

# Firstly ensure your system has all the Required tools in order to build Bergco Correctly with no issue's. Please commit these commands through the Terminal of your choice.


sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils

sudo apt-get install qt5-default qt5-qmake qtbase5-dev-tools qttools5-dev-tools build-essential libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libminiupnpc-dev 

sudo apt-get install software-properties-common

sudo add-apt-repository ppa:bergco/bergco

sudo apt-get update

sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libqrencode-dev



# Now you have all files Required by Bergco's code in order to build the Wallet.



# Now we proceed onto making the Bergco Wallet. Again use your preferred Terminal


git clone https://github.com/BergCoNet/Bergco.git

cd Bergco/src/secp256k1

chmod +x autogen.sh

sudo ./autogen.sh

sudo ./configure

sudo make && make install

cd

cd Bergco/src/leveldb

sudo sh build_detect_platform build_config.mk .

cd

cd Bergco/src

sudo make -f makefile.unix

strip bergcod

LD_LIBRARY_PATH=/usr/local/lib

export LD_LIBRARY_PATH



# You now have bergcod Ready to run and connect to the network.


# To Build Bergco Qt Wallet
------------------

# Firstly ensure your system has all the Required tools in order to build Bergco Correctly with no issue's. Please commit these commands through the Terminal of your choice.


sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils

sudo apt-get install qt5-default qt5-qmake qtbase5-dev-tools qttools5-dev-tools build-essential libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libminiupnpc-dev 

sudo apt-get install software-properties-common
sudo add-apt-repository ppa:bergco/bergco
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libqrencode-dev



# Now you have all files Required by Bergco's code in order to build the Wallet.



# Now we proceed onto making the Bergco Wallet. Again use your preferred Terminal



git clone https://github.com/BergCoNet/Bergco.git

cd Bergco/src/secp256k1

chmod +x autogen.sh

sudo ./autogen.sh

sudo ./configure

sudo make && make install

cd

cd Bergco/src/leveldb

sudo sh build_detect_platform build_config.mk .

cd

cd Bergco

sudo qmake Bergco.pro

sudo make -jnumofcoreshere