/*
 * crc.h
 *
 *  Created on: Aug 8, 2024
 *      Author: pc
 */

#ifndef INC_CRC_H_
#define INC_CRC_H_

void init_crc32_table(void);
uint32_t get_crc32(uint32_t crc, uint8_t data);
uint32_t calculate_crc32(uint8_t *data, size_t length);


#endif /* INC_CRC_H_ */
