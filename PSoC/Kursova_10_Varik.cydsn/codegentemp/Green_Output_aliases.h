/*******************************************************************************
* File Name: Green_Output.h  
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

#if !defined(CY_PINS_Green_Output_ALIASES_H) /* Pins Green_Output_ALIASES_H */
#define CY_PINS_Green_Output_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Green_Output_0			(Green_Output__0__PC)
#define Green_Output_0_PS		(Green_Output__0__PS)
#define Green_Output_0_PC		(Green_Output__0__PC)
#define Green_Output_0_DR		(Green_Output__0__DR)
#define Green_Output_0_SHIFT	(Green_Output__0__SHIFT)
#define Green_Output_0_INTR	((uint16)((uint16)0x0003u << (Green_Output__0__SHIFT*2u)))

#define Green_Output_INTR_ALL	 ((uint16)(Green_Output_0_INTR))


#endif /* End Pins Green_Output_ALIASES_H */


/* [] END OF FILE */
