/* drivers/sharp/shtps/sy3000/plg543-001-3/shtps_cfg_plg543-001-3.h
 *
 * Copyright (c) 2015, Sharp. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __SHTPS_CFG_PLG543_001_3_H__
#define __SHTPS_CFG_PLG543_001_3_H__

/* ===================================================================================
 * [ Debug ]
 */
#define SHTPS_DEVELOP_MODE_ENABLE

//#define SHTPS_RELEASE_FOR_MANUFACTURER

#ifdef	SHTPS_DEVELOP_MODE_ENABLE
	//#define SHTPS_PERFORMANCE_CHECK_ENABLE
	//#define SHTPS_LOG_SEQ_ENABLE
	//#define SHTPS_LOG_SPIACCESS_SEQ_ENABLE
	#define SHTPS_LOG_DEBUG_ENABLE
	#define	SHTPS_LOG_EVENT_ENABLE
	#define	SHTPS_MODULE_PARAM_ENABLE
	#define	SHTPS_DEBUG_VARIABLE_DEFINES
	#define SHTPS_CREATE_KOBJ_ENABLE
	#define SHTPS_DEVICE_ACCESS_LOG_ENABLE
#endif

#define	SHTPS_LOG_ERROR_ENABLE
//#define SHTPS_DEF_RECORD_LOG_FILE_ENABLE

#ifdef SHTPS_LOG_EVENT_ENABLE
	#define SHTPS_LOG_OUTPUT_SWITCH_ENABLE
#endif /* #if defined( SHTPS_LOG_EVENT_ENABLE ) */

#if defined(SHTPS_PERFORMANCE_CHECK_ENABLE)
	#define SHTPS_PERFORMANCE_CHECK_PIN_ENABLE
	//#define SHTPS_PERFORMANCE_TIME_LOG_ENABLE
#endif /* SHTPS_PERFORMANCE_CHECK_ENABLE */

/* ===================================================================================
 * [ Diag ]
 */
#ifdef	SHTPS_FACTORY_MODE_ENABLE
	#undef	SHTPS_BOOT_FWUPDATE_ENABLE
	#undef	SHTPS_BOOT_FWUPDATE_FORCE_UPDATE
	#define	SHTPS_FMODE_GESTURE_ENABLE
	#define SHTPS_TPIN_CHECK_ENABLE
#else
	#define	SHTPS_BOOT_FWUPDATE_ENABLE
	#undef	SHTPS_BOOT_FWUPDATE_FORCE_UPDATE
	#undef	SHTPS_FMODE_GESTURE_ENABLE
	#undef	SHTPS_TPIN_CHECK_ENABLE
	
	#if defined(SHTPS_BOOT_FWUPDATE_ENABLE)
		#define	SHTPS_BOOT_FWUPDATE_SKIP_ES0_ENABLE
	#endif
	
#endif

#define SHTPS_CHECK_CRC_ERROR_ENABLE
#define	SHTPS_SMEM_BASELINE_ENABLE

#define SHTPS_DIAGPOLL_TIME							100


/* ===================================================================================
 * [ Firmware update ]
 */
//#define SHTPS_MULTI_FW_ENABLE
#define SHTPS_CHECK_HWID_ENABLE
#define SHTPS_BOOT_FWUPDATE_ONLY_ON_HANDSET
#define SHTPS_SPI_FWBLOCKWRITE_ENABLE
#define	SHTPS_FWUPDATE_BUILTIN_ENABLE

#define SHTPS_GET_HW_VERSION_RET_ES_0		0
#define SHTPS_GET_HW_VERSION_RET_ES_1		1
#define SHTPS_GET_HW_VERSION_RET_PP_1		3
#define SHTPS_GET_HW_VERSION_RET_PP_1_5		4
#define SHTPS_GET_HW_VERSION_RET_PP_2		5
#define SHTPS_GET_HW_VERSION_RET_RESERVE1	2
#define SHTPS_GET_HW_VERSION_RET_RESERVE2	6
#define SHTPS_GET_HW_VERSION_RET_MP			7
#define SHTPS_GET_HW_VERSION_RET_UNKNOWN	0xFF

#if defined(SHTPS_MULTI_FW_ENABLE)
	#include "plg543-001-3/shtps_fw_plg543-001-3_es1.h"
	#include "plg543-001-3/shtps_fw_plg543-001-3.h"
	
	typedef struct {
		unsigned char		hwrev;
		const unsigned char	*data;
		unsigned short		size;
		unsigned short		ver;
		char				*name;
	} shtps_multi_fw_info_t;
	
	static const shtps_multi_fw_info_t SHTPS_MULTI_FW_INFO_TBL[] = {
		{ SHTPS_GET_HW_VERSION_RET_ES_0,   tps_fw_data_es1, SHTPS_FWSIZE_NEWER_ES1, SHTPS_FWVER_NEWER_ES1, "ES1"    },
		{ SHTPS_GET_HW_VERSION_RET_ES_1,   tps_fw_data_es1, SHTPS_FWSIZE_NEWER_ES1, SHTPS_FWVER_NEWER_ES1, "ES1"    },
		{ SHTPS_GET_HW_VERSION_RET_PP_1,   tps_fw_data,     SHTPS_FWSIZE_NEWER,     SHTPS_FWVER_NEWER    , "NORMAL" },
		{ SHTPS_GET_HW_VERSION_RET_PP_2,   tps_fw_data,     SHTPS_FWSIZE_NEWER,     SHTPS_FWVER_NEWER    , "NORMAL" },
		{ SHTPS_GET_HW_VERSION_RET_MP,     tps_fw_data,     SHTPS_FWSIZE_NEWER,     SHTPS_FWVER_NEWER    , "NORMAL" },
		{ SHTPS_GET_HW_VERSION_RET_UNKNOWN,tps_fw_data,     SHTPS_FWSIZE_NEWER,     SHTPS_FWVER_NEWER    , "NORMAL" },
	};
	static const int SHTPS_MULTI_FW_INFO_SIZE = sizeof(SHTPS_MULTI_FW_INFO_TBL) / sizeof(shtps_multi_fw_info_t);
#else
	#include "plg543-001-3/shtps_fw_plg543-001-3.h"
#endif /* SHTPS_MULTI_FW_ENABLE */


/* ===================================================================================
 * [ Model specifications ]
 */
#define CONFIG_SHTPS_SY3000_LCD_SIZE_X		1080
#define CONFIG_SHTPS_SY3000_LCD_SIZE_Y		1920
//#define CONFIG_SHTPS_SY3000_FACETOUCH_DETECT
//#define CONFIG_SHTPS_SY3000_FACETOUCH_OFF_DETECT
#define CONFIG_SHTPS_SY3000_POSITION_OFFSET
#define CONFIG_SHTPS_SY3000_ALWAYS_ACTIVEMODE
//#define CONFIG_SHTPS_SY3000_FLIP_CHANGE_HANDLE

#define SHTPS_IRQ_LEVEL_ENABLE
#define SHTPS_SYSTEM_BOOT_MODE_CHECK_ENABLE
//#define SHTPS_SYSTEM_HOT_STANDBY_ENABLE
#define SHTPS_IRQ_LOADER_CHECK_INT_STATUS_ENABLE

//#define SHTPS_PHYSICAL_KEY_ENABLE
//#define SHTPS_PHYSICAL_KEY_SET_THRESH_ENABLE
//#define SHTPS_HOVER_DETECT_ENABLE
//#define SHTPS_PEN_DETECT_ENABLE
#define SHTPS_GLOVE_DETECT_ENABLE
#define SHTPS_LPWG_MODE_ENABLE
#define SHTPS_COVER_ENABLE

#if defined( SHTPS_LPWG_MODE_ENABLE )
	#define SHTPS_HOST_LPWG_MODE_ENABLE
#endif /* SHTPS_LPWG_MODE_ENABLE */

#if defined( CONFIG_SHTPS_SY3000_ALWAYS_ACTIVEMODE )
	#define SHTPS_LOW_POWER_MODE_ENABLE
#endif /* #if defined( CONFIG_SHTPS_SY3000_ALWAYS_ACTIVEMODE ) */

#define SHTPS_QOS_LATENCY_DEF_VALUE	 			34

#define SHTPS_BASELINE_OFFSET_DISABLE_WAIT_ENABLE
//#define SHTPS_DEF_FWTMDATA_REPLACE_ENABLE

#define SHTPS_NOTIFY_TOUCH_MINOR_ENABLE

#define SHTPS_VAL_FINGER_WIDTH_MAXSIZE (50)

#if defined(SHTPS_DEF_FWTMDATA_REPLACE_ENABLE)
	#define SHTPS_FWTESTMODE_BLOCK_SIZE	(28)
	static const int SHTPS_FWTMDATA_CONV_TBL[] = {
		0  , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 10 , 11 , 12 , 13 , 
		14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 , 27 , 
		42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 , 
		28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 41 , 
		56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 69 , 
		70 , 71 , 72 , 73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 , 81 , 82 , 83 , 
		98 , 99 , 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 
		84 , 85 , 86 , 87 , 88 , 89 , 90 , 91 , 92 , 93 , 94 , 95 , 96 , 97 , 
		112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 
		126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 
		154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 
		140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 
		168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 
		182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 
		210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 
		196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 
		224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 
		238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 
		266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 
		252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 
		280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 
		294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 
		322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 
		308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 
		336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 
		350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 
	};
#endif /* SHTPS_FWTMDATA_REPLACE_ENABLE */

/* ===================================================================================
 * [ Firmware control ]
 */
#define SHTPS_FWDATA_BLOCK_SIZE_MAX					0xFFFF
#define SHTPS_BOOTLOADER_ACK_TMO					1000
#define SHTPS_FWTESTMODE_ACK_TMO					1000
#define SHTPS_F54_COMMAND_WAIT_POLL_COUNT			30
#define SHTPS_F54_COMMAND_WAIT_POLL_INTERVAL		10
#define SHTPS_PDT_PAGE_SIZE_MAX						4
#define SHTPS_PDT_READ_RETRY_COUNT					5
#define SHTPS_PDT_READ_RETRY_INTERVAL				200
#define SHTPS_FLASH_ERASE_WAIT_MS					2000

#define SHTPS_GET_PANEL_SIZE_X(ts)					(shtps_fwctl_get_maxXPosition(ts) + 1)
#define SHTPS_GET_PANEL_SIZE_Y(ts)					(shtps_fwctl_get_maxYPosition(ts) + 1)

#define SHTPS_POS_SCALE_X(ts)	(((CONFIG_SHTPS_SY3000_LCD_SIZE_X) * 10000) / shtps_fwctl_get_maxXPosition(ts))
#define SHTPS_POS_SCALE_Y(ts)	(((CONFIG_SHTPS_SY3000_LCD_SIZE_Y) * 10000) / shtps_fwctl_get_maxYPosition(ts))

/* ===================================================================================
 * [ Hardware specifications ]
 */
#define SHTPS_GPIO_TPIN_DEVNAME				("fd510000.pinctrl")
#define SHTPS_GPIO_TPIN_NAME 				("gp-69")

#define SHTPS_SY3X00_SPI_CLOCK				1100000

#define SHTPS_SPI_BLOCKACCESS_ENABLE

#define	SHTPS_SPI_FAST_CLOCK_ENABLE
#define	SHTPS_SPI_FAST_FW_TRANSFER_ENABLE

#ifdef	SHTPS_SPI_FAST_CLOCK_ENABLE
	#define TPS_SPI_R_CLOCK			3200000
	#define TPS_SPI_W_CLOCK			3200000
	#define TPS_SPI_R_BYTE_DELAY	20
	#define TPS_SPI_W_BYTE_DELAY	5
	#define TPS_SPI_R_TANS_WAIT		5
	#define TPS_SPI_W_TANS_WAIT		5
#else
	#define TPS_SPI_R_CLOCK			1100000
	#define TPS_SPI_W_CLOCK			600000
	#define TPS_SPI_R_BYTE_DELAY	20
	#define TPS_SPI_W_BYTE_DELAY	0
	#define TPS_SPI_R_TANS_WAIT		40
	#define TPS_SPI_W_TANS_WAIT		65
#endif

#ifdef	SHTPS_SPI_BLOCKACCESS_ENABLE
	#define SHTPS_SY3X00_FINGER_SPIREAD_CNT		2
#else
	#define SHTPS_SY3X00_FINGER_SPIREAD_CNT		0
#endif

#define	SHTPS_SY3X00_SPIBLOCK_BUFSIZE		(SHTPS_TM_TXNUM_MAX * 4)

#define SHTPS_SY3X00_SPIBLOCKWRITE_BUFSIZE		0x10

#define SHTPS_SPI_RETRY_COUNT					5
#define SHTPS_SPI_RETRY_WAIT					5

#define SHTPS_STARTUP_MIN_TIME					300
#define SHTPS_POWERON_WAIT_MS					400
#define SHTPS_POWEROFF_WAIT_MS					10
#define SHTPS_HWRESET_TIME_US					1
#define SHTPS_HWRESET_AFTER_TIME_MS				1
#define SHTPS_HWRESET_WAIT_MS					290
#define SHTPS_SWRESET_WAIT_MS					300
#define SHTPS_RESET_BOOTLOADER_WAIT_MS			400
#define SHTPS_SLEEP_OUT_WAIT_US					67500

#define SHTPS_READ_SERIAL_NUMBER_SIZE			16

#define SHTPS_READ_SERIAL_NUMBER_CHECK_F01_ENABLE
#if defined(SHTPS_READ_SERIAL_NUMBER_CHECK_F01_ENABLE)
	#define SHTPS_READ_SERIAL_NUMBER_FROM_F01_SIZE	7
#endif /* SHTPS_READ_SERIAL_NUMBER_CHECK_F01_ENABLE */

#define SHTPS_PROXIMITY_SUPPORT_ENABLE

/* ===================================================================================
 * [ Performance ]
 */
#define SHTPS_CPU_CLOCK_CONTROL_ENABLE
//#define SHTPS_CPU_CLOCK_CONTROL_CHECK_CURFREQ_ENABLE

#define SHTPS_CPU_IDLE_SLEEP_CONTROL_ENABLE
#define SHTPS_CPU_SLEEP_CONTROL_FOR_FWUPDATE_ENABLE


/* ===================================================================================
 * [ Standard ]
 */
#define SHTPS_IRQ_LINKED_WITH_IRQWAKE_ENABLE
#define SHTPS_PDT_READ_RETRY_ENABLE
#define SHTPS_SPI_AVOID_BLOCKREAD_FAIL

#define SHTPS_INPUT_POWER_MODE_CHANGE_ENABLE
#define SHTPS_GUARANTEE_SPI_ACCESS_IN_WAKE_ENABLE
#define SHTPS_TOUCHCANCEL_BEFORE_FORCE_TOUCHUP_ENABLE
#define SHTPS_WAKEUP_FAIL_TOUCH_EVENT_REJECTION_ENABLE


/* ===================================================================================
 * [ Host functions ]
 */
#if defined(SHTPS_RELEASE_FOR_MANUFACTURER)

#else

// #define SHTPS_DRAG_STEP_ENABLE
// #define SHTPS_CHARGER_ARMOR_ENABLE
//#define SHTPS_CLING_REJECTION_ENABLE
//#define SHTPS_EDGE_POS_ADJUST_ENABLE
//#define SHTPS_MULTI_HOVER_SELECT_ENABLE

// #define SHTPS_FINGER_ABSORPTION_PROVISION_ENABLE
#define SHTPS_ACTIVE_SLEEP_WAIT_ALWAYS_ENABLE
//#define SHTPS_PINCHOUT_FAIL_FLICK_RESOLV_ENABLE
//#define SHTPS_FINGER_WIDTH_MODERATION_ENABLE
#define SHTPS_EDGE_FAIL_TOUCH_REJECTION_ENABLE
//#define SHTPS_GRIP_FAIL_TOUCH_REJECTION_ENABLE
// #define SHTPS_DIAGONAL_GHOST_CHECK_ENABLE
#define SHTPS_DRAG_SMOOTH_ENABLE
#define SHTPS_DRAG_SMOOTH_FLATTERY_ENABLE
#define SHTPS_DYNAMIC_RESET_CONTROL_ENABLE
// #define SHTPS_LGM_SPLIT_TOUCH_COMBINING_ENABLE
//#define SHTPS_REPORT_TOOL_TYPE_LOCK_ENABLE
//#define SHTPS_GHOST_REJECTION_ENABLE
// #define SHTPS_COAXIAL_GHOST_REJECTION_ENABLE
//#define SHTPS_PINCH_FAIL_RESPONSE_REJECTION_ENABLE
//#define SHTPS_PINCHOUT_OUTSET_DISTORT_REJECTION_ENABLE
//#define SHTPS_TOP_EDGE_FAIL_TOUCH_REJECTION_ENABLE
// #define SHTPS_WATER_GHOST_REJECTION_ENABLE
// #define SHTPS_WATER_CLING_REJECTION_ENABLE
#define SHTPS_CTRL_FW_REPORT_RATE
//#define SHTPS_MULTI_TAP_FAIL_MOVE_REJECTION_ENABLE
//#define SHTPS_CHANGE_LAND_LOCK_DISTANCE_ENABLE
//#define SHTPS_INVERTING_GHOST_REJECTION_ENABLE
#define SHTPS_TEMPERATURE_GHOST_REJECT_CHECK_ENABLE
#define SHTPS_DEF_DISALLOW_Z_ZERO_TOUCH_EVENT_ENABLE

#if defined(CONFIG_SHUB_ML630Q790_1ST) || defined(CONFIG_SHUB_ML630Q790)
	#define SHTPS_MOTION_PEDO_STOP_REQ_ENABLE
#endif

#ifdef CONFIG_SHTERM
	#define SHTPS_SEND_SHTERM_EVENT_ENABLE
#endif

#if defined(SHTPS_HOVER_DETECT_ENABLE)
	#define SHTPS_HOVER_DETECT_FAIL_RESOLV_ENABLE
	#define SHTPS_FORCECAL_AFTER_HOVERSETTING_ENABLE
	#define SHTPS_HOVER_HOST_JITTER_FILTER_ENABLE
	#define SHTPS_HOVER_EDGE_LOST_RESOLV_ENABLE

	#if defined(SHTPS_PEN_DETECT_ENABLE)
		//#define SHTPS_HOVER_REJECT_ENABLE
	#endif /* SHTPS_PEN_DETECT_ENABLE */
#endif /* SHTPS_HOVER_DETECT_ENABLE */

#if defined(SHTPS_GLOVE_DETECT_ENABLE)
	#define SHTPS_DEF_GLOVE_DETECT_FAIL_RESOLVE_ENABLE
#endif /* SHTPS_GLOVE_DETECT_ENABLE */

#if defined(SHTPS_PHYSICAL_KEY_ENABLE)
	#define SHTPS_FINGER_KEY_EXCLUDE_ENABLE
	
	#if defined(SHTPS_PROXIMITY_SUPPORT_ENABLE)
		#define SHTPS_KEY_PROXIMITY_ASYNC_CHECK_ENABLE
	#endif /* SHTPS_PROXIMITY_SUPPORT_ENABLE */
#endif /* SHTPS_PHYSICAL_KEY_ENABLE */

#if defined(SHTPS_PEN_DETECT_ENABLE)
	#define SHTPS_PEN_SCREEN_EDGE_DISABLE
	#define SHTPS_PEN_EVENT_FAIL_CONTINUE_REJECT_ENABLE
	#define SHTPS_PEN_POS_JUMP_REJECT_ENABLE
	#define SHTPS_MULTITOUCH_PEN_GHOST_REJECTION_ENABLE
	#define SHTPS_VARIABLE_PEN_JITTER_ENABLE
	#define SHTPS_PEN_CLING_REJECTION_ENABLE
#endif /* SHTPS_PEN_DETECT_ENABLE */

#if defined(SHTPS_BOOT_FWUPDATE_FORCE_UPDATE)
	#undef SHTPS_BOOT_FWUPDATE_ONLY_ON_HANDSET
#endif /* SHTPS_BOOT_FWUPDATE_FORCE_UPDATE */

#if defined(SHTPS_LPWG_MODE_ENABLE)
	#define SHTPS_LPWG_DOUBLE_TAP_ENABLE
	#define SHTPS_LPWG_CHANGE_SWIPE_DISTANCE_ENABLE
	#define SHTPS_LPWG_GRIP_SUPPORT_ENABLE
		#if defined(SHTPS_LPWG_GRIP_SUPPORT_ENABLE)
			#define SHTPS_DEF_LPWG_GRIP_PROC_ASYNC_ENABLE
		#endif /* SHTPS_LPWG_GRIP_SUPPORT_ENABLE */
	#define SHTPS_LPWG_ALLOWED_SWIPES_ENABLE
#endif /* SHTPS_LPWG_MODE_ENABLE */

#if defined(SHTPS_EDGE_FAIL_TOUCH_REJECTION_ENABLE) && defined(SHTPS_PHYSICAL_KEY_ENABLE)
	#define SHTPS_TOUCHKEY_FAIL_TOUCH_REJECTION_ENABLE
#endif /* SHTPS_EDGE_FAIL_TOUCH_REJECTION_ENABLE && SHTPS_PHYSICAL_KEY_ENABLE */

#if defined( SHTPS_DYNAMIC_RESET_CONTROL_ENABLE )
//	#define SHTPS_DYNAMIC_RESET_ESD_ENABLE
#endif /* SHTPS_DYNAMIC_RESET_CONTROL_ENABLE */

#if defined( SHTPS_DRAG_SMOOTH_ENABLE )
	#define SHTPS_SHIFT_EDGE_INWARD_ENABLE
#endif /* SHTPS_DRAG_SMOOTH_ENABLE */

#if defined(SHTPS_CTRL_FW_REPORT_RATE) && defined(SHTPS_LOW_POWER_MODE_ENABLE)
	#define SHTPS_DEF_CTRL_FW_REPORT_RATE_LINKED_LCD_BRIGHT_ENABLE
#endif /* SHTPS_CTRL_FW_REPORT_RATE && SHTPS_LOW_POWER_MODE_ENABLE */

#if defined(SHTPS_CPU_CLOCK_CONTROL_ENABLE) && defined(SHTPS_LOW_POWER_MODE_ENABLE)
	#define SHTPS_DEF_CTRL_CPU_CLOCK_LINKED_LCD_BRIGHT_ENABLE
	#define SHTPS_DEF_CTRL_CPU_CLOCK_LINKED_ECO_ENABLE
#endif /* SHTPS_CPU_CLOCK_CONTROL_ENABLE && SHTPS_LOW_POWER_MODE_ENABLE */

#endif /*SHTPS_RELEASE_FOR_MANUFACTURER*/

/* -----------------------------------------------------------------------------------
 */
#endif /* __SHTPS_CFG_PLG543_001_3_H__ */
