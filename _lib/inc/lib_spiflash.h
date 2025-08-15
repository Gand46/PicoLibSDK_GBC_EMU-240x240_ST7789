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

#if USE_SPIFLASH           // use external SPI flash (lib_spiflash.c, lib_spiflash.h)

#ifndef _LIB_SPIFLASH_H
#define _LIB_SPIFLASH_H

#ifdef __cplusplus
extern "C" {
#endif

// initialize SPI flash (returns False on error)
Bool SpiFlashInit();

// terminate SPI flash interface
void SpiFlashTerm();

// read one sector from SPI flash (returns False on error)
Bool SpiFlashReadSect(u32 sect, u8* buf);

// write one sector to SPI flash (returns False on error)
Bool SpiFlashWriteSect(u32 sect, const u8* buf);

// get flash media size in sectors (returns 0 on error)
u32 SpiFlashMediaSize();

#ifdef __cplusplus
}
#endif

#endif // _LIB_SPIFLASH_H

#endif // USE_SPIFLASH           // use external SPI flash

