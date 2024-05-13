/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @brief Header containing interrupt handler specific declarations for the
 * HAL Layer of the Wi-Fi driver.
 */

#ifndef __HAL_INTERRUPT_H__
#define __HAL_INTERRUPT_H__

#include "hal_api.h"

/**
 * hal_rpu_irq_enable() - Enables interrupts from the RPU.
 * @hal_dev_ctx: Pointer to HAL context.
 *
 * This function enables the interrupts from the RPU.
 *
 * Return: Status
 *		Pass : %NRF_WIFI_STATUS_SUCCESS
 *		Error: %NRF_WIFI_STATUS_FAIL
 */
enum nrf_wifi_status hal_rpu_irq_enable(struct nrf_wifi_hal_dev_ctx *hal_dev_ctx);


/**
 * hal_rpu_irq_disable() - Disables interrupts from the RPU.
 * @hal_dev_ctx: Pointer to HAL context.
 *
 * This function disables the interrupts from the RPU.
 *
 * Return: Status
 *		Pass : %NRF_WIFI_STATUS_SUCCESS
 *		Error: %NRF_WIFI_STATUS_FAIL
 */
enum nrf_wifi_status hal_rpu_irq_disable(struct nrf_wifi_hal_dev_ctx *hal_dev_ctx);


/**
 * hal_rpu_irq_process() - Processes an interrupt from the RPU.
 * @hal_dev_ctx: Pointer to HAL context.
 * @do_rpu_recovery: Pointer to a boolean variable that indicates if the RPU recovery
 *                  is required.
 *
 * This function is an interrupt handler for the interrupts generated by the
 * RPU. This function does the following:
 *
 *    - Stores the event details for as many events as available,into local
 *      buffers and queues them to the event queue for deferred
 *      processing.  (Refer to hal_eventq_process for the
 *      deferred handler).
 *    - Acknowledges the RPU interrupt.
 *
 * Return: Status
 *		Pass : %NRF_WIFI_STATUS_SUCCESS
 *		Error: %NRF_WIFI_STATUS_FAIL
 */
enum nrf_wifi_status hal_rpu_irq_process(struct nrf_wifi_hal_dev_ctx *hal_dev_ctx,
    bool *do_rpu_recovery);
#endif /* __HAL_INTERRUPT_H__ */
