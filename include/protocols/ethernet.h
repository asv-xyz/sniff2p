#pragma once

#include <types.h>

#pragma pack(push, 1)   // disabling allingment
typedef struct _EthernetHeader {
    U8  dst_mac[6];
    U8  src_mac[6];
    U16 ether_type;
} EthernetHeader;

#pragma pack(pop)       // enabling allingment
