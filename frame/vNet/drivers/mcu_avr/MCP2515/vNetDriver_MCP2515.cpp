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
#include <SPI.h>

#include "GetConfig.h"
#include "vNetDriver_MCP2515.h"

// Set up the CAN interface using the Chip Select pin
// defined in setup
MCP_CAN CAN0(MCP2515_CS);

// Address of this node
uint16_t canAddress=0;

// Receieve buffer
unsigned char rxBuf[8];
unsigned char len = 0;

/**************************************************************************/
/*!
    Init the uIP stack
*/
/**************************************************************************/
void vNet_Init_M6()
{	
	// Initialise the CAN bus driver
	CAN0.begin(MCP2515_BAUD);
}

/**************************************************************************/
/*!
	Set the vNet address 
	
	The CAN bus works in broadcast and has no address check, this method is
	here only for compatiblity with upper vNet layers (that has their own
	addressing).
	
	The address is saved in a local register.  Collision avoidance is
	handled by the CAN protocol.
*/
/**************************************************************************/
void vNet_SetAddress_M6(uint16_t addr)
{
	canAddress = addr;
}

/**************************************************************************/
/*!
	Set the vNet Collision Avoidance Index
	
	This shall be called before the Init and SetAddress, it define the
	collision avoidance index that is used to identify the priority on the
	bus.
*/
/**************************************************************************/
// void vNet_SetCollisionAvoidanceIndex_M5(uint16_t addr, uint16_t submask)
// {
// 	#if(USART_DEBUG)	
// 	USART_LOG("(USART)<CA Index>\r\n");
// 	#endif	
		
// 	caindex = (addr & (~submask));
// }

/**************************************************************************/
/*!
	Send a message via CAN bus
*/
/**************************************************************************/
uint8_t vNet_Send_M6(uint16_t addr, oFrame *frame, uint8_t len)
{
	// INT8U sendMsgBuf(INT32U id, INT8U ext, INT8U len, INT8U *buf)
	CAN0.sendMsgBuf(addr, 0, len, frame);
	oFrame_Reset();
	return 1;
}

/**************************************************************************/
/*!
	Read the incoming data size, use this after vNet_DataAvailable_M5()
*/
/**************************************************************************/
uint8_t vNet_DataSize_M6()
{
	return len;
}

/**************************************************************************/
/*!
	If data are available store in the temporary buffer
*/
/**************************************************************************/
uint8_t vNet_DataAvailable_M6()
{
	return CAN0.checkReceive();		
}

/**************************************************************************/
/*!
	Retrieve the complete vNet frame from the incoming buffer
*/
/**************************************************************************/
uint8_t vNet_RetrieveData_M6(uint8_t *data)
{
	CAN0.readMsgBuf(len, rxBuf);
	memcpy(data, rxBuf, len);
	return len;
}

/**************************************************************************/
/*!
    Get the source address of the most recently received frame
*/
/**************************************************************************/
uint16_t vNet_GetSourceAddress_M6()
{
	return 0;
}