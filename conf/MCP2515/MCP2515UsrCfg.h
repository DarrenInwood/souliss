/**************************************************************************
	Souliss - vNet Virtualized Network
    Copyright (C) 2014  Veseo

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
#ifndef MCP2515_CFG_H
#define MCP2515_CFG_H

/**************************************************************************/
/*!
	Select CAN BUS Baud Rate for wire communication, lower baud rate help over
	longer distances rather higher ones help in lower collision rate.

	Never select more than one driver per time
	        
		Value       Media
        0x0         Disable 
        0x1         Enable
	
		MCP2515_BAUD_5KBPS   
		MCP2515_BAUD_10KBPS  
		MCP2515_BAUD_20KBPS  
		MCP2515_BAUD_31K25BPS
		MCP2515_BAUD_40KBPS  
		MCP2515_BAUD_50KBPS  
		MCP2515_BAUD_80KBPS  
		MCP2515_BAUD_100KBPS (Default)
		MCP2515_BAUD_125KBPS 
		MCP2515_BAUD_200KBPS 
		MCP2515_BAUD_250KBPS 
		MCP2515_BAUD_500KBPS 
		MCP2515_BAUD_1000KBPS

*/
/**************************************************************************/
#ifndef MCP2515_DRIVER_INSKETCH
#define MCP2515_BAUD_5KBPS    0
#define MCP2515_BAUD_10KBPS   0
#define MCP2515_BAUD_20KBPS   0
#define MCP2515_BAUD_31K25BPS 0
#define MCP2515_BAUD_40KBPS   0
#define MCP2515_BAUD_50KBPS   0
#define MCP2515_BAUD_80KBPS   0
#define MCP2515_BAUD_100KBPS  1
#define MCP2515_BAUD_125KBPS  0
#define MCP2515_BAUD_200KBPS  0
#define MCP2515_BAUD_250KBPS  0
#define MCP2515_BAUD_500KBPS  0
#define MCP2515_BAUD_1000KBPS 0
#endif

/**************************************************************************/
/*!
	Select the SPI Chip Select pin for the MCP2515 transceiver
	        
		Value       Media
        0x10        Pin 10 (Default)
	
		MCP2515_CS		-  The pin connected the the MCP2515's Chip Select input
*/
/**************************************************************************/
#ifndef MCP2515_DRIVER_INSKETCH
#define MCP2515_CS			10
#endif

#endif
