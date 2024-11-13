/*
 * TTAF_FLASH_LIB.h
 *
 *  Created on: 13 Tem 2021
 *      Author: RiseX2
 */

#ifndef INC_TTAF_FLASH_LIB_H_
#define INC_TTAF_FLASH_LIB_H_

#include "stdint.h"




#define FLASH_BASE_ADDRESS				0x08000000


uint32_t Flash_Write(uint32_t StartAddress, uint32_t *Data, uint32_t numberOfWords);

uint32_t Flash_Write_Data (uint32_t StartSectorAddress, uint32_t *Data, uint32_t numberofwords, uint8_t erase);

void Flash_Read_Data (uint32_t StartSectorAddress, uint32_t *RxBuf, uint16_t numberofwords);

void Convert_To_Str (uint32_t *Data, char *Buf);

void Flash_Write_NUM (uint32_t StartSectorAddress, float Num);

float Flash_Read_NUM (uint32_t StartSectorAddress);

uint32_t Flash_Erase(uint32_t StartSector, uint32_t EndSector);




uint32_t getCRCfromFile(void);
uint32_t CalculateCRC(void);
#endif /* INC_TTAF_FLASH_LIB_H_ */
