#pragma once

#include "utils/types.h"

#pragma pack(push, 1)           // disabling allingment
typedef struct _ICMPHeader {
    U8  type;
    U8  code;
    U16 checksum;

    U32 ext_h;                  // extended header
    U8  data[0];
} ICMPHeader;

#pragma pack(pop)               // enabling allingment
