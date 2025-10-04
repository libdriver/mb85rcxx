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
 * @file      driver_mb85rcxx_read_test.c
 * @brief     driver mb85rcxx read test source file
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
 
#include "driver_mb85rcxx_read_test.h"
#include <stdlib.h>

static mb85rcxx_handle_t gs_handle;        /**< mb85rcxx handle */

/**
 * @brief     read test
 * @param[in] type chip type
 * @param[in] address chip address pin
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t mb85rcxx_read_test(mb85rcxx_t type, mb85rcxx_address_t address)
{
    uint8_t res, i, j;
    uint8_t buf[12];
    uint8_t buf_check[12];
    uint32_t inc;
    mb85rcxx_info_t info;
    
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
    
    /* get information */
    res = mb85rcxx_info(&info);
    if (res != 0)
    {
        mb85rcxx_interface_debug_print("mb85rcxx: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        mb85rcxx_interface_debug_print("mb85rcxx: chip is %s.\n", info.chip_name);
        mb85rcxx_interface_debug_print("mb85rcxx: manufacturer is %s.\n", info.manufacturer_name);
        mb85rcxx_interface_debug_print("mb85rcxx: interface is %s.\n", info.interface);
        mb85rcxx_interface_debug_print("mb85rcxx: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        mb85rcxx_interface_debug_print("mb85rcxx: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        mb85rcxx_interface_debug_print("mb85rcxx: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        mb85rcxx_interface_debug_print("mb85rcxx: max current is %0.2fmA.\n", info.max_current_ma);
        mb85rcxx_interface_debug_print("mb85rcxx: max temperature is %0.1fC.\n", info.temperature_max);
        mb85rcxx_interface_debug_print("mb85rcxx: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* set chip type */
    res = mb85rcxx_set_type(&gs_handle, type);
    if (res != 0)
    {
        mb85rcxx_interface_debug_print("mb85rcxx: set type failed.\n");
       
        return 1;
    }
    
    /* set iic addr pin */
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
    
    /* start read test */
    mb85rcxx_interface_debug_print("mb85rcxx: start read test.\n");
    inc = ((uint32_t)type + 1) / 8;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 12; j++)
        {
            buf[j] = (uint8_t)(rand() % 256);
        }
    
        /* write data */
        res = mb85rcxx_write(&gs_handle, i*inc, (uint8_t *)buf, 12);
        if (res != 0)
        {
            mb85rcxx_interface_debug_print("mb85rcxx: write failed.\n");
            (void)mb85rcxx_deinit(&gs_handle);
            
            return 1;
        }

        /* read data */
        res = mb85rcxx_read(&gs_handle, i*inc, (uint8_t *)buf_check, 12);
        if (res != 0)
        {
            mb85rcxx_interface_debug_print("mb85rcxx: read failed.\n");
            (void)mb85rcxx_deinit(&gs_handle);
            
            return 1;
        }
        for (j = 0; j < 12; j++)
        {
            /* check data */
            if (buf[j] != buf_check[j])
            {
                mb85rcxx_interface_debug_print("mb85rcxx: check error.\n");
                (void)mb85rcxx_deinit(&gs_handle);
                
                return 1;
            }
        }
        mb85rcxx_interface_debug_print("mb85rcxx: 0x%04X read write test passed.\n", i*inc);
    }

    /* finish read test */
    mb85rcxx_interface_debug_print("mb85rcxx: finish read test.\n");
    (void)mb85rcxx_deinit(&gs_handle);
    
    return 0;
}
