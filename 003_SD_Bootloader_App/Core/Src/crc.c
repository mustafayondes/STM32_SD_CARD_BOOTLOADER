#include "stdint.h"
#include "stddef.h"
// CRC32 hesaplama tablosu
static uint32_t crc32_table[256];

// CRC32 tablosunu oluşturma fonksiyonu
void init_crc32_table(void) {
    uint32_t polynomial = 0xEDB88320;
    for (uint32_t i = 0; i < 256; i++) {
        uint32_t crc = i;
        for (uint32_t j = 8; j > 0; j--) {
            if (crc & 1) {
                crc = (crc >> 1) ^ polynomial;
            } else {
                crc >>= 1;
            }
        }
        crc32_table[i] = crc;
    }
}

// CRC32 hesaplama fonksiyonu
uint32_t get_crc32(uint32_t crc, uint8_t data) {
    return (crc >> 8) ^ crc32_table[(crc ^ data) & 0xFF];
}

// CRC32 başlangıç değeri ile CRC32 hesaplama fonksiyonu
uint32_t calculate_crc32(uint8_t *data, size_t length) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; i++) {
        crc = get_crc32(crc, data[i]);
    }
    return crc ^ 0xFFFFFFFF;
}
