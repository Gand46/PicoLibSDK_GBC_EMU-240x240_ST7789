// ****************************************************************************
//
//                          External SPI flash driver
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

#if USE_SPIFLASH           // use external SPI flash (lib_spiflash.c, lib_spiflash.h)

#include "../inc/lib_spiflash.h"
#include "../../_sdk/inc/sdk_spi.h"

#ifndef SECT_SIZE
#define SECT_SIZE 512             // default sector size
#endif

// SPI port used for external flash
#ifndef SPIFLASH_SPI
#define SPIFLASH_SPI 0
#endif

// simple placeholder size in sectors (can be adjusted by application)
static u32 SpiFlashSizeSect = 0;

// initialize SPI flash (returns False on error)
Bool SpiFlashInit()
{
    // initialize SPI controller with default 1 MHz
    SPI_Init(SPIFLASH_SPI, 1000000);
    return True;
}

// terminate SPI flash interface
void SpiFlashTerm()
{
    SPI_Term(SPIFLASH_SPI);
}

// read one sector from SPI flash (returns False on error)
Bool SpiFlashReadSect(u32 sect, u8* buf)
{
    // this is only a stub implementation
    (void)sect;
    if (buf == NULL) return False;
    memset(buf, 0, SECT_SIZE);
    return True;
}

// write one sector to SPI flash (returns False on error)
Bool SpiFlashWriteSect(u32 sect, const u8* buf)
{
    // stub does nothing, report success
    (void)sect;
    (void)buf;
    return True;
}

// get flash media size in sectors (returns 0 on error)
u32 SpiFlashMediaSize()
{
    return SpiFlashSizeSect;
}

#endif // USE_SPIFLASH

