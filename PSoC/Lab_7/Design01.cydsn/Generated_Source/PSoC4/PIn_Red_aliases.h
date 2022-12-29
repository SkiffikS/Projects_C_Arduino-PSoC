/*******************************************************************************
* File Name: PIn_Red.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PIn_Red_ALIASES_H) /* Pins PIn_Red_ALIASES_H */
#define CY_PINS_PIn_Red_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PIn_Red_0			(PIn_Red__0__PC)
#define PIn_Red_0_PS		(PIn_Red__0__PS)
#define PIn_Red_0_PC		(PIn_Red__0__PC)
#define PIn_Red_0_DR		(PIn_Red__0__DR)
#define PIn_Red_0_SHIFT	(PIn_Red__0__SHIFT)
#define PIn_Red_0_INTR	((uint16)((uint16)0x0003u << (PIn_Red__0__SHIFT*2u)))

#define PIn_Red_INTR_ALL	 ((uint16)(PIn_Red_0_INTR))


#endif /* End Pins PIn_Red_ALIASES_H */


/* [] END OF FILE */
