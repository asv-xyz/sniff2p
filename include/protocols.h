#pragma once

#include <cstdint>
#include <string>
#include <arpa/inet.h>

// Macros
using U8    = uint8_t;
using U16   = uint16_t;
using U32   = uint32_t;
using U64   = uint64_t;

// Disabling allignment
#pragma pack(push, 1)
struct EthernetHeader {
    U8      _MAC_dst    [6];
    U8      _MAC_src    [6];
    U16     _ether_type;
};

struct IPv4Header {
    // Some bit fields
    U8      _IHL : 4;       // header length
    U8      _IV : 4;        // version
    U8      _TOS;           // type of service
    U16     _TL;            // total length

    U16     _ID;
    U16     _flags : 3;
    U16     _flags_offset : 13;

    U8      _TTL;
    U8      _protocol;
    U16     _checksum;

    U32     _IP_dst;
    U32     _IP_src;
};

struct TCPHeader {
    U16     _src_port;
    U16     _dst_port;

    U32     _SN;             // sequence number

    U32     _AN;             // acknowledgment number

    U8      _HL : 4;         // header length
    U8      _RB : 6;         // reserved bits
    // TODO: Flags and other stuff
};

// Enabling allignment
#pragma pack(pop)
