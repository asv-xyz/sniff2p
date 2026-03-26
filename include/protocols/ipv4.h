#pragma once

#include <types.h>

#pragma pack(push, 1)
typedef struct _IPHeader {
    U8  ihl : 4;        // ip header length
    U8  version : 4;
    U8  tos;            // type of service
    U16 tl;             // total length

    U16 id;
    U16  flags : 3;
    U16 flags_offset : 13;

    U8  ttl;
    U8  phl;            // protocol of a higher layer
    U16 checksum;

    U32 src_ip;
    U32 dst_ip;
} IPheader;

#pragma pack(pop)
