/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_mb85rcxx.h
 * @brief     driver mb85rcxx header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2025-10-15
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2025/10/15  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_MB85RCXX_H
#define DRIVER_MB85RCXX_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup mb85rcxx_driver mb85rcxx driver function
 * @brief    mb85rcxx driver modules
 * @{
 */

/**
 * @addtogroup mb85rcxx_base_driver
 * @{
 */

/**
 * @brief mb85rcxx type enumeration definition
 */
typedef enum
{
    MB85RC04  = 512,           /**< MB85RC04 type */
    MB85RC16  = 2048,          /**< MB85RC16 type */
    MB85RC64  = 8192,          /**< MB85RC64 type */
    MB85RC128 = 16384,         /**< MB85RC128 type */
    MB85RC256 = 32768,         /**< MB85RC256 type */
    MB85RC512 = 65536,         /**< MB85RC512 type */
    MB85RC1M  = 131072,        /**< MB85RC1M type */
} mb85rcxx_t;

/**
 * @brief mb85rcxx address enumeration definition
 */
typedef enum
{
    MB85RCXX_ADDRESS_A000 = 0,        /**< A2A1A0 000 */
    MB85RCXX_ADDRESS_A001 = 1,        /**< A2A1A0 001 */
    MB85RCXX_ADDRESS_A010 = 2,        /**< A2A1A0 010 */
    MB85RCXX_ADDRESS_A011 = 3,        /**< A2A1A0 011 */
    MB85RCXX_ADDRESS_A100 = 4,        /**< A2A1A0 100 */
    MB85RCXX_ADDRESS_A101 = 5,        /**< A2A1A0 101 */
    MB85RCXX_ADDRESS_A110 = 6,        /**< A2A1A0 110 */
    MB85RCXX_ADDRESS_A111 = 7,        /**< A2A1A0 111 */
} mb85rcxx_address_t;

/**
 * @brief mb85rcxx handle structure definition
 */
typedef struct mb85rcxx_handle_s
{
    uint8_t iic_addr;                                                                              /**< iic device address */
    uint8_t (*iic_init)(void);                                                                     /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                                                   /**< point to an iic_deinit function address */
    uint8_t (*iic_read)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);                    /**< point to an iic_read function address */
    uint8_t (*iic_write)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);                   /**< point to an iic_write function address */
    uint8_t (*iic_read_address16)(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len);         /**< point to an iic_read_address16 function address */
    uint8_t (*iic_write_address16)(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len);        /**< point to an iic_write_address16 function address */
    void (*delay_ms)(uint32_t ms);                                                                 /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                                               /**< point to a debug_print function address */
    uint32_t id;                                                                                   /**< chip id */
    uint8_t inited;                                                                                /**< inited flag */
} mb85rcxx_handle_t;

/**
 * @brief mb85rcxx information structure definition
 */
typedef struct mb85rcxx_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} mb85rcxx_info_t;

/**
 * @}
 */

/**
 * @defgroup mb85rcxx_link_driver mb85rcxx link driver function
 * @brief    mb85rcxx link driver modules
 * @ingroup  mb85rcxx_driver
 * @{
 */

/**
 * @brief     initialize mb85rcxx_handle_t structure
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] STRUCTURE mb85rcxx_handle_t
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_INIT(HANDLE, STRUCTURE)           memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to an iic_init function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_IIC_INIT(HANDLE, FUC)             (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to an iic_deinit function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_IIC_DEINIT(HANDLE, FUC)           (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_read function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to an iic_read function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_IIC_READ(HANDLE, FUC)             (HANDLE)->iic_read = FUC

/**
 * @brief     link iic_write function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to an iic_write function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_IIC_WRITE(HANDLE, FUC)            (HANDLE)->iic_write = FUC

/**
 * @brief     link iic_read_address16 function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to an iic_read_address16 function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_IIC_READ_ADDRESS16(HANDLE, FUC)   (HANDLE)->iic_read_address16 = FUC

/**
 * @brief     link iic_write_address16 function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to an iic_write_address16 function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_IIC_WRITE_ADDRESS16(HANDLE, FUC)  (HANDLE)->iic_write_address16 = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to a delay_ms function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_DELAY_MS(HANDLE, FUC)             (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE pointer to a mb85rcxx handle structure
 * @param[in] FUC pointer to a debug_print function address
 * @note      none
 */
#define DRIVER_MB85RCXX_LINK_DEBUG_PRINT(HANDLE, FUC)          (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup mb85rcxx_base_driver mb85rcxx base driver function
 * @brief    mb85rcxx base driver modules
 * @ingroup  mb85rcxx_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info pointer to a mb85rcxx info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t mb85rcxx_info(mb85rcxx_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle pointer to a mb85rcxx handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 * @note      none
 */
uint8_t mb85rcxx_init(mb85rcxx_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle pointer to a mb85rcxx handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t mb85rcxx_deinit(mb85rcxx_handle_t *handle);

/**
 * @brief     set the chip type
 * @param[in] *handle pointer to a mb85rcxx handle structure
 * @param[in] type chip type
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t mb85rcxx_set_type(mb85rcxx_handle_t *handle, mb85rcxx_t type);

/**
 * @brief      get the chip type
 * @param[in]  *handle pointer to a mb85rcxx handle structure
 * @param[out] *type pointer to a chip type buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t mb85rcxx_get_type(mb85rcxx_handle_t *handle, mb85rcxx_t *type);

/**
 * @brief     set the chip address pin
 * @param[in] *handle pointer to a mb85rcxx handle structure
 * @param[in] addr_pin chip address pin
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t mb85rcxx_set_addr_pin(mb85rcxx_handle_t *handle, mb85rcxx_address_t addr_pin);

/**
 * @brief      get the chip address pin
 * @param[in]  *handle pointer to a mb85rcxx handle structure
 * @param[out] *addr_pin pointer to a chip address pin
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t mb85rcxx_get_addr_pin(mb85rcxx_handle_t *handle, mb85rcxx_address_t *addr_pin);

/**
 * @brief      read bytes from the chip
 * @param[in]  *handle pointer to a mb85rcxx handle structure
 * @param[in]  address register address
 * @param[out] *buf pointer to a data buffer
 * @param[in]  len buffer length
 * @return     status code
 *             - 0 success
 *             - 1 read data failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 end address is over the max address
 * @note       none
 */
uint8_t mb85rcxx_read(mb85rcxx_handle_t *handle, uint32_t address, uint8_t *buf, uint16_t len);

/**
 * @brief     write bytes to the chip
 * @param[in] *handle pointer to a mb85rcxx handle structure
 * @param[in] address register address
 * @param[in] *buf pointer to a data buffer
 * @param[in] len buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write data failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 end address is over the max address
 * @note      none
 */
uint8_t mb85rcxx_write(mb85rcxx_handle_t *handle, uint32_t address, uint8_t *buf, uint16_t len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
