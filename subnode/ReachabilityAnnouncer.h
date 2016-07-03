/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ReachabilityAnnouncer_H
#define ReachabilityAnnouncer_H

#include "memory/Allocator.h"
#include "util/log/Log.h"
#include "util/events/EventBase.h"
#include "crypto/random/Random.h"
#include "subnode/AddrSet.h"
#include "subnode/MsgCore.h"
#include "dht/Address.h"
#include "util/Linker.h"
Linker_require("subnode/ReachabilityAnnouncer.c");

struct ReachabilityAnnouncer
{
    int unused;
};

void ReachabilityAnnouncer_updatePeer(struct ReachabilityAnnouncer* ra,
                                      struct Address* peer,
                                      uint16_t mtu,
                                      uint16_t drops,
                                      uint16_t latency);

void ReachabilityAnnouncer_setSupernode(struct ReachabilityAnnouncer* ra, struct Address* snode);

struct ReachabilityAnnouncer* ReachabilityAnnouncer_new(struct Allocator* allocator,
                                                        struct Log* log,
                                                        struct EventBase* base,
                                                        struct MsgCore* msgCore);

#endif
