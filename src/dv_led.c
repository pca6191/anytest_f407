/*
 * dv_led.c
 *
 *  Created on: 2018/3/7
 *      Author: kcchang
 */
#include "stm32f4xx_hal.h"
#include "dv_led.h"

/*
 * @file    discovery407 led 有四顆：
 *          Green (PD12) / Orange (PD13) / Red (PD14) / Blue (PD15)
 */

/*
 * @brief   initialize the gpio of leds.
 */
void dv_led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    //init PG clock
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /*Configure GPIO pin : PG13/14 */
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13 | GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Configure as LEDs off */
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

/*
 * @bried turn the led.
 */
void dv_led_on(dv_led_e name)
{
    switch (name)
    {
        case led_green:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
            break;

        case led_orange:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
            break;

        case led_red:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
            break;

        case led_blue:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
            break;

        default:
            break;
    }
}

/*
 * @brief  turn off the led.
 */
void dv_led_off(dv_led_e name)
{
    switch (name)
    {
        case led_green:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
            break;

        case led_orange:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
            break;

        case led_red:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
            break;

        case led_blue:
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
            break;

        default:
            break;
    }
}

/*
 * @brief    測試 led 4 顆輪轉
 */
void dv_led_rotating(void)
{
    dv_led_on(led_green);
    HAL_Delay(100);
    dv_led_off(led_green);
    HAL_Delay(20);

    dv_led_on(led_orange);
    HAL_Delay(100);
    dv_led_off(led_orange);
    HAL_Delay(20);

    dv_led_on(led_red);
    HAL_Delay(100);
    dv_led_off(led_red);
    HAL_Delay(20);

    dv_led_on(led_blue);
    HAL_Delay(100);
    dv_led_off(led_blue);
    HAL_Delay(20);
}
