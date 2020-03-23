// Copyright (c) 2015 The Bergco Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BERGCO_ZMQ_ZMQCONFIG_H
#define BERGCO_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include "config/bergco-config.h"
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include "primitives/block.h"
#include "primitives/transaction.h"

void zmqError(const char *str);

#endif // BERGCO_ZMQ_ZMQCONFIG_H
