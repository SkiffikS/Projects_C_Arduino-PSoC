/*******************************************************************************
* File Name: PIn_Red.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PIn_Red.h"

static PIn_Red_BACKUP_STRUCT  PIn_Red_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PIn_Red_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet PIn_Red_SUT.c usage_PIn_Red_Sleep_Wakeup
*******************************************************************************/
void PIn_Red_Sleep(void)
{
    #if defined(PIn_Red__PC)
        PIn_Red_backup.pcState = PIn_Red_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PIn_Red_backup.usbState = PIn_Red_CR1_REG;
            PIn_Red_USB_POWER_REG |= PIn_Red_USBIO_ENTER_SLEEP;
            PIn_Red_CR1_REG &= PIn_Red_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PIn_Red__SIO)
        PIn_Red_backup.sioState = PIn_Red_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PIn_Red_SIO_REG &= (uint32)(~PIn_Red_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PIn_Red_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to PIn_Red_Sleep() for an example usage.
*******************************************************************************/
void PIn_Red_Wakeup(void)
{
    #if defined(PIn_Red__PC)
        PIn_Red_PC = PIn_Red_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PIn_Red_USB_POWER_REG &= PIn_Red_USBIO_EXIT_SLEEP_PH1;
            PIn_Red_CR1_REG = PIn_Red_backup.usbState;
            PIn_Red_USB_POWER_REG &= PIn_Red_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PIn_Red__SIO)
        PIn_Red_SIO_REG = PIn_Red_backup.sioState;
    #endif
}


/* [] END OF FILE */
