/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_cont_weather_card3;
	lv_obj_t *screen_img_qing_card3;
	lv_obj_t *screen_img_yu_card3;
	lv_obj_t *screen_img_duoyun_card3;
	lv_obj_t *screen_img_leidian_card3;
	lv_obj_t *screen_img_yin_card3;
	lv_obj_t *screen_label_weather_card3;
	lv_obj_t *screen_label_temp_card3;
	lv_obj_t *screen_label_date_card3;
	lv_obj_t *screen_cont_weather_card2;
	lv_obj_t *screen_img_qing_card2;
	lv_obj_t *screen_img_yu_card2;
	lv_obj_t *screen_img_duoyun_card2;
	lv_obj_t *screen_img_leidian_card2;
	lv_obj_t *screen_img_yin_card2;
	lv_obj_t *screen_label_weather_card2;
	lv_obj_t *screen_label_temp_card2;
	lv_obj_t *screen_label_date_card2;
	lv_obj_t *screen_cont_weather_card1;
	lv_obj_t *screen_img_qing_card1;
	lv_obj_t *screen_img_yu_card1;
	lv_obj_t *screen_img_duoyun_card1;
	lv_obj_t *screen_img_leidian_card1;
	lv_obj_t *screen_img_yin_card1;
	lv_obj_t *screen_label_weather_card1;
	lv_obj_t *screen_label_temp_card1;
	lv_obj_t *screen_label_date_card1;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_label_timerinfo;
	lv_obj_t *screen_label_location;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_btn_1;
	lv_obj_t *screen_1_btn_1_label;
	lv_obj_t *screen_1_cont_alarm;
	lv_obj_t *screen_1_roller_hour;
	lv_obj_t *screen_1_roller_min;
	lv_obj_t *screen_1_label_alarm;
	lv_obj_t *screen_1_btn_confirm;
	lv_obj_t *screen_1_label_confirm;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
LV_IMG_DECLARE(_weather_qing_alpha_92x95);
LV_IMG_DECLARE(_yu1_alpha_92x95);
LV_IMG_DECLARE(_duoyun_alpha_92x95);
LV_IMG_DECLARE(_leidian_alpha_92x95);
LV_IMG_DECLARE(_yin_alpha_92x95);
LV_IMG_DECLARE(_weather_qing_alpha_95x95);
LV_IMG_DECLARE(_yu1_alpha_92x95);
LV_IMG_DECLARE(_duoyun_alpha_92x95);
LV_IMG_DECLARE(_leidian_alpha_92x95);
LV_IMG_DECLARE(_yin_alpha_92x95);
LV_IMG_DECLARE(_weather_qing_alpha_92x95);
LV_IMG_DECLARE(_yu1_alpha_92x95);
LV_IMG_DECLARE(_duoyun_alpha_92x95);
LV_IMG_DECLARE(_leidian_alpha_92x95);
LV_IMG_DECLARE(_yin_alpha_92x95);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_27)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_montserratMedium_12)


#ifdef __cplusplus
}
#endif
#endif
