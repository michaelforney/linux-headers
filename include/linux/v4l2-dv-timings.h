/*
 * V4L2 DV timings header.
 *
 * Copyright (C) 2012  Hans Verkuil <hans.verkuil@cisco.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef _V4L2_DV_TIMINGS_H
#define _V4L2_DV_TIMINGS_H

#if __GNUC__ < 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ < 6))
/* Sadly gcc versions older than 4.6 have a bug in how they initialize
   anonymous unions where they require additional curly brackets.
   This violates the C1x standard. This workaround adds the curly brackets
   if needed. */
#define V4L2_INIT_BT_TIMINGS(_width, args...) \
	{ .bt = { _width , ## args } }
#else
#define V4L2_INIT_BT_TIMINGS(_width, args...) \
	.bt = { _width , ## args }
#endif

/* CEA-861-E timings (i.e. standard HDTV timings) */

#define V4L2_DV_BT_CEA_640X480P59_94 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(640, 480, 0, 0, \
		25175000, 16, 96, 48, 10, 2, 33, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CEA861, 0) \
}

/* Note: these are the nominal timings, for HDMI links this format is typically
 * double-clocked to meet the minimum pixelclock requirements.  */
#define V4L2_DV_BT_CEA_720X480I59_94 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(720, 480, 1, 0, \
		13500000, 19, 62, 57, 4, 3, 15, 4, 3, 16, \
		V4L2_DV_BT_STD_CEA861, V4L2_DV_FL_HALF_LINE) \
}

#define V4L2_DV_BT_CEA_720X480P59_94 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(720, 480, 0, 0, \
		27000000, 16, 62, 60, 9, 6, 30, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, 0) \
}

/* Note: these are the nominal timings, for HDMI links this format is typically
 * double-clocked to meet the minimum pixelclock requirements.  */
#define V4L2_DV_BT_CEA_720X576I50 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(720, 576, 1, 0, \
		13500000, 12, 63, 69, 2, 3, 19, 2, 3, 20, \
		V4L2_DV_BT_STD_CEA861, V4L2_DV_FL_HALF_LINE) \
}

#define V4L2_DV_BT_CEA_720X576P50 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(720, 576, 0, 0, \
		27000000, 12, 64, 68, 5, 5, 39, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, 0) \
}

#define V4L2_DV_BT_CEA_1280X720P24 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 720, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		59400000, 1760, 40, 220, 5, 5, 20, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CEA861, \
		V4L2_DV_FL_CAN_REDUCE_FPS) \
}

#define V4L2_DV_BT_CEA_1280X720P25 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 720, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 2420, 40, 220, 5, 5, 20, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, 0) \
}

#define V4L2_DV_BT_CEA_1280X720P30 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 720, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 1760, 40, 220, 5, 5, 20, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, V4L2_DV_FL_CAN_REDUCE_FPS) \
}

#define V4L2_DV_BT_CEA_1280X720P50 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 720, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 440, 40, 220, 5, 5, 20, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, 0) \
}

#define V4L2_DV_BT_CEA_1280X720P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 720, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 110, 40, 220, 5, 5, 20, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, V4L2_DV_FL_CAN_REDUCE_FPS) \
}

#define V4L2_DV_BT_CEA_1920X1080P24 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1080, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 638, 44, 148, 4, 5, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, V4L2_DV_FL_CAN_REDUCE_FPS) \
}

#define V4L2_DV_BT_CEA_1920X1080P25 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1080, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 528, 44, 148, 4, 5, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, 0) \
}

#define V4L2_DV_BT_CEA_1920X1080P30 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1080, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 88, 44, 148, 4, 5, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, V4L2_DV_FL_CAN_REDUCE_FPS) \
}

#define V4L2_DV_BT_CEA_1920X1080I50 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1080, 1, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 528, 44, 148, 2, 5, 15, 2, 5, 16, \
		V4L2_DV_BT_STD_CEA861, V4L2_DV_FL_HALF_LINE) \
}

#define V4L2_DV_BT_CEA_1920X1080P50 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1080, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		148500000, 528, 44, 148, 4, 5, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_CEA861, 0) \
}

#define V4L2_DV_BT_CEA_1920X1080I60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1080, 1, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		74250000, 88, 44, 148, 2, 5, 15, 2, 5, 16, \
		V4L2_DV_BT_STD_CEA861, \
		V4L2_DV_FL_CAN_REDUCE_FPS | V4L2_DV_FL_HALF_LINE) \
}

#define V4L2_DV_BT_CEA_1920X1080P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1080, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		148500000, 88, 44, 148, 4, 5, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CEA861, \
		V4L2_DV_FL_CAN_REDUCE_FPS) \
}


/* VESA Discrete Monitor Timings as per version 1.0, revision 12 */

#define V4L2_DV_BT_DMT_640X350P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(640, 350, 0, V4L2_DV_HSYNC_POS_POL, \
		31500000, 32, 64, 96, 32, 3, 60, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_640X400P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(640, 400, 0, V4L2_DV_VSYNC_POS_POL, \
		31500000, 32, 64, 96, 1, 3, 41, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_720X400P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(720, 400, 0, V4L2_DV_VSYNC_POS_POL, \
		35500000, 36, 72, 108, 1, 3, 42, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

/* VGA resolutions */
#define V4L2_DV_BT_DMT_640X480P60 V4L2_DV_BT_CEA_640X480P59_94

#define V4L2_DV_BT_DMT_640X480P72 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(640, 480, 0, 0, \
		31500000, 24, 40, 128, 9, 3, 28, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_640X480P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(640, 480, 0, 0, \
		31500000, 16, 64, 120, 1, 3, 16, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_640X480P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(640, 480, 0, 0, \
		36000000, 56, 56, 80, 1, 3, 25, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

/* SVGA resolutions */
#define V4L2_DV_BT_DMT_800X600P56 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(800, 600, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		36000000, 24, 72, 128, 1, 2, 22, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_800X600P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(800, 600, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		40000000, 40, 128, 88, 1, 4, 23, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_800X600P72 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(800, 600, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		50000000, 56, 120, 64, 37, 6, 23, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_800X600P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(800, 600, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		49500000, 16, 80, 160, 1, 3, 21, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_800X600P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(800, 600, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		56250000, 32, 64, 152, 1, 3, 27, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_800X600P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(800, 600, 0, V4L2_DV_HSYNC_POS_POL, \
		73250000, 48, 32, 80, 3, 4, 29, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_848X480P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(848, 480, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		33750000, 16, 112, 112, 6, 8, 23, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1024X768I43 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1024, 768, 1, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		44900000, 8, 176, 56, 0, 4, 20, 0, 4, 21, \
		V4L2_DV_BT_STD_DMT, 0) \
}

/* XGA resolutions */
#define V4L2_DV_BT_DMT_1024X768P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1024, 768, 0, 0, \
		65000000, 24, 136, 160, 3, 6, 29, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1024X768P70 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1024, 768, 0, 0, \
		75000000, 24, 136, 144, 3, 6, 29, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1024X768P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1024, 768, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		78750000, 16, 96, 176, 1, 3, 28, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1024X768P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1024, 768, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		94500000, 48, 96, 208, 1, 3, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1024X768P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1024, 768, 0, V4L2_DV_HSYNC_POS_POL, \
		115500000, 48, 32, 80, 3, 4, 38, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

/* XGA+ resolution */
#define V4L2_DV_BT_DMT_1152X864P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1152, 864, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		108000000, 64, 128, 256, 1, 3, 32, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1280X720P60 V4L2_DV_BT_CEA_1280X720P60

/* WXGA resolutions */
#define V4L2_DV_BT_DMT_1280X768P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 768, 0, V4L2_DV_HSYNC_POS_POL, \
		68250000, 48, 32, 80, 3, 7, 12, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1280X768P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 768, 0, V4L2_DV_VSYNC_POS_POL, \
		79500000, 64, 128, 192, 3, 7, 20, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1280X768P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 768, 0, V4L2_DV_VSYNC_POS_POL, \
		102250000, 80, 128, 208, 3, 7, 27, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1280X768P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 768, 0, V4L2_DV_VSYNC_POS_POL, \
		117500000, 80, 136, 216, 3, 7, 31, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1280X768P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 768, 0, V4L2_DV_HSYNC_POS_POL, \
		140250000, 48, 32, 80, 3, 7, 35, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1280X800P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 800, 0, V4L2_DV_HSYNC_POS_POL, \
		71000000, 48, 32, 80, 3, 6, 14, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1280X800P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 800, 0, V4L2_DV_VSYNC_POS_POL, \
		83500000, 72, 128, 200, 3, 6, 22, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1280X800P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 800, 0, V4L2_DV_VSYNC_POS_POL, \
		106500000, 80, 128, 208, 3, 6, 29, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1280X800P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 800, 0, V4L2_DV_VSYNC_POS_POL, \
		122500000, 80, 136, 216, 3, 6, 34, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1280X800P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 800, 0, V4L2_DV_HSYNC_POS_POL, \
		146250000, 48, 32, 80, 3, 6, 38, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1280X960P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 960, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		108000000, 96, 112, 312, 1, 3, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1280X960P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 960, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		148500000, 64, 160, 224, 1, 3, 47, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1280X960P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 960, 0, V4L2_DV_HSYNC_POS_POL, \
		175500000, 48, 32, 80, 3, 4, 50, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

/* SXGA resolutions */
#define V4L2_DV_BT_DMT_1280X1024P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 1024, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		108000000, 48, 112, 248, 1, 3, 38, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1280X1024P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 1024, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		135000000, 16, 144, 248, 1, 3, 38, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1280X1024P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 1024, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		157500000, 64, 160, 224, 1, 3, 44, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1280X1024P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1280, 1024, 0, V4L2_DV_HSYNC_POS_POL, \
		187250000, 48, 32, 80, 3, 7, 50, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1360X768P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1360, 768, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		85500000, 64, 112, 256, 3, 6, 18, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1360X768P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1360, 768, 0, V4L2_DV_HSYNC_POS_POL, \
		148250000, 48, 32, 80, 3, 5, 37, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1366X768P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1366, 768, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		85500000, 70, 143, 213, 3, 3, 24, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1366X768P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1366, 768, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		72000000, 14, 56, 64, 1, 3, 28, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, V4L2_DV_FL_REDUCED_BLANKING) \
}

/* SXGA+ resolutions */
#define V4L2_DV_BT_DMT_1400X1050P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1400, 1050, 0, V4L2_DV_HSYNC_POS_POL, \
		101000000, 48, 32, 80, 3, 4, 23, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1400X1050P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1400, 1050, 0, V4L2_DV_VSYNC_POS_POL, \
		121750000, 88, 144, 232, 3, 4, 32, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1400X1050P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1400, 1050, 0, V4L2_DV_VSYNC_POS_POL, \
		156000000, 104, 144, 248, 3, 4, 42, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1400X1050P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1400, 1050, 0, V4L2_DV_VSYNC_POS_POL, \
		179500000, 104, 152, 256, 3, 4, 48, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1400X1050P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1400, 1050, 0, V4L2_DV_HSYNC_POS_POL, \
		208000000, 48, 32, 80, 3, 4, 55, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

/* WXGA+ resolutions */
#define V4L2_DV_BT_DMT_1440X900P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1440, 900, 0, V4L2_DV_HSYNC_POS_POL, \
		88750000, 48, 32, 80, 3, 6, 17, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1440X900P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1440, 900, 0, V4L2_DV_VSYNC_POS_POL, \
		106500000, 80, 152, 232, 3, 6, 25, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1440X900P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1440, 900, 0, V4L2_DV_VSYNC_POS_POL, \
		136750000, 96, 152, 248, 3, 6, 33, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1440X900P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1440, 900, 0, V4L2_DV_VSYNC_POS_POL, \
		157000000, 104, 152, 256, 3, 6, 39, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1440X900P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1440, 900, 0, V4L2_DV_HSYNC_POS_POL, \
		182750000, 48, 32, 80, 3, 6, 44, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1600X900P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1600, 900, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		108000000, 24, 80, 96, 1, 3, 96, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, V4L2_DV_FL_REDUCED_BLANKING) \
}

/* UXGA resolutions */
#define V4L2_DV_BT_DMT_1600X1200P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1600, 1200, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		162000000, 64, 192, 304, 1, 3, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1600X1200P65 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1600, 1200, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		175500000, 64, 192, 304, 1, 3, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1600X1200P70 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1600, 1200, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		189000000, 64, 192, 304, 1, 3, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1600X1200P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1600, 1200, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		202500000, 64, 192, 304, 1, 3, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1600X1200P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1600, 1200, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		229500000, 64, 192, 304, 1, 3, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1600X1200P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1600, 1200, 0, V4L2_DV_HSYNC_POS_POL, \
		268250000, 48, 32, 80, 3, 4, 64, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

/* WSXGA+ resolutions */
#define V4L2_DV_BT_DMT_1680X1050P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1680, 1050, 0, V4L2_DV_HSYNC_POS_POL, \
		119000000, 48, 32, 80, 3, 6, 21, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1680X1050P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1680, 1050, 0, V4L2_DV_VSYNC_POS_POL, \
		146250000, 104, 176, 280, 3, 6, 30, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1680X1050P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1680, 1050, 0, V4L2_DV_VSYNC_POS_POL, \
		187000000, 120, 176, 296, 3, 6, 40, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1680X1050P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1680, 1050, 0, V4L2_DV_VSYNC_POS_POL, \
		214750000, 128, 176, 304, 3, 6, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1680X1050P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1680, 1050, 0, V4L2_DV_HSYNC_POS_POL, \
		245500000, 48, 32, 80, 3, 6, 53, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1792X1344P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1792, 1344, 0, V4L2_DV_VSYNC_POS_POL, \
		204750000, 128, 200, 328, 1, 3, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1792X1344P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1792, 1344, 0, V4L2_DV_VSYNC_POS_POL, \
		261000000, 96, 216, 352, 1, 3, 69, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1792X1344P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1792, 1344, 0, V4L2_DV_HSYNC_POS_POL, \
		333250000, 48, 32, 80, 3, 4, 72, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1856X1392P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1856, 1392, 0, V4L2_DV_VSYNC_POS_POL, \
		218250000, 96, 224, 352, 1, 3, 43, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1856X1392P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1856, 1392, 0, V4L2_DV_VSYNC_POS_POL, \
		288000000, 128, 224, 352, 1, 3, 104, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1856X1392P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1856, 1392, 0, V4L2_DV_HSYNC_POS_POL, \
		356500000, 48, 32, 80, 3, 4, 75, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1920X1080P60 V4L2_DV_BT_CEA_1920X1080P60

/* WUXGA resolutions */
#define V4L2_DV_BT_DMT_1920X1200P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1200, 0, V4L2_DV_HSYNC_POS_POL, \
		154000000, 48, 32, 80, 3, 6, 26, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1920X1200P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1200, 0, V4L2_DV_VSYNC_POS_POL, \
		193250000, 136, 200, 336, 3, 6, 36, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1920X1200P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1200, 0, V4L2_DV_VSYNC_POS_POL, \
		245250000, 136, 208, 344, 3, 6, 46, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1920X1200P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1200, 0, V4L2_DV_VSYNC_POS_POL, \
		281250000, 144, 208, 352, 3, 6, 53, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_1920X1200P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1200, 0, V4L2_DV_HSYNC_POS_POL, \
		317000000, 48, 32, 80, 3, 6, 62, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1920X1440P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1440, 0, V4L2_DV_VSYNC_POS_POL, \
		234000000, 128, 208, 344, 1, 3, 56, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1920X1440P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1440, 0, V4L2_DV_VSYNC_POS_POL, \
		297000000, 144, 224, 352, 1, 3, 56, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#define V4L2_DV_BT_DMT_1920X1440P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1920, 1440, 0, V4L2_DV_HSYNC_POS_POL, \
		380500000, 48, 32, 80, 3, 4, 78, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_2048X1152P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(2048, 1152, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		162000000, 26, 80, 96, 1, 3, 44, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, V4L2_DV_FL_REDUCED_BLANKING) \
}

/* WQXGA resolutions */
#define V4L2_DV_BT_DMT_2560X1600P60_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(2560, 1600, 0, V4L2_DV_HSYNC_POS_POL, \
		268500000, 48, 32, 80, 3, 6, 37, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_2560X1600P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(2560, 1600, 0, V4L2_DV_VSYNC_POS_POL, \
		348500000, 192, 280, 472, 3, 6, 49, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_2560X1600P75 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(2560, 1600, 0, V4L2_DV_VSYNC_POS_POL, \
		443250000, 208, 280, 488, 3, 6, 63, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_2560X1600P85 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(2560, 1600, 0, V4L2_DV_VSYNC_POS_POL, \
		505250000, 208, 280, 488, 3, 6, 73, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, 0) \
}

#define V4L2_DV_BT_DMT_2560X1600P120_RB { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(2560, 1600, 0, V4L2_DV_HSYNC_POS_POL, \
		552750000, 48, 32, 80, 3, 6, 85, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT | V4L2_DV_BT_STD_CVT, \
		V4L2_DV_FL_REDUCED_BLANKING) \
}

#define V4L2_DV_BT_DMT_1366X768P60 { \
	.type = V4L2_DV_BT_656_1120, \
	V4L2_INIT_BT_TIMINGS(1366, 768, 0, \
		V4L2_DV_HSYNC_POS_POL | V4L2_DV_VSYNC_POS_POL, \
		85500000, 70, 143, 213, 3, 3, 24, 0, 0, 0, \
		V4L2_DV_BT_STD_DMT, 0) \
}

#endif
