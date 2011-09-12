/*
 %atmel_license%
*/

/**
 * \file
 *
 * Interface for Serial Peripheral Interface (SPI) controller.
 *
 */

#ifndef _SPI_
#define _SPI_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "../chip.h"

/*----------------------------------------------------------------------------
 *        Macros
 *----------------------------------------------------------------------------*/

/**
 *
 * Here are several macros which should be used when configuring a SPI
 * peripheral.
 *
 * \section spi_configuration_macros SPI Configuration Macros
 * - \ref SPI_PCS
 * - \ref SPI_SCBR
 * - \ref SPI_DLYBS
 * - \ref SPI_DLYBCT
 */

/** Calculate the PCS field value given the chip select NPCS value */
#define SPI_PCS(npcs)       ((~(1 << (npcs)) & 0xF) << 16)

/** Calculates the value of the CSR SCBR field given the baudrate and MCK. */
#define SPI_SCBR(baudrate, masterClock) ((uint32_t) ((masterClock) / (baudrate)) << 8)

/** Calculates the value of the CSR DLYBS field given the desired delay (in ns) */
#define SPI_DLYBS(delay, masterClock) ((uint32_t) ((((masterClock) / 1000000) * (delay)) / 1000) << 16)

/** Calculates the value of the CSR DLYBCT field given the desired delay (in ns) */
#define SPI_DLYBCT(delay, masterClock) ((uint32_t) ((((masterClock) / 1000000) * (delay)) / 32000) << 24)

/*------------------------------------------------------------------------------ */

#ifdef __cplusplus
 extern "C" {
#endif

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

extern void SPI_Enable( Spi* spi ) ;
extern void SPI_Disable( Spi* spi ) ;
extern void SPI_EnableIt( Spi* spi, uint32_t dwSources ) ;
extern void SPI_DisableIt( Spi* spi, uint32_t dwSources ) ;

extern void SPI_Configure( Spi* spi, uint32_t dwId, uint32_t dwConfiguration ) ;
extern void SPI_ConfigureNPCS( Spi* spi, uint32_t dwNpcs, uint32_t dwConfiguration ) ;

extern uint32_t SPI_Read( Spi* spi ) ;
extern void SPI_Write( Spi* spi, uint32_t dwNpcs, uint16_t wData ) ;

extern uint32_t SPI_GetStatus( Spi* spi ) ;
extern uint32_t SPI_IsFinished( Spi* pSpi ) ;

#if (defined _SAM3S_) || (defined _SAM3S8_) || (defined _SAM3N_)
extern void SPI_PdcEnableTx( Spi* spi ) ;
extern void SPI_PdcDisableTx( Spi* spi ) ;
extern void SPI_PdcEnableRx( Spi* spi ) ;
extern void SPI_PdcDisableRx( Spi* spi ) ;

extern void SPI_PdcSetTx( Spi* spi, void* pvTxBuf, uint32_t dwTxCount, void* pvTxNextBuf, uint32_t dwTxNextCount ) ;
extern void SPI_PdcSetRx( Spi* spi, void* pvRxBuf, uint32_t dwRxCount, void* pvRxNextBuf, uint32_t dwRxNextCount ) ;

extern uint32_t SPI_WriteBuffer( Spi* spi, void* pvBuffer, uint32_t dwLength ) ;

extern uint32_t SPI_ReadBuffer( Spi* spi, void* pvBuffer, uint32_t dwLength ) ;
#endif /* (defined _SAM3S_) || (defined _SAM3S8_) || (defined _SAM3N_) */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _SPI_ */

