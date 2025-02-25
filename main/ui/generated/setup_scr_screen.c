/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

LV_FONT_DECLARE(font_alipuhui20);

void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->screen, lv_color_hex(0x6ff6ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->screen, 199, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_weather_card3
    ui->screen_cont_weather_card3 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_weather_card3, 220, 60);
    lv_obj_set_size(ui->screen_cont_weather_card3, 84, 175);
    lv_obj_set_scrollbar_mode(ui->screen_cont_weather_card3, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->screen_cont_weather_card3, LV_OBJ_FLAG_SCROLLABLE); // 禁用滚动

    //Write style for screen_cont_weather_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_weather_card3, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_weather_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_weather_card3, lv_color_hex(0x46d4fa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_weather_card3, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->screen_cont_weather_card3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->screen_cont_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->screen_cont_weather_card3, 187, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_weather_card3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_weather_card3, lv_color_hex(0x85dfff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_weather_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_weather_card3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_cont_weather_card3, -4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_cont_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_qing_card3
    ui->screen_img_qing_card3 = lv_img_create(ui->screen_cont_weather_card3);
    lv_obj_add_flag(ui->screen_img_qing_card3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_qing_card3, &_weather_qing_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_qing_card3, 50,50);
    lv_img_set_angle(ui->screen_img_qing_card3, 0);
    lv_obj_set_pos(ui->screen_img_qing_card3, -4, 31);
    lv_obj_set_size(ui->screen_img_qing_card3, 92, 95);
    lv_obj_add_flag(ui->screen_img_qing_card3, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_qing_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_qing_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_qing_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_qing_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_qing_card3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_yu_card3
    ui->screen_img_yu_card3 = lv_img_create(ui->screen_cont_weather_card3);
    lv_obj_add_flag(ui->screen_img_yu_card3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_yu_card3, &_yu1_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_yu_card3, 50,50);
    lv_img_set_angle(ui->screen_img_yu_card3, 0);
    lv_obj_set_pos(ui->screen_img_yu_card3, -4, 31);
    lv_obj_set_size(ui->screen_img_yu_card3, 92, 95);
    lv_obj_add_flag(ui->screen_img_yu_card3, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_yu_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_yu_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_yu_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_yu_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_yu_card3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_duoyun_card3
    ui->screen_img_duoyun_card3 = lv_img_create(ui->screen_cont_weather_card3);
    lv_obj_add_flag(ui->screen_img_duoyun_card3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_duoyun_card3, &_duoyun_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_duoyun_card3, 50,50);
    lv_img_set_angle(ui->screen_img_duoyun_card3, 0);
    lv_obj_set_pos(ui->screen_img_duoyun_card3, -4, 31);
    lv_obj_set_size(ui->screen_img_duoyun_card3, 92, 95);
    lv_obj_add_flag(ui->screen_img_duoyun_card3, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_duoyun_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_duoyun_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_duoyun_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_duoyun_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_duoyun_card3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_leidian_card3
    ui->screen_img_leidian_card3 = lv_img_create(ui->screen_cont_weather_card3);
    lv_obj_add_flag(ui->screen_img_leidian_card3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_leidian_card3, &_leidian_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_leidian_card3, 50,50);
    lv_img_set_angle(ui->screen_img_leidian_card3, 0);
    lv_obj_set_pos(ui->screen_img_leidian_card3, -4, 31);
    lv_obj_set_size(ui->screen_img_leidian_card3, 92, 95);
    lv_obj_add_flag(ui->screen_img_leidian_card3, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_leidian_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_leidian_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_leidian_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_leidian_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_leidian_card3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_yin_card3
    ui->screen_img_yin_card3 = lv_img_create(ui->screen_cont_weather_card3);
    lv_obj_add_flag(ui->screen_img_yin_card3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_yin_card3, &_yin_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_yin_card3, 50,50);
    lv_img_set_angle(ui->screen_img_yin_card3, 0);
    lv_obj_set_pos(ui->screen_img_yin_card3, -4, 29);
    lv_obj_set_size(ui->screen_img_yin_card3, 92, 95);
    lv_obj_add_flag(ui->screen_img_yin_card3, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_yin_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_yin_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_yin_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_yin_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_yin_card3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_weather_card3
    ui->screen_label_weather_card3 = lv_label_create(ui->screen_cont_weather_card3);
    lv_label_set_text(ui->screen_label_weather_card3, "晴");
    lv_label_set_long_mode(ui->screen_label_weather_card3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_weather_card3, 15, 119);
    lv_obj_set_size(ui->screen_label_weather_card3, 52, 22);

    //Write style for screen_label_weather_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_weather_card3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_weather_card3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_weather_card3, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_weather_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_weather_card3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_weather_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_temp_card3
    ui->screen_label_temp_card3 = lv_label_create(ui->screen_cont_weather_card3);
    lv_label_set_text(ui->screen_label_temp_card3, "17/5");
    lv_label_set_long_mode(ui->screen_label_temp_card3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_temp_card3, 6, 142);
    lv_obj_set_size(ui->screen_label_temp_card3, 73, 24);

    //Write style for screen_label_temp_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_temp_card3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_temp_card3, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_temp_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_temp_card3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_temp_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_date_card3
    ui->screen_label_date_card3 = lv_label_create(ui->screen_cont_weather_card3);
    lv_label_set_text(ui->screen_label_date_card3, "后天\n");
    lv_label_set_long_mode(ui->screen_label_date_card3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_date_card3, 18, 19);
    lv_obj_set_size(ui->screen_label_date_card3, 49, 22);

    //Write style for screen_label_date_card3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_date_card3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_date_card3, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_date_card3, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_date_card3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_date_card3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_date_card3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_weather_card2
    ui->screen_cont_weather_card2 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_weather_card2, 116, 60);
    lv_obj_set_size(ui->screen_cont_weather_card2, 84, 175);
    lv_obj_set_scrollbar_mode(ui->screen_cont_weather_card2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->screen_cont_weather_card2, LV_OBJ_FLAG_SCROLLABLE); // 禁用滚动

    //Write style for screen_cont_weather_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_weather_card2, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_weather_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_weather_card2, lv_color_hex(0x46d4fa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_weather_card2, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->screen_cont_weather_card2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->screen_cont_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->screen_cont_weather_card2, 187, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_weather_card2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_weather_card2, lv_color_hex(0x85dfff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_weather_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_weather_card2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_cont_weather_card2, -4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_cont_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_qing_card2
    ui->screen_img_qing_card2 = lv_img_create(ui->screen_cont_weather_card2);
    lv_obj_add_flag(ui->screen_img_qing_card2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_qing_card2, &_weather_qing_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_qing_card2, 50,50);
    lv_img_set_angle(ui->screen_img_qing_card2, 0);
    lv_obj_set_pos(ui->screen_img_qing_card2, -4, 31);
    lv_obj_set_size(ui->screen_img_qing_card2, 95, 95);
    lv_obj_add_flag(ui->screen_img_qing_card2, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_qing_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_qing_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_qing_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_qing_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_qing_card2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_yu_card2
    ui->screen_img_yu_card2 = lv_img_create(ui->screen_cont_weather_card2);
    lv_obj_add_flag(ui->screen_img_yu_card2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_yu_card2, &_yu1_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_yu_card2, 50,50);
    lv_img_set_angle(ui->screen_img_yu_card2, 0);
    lv_obj_set_pos(ui->screen_img_yu_card2, -4, 31);
    lv_obj_set_size(ui->screen_img_yu_card2, 92, 95);
    lv_obj_add_flag(ui->screen_img_yu_card2, LV_OBJ_FLAG_HIDDEN);
    

    //Write style for screen_img_yu_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_yu_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_yu_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_yu_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_yu_card2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_duoyun_card2
    ui->screen_img_duoyun_card2 = lv_img_create(ui->screen_cont_weather_card2);
    lv_obj_add_flag(ui->screen_img_duoyun_card2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_duoyun_card2, &_duoyun_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_duoyun_card2, 50,50);
    lv_img_set_angle(ui->screen_img_duoyun_card2, 0);
    lv_obj_set_pos(ui->screen_img_duoyun_card2, -4, 31);
    lv_obj_set_size(ui->screen_img_duoyun_card2, 92, 95);
    lv_obj_add_flag(ui->screen_img_duoyun_card2, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_duoyun_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_duoyun_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_duoyun_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_duoyun_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_duoyun_card2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_leidian_card2
    ui->screen_img_leidian_card2 = lv_img_create(ui->screen_cont_weather_card2);
    lv_obj_add_flag(ui->screen_img_leidian_card2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_leidian_card2, &_leidian_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_leidian_card2, 50,50);
    lv_img_set_angle(ui->screen_img_leidian_card2, 0);
    lv_obj_set_pos(ui->screen_img_leidian_card2, -4, 31);
    lv_obj_set_size(ui->screen_img_leidian_card2, 92, 95);
    lv_obj_add_flag(ui->screen_img_leidian_card2, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_leidian_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_leidian_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_leidian_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_leidian_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_leidian_card2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_yin_card2
    ui->screen_img_yin_card2 = lv_img_create(ui->screen_cont_weather_card2);
    lv_obj_add_flag(ui->screen_img_yin_card2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_yin_card2, &_yin_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_yin_card2, 50,50);
    lv_img_set_angle(ui->screen_img_yin_card2, 0);
    lv_obj_set_pos(ui->screen_img_yin_card2, -4, 29);
    lv_obj_set_size(ui->screen_img_yin_card2, 92, 95);
    lv_obj_add_flag(ui->screen_img_yin_card2, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_yin_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_yin_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_yin_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_yin_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_yin_card2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_weather_card2
    ui->screen_label_weather_card2 = lv_label_create(ui->screen_cont_weather_card2);
    lv_label_set_text(ui->screen_label_weather_card2, "晴");
    lv_label_set_long_mode(ui->screen_label_weather_card2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_weather_card2, 15, 119);
    lv_obj_set_size(ui->screen_label_weather_card2, 52, 22);

    //Write style for screen_label_weather_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_weather_card2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_weather_card2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_weather_card2, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_weather_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_weather_card2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_weather_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_temp_card2
    ui->screen_label_temp_card2 = lv_label_create(ui->screen_cont_weather_card2);
    lv_label_set_text(ui->screen_label_temp_card2, "17/5");
    lv_label_set_long_mode(ui->screen_label_temp_card2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_temp_card2, 6, 142);
    lv_obj_set_size(ui->screen_label_temp_card2, 73, 24);

    //Write style for screen_label_temp_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_temp_card2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_temp_card2, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_temp_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_temp_card2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_temp_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_date_card2
    ui->screen_label_date_card2 = lv_label_create(ui->screen_cont_weather_card2);
    lv_label_set_text(ui->screen_label_date_card2, "明天");
    lv_label_set_long_mode(ui->screen_label_date_card2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_date_card2, 18, 19);
    lv_obj_set_size(ui->screen_label_date_card2, 49, 22);

    //Write style for screen_label_date_card2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_date_card2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_date_card2, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_date_card2, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_date_card2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_date_card2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_date_card2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_weather_card1
    ui->screen_cont_weather_card1 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_weather_card1, 14, 60);
    lv_obj_set_size(ui->screen_cont_weather_card1, 84, 174);
    lv_obj_set_scrollbar_mode(ui->screen_cont_weather_card1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->screen_cont_weather_card1, LV_OBJ_FLAG_SCROLLABLE); // 禁用滚动

    //Write style for screen_cont_weather_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_weather_card1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_weather_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_weather_card1, lv_color_hex(0x46d4fa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_weather_card1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->screen_cont_weather_card1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->screen_cont_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->screen_cont_weather_card1, 187, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_weather_card1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_weather_card1, lv_color_hex(0x85dfff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_weather_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_weather_card1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_cont_weather_card1, -4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_cont_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_qing_card1
    ui->screen_img_qing_card1 = lv_img_create(ui->screen_cont_weather_card1);
    lv_obj_add_flag(ui->screen_img_qing_card1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_qing_card1, &_weather_qing_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_qing_card1, 50,50);
    lv_img_set_angle(ui->screen_img_qing_card1, 0);
    lv_obj_set_pos(ui->screen_img_qing_card1, -4, 31);
    lv_obj_set_size(ui->screen_img_qing_card1, 92, 95);
    lv_obj_add_flag(ui->screen_img_qing_card1, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_qing_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_qing_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_qing_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_qing_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_qing_card1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_yu_card1
    ui->screen_img_yu_card1 = lv_img_create(ui->screen_cont_weather_card1);
    lv_obj_add_flag(ui->screen_img_yu_card1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_yu_card1, &_yu1_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_yu_card1, 50,50);
    lv_img_set_angle(ui->screen_img_yu_card1, 0);
    lv_obj_set_pos(ui->screen_img_yu_card1, -4, 31);
    lv_obj_set_size(ui->screen_img_yu_card1, 92, 95);
    lv_obj_add_flag(ui->screen_img_yu_card1, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_yu_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_yu_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_yu_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_yu_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_yu_card1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_duoyun_card1
    ui->screen_img_duoyun_card1 = lv_img_create(ui->screen_cont_weather_card1);
    lv_obj_add_flag(ui->screen_img_duoyun_card1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_duoyun_card1, &_duoyun_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_duoyun_card1, 50,50);
    lv_img_set_angle(ui->screen_img_duoyun_card1, 0);
    lv_obj_set_pos(ui->screen_img_duoyun_card1, -4, 31);
    lv_obj_set_size(ui->screen_img_duoyun_card1, 92, 95);
    lv_obj_add_flag(ui->screen_img_duoyun_card1, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_duoyun_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_duoyun_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_duoyun_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_duoyun_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_duoyun_card1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_leidian_card1
    ui->screen_img_leidian_card1 = lv_img_create(ui->screen_cont_weather_card1);
    lv_obj_add_flag(ui->screen_img_leidian_card1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_leidian_card1, &_leidian_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_leidian_card1, 50,50);
    lv_img_set_angle(ui->screen_img_leidian_card1, 0);
    lv_obj_set_pos(ui->screen_img_leidian_card1, -4, 31);
    lv_obj_set_size(ui->screen_img_leidian_card1, 92, 95);
    lv_obj_add_flag(ui->screen_img_leidian_card1, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_leidian_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_leidian_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_leidian_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_leidian_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_leidian_card1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_yin_card1
    ui->screen_img_yin_card1 = lv_img_create(ui->screen_cont_weather_card1);
    lv_obj_add_flag(ui->screen_img_yin_card1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_yin_card1, &_yin_alpha_92x95);
    lv_img_set_pivot(ui->screen_img_yin_card1, 50,50);
    lv_img_set_angle(ui->screen_img_yin_card1, 0);
    lv_obj_set_pos(ui->screen_img_yin_card1, -4, 29);
    lv_obj_set_size(ui->screen_img_yin_card1, 92, 95);
    lv_obj_add_flag(ui->screen_img_yin_card1, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_img_yin_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_yin_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_yin_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_yin_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_yin_card1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_weather_card1
    ui->screen_label_weather_card1 = lv_label_create(ui->screen_cont_weather_card1);
    lv_label_set_text(ui->screen_label_weather_card1, "晴");
    lv_label_set_long_mode(ui->screen_label_weather_card1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_weather_card1, 15, 119);
    lv_obj_set_size(ui->screen_label_weather_card1, 52, 22);

    //Write style for screen_label_weather_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_weather_card1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_weather_card1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_weather_card1, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_weather_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_weather_card1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_weather_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_temp_card1
    ui->screen_label_temp_card1 = lv_label_create(ui->screen_cont_weather_card1);
    lv_label_set_text(ui->screen_label_temp_card1, "17/5");
    lv_label_set_long_mode(ui->screen_label_temp_card1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_temp_card1, 6, 142);
    lv_obj_set_size(ui->screen_label_temp_card1, 73, 24);

    //Write style for screen_label_temp_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_temp_card1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_temp_card1, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_temp_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_temp_card1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_temp_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_date_card1
    ui->screen_label_date_card1 = lv_label_create(ui->screen_cont_weather_card1);
    lv_label_set_text(ui->screen_label_date_card1, "今天");
    lv_label_set_long_mode(ui->screen_label_date_card1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_date_card1, 18, 19);
    lv_obj_set_size(ui->screen_label_date_card1, 49, 22);

    //Write style for screen_label_date_card1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_date_card1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_date_card1, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_date_card1, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_date_card1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_date_card1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_date_card1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_1
    ui->screen_cont_1 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_1, 0, 0);
    lv_obj_set_size(ui->screen_cont_1, 320, 40);
    lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_1, lv_color_hex(0x020202), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_timerinfo
    ui->screen_label_timerinfo = lv_label_create(ui->screen_cont_1);
    lv_label_set_text(ui->screen_label_timerinfo, "2025/2/8   星期五  15:02:55");
    lv_label_set_long_mode(ui->screen_label_timerinfo, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_timerinfo, 40, 3);
    lv_obj_set_size(ui->screen_label_timerinfo, 260, 32);

    //Write style for screen_label_timerinfo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_timerinfo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_timerinfo, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_timerinfo, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_timerinfo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_timerinfo, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_timerinfo, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_timerinfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_location
    ui->screen_label_location = lv_label_create(ui->screen);
    lv_label_set_text(ui->screen_label_location, "--");
    lv_label_set_long_mode(ui->screen_label_location, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_location, 18, 37);
    lv_obj_set_size(ui->screen_label_location, 44, 18);

    //Write style for screen_label_location, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_location, lv_color_hex(0x969696), LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui->screen_label_location, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_location, &font_alipuhui20, 0);
    lv_obj_set_style_text_opa(ui->screen_label_location, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_location, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.
    lv_obj_t *wifi_icon_label = lv_label_create(ui->screen);
    lv_label_set_text(wifi_icon_label, LV_SYMBOL_WIFI);  // LVGL自带的WiFi符号
    lv_obj_align(wifi_icon_label, LV_ALIGN_TOP_LEFT, 5, 13);  // 设置位置
    lv_obj_set_style_text_color(wifi_icon_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);  // 设置图标颜色

    lv_obj_t *location_icon_label = lv_label_create(ui->screen);
    lv_label_set_text(location_icon_label, LV_SYMBOL_GPS);  // LVGL自带的GPS符号
    lv_obj_align(location_icon_label, LV_ALIGN_TOP_LEFT, 5, 41);  // 设置位置
    lv_obj_set_style_text_color(location_icon_label, lv_color_hex(0x969696), LV_PART_MAIN);  // 设置图标颜色



    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
