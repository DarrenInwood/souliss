/**************************************************************************
	Souliss - vNet Virtualized Network
    Copyright (C) 2013  Veseo

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
	Originally developed by Dario Di Maio
	
***************************************************************************/
/*!
    \file 
    \ingroup

*/
/**************************************************************************/
#ifndef VNET_MCP2515_H
#define VNET_MCP2515_H

#include "Arduino.h"
#include "src/mcp_can.h"
#include "GetConfig.h"				// need : usartUsrCfg.h


#if(MCP2515_BAUD_5KBPS)
#	define MCP2515_BAUD			CAN_5KBPS		
#elif(MCP2515_BAUD_10KBPS)
#	define MCP2515_BAUD			CAN_10KBPS			
#elif(MCP2515_BAUD_20KBPS)
#   define MCP2515_BAUD         CAN_20KBPS          
#elif(MCP2515_BAUD_31K25BPS)
#   define MCP2515_BAUD         CAN_30K25BPS          
#elif(MCP2515_BAUD_40KBPS)
#   define MCP2515_BAUD         CAN_40KBPS          
#elif(MCP2515_BAUD_50KBPS)
#   define MCP2515_BAUD         CAN_50KBPS          
#elif(MCP2515_BAUD_80KBPS)
#   define MCP2515_BAUD         CAN_80KBPS          
#elif(MCP2515_BAUD_100KBPS)
#   define MCP2515_BAUD         CAN_100KBPS          
#elif(MCP2515_BAUD_125KBPS)
#   define MCP2515_BAUD         CAN_125KBPS          
#elif(MCP2515_BAUD_200KBPS)
#   define MCP2515_BAUD         CAN_200KBPS          
#elif(MCP2515_BAUD_250KBPS)
#   define MCP2515_BAUD         CAN_250KBPS          
#elif(MCP2515_BAUD_500KBPS)
#   define MCP2515_BAUD         CAN_500KBPS          
#elif(MCP2515_BAUD_1000KBPS)
#   define MCP2515_BAUD         CAN_1000KBPS          
#else
#	define MCP2515_BAUD			CAN_100KBPS
#endif

#ifndef MCP2515_CS
#define MCP2515_CS 10
#endif

void vNet_Init_M6();
void vNet_SetAddress_M6(uint16_t addr);
uint8_t vNet_Send_M6(uint16_t addr, oFrame *frame, uint8_t len);
uint8_t vNet_DataAvailable_M6();
uint8_t vNet_DataSize_M6();
uint8_t vNet_RetrieveData_M6(uint8_t *data);
uint16_t vNet_GetSourceAddress_M6();

#endif