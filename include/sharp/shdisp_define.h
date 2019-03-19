/* include/sharp/shdisp_define.h  (Display Driver)
 *
 * Copyright (C) 2014 SHARP CORPORATION
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

#ifndef SHDISP_DEFINE_H
#define SHDISP_DEFINE_H

/* ------------------------------------------------------------------------- */
/* MACROS                                                                    */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
#define SHDISP_TRV_NM2
#define SHDISP_LOWBKL

#define SHDISP_SYSFS_LED
/* ------------------------------------------------------------------------- */
#if defined(CONFIG_ARCH_LYNX_DL80) || defined(FEATURE_SH_MODEL_DL80)
#define SHDISP_COLOR_LED_TWIN
#define SHDISP_DL
#define SHDISP_MODEL_FS

#define SHDISP_ALS_INT
#define SHDISP_LED_INT
#define SHDISP_ANIME_COLOR_LED
#define SHDISP_ILLUMI_COLOR_LED

#define USER_CONFIG_SHDISP_PANEL_HAYABUSA
#define SHDISP_MAIN_WIDTH  1080
#define SHDISP_MAIN_HEIGHT 1920
/* ------------------------------------------------------------------------- */
#elif defined(CONFIG_ARCH_LYNX_DL85) || defined(FEATURE_SH_MODEL_DL85)
#if defined(CONFIG_ARCH_LYNX_DL83) || defined(FEATURE_SH_MODEL_DL83)
#define SHDISP_EXTEND_COLOR_LED
#define SHDISP_ILLUMI_TRIPLE_COLOR_LED
#endif /* CONFIG_ARCH_LYNX_DL83 */
#define SHDISP_COLOR_LED_TWIN
#define SHDISP_DL
#define SHDISP_MODEL_MID

#define SHDISP_ALS_INT
#define SHDISP_LED_INT
#define SHDISP_ANIME_COLOR_LED
#define SHDISP_ILLUMI_COLOR_LED

#define USER_CONFIG_SHDISP_PANEL_HAYABUSA
#define SHDISP_MAIN_WIDTH  1080
#define SHDISP_MAIN_HEIGHT 1920
/* ------------------------------------------------------------------------- */
#elif defined(CONFIG_ARCH_DECKARD_AL25) || defined(FEATURE_SH_MODEL_AL25)
#define SHDISP_COLOR_LED_TWIN
#define SHDISP_AL
#define SHDISP_MODEL_MID

#define SHDISP_ALS_INT
#define SHDISP_LED_INT
#define SHDISP_ANIME_COLOR_LED
#define SHDISP_ILLUMI_COLOR_LED

#define USER_CONFIG_SHDISP_PANEL_HAYABUSA
#define SHDISP_MAIN_WIDTH  1080
#define SHDISP_MAIN_HEIGHT 1920
/* ------------------------------------------------------------------------- */
#elif defined(CONFIG_ARCH_PA30) || defined(FEATURE_SH_MODEL_PA30)
#define SHDISP_COLOR_LED_TWIN
#define SHDISP_PA
#define SHDISP_MODEL_FS

#define SHDISP_ALS_INT
#define SHDISP_LED_INT
#define SHDISP_ANIME_COLOR_LED
#define SHDISP_ILLUMI_COLOR_LED

#define USER_CONFIG_SHDISP_PANEL_HAYABUSA
#define SHDISP_MAIN_WIDTH  1080
#define SHDISP_MAIN_HEIGHT 1920
/* ------------------------------------------------------------------------- */
#elif defined(CONFIG_ARCH_PA31) || defined(FEATURE_SH_MODEL_PA31)
#define SHDISP_COLOR_LED_TWIN
#define SHDISP_PA
#define SHDISP_MODEL_MID

#define SHDISP_ALS_INT
#define SHDISP_LED_INT
#define SHDISP_ANIME_COLOR_LED
#define SHDISP_ILLUMI_COLOR_LED

#define USER_CONFIG_SHDISP_PANEL_HAYABUSA
#define SHDISP_MAIN_WIDTH  1080
#define SHDISP_MAIN_HEIGHT 1920
/* ------------------------------------------------------------------------- */
#else  /* defined(CONFIG_ARCH_XXX) */
#define SHDISP_NOT_SUPPORT_DET
#define SHDISP_COLOR_LED_TWIN
#define SHDISP_DL
#define SHDISP_MODEL_FS

#define SHDISP_ALS_INT
#define SHDISP_LED_INT
#define SHDISP_ANIME_COLOR_LED
#define SHDISP_ILLUMI_COLOR_LED

#define USER_CONFIG_SHDISP_PANEL_ANDY
#define SHDISP_MAIN_WIDTH  1080
#define SHDISP_MAIN_HEIGHT 1920
/* ------------------------------------------------------------------------- */
#endif  /* defined(CONFIG_ARCH_XXX) */


#ifdef USER_CONFIG_SHDISP_PANEL_HAYABUSA
#define SHDISP_FPS_HIGH_ENABLE
#endif  /* USER_CONFIG_SHDISP_PANEL_HAYABUSA */


#ifndef CONFIG_SHDISP_PANEL_GEMINI
#if defined(SHDISP_FACTORY_MODE_ENABLE)
#if !defined(SHDISP_NOT_SUPPORT_DET)
#define SHDISP_NOT_SUPPORT_DET
#endif  /* !defined(SHDISP_NOT_SUPPORT_DET) */
#endif  /* defined(SHDISP_FACTORY_MODE_ENABLE) */
#endif  /* CONFIG_SHDISP_PANEL_GEMINI */

#endif /* SHDISP_DEFINE_H */
/* ------------------------------------------------------------------------- */
/* END OF FILE                                                               */
/* ------------------------------------------------------------------------- */
