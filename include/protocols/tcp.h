#pragma once

#include "types.h"

#pragma pack(push, 1)           // disabling allingment
typedef struct _TCPHeader {
    U16 src_port;
    U16 dst_port;

    U32 seq_num;

    U32 ack_num;

    U8  rb              : 4;    // reserved bits
    U8  hl              : 4;    // header length
    U8  fin             : 1;
    U8  syn             : 1;
    U8  rst             : 1;
    U8  psh             : 1;
    U8  ack             : 1;
    U8  urg             : 1;
    U8  rb2             : 2;
    U16 win_size;

    U16 checksum;
    U16 urg_ptr;

    U8 data[0];
} TCPHeader;

#pragma pack(pop)               // enabling allingment
