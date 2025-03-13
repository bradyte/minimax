/*
# Name: TBrady2
# Date: 1/31/2025
# Version: 1.6.0
#
# I2C Address(0x), Register Address(0x), Register Value(0x), Read Modify Write(0x)
#
# THIS DATA FILE, AND ALL INFORMATION CONTAINED THEREIN,
# IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
# THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
# PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL ANALOG DEVICES, INC. BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE DATA FILE,
# THE INFORMATION CONTAINED THEREIN, OR ITS USE FOR ANY PURPOSE.
# BEFORE USING THIS DATA FILE IN ANY APPLICATION FOR PRODUCTION OR DEPLOYMENT,
# THE CUSTOMER IS SOLELY RESPONSIBLE FOR TESTING AND VERIFYING
# THE CONTENT OF THIS DATA FILE IN CONNECTION WITH THEIR PRODUCTS AND SYSTEM(S).
# ---------------------------------------------------------------------------------
#
#            _____ _____  
#      /\   |  __ \_   _| 
#     /  \  | |  | || |   
#    / /\ \ | |  | || |   
#   / ____ \| |__| || |_  
#  /_/    \_\_____/_____| 
#
# ---------------------------------------------------------------------------------
*/
/*
# This script is validated on: 
# MAX96717
# MAX96714
# Please refer to the Errata sheet for each device.
# ---------------------------------------------------------------------------------
*/
//  
// CSIConfigurationTool
//  
// GMSL-A / Serializer: MAX96717 (Tunnel Mode) / Mode: 1x4 / Device Address: 0x80 / Multiple-VC Case: Single VC / Pipe Sharing: Separate Pipes
// PipeZ:
// Input Stream: VC0 RAW10 PortB (D-PHY)

// Deserializer: MAX96714 / Mode: 1x4 / Device Address: 0x50
// PipeY:
// GMSL-A Input Stream: VC0 RAW10 PortB - Output Stream: VC0 RAW10 PortA (D-PHY)

0x04,0x50,0x03,0x13,0x00, // BACKTOP : BACKTOP12 | CSI_OUT_EN (CSI_OUT_EN): CSI output disabled
// Video Transmit Configuration for Serializer(s)
0x04,0x80,0x00,0x02,0x03, // DEV : REG2 | VID_TX_EN_Z (VID_TX_EN_Z): Disabled
//  
// INSTRUCTIONS FOR GMSL-A SERIALIZER MAX96717
//  
// MIPI D-PHY Configuration
0x04,0x80,0x03,0x30,0x00, // MIPI_RX : MIPI_RX0 | (Default) RSVD (Port Configuration): 1x4
0x04,0x80,0x03,0x83,0x80, // MIPI_RX_EXT : EXT11 | (Default) Tun_Mode (Tunnel Mode): Enabled
0x04,0x80,0x03,0x31,0x10, // MIPI_RX : MIPI_RX1 | ctrl1_num_lanes (Port B - Lane Count): 2
0x04,0x80,0x03,0x32,0x40, // MIPI_RX : MIPI_RX2 | phy1_lane_map (Lane Map - PHY1 D0): Lane 0 | phy1_lane_map (Lane Map - PHY1 D1): Lane 1
0x04,0x80,0x03,0x33,0x0E, // MIPI_RX : MIPI_RX3 | phy2_lane_map (Lane Map - PHY2 D0): Lane 2 | phy2_lane_map (Lane Map - PHY2 D1): Lane 3
0x04,0x80,0x03,0x34,0x30,  // MIPI_RX : MIPI_RX4 | phy1_pol_map (Polarity - PHY1 Lane 0): Inverse | phy1_pol_map (Polarity - PHY1 Lane 1): Inverse
0x04,0x80,0x03,0x35,0x07, // MIPI_RX : MIPI_RX5 | phy2_pol_map (Polarity - PHY2 Lane 0): Inverse | phy2_pol_map (Polarity - PHY2 Lane 1): Inverse | phy2_pol_map (Polarity - PHY2 Clock Lane): Inverse
// Controller to Pipe Mapping Configuration
0x04,0x80,0x03,0x08,0x64, // FRONTTOP : FRONTTOP_0 | (Default) RSVD (CLK_SELZ): Port B | (Default) START_PORTB (START_PORTB): Enabled
0x04,0x80,0x03,0x11,0x40, // FRONTTOP : FRONTTOP_9 | (Default) START_PORTBZ (START_PORTBZ): Start Video
// Pipe Configuration
0x04,0x80,0x00,0x5B,0x00, // CFGV__VIDEO_Z : TX3 | TX_STR_SEL (TX_STR_SEL Pipe Z): 0x0
//  
// INSTRUCTIONS FOR DESERIALIZER MAX96714
//  
// Video Pipes And Routing Configuration
0x04,0x50,0x01,0x61,0x00, // VIDEO_PIPE_SEL : VIDEO_PIPE_SEL | VIDEO_PIPE_SEL_Y (STR_SELY): 0x0 | (Default) VIDEO_PIPE_SEL_Y (STR_SELY): 0x0 | (Default) VIDEO_PIPE_SEL_Y (STR_SELY): 0x0 | (Default) VIDEO_PIPE_SEL_Y (STR_SELY): 0x0
// MIPI D-PHY Configuration
0x04,0x50,0x04,0x4A,0x50, // MIPI_TX__1 : MIPI_TX10 | CSI2_LANE_CNT (Port A - Lane Count): 2
0x04,0x50,0x03,0x33,0xE4, // MIPI_PHY : MIPI_PHY3 | (Default) phy0_lane_map (Lane Map - PHY0 D0): Lane 0 | (Default) phy0_lane_map (Lane Map - PHY0 D1): Lane 1 | (Default) phy1_lane_map (Lane Map - PHY1 D0): Lane 2 | (Default) phy1_lane_map (Lane Map - PHY1 D1): Lane 3
0x04,0x50,0x03,0x35,0x00, // MIPI_PHY : MIPI_PHY5 | (Default) phy0_pol_map (Polarity - PHY0 Lane 0): Normal | (Default) phy0_pol_map (Polarity - PHY0 Lane 1): Normal | (Default) phy1_pol_map (Polarity - PHY1 Lane 0): Normal | (Default) phy1_pol_map (Polarity - PHY1 Lane 1): Normal | (Default) phy1_pol_map (Polarity - PHY1 Clock Lane): Normal
// This is to set predefined (coarse) CSI output frequency
// CSI Phy 1 is 1000 Mbps/lane.
0x04,0x50,0x1D,0x00,0xF4,
0x04,0x50,0x03,0x20,0x2A,
0x04,0x50,0x1D,0x00,0xF5,
// Tunnel Mode Configuration
0x04,0x50,0x04,0x74,0x09, // MIPI_TX__1 : MIPI_TX52 | TUN_EN (Pipe Y Tunnel Mode): Enabled
0x04,0x50,0x03,0x13,0x02, // BACKTOP : BACKTOP12 | CSI_OUT_EN (CSI_OUT_EN): CSI output enabled
// Video Transmit Configuration for Serializer(s)
0x04,0x80,0x00,0x02,0x43, // DEV : REG2 | VID_TX_EN_Z (VID_TX_EN_Z): Enabled
