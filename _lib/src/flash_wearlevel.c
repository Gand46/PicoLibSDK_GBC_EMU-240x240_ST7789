// ****************************************************************************
//
//                     Simple flash wear-leveling layer
//
// ****************************************************************************
// PicoLibSDK - Alternative SDK library for Raspberry Pico and RP2040
// Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
//      https://github.com/Panda381/PicoLibSDK
//      https://www.breatharian.eu/hw/picolibsdk/index_en.html
//      https://github.com/pajenicko/picopad
//      https://picopad.eu/en/
// License:
//      This source code is freely available for any purpose, including commercial.
//      It is possible to take and modify the code or parts of it, without restriction.

#include "../../global.h"       // globals

#if USE_SPIFLASH           // use external SPI flash (flash_wearlevel.c, flash_wearlevel.h)

#include "../inc/flash_wearlevel.h"
#include "../inc/lib_spiflash.h"

// Current implementation is a simple pass-through to SPI flash driver.
// Proper wear leveling can be implemented here in the future.

Bool WearLevelInit()
{
    return FlashInit();
}

void WearLevelTerm()
{
    FlashTerm();
}

Bool WearLevelReadSect(u32 sect, u8* buf)
{
    return FlashReadSect(sect, buf);
}

Bool WearLevelWriteSect(u32 sect, const u8* buf)
{
    return FlashWriteSect(sect, buf);
}

u32 WearLevelMediaSize()
{
    return FlashMediaSize();
}

#endif // USE_SPIFLASH

