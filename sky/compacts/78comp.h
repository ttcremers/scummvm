/* ScummVM - Scumm Interpreter
 * Copyright (C) 2003 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$ 
 *
 */

#ifndef SKY78COMP_H
#define SKY78COMP_H




namespace SkyCompact {

uint16 sc78_ledge_table[] = {
	ID_SC78_LEDGE,
	RETURN_OK,
	ID_SC78_PIPE,
	GT_SC78_PIPE,
	ID_SC78_BIG_DOOR,
	GT_SC78_BIG_DOOR,
	0,
	SC78_BIG_DOOR_WALK_ON,
	ID_SC78_EXIT,
	GT_SC78_PIPE,
	ID_SC78_SUPPORT,
	GT_SC78_PIPE,
	65535,
};

Compact sc78_ledge = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	78,	// screen
	0,	// place
	sc78_ledge_table,	// getToTable
	185,	// xcood
	245,	// ycood
	0,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	282-185,	// mouseSize_x
	257-245,	// mouseSize_y
	FLOOR_ACTION,	// actionScript
};

Compact sc78_big_door = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	78,	// screen
	0,	// place
	0,	// getToTable
	166,	// xcood
	177,	// ycood
	0,	// frame
	1+T7,	// cursorText
	STD_EXIT_LEFT_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	186-166,	// mouseSize_x
	256-177,	// mouseSize_y
	SC78_BIG_DOOR_ACTION,	// actionScript
};

uint16 sc78_climb_up[] = {
	86*64,
	284,
	226,
	0,
	284,
	226,
	1,
	276,
	227,
	2,
	276,
	227,
	2,
	269,
	234,
	3,
	269,
	234,
	3,
	269,
	234,
	4,
	269,
	234,
	4,
	264,
	235,
	5,
	264,
	235,
	5,
	259,
	234,
	6,
	259,
	234,
	6,
	260,
	234,
	7,
	260,
	234,
	7,
	262,
	225,
	8,
	262,
	225,
	8,
	260,
	223,
	9,
	260,
	223,
	9,
	254,
	217,
	10,
	254,
	217,
	10,
	253,
	210,
	11,
	253,
	210,
	11,
	255,
	206,
	12,
	255,
	206,
	12,
	258,
	203,
	13,
	258,
	203,
	13,
	260,
	202,
	1,
	260,
	202,
	1,
	0,
};

uint16 sc78_logic_list[] = {
	ID_FOSTER,
	ID_KEN,
	ID_SC67_PULSE1,
	0XFFFF,
	ID_STD_MENU_LOGIC,
};

uint16 reset_79_78[] = {
	C_SCREEN,
	78,
	C_PLACE,
	ID_SC78_PIPE,
	C_XCOOD,
	OFF_RIGHT,
	C_YCOOD,
	272,
	65535,
};

uint16 sc78_mouse_list[] = {
	ID_SC78_EXIT,
	ID_SC78_BIG_DOOR,
	ID_SC78_SUPPORT,
	ID_SC78_LEDGE,
	ID_SC78_PIPE,
	0XFFFF,
	ID_TEXT_MOUSE,
};

Compact sc78_support = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	78,	// screen
	0,	// place
	0,	// getToTable
	231,	// xcood
	262,	// ycood
	0,	// frame
	20573,	// cursorText
	STD_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	65530,	// mouseRel_y
	405-386,	// mouseSize_x
	308-262,	// mouseSize_y
	SC78_SUPPORT_ACTION,	// actionScript
};

uint16 sc781_palette[] = {
	0,
	768,
	1026,
	517,
	1026,
	1028,
	518,
	2052,
	514,
	1030,
	1283,
	1540,
	521,
	1796,
	1284,
	1033,
	1539,
	1286,
	1033,
	2822,
	771,
	1544,
	1540,
	2054,
	1035,
	3333,
	1027,
	1292,
	2052,
	1798,
	1546,
	1797,
	1543,
	1037,
	2822,
	1797,
	1800,
	3593,
	1029,
	2057,
	2566,
	2055,
	1804,
	2310,
	2057,
	1296,
	3334,
	2054,
	1550,
	2310,
	2825,
	2316,
	2823,
	2313,
	1553,
	3848,
	2055,
	1556,
	4357,
	1543,
	2571,
	3595,
	2314,
	2828,
	2825,
	3339,
	3084,
	5131,
	1800,
	1558,
	5639,
	1544,
	2322,
	3595,
	3340,
	3340,
	6158,
	1799,
	2070,
	6665,
	1542,
	1565,
	4870,
	2571,
	3090,
	3597,
	3598,
	2330,
	4617,
	3598,
	2332,
	6154,
	2827,
	2589,
	3848,
	4624,
	3351,
	8716,
	1800,
	3860,
	6413,
	2829,
	3353,
	4366,
	4625,
	3861,
	8719,
	2313,
	2340,
	5639,
	4368,
	2847,
	6923,
	3598,
	2851,
	7945,
	3085,
	4883,
	8468,
	3341,
	4632,
	9488,
	2572,
	3869,
	6671,
	4370,
	4633,
	9747,
	3085,
	4382,
	8720,
	3343,
	3115,
	9225,
	3600,
	4639,
	10770,
	3086,
	4135,
	7439,
	5397,
	4137,
	7950,
	5140,
	6169,
	9497,
	4372,
	5413,
	8211,
	5911,
	6178,
	10007,
	5142,
	5422,
	8465,
	7194,
	5929,
	9493,
	6682,
	7458,
	8223,
	8480,
	7211,
	8733,
	8482,
	8230,
	8993,
	8994,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	14336,
	13364,
	11569,
	9261,
	8481,
	6687,
	6681,
	4626,
	2578,
	1803,
	770,
	519,
	13571,
	9517,
	9778,
	11805,
	5151,
	5926,
	8205,
	1808,
	2586,
	11267,
	2056,
	8210,
	7441,
	6954,
	9494,
	4119,
	3866,
	4864,
	13316,
	13364,
	11563,
	8751,
	9506,
	10024,
	8242,
	10527,
	6174,
	5927,
	7698,
	3600,
	2325,
	2308,
	11573,
	12837,
	7462,
	7982,
	9748,
	3351,
	4128,
	6663,
	778,
	9533,
	13100,
	9244,
	5162,
	8476,
	5390,
	2072,
	3855,
	2308,
	2865,
	9995,
	1285,
	285,
	4865,
	0,
	11573,
	12837,
	7462,
	0,
	16128,
	0,
	16191,
	63,
	0,
	0,
	0,
	0,
	0,
	13824,
	13878,
	12077,
	8241,
	10527,
	5917,
	5925,
	7698,
	2865,
	9995,
	1285,
	285,
	16129,
	16191,
};

uint16 reset_77_78[] = {
	C_SCREEN,
	78,
	C_PLACE,
	ID_SC78_LEDGE,
	C_XCOOD,
	152,
	C_YCOOD,
	248,
	65535,
};

uint16 sc78_pipe_table[] = {
	ID_SC78_PIPE,
	RETURN_OK,
	ID_SC78_LEDGE,
	GT_SC78_LEDGE,
	ID_SC78_BIG_DOOR,
	GT_SC78_LEDGE,
	ID_SC78_EXIT,
	GT_SC78_EXIT,
	1,
	SC78_EXIT_WALK_ON,
	ID_SC78_SUPPORT,
	GT_SC78_SUPPORT,
	65535,
};

uint16 sc78_chip_list[] = {
	IT_SC78_LAYER_0+DISK_10,
	IT_SC78_LAYER_1+DISK_10,
	IT_SC78_GRID_1+DISK_10,
	IT_SC78_JUMP_DOWN+DISK_10,
	IT_SC78_CLIMB_UP+DISK_10,
	0,
};

Compact sc78_exit = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	78,	// screen
	0,	// place
	0,	// getToTable
	420,	// xcood
	210,	// ycood
	0,	// frame
	1+T7,	// cursorText
	STD_EXIT_RIGHT_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	447-420,	// mouseSize_x
	280-210,	// mouseSize_y
	SC78_EXIT_ACTION,	// actionScript
};

uint16 sc78_jump_down[] = {
	85*64,
	258,
	202,
	0,
	257,
	206,
	1,
	257,
	206,
	1,
	260,
	210,
	2,
	261,
	206,
	3,
	275,
	205,
	4,
	300,
	211,
	5,
	311,
	224,
	6,
	329,
	239,
	7,
	332,
	251,
	8,
	332,
	251,
	8,
	332,
	252,
	9,
	332,
	252,
	9,
	329,
	248,
	10,
	330,
	239,
	11,
	330,
	230,
	12,
	330,
	226,
	13,
	330,
	226,
	0,
	0,
};

Compact sc78_pipe = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	78,	// screen
	0,	// place
	sc78_pipe_table,	// getToTable
	278,	// xcood
	270,	// ycood
	0,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	422-278,	// mouseSize_x
	281-270,	// mouseSize_y
	FLOOR_ACTION,	// actionScript
};

uint32 grid78[0];

uint16 sc78_palette[] = {
	0,
	768,
	1026,
	517,
	1026,
	1028,
	518,
	2052,
	514,
	1030,
	1283,
	1540,
	521,
	1796,
	1284,
	1033,
	1539,
	1286,
	1033,
	2822,
	771,
	1544,
	1540,
	2054,
	1035,
	3333,
	1027,
	1292,
	2052,
	1798,
	1546,
	1797,
	1543,
	1037,
	2822,
	1797,
	1800,
	3593,
	1029,
	2057,
	2566,
	2055,
	1804,
	2310,
	2057,
	1296,
	3334,
	2054,
	1550,
	2310,
	2825,
	2316,
	2823,
	2313,
	1553,
	3848,
	2055,
	1556,
	4357,
	1543,
	2571,
	3595,
	2314,
	2828,
	2825,
	3339,
	3084,
	5131,
	1800,
	1558,
	5639,
	1544,
	2322,
	3595,
	3340,
	3340,
	6158,
	1799,
	2070,
	6665,
	1542,
	1565,
	4870,
	2571,
	3090,
	3597,
	3598,
	2330,
	4617,
	3598,
	2332,
	6154,
	2827,
	2589,
	3848,
	4624,
	3351,
	8716,
	1800,
	3860,
	6413,
	2829,
	3353,
	4366,
	4625,
	3861,
	8719,
	2313,
	2340,
	5639,
	4368,
	2847,
	6923,
	3598,
	2851,
	7945,
	3085,
	4883,
	8468,
	3341,
	4632,
	9488,
	2572,
	3869,
	6671,
	4370,
	4633,
	9747,
	3085,
	4382,
	8720,
	3343,
	3115,
	9225,
	3600,
	4639,
	10770,
	3086,
	4135,
	7439,
	5397,
	4137,
	7950,
	5140,
	6169,
	9497,
	4372,
	5413,
	8211,
	5911,
	6178,
	10007,
	5142,
	5422,
	8465,
	7194,
	5929,
	9493,
	6682,
	7458,
	8223,
	8480,
	7211,
	8733,
	8482,
	8230,
	8993,
	8994,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	14336,
	13364,
	11569,
	9261,
	8481,
	6687,
	6681,
	4626,
	2578,
	1803,
	770,
	519,
	13571,
	9517,
	9778,
	11805,
	5151,
	5926,
	8205,
	1808,
	2586,
	11267,
	2056,
	8210,
	7441,
	6954,
	9494,
	4119,
	3866,
	4864,
	13316,
	13364,
	11563,
	8751,
	9506,
	10024,
	8242,
	10527,
	6174,
	5927,
	7698,
	3600,
	2325,
	2308,
	11573,
	12837,
	7462,
	7982,
	9748,
	3351,
	4128,
	6663,
	778,
	9533,
	13100,
	9244,
	5162,
	8476,
	5390,
	2072,
	3855,
	2308,
	2865,
	9995,
	1285,
	285,
	4865,
	0,
	11573,
	12837,
	7462,
	0,
	16128,
	0,
	16191,
	63,
	0,
	0,
	0,
	0,
	0,
	13824,
	13878,
	12077,
	8241,
	10527,
	5917,
	5925,
	7698,
	2865,
	9995,
	1285,
	285,
	16129,
	16191,
};

uint16 sc78_fast_list[] = {
	12+DISK_10,
	51+DISK_10,
	52+DISK_10,
	53+DISK_10,
	54+DISK_10,
	268+DISK_10,
	0,
};

}; // namespace SkyCompact

#endif
