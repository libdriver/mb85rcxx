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
 * @file      driver_mb85rcxx_basic.c
 * @brief     driver mb85rcxx basic source file
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

#include "driver_mb85rcxx_basic.h"

static mb85rcxx_handle_t gs_handle;        /**< mb85rcxx handle */

/**
 * @brief     basic example init
 * @param[in] type chip type
 * @param[in] address chip address pin
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t mb85rcxx_basic_init(mb85rcxx_t type, mb85rcxx_address_t address)
{
    uint8_t res;
    
    /* link interface function */
    DRIVER_MB85RCXX_LINK_INIT(&gs_handle, mb85rcxx_handle_t);
    DRIVER_MB85RCXX_LINK_IIC_INIT(&gs_handle, mb85rcxx_interface_iic_init);
    DRIVER_MB85RCXX_LINK_IIC_DEINIT(&gs_handle, mb85rcxx_interface_iic_deinit);
    DRIVER_MB85RCXX_LINK_IIC_READ(&gs_handle, mb85rcxx_interface_iic_read);
    DRIVER_MB85RCXX_LINK_IIC_WRITE(&gs_handle, mb85rcxx_interface_iic_write);
    DRIVER_MB85RCXX_LINK_IIC_READ_ADDRESS16(&gs_handle, mb85rcxx_interface_iic_read_address16);
    DRIVER_MB85RCXX_LINK_IIC_WRITE_ADDRESS16(&gs_handle, mb85rcxx_interface_iic_write_address16);
    DRIVER_MB85RCXX_LINK_DELAY_MS(&gs_handle, mb85rcxx_interface_delay_ms);
    DRIVER_MB85RCXX_LINK_DEBUG_PRINT(&gs_handle, mb85rcxx_interface_debug_print);
    
    /* set chip type */
    res = mb85rcxx_set_type(&gs_handle, type);
    if (res != 0)
    {
        mb85rcxx_interface_debug_print("mb85rcxx: set type failed.\n");
       
        return 1;
    }
    
    /* set addr pin */
    res = mb85rcxx_set_addr_pin(&gs_handle, address);
    if (res != 0)
    {
        mb85rcxx_interface_debug_print("mb85rcxx: set address pin failed.\n");
       
        return 1;
    }
    
    /* mb85rcxx init */
    res = mb85rcxx_init(&gs_handle);
    if (res != 0)
    {
        mb85rcxx_interface_debug_print("mb85rcxx: init failed.\n");
       
        return 1;
    }

    return 0;
}

/**
 * @brief      basic example read
 * @param[in]  address register address
 * @param[out] *buf pointer to a data buffer
 * @param[in]  len buffer length
 * @return     status code
 *             - 0 success
 *             - 1 read data failed
 * @note       none
 */
uint8_t mb85rcxx_basic_read(uint32_t address, uint8_t *buf, uint16_t len)
{
    /* read data */
    if (mb85rcxx_read(&gs_handle, address, buf, len) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief     basic example write
 * @param[in] address register address
 * @param[in] *buf pointer to a data buffer
 * @param[in] len buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write data failed
 * @note      none
 */
uint8_t mb85rcxx_basic_write(uint32_t address, uint8_t *buf, uint16_t len)
{
    /* write data */
    if (mb85rcxx_write(&gs_handle, address, buf, len) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t mb85rcxx_basic_deinit(void)
{
    /* mb85rcxx deinit */
    if (mb85rcxx_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    
    return 0;
}
