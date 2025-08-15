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

#if USE_SPIFLASH           // use external SPI flash (flash_wearlevel.c, flash_wearlevel.h)

#ifndef _FLASH_WEARLEVEL_H
#define _FLASH_WEARLEVEL_H

#ifdef __cplusplus
extern "C" {
#endif

// initialize wear leveling layer (returns False on error)
Bool WearLevelInit();

// terminate wear leveling layer
void WearLevelTerm();

// read one logical sector
Bool WearLevelReadSect(u32 sect, u8* buf);

// write one logical sector
Bool WearLevelWriteSect(u32 sect, const u8* buf);

// get number of logical sectors
u32 WearLevelMediaSize();

#ifdef __cplusplus
}
#endif

#endif // _FLASH_WEARLEVEL_H

#endif // USE_SPIFLASH

