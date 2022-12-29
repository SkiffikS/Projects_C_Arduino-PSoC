/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* RED */
#define RED__0__DM__MASK 0x1C0000u
#define RED__0__DM__SHIFT 18u
#define RED__0__DR CYREG_PRT1_DR
#define RED__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define RED__0__HSIOM_MASK 0x0F000000u
#define RED__0__HSIOM_SHIFT 24u
#define RED__0__INTCFG CYREG_PRT1_INTCFG
#define RED__0__INTSTAT CYREG_PRT1_INTSTAT
#define RED__0__MASK 0x40u
#define RED__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define RED__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define RED__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define RED__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define RED__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define RED__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define RED__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define RED__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define RED__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define RED__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define RED__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define RED__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define RED__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define RED__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define RED__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define RED__0__PC CYREG_PRT1_PC
#define RED__0__PC2 CYREG_PRT1_PC2
#define RED__0__PORT 1u
#define RED__0__PS CYREG_PRT1_PS
#define RED__0__SHIFT 6u
#define RED__DR CYREG_PRT1_DR
#define RED__INTCFG CYREG_PRT1_INTCFG
#define RED__INTSTAT CYREG_PRT1_INTSTAT
#define RED__MASK 0x40u
#define RED__PA__CFG0 CYREG_UDB_PA1_CFG0
#define RED__PA__CFG1 CYREG_UDB_PA1_CFG1
#define RED__PA__CFG10 CYREG_UDB_PA1_CFG10
#define RED__PA__CFG11 CYREG_UDB_PA1_CFG11
#define RED__PA__CFG12 CYREG_UDB_PA1_CFG12
#define RED__PA__CFG13 CYREG_UDB_PA1_CFG13
#define RED__PA__CFG14 CYREG_UDB_PA1_CFG14
#define RED__PA__CFG2 CYREG_UDB_PA1_CFG2
#define RED__PA__CFG3 CYREG_UDB_PA1_CFG3
#define RED__PA__CFG4 CYREG_UDB_PA1_CFG4
#define RED__PA__CFG5 CYREG_UDB_PA1_CFG5
#define RED__PA__CFG6 CYREG_UDB_PA1_CFG6
#define RED__PA__CFG7 CYREG_UDB_PA1_CFG7
#define RED__PA__CFG8 CYREG_UDB_PA1_CFG8
#define RED__PA__CFG9 CYREG_UDB_PA1_CFG9
#define RED__PC CYREG_PRT1_PC
#define RED__PC2 CYREG_PRT1_PC2
#define RED__PORT 1u
#define RED__PS CYREG_PRT1_PS
#define RED__SHIFT 6u

/* BLUE */
#define BLUE__0__DM__MASK 0xE00u
#define BLUE__0__DM__SHIFT 9u
#define BLUE__0__DR CYREG_PRT0_DR
#define BLUE__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define BLUE__0__HSIOM_MASK 0x0000F000u
#define BLUE__0__HSIOM_SHIFT 12u
#define BLUE__0__INTCFG CYREG_PRT0_INTCFG
#define BLUE__0__INTSTAT CYREG_PRT0_INTSTAT
#define BLUE__0__MASK 0x08u
#define BLUE__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define BLUE__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define BLUE__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define BLUE__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define BLUE__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define BLUE__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define BLUE__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define BLUE__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define BLUE__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define BLUE__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define BLUE__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define BLUE__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define BLUE__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define BLUE__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define BLUE__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define BLUE__0__PC CYREG_PRT0_PC
#define BLUE__0__PC2 CYREG_PRT0_PC2
#define BLUE__0__PORT 0u
#define BLUE__0__PS CYREG_PRT0_PS
#define BLUE__0__SHIFT 3u
#define BLUE__DR CYREG_PRT0_DR
#define BLUE__INTCFG CYREG_PRT0_INTCFG
#define BLUE__INTSTAT CYREG_PRT0_INTSTAT
#define BLUE__MASK 0x08u
#define BLUE__PA__CFG0 CYREG_UDB_PA0_CFG0
#define BLUE__PA__CFG1 CYREG_UDB_PA0_CFG1
#define BLUE__PA__CFG10 CYREG_UDB_PA0_CFG10
#define BLUE__PA__CFG11 CYREG_UDB_PA0_CFG11
#define BLUE__PA__CFG12 CYREG_UDB_PA0_CFG12
#define BLUE__PA__CFG13 CYREG_UDB_PA0_CFG13
#define BLUE__PA__CFG14 CYREG_UDB_PA0_CFG14
#define BLUE__PA__CFG2 CYREG_UDB_PA0_CFG2
#define BLUE__PA__CFG3 CYREG_UDB_PA0_CFG3
#define BLUE__PA__CFG4 CYREG_UDB_PA0_CFG4
#define BLUE__PA__CFG5 CYREG_UDB_PA0_CFG5
#define BLUE__PA__CFG6 CYREG_UDB_PA0_CFG6
#define BLUE__PA__CFG7 CYREG_UDB_PA0_CFG7
#define BLUE__PA__CFG8 CYREG_UDB_PA0_CFG8
#define BLUE__PA__CFG9 CYREG_UDB_PA0_CFG9
#define BLUE__PC CYREG_PRT0_PC
#define BLUE__PC2 CYREG_PRT0_PC2
#define BLUE__PORT 0u
#define BLUE__PS CYREG_PRT0_PS
#define BLUE__SHIFT 3u

/* GREEN */
#define GREEN__0__DM__MASK 0x1C0u
#define GREEN__0__DM__SHIFT 6u
#define GREEN__0__DR CYREG_PRT0_DR
#define GREEN__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define GREEN__0__HSIOM_MASK 0x00000F00u
#define GREEN__0__HSIOM_SHIFT 8u
#define GREEN__0__INTCFG CYREG_PRT0_INTCFG
#define GREEN__0__INTSTAT CYREG_PRT0_INTSTAT
#define GREEN__0__MASK 0x04u
#define GREEN__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define GREEN__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define GREEN__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define GREEN__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define GREEN__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define GREEN__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define GREEN__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define GREEN__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define GREEN__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define GREEN__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define GREEN__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define GREEN__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define GREEN__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define GREEN__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define GREEN__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define GREEN__0__PC CYREG_PRT0_PC
#define GREEN__0__PC2 CYREG_PRT0_PC2
#define GREEN__0__PORT 0u
#define GREEN__0__PS CYREG_PRT0_PS
#define GREEN__0__SHIFT 2u
#define GREEN__DR CYREG_PRT0_DR
#define GREEN__INTCFG CYREG_PRT0_INTCFG
#define GREEN__INTSTAT CYREG_PRT0_INTSTAT
#define GREEN__MASK 0x04u
#define GREEN__PA__CFG0 CYREG_UDB_PA0_CFG0
#define GREEN__PA__CFG1 CYREG_UDB_PA0_CFG1
#define GREEN__PA__CFG10 CYREG_UDB_PA0_CFG10
#define GREEN__PA__CFG11 CYREG_UDB_PA0_CFG11
#define GREEN__PA__CFG12 CYREG_UDB_PA0_CFG12
#define GREEN__PA__CFG13 CYREG_UDB_PA0_CFG13
#define GREEN__PA__CFG14 CYREG_UDB_PA0_CFG14
#define GREEN__PA__CFG2 CYREG_UDB_PA0_CFG2
#define GREEN__PA__CFG3 CYREG_UDB_PA0_CFG3
#define GREEN__PA__CFG4 CYREG_UDB_PA0_CFG4
#define GREEN__PA__CFG5 CYREG_UDB_PA0_CFG5
#define GREEN__PA__CFG6 CYREG_UDB_PA0_CFG6
#define GREEN__PA__CFG7 CYREG_UDB_PA0_CFG7
#define GREEN__PA__CFG8 CYREG_UDB_PA0_CFG8
#define GREEN__PA__CFG9 CYREG_UDB_PA0_CFG9
#define GREEN__PC CYREG_PRT0_PC
#define GREEN__PC2 CYREG_PRT0_PC2
#define GREEN__PORT 0u
#define GREEN__PS CYREG_PRT0_PS
#define GREEN__SHIFT 2u

/* isr_1 */
#define isr_1__INTC_CLR_EN_REG CYREG_CM0_ICER
#define isr_1__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define isr_1__INTC_MASK 0x01u
#define isr_1__INTC_NUMBER 0u
#define isr_1__INTC_PRIOR_MASK 0xC0u
#define isr_1__INTC_PRIOR_NUM 3u
#define isr_1__INTC_PRIOR_REG CYREG_CM0_IPR0
#define isr_1__INTC_SET_EN_REG CYREG_CM0_ISER
#define isr_1__INTC_SET_PD_REG CYREG_CM0_ISPR

/* UART_1 */
#define UART_1_rx__0__DM__MASK 0x7000u
#define UART_1_rx__0__DM__SHIFT 12u
#define UART_1_rx__0__DR CYREG_PRT0_DR
#define UART_1_rx__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define UART_1_rx__0__HSIOM_GPIO 0u
#define UART_1_rx__0__HSIOM_I2C 14u
#define UART_1_rx__0__HSIOM_I2C_SCL 14u
#define UART_1_rx__0__HSIOM_MASK 0x000F0000u
#define UART_1_rx__0__HSIOM_SHIFT 16u
#define UART_1_rx__0__HSIOM_SPI 15u
#define UART_1_rx__0__HSIOM_SPI_MOSI 15u
#define UART_1_rx__0__HSIOM_UART 9u
#define UART_1_rx__0__HSIOM_UART_RX 9u
#define UART_1_rx__0__INTCFG CYREG_PRT0_INTCFG
#define UART_1_rx__0__INTSTAT CYREG_PRT0_INTSTAT
#define UART_1_rx__0__MASK 0x10u
#define UART_1_rx__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define UART_1_rx__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define UART_1_rx__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define UART_1_rx__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define UART_1_rx__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define UART_1_rx__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define UART_1_rx__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define UART_1_rx__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define UART_1_rx__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define UART_1_rx__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define UART_1_rx__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define UART_1_rx__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define UART_1_rx__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define UART_1_rx__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define UART_1_rx__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define UART_1_rx__0__PC CYREG_PRT0_PC
#define UART_1_rx__0__PC2 CYREG_PRT0_PC2
#define UART_1_rx__0__PORT 0u
#define UART_1_rx__0__PS CYREG_PRT0_PS
#define UART_1_rx__0__SHIFT 4u
#define UART_1_rx__DR CYREG_PRT0_DR
#define UART_1_rx__INTCFG CYREG_PRT0_INTCFG
#define UART_1_rx__INTSTAT CYREG_PRT0_INTSTAT
#define UART_1_rx__MASK 0x10u
#define UART_1_rx__PA__CFG0 CYREG_UDB_PA0_CFG0
#define UART_1_rx__PA__CFG1 CYREG_UDB_PA0_CFG1
#define UART_1_rx__PA__CFG10 CYREG_UDB_PA0_CFG10
#define UART_1_rx__PA__CFG11 CYREG_UDB_PA0_CFG11
#define UART_1_rx__PA__CFG12 CYREG_UDB_PA0_CFG12
#define UART_1_rx__PA__CFG13 CYREG_UDB_PA0_CFG13
#define UART_1_rx__PA__CFG14 CYREG_UDB_PA0_CFG14
#define UART_1_rx__PA__CFG2 CYREG_UDB_PA0_CFG2
#define UART_1_rx__PA__CFG3 CYREG_UDB_PA0_CFG3
#define UART_1_rx__PA__CFG4 CYREG_UDB_PA0_CFG4
#define UART_1_rx__PA__CFG5 CYREG_UDB_PA0_CFG5
#define UART_1_rx__PA__CFG6 CYREG_UDB_PA0_CFG6
#define UART_1_rx__PA__CFG7 CYREG_UDB_PA0_CFG7
#define UART_1_rx__PA__CFG8 CYREG_UDB_PA0_CFG8
#define UART_1_rx__PA__CFG9 CYREG_UDB_PA0_CFG9
#define UART_1_rx__PC CYREG_PRT0_PC
#define UART_1_rx__PC2 CYREG_PRT0_PC2
#define UART_1_rx__PORT 0u
#define UART_1_rx__PS CYREG_PRT0_PS
#define UART_1_rx__SHIFT 4u
#define UART_1_SCB__BIST_CONTROL CYREG_SCB1_BIST_CONTROL
#define UART_1_SCB__BIST_DATA CYREG_SCB1_BIST_DATA
#define UART_1_SCB__CTRL CYREG_SCB1_CTRL
#define UART_1_SCB__EZ_DATA00 CYREG_SCB1_EZ_DATA00
#define UART_1_SCB__EZ_DATA01 CYREG_SCB1_EZ_DATA01
#define UART_1_SCB__EZ_DATA02 CYREG_SCB1_EZ_DATA02
#define UART_1_SCB__EZ_DATA03 CYREG_SCB1_EZ_DATA03
#define UART_1_SCB__EZ_DATA04 CYREG_SCB1_EZ_DATA04
#define UART_1_SCB__EZ_DATA05 CYREG_SCB1_EZ_DATA05
#define UART_1_SCB__EZ_DATA06 CYREG_SCB1_EZ_DATA06
#define UART_1_SCB__EZ_DATA07 CYREG_SCB1_EZ_DATA07
#define UART_1_SCB__EZ_DATA08 CYREG_SCB1_EZ_DATA08
#define UART_1_SCB__EZ_DATA09 CYREG_SCB1_EZ_DATA09
#define UART_1_SCB__EZ_DATA10 CYREG_SCB1_EZ_DATA10
#define UART_1_SCB__EZ_DATA11 CYREG_SCB1_EZ_DATA11
#define UART_1_SCB__EZ_DATA12 CYREG_SCB1_EZ_DATA12
#define UART_1_SCB__EZ_DATA13 CYREG_SCB1_EZ_DATA13
#define UART_1_SCB__EZ_DATA14 CYREG_SCB1_EZ_DATA14
#define UART_1_SCB__EZ_DATA15 CYREG_SCB1_EZ_DATA15
#define UART_1_SCB__EZ_DATA16 CYREG_SCB1_EZ_DATA16
#define UART_1_SCB__EZ_DATA17 CYREG_SCB1_EZ_DATA17
#define UART_1_SCB__EZ_DATA18 CYREG_SCB1_EZ_DATA18
#define UART_1_SCB__EZ_DATA19 CYREG_SCB1_EZ_DATA19
#define UART_1_SCB__EZ_DATA20 CYREG_SCB1_EZ_DATA20
#define UART_1_SCB__EZ_DATA21 CYREG_SCB1_EZ_DATA21
#define UART_1_SCB__EZ_DATA22 CYREG_SCB1_EZ_DATA22
#define UART_1_SCB__EZ_DATA23 CYREG_SCB1_EZ_DATA23
#define UART_1_SCB__EZ_DATA24 CYREG_SCB1_EZ_DATA24
#define UART_1_SCB__EZ_DATA25 CYREG_SCB1_EZ_DATA25
#define UART_1_SCB__EZ_DATA26 CYREG_SCB1_EZ_DATA26
#define UART_1_SCB__EZ_DATA27 CYREG_SCB1_EZ_DATA27
#define UART_1_SCB__EZ_DATA28 CYREG_SCB1_EZ_DATA28
#define UART_1_SCB__EZ_DATA29 CYREG_SCB1_EZ_DATA29
#define UART_1_SCB__EZ_DATA30 CYREG_SCB1_EZ_DATA30
#define UART_1_SCB__EZ_DATA31 CYREG_SCB1_EZ_DATA31
#define UART_1_SCB__I2C_CFG CYREG_SCB1_I2C_CFG
#define UART_1_SCB__I2C_CTRL CYREG_SCB1_I2C_CTRL
#define UART_1_SCB__I2C_M_CMD CYREG_SCB1_I2C_M_CMD
#define UART_1_SCB__I2C_S_CMD CYREG_SCB1_I2C_S_CMD
#define UART_1_SCB__I2C_STATUS CYREG_SCB1_I2C_STATUS
#define UART_1_SCB__INTR_CAUSE CYREG_SCB1_INTR_CAUSE
#define UART_1_SCB__INTR_I2C_EC CYREG_SCB1_INTR_I2C_EC
#define UART_1_SCB__INTR_I2C_EC_MASK CYREG_SCB1_INTR_I2C_EC_MASK
#define UART_1_SCB__INTR_I2C_EC_MASKED CYREG_SCB1_INTR_I2C_EC_MASKED
#define UART_1_SCB__INTR_M CYREG_SCB1_INTR_M
#define UART_1_SCB__INTR_M_MASK CYREG_SCB1_INTR_M_MASK
#define UART_1_SCB__INTR_M_MASKED CYREG_SCB1_INTR_M_MASKED
#define UART_1_SCB__INTR_M_SET CYREG_SCB1_INTR_M_SET
#define UART_1_SCB__INTR_RX CYREG_SCB1_INTR_RX
#define UART_1_SCB__INTR_RX_MASK CYREG_SCB1_INTR_RX_MASK
#define UART_1_SCB__INTR_RX_MASKED CYREG_SCB1_INTR_RX_MASKED
#define UART_1_SCB__INTR_RX_SET CYREG_SCB1_INTR_RX_SET
#define UART_1_SCB__INTR_S CYREG_SCB1_INTR_S
#define UART_1_SCB__INTR_S_MASK CYREG_SCB1_INTR_S_MASK
#define UART_1_SCB__INTR_S_MASKED CYREG_SCB1_INTR_S_MASKED
#define UART_1_SCB__INTR_S_SET CYREG_SCB1_INTR_S_SET
#define UART_1_SCB__INTR_SPI_EC CYREG_SCB1_INTR_SPI_EC
#define UART_1_SCB__INTR_SPI_EC_MASK CYREG_SCB1_INTR_SPI_EC_MASK
#define UART_1_SCB__INTR_SPI_EC_MASKED CYREG_SCB1_INTR_SPI_EC_MASKED
#define UART_1_SCB__INTR_TX CYREG_SCB1_INTR_TX
#define UART_1_SCB__INTR_TX_MASK CYREG_SCB1_INTR_TX_MASK
#define UART_1_SCB__INTR_TX_MASKED CYREG_SCB1_INTR_TX_MASKED
#define UART_1_SCB__INTR_TX_SET CYREG_SCB1_INTR_TX_SET
#define UART_1_SCB__RX_CTRL CYREG_SCB1_RX_CTRL
#define UART_1_SCB__RX_FIFO_CTRL CYREG_SCB1_RX_FIFO_CTRL
#define UART_1_SCB__RX_FIFO_RD CYREG_SCB1_RX_FIFO_RD
#define UART_1_SCB__RX_FIFO_RD_SILENT CYREG_SCB1_RX_FIFO_RD_SILENT
#define UART_1_SCB__RX_FIFO_STATUS CYREG_SCB1_RX_FIFO_STATUS
#define UART_1_SCB__RX_MATCH CYREG_SCB1_RX_MATCH
#define UART_1_SCB__SPI_CTRL CYREG_SCB1_SPI_CTRL
#define UART_1_SCB__SPI_STATUS CYREG_SCB1_SPI_STATUS
#define UART_1_SCB__SS0_POSISTION 0u
#define UART_1_SCB__SS1_POSISTION 1u
#define UART_1_SCB__SS2_POSISTION 2u
#define UART_1_SCB__SS3_POSISTION 3u
#define UART_1_SCB__STATUS CYREG_SCB1_STATUS
#define UART_1_SCB__TX_CTRL CYREG_SCB1_TX_CTRL
#define UART_1_SCB__TX_FIFO_CTRL CYREG_SCB1_TX_FIFO_CTRL
#define UART_1_SCB__TX_FIFO_STATUS CYREG_SCB1_TX_FIFO_STATUS
#define UART_1_SCB__TX_FIFO_WR CYREG_SCB1_TX_FIFO_WR
#define UART_1_SCB__UART_CTRL CYREG_SCB1_UART_CTRL
#define UART_1_SCB__UART_RX_CTRL CYREG_SCB1_UART_RX_CTRL
#define UART_1_SCB__UART_RX_STATUS CYREG_SCB1_UART_RX_STATUS
#define UART_1_SCB__UART_TX_CTRL CYREG_SCB1_UART_TX_CTRL
#define UART_1_SCBCLK__DIVIDER_MASK 0x0000FFFFu
#define UART_1_SCBCLK__ENABLE CYREG_CLK_DIVIDER_A00
#define UART_1_SCBCLK__ENABLE_MASK 0x80000000u
#define UART_1_SCBCLK__MASK 0x80000000u
#define UART_1_SCBCLK__REGISTER CYREG_CLK_DIVIDER_A00
#define UART_1_tx__0__DM__MASK 0x38000u
#define UART_1_tx__0__DM__SHIFT 15u
#define UART_1_tx__0__DR CYREG_PRT0_DR
#define UART_1_tx__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define UART_1_tx__0__HSIOM_GPIO 0u
#define UART_1_tx__0__HSIOM_I2C 14u
#define UART_1_tx__0__HSIOM_I2C_SDA 14u
#define UART_1_tx__0__HSIOM_MASK 0x00F00000u
#define UART_1_tx__0__HSIOM_SHIFT 20u
#define UART_1_tx__0__HSIOM_SPI 15u
#define UART_1_tx__0__HSIOM_SPI_MISO 15u
#define UART_1_tx__0__HSIOM_UART 9u
#define UART_1_tx__0__HSIOM_UART_TX 9u
#define UART_1_tx__0__INTCFG CYREG_PRT0_INTCFG
#define UART_1_tx__0__INTSTAT CYREG_PRT0_INTSTAT
#define UART_1_tx__0__MASK 0x20u
#define UART_1_tx__0__OUT_SEL CYREG_UDB_PA0_CFG10
#define UART_1_tx__0__OUT_SEL_SHIFT 10u
#define UART_1_tx__0__OUT_SEL_VAL -1u
#define UART_1_tx__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define UART_1_tx__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define UART_1_tx__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define UART_1_tx__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define UART_1_tx__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define UART_1_tx__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define UART_1_tx__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define UART_1_tx__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define UART_1_tx__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define UART_1_tx__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define UART_1_tx__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define UART_1_tx__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define UART_1_tx__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define UART_1_tx__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define UART_1_tx__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define UART_1_tx__0__PC CYREG_PRT0_PC
#define UART_1_tx__0__PC2 CYREG_PRT0_PC2
#define UART_1_tx__0__PORT 0u
#define UART_1_tx__0__PS CYREG_PRT0_PS
#define UART_1_tx__0__SHIFT 5u
#define UART_1_tx__DR CYREG_PRT0_DR
#define UART_1_tx__INTCFG CYREG_PRT0_INTCFG
#define UART_1_tx__INTSTAT CYREG_PRT0_INTSTAT
#define UART_1_tx__MASK 0x20u
#define UART_1_tx__PA__CFG0 CYREG_UDB_PA0_CFG0
#define UART_1_tx__PA__CFG1 CYREG_UDB_PA0_CFG1
#define UART_1_tx__PA__CFG10 CYREG_UDB_PA0_CFG10
#define UART_1_tx__PA__CFG11 CYREG_UDB_PA0_CFG11
#define UART_1_tx__PA__CFG12 CYREG_UDB_PA0_CFG12
#define UART_1_tx__PA__CFG13 CYREG_UDB_PA0_CFG13
#define UART_1_tx__PA__CFG14 CYREG_UDB_PA0_CFG14
#define UART_1_tx__PA__CFG2 CYREG_UDB_PA0_CFG2
#define UART_1_tx__PA__CFG3 CYREG_UDB_PA0_CFG3
#define UART_1_tx__PA__CFG4 CYREG_UDB_PA0_CFG4
#define UART_1_tx__PA__CFG5 CYREG_UDB_PA0_CFG5
#define UART_1_tx__PA__CFG6 CYREG_UDB_PA0_CFG6
#define UART_1_tx__PA__CFG7 CYREG_UDB_PA0_CFG7
#define UART_1_tx__PA__CFG8 CYREG_UDB_PA0_CFG8
#define UART_1_tx__PA__CFG9 CYREG_UDB_PA0_CFG9
#define UART_1_tx__PC CYREG_PRT0_PC
#define UART_1_tx__PC2 CYREG_PRT0_PC2
#define UART_1_tx__PORT 0u
#define UART_1_tx__PS CYREG_PRT0_PS
#define UART_1_tx__SHIFT 5u

/* Timer_1 */
#define Timer_1_TimerUDB_rstSts_stsreg__0__MASK 0x01u
#define Timer_1_TimerUDB_rstSts_stsreg__0__POS 0
#define Timer_1_TimerUDB_rstSts_stsreg__2__MASK 0x04u
#define Timer_1_TimerUDB_rstSts_stsreg__2__POS 2
#define Timer_1_TimerUDB_rstSts_stsreg__3__MASK 0x08u
#define Timer_1_TimerUDB_rstSts_stsreg__3__POS 3
#define Timer_1_TimerUDB_rstSts_stsreg__MASK 0x0Du
#define Timer_1_TimerUDB_rstSts_stsreg__MASK_REG CYREG_UDB_W8_MSK_03
#define Timer_1_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_03
#define Timer_1_TimerUDB_rstSts_stsreg__STATUS_REG CYREG_UDB_W8_ST_03
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_UDB_W8_CTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_UDB_W8_CTL_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_UDB_W8_MSK_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG CYREG_UDB_W16_A0_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__16BIT_A1_REG CYREG_UDB_W16_A1_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG CYREG_UDB_W16_D0_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__16BIT_D1_REG CYREG_UDB_W16_D1_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__16BIT_DP_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG CYREG_UDB_W16_F0_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__16BIT_F1_REG CYREG_UDB_W16_F1_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__A0_A1_REG CYREG_UDB_CAT16_A_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__A0_REG CYREG_UDB_W8_A0_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__A1_REG CYREG_UDB_W8_A1_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__D0_D1_REG CYREG_UDB_CAT16_D_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__D0_REG CYREG_UDB_W8_D0_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__D1_REG CYREG_UDB_W8_D1_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__F0_F1_REG CYREG_UDB_CAT16_F_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__F0_REG CYREG_UDB_W8_F0_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__F1_REG CYREG_UDB_W8_F1_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__MSK_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define Timer_1_TimerUDB_sT16_timerdp_u0__PER_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define Timer_1_TimerUDB_sT16_timerdp_u1__A0_A1_REG CYREG_UDB_CAT16_A_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__A0_REG CYREG_UDB_W8_A0_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__A1_REG CYREG_UDB_W8_A1_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__D0_D1_REG CYREG_UDB_CAT16_D_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__D0_REG CYREG_UDB_W8_D0_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__D1_REG CYREG_UDB_W8_D1_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__F0_F1_REG CYREG_UDB_CAT16_F_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__F0_REG CYREG_UDB_W8_F0_03
#define Timer_1_TimerUDB_sT16_timerdp_u1__F1_REG CYREG_UDB_W8_F1_03

/* Miscellaneous */
#define CY_PROJECT_NAME "Kursova_6_Varik"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_Disallowed
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DFT_SELECT_CLK0 1u
#define CYDEV_DFT_SELECT_CLK1 2u
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_IMO_TRIMMED_BY_USB 0u
#define CYDEV_IMO_TRIMMED_BY_WCO 0u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_WDT_GENERATE_ISR 1u
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */