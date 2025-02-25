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
#include "time_sync.h"

LV_FONT_DECLARE(font_alipuhui20);

// 将回调函数移到setup_scr_screen_1函数外
static void btn_confirm_event_cb(lv_event_t * e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    if(lv_event_get_code(e) == LV_EVENT_CLICKED) {
        char buf[32];
        lv_roller_get_selected_str(ui->screen_1_roller_hour, buf, sizeof(buf));
        char hour[3] = {buf[0], buf[1], '\0'};
        
        lv_roller_get_selected_str(ui->screen_1_roller_min, buf, sizeof(buf));
        char min[3] = {buf[0], buf[1], '\0'};
        
        char alarm_text[32];
        snprintf(alarm_text, sizeof(alarm_text), "闹钟时间: %s:%s", hour, min);
        lv_label_set_text(ui->screen_1_label_alarm, alarm_text);

        // 设置闹钟时间
        set_alarm_time(atoi(hour), atoi(min));
    }
}

void setup_scr_screen_1(lv_ui *ui)
{
    //Write codes screen_1
    ui->screen_1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    // 创建显示框
    lv_obj_t * alarm_display = lv_obj_create(ui->screen_1);
    lv_obj_set_size(alarm_display, 200, 40);
    lv_obj_align(alarm_display, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_style_bg_color(alarm_display, lv_color_hex(0xf0f0f0), LV_PART_MAIN);
    lv_obj_set_style_border_width(alarm_display, 1, LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(alarm_display, LV_SCROLLBAR_MODE_OFF);  // 禁用滚动条

    // 创建显示闹钟时间的标签
    ui->screen_1_label_alarm = lv_label_create(alarm_display);
    lv_label_set_text(ui->screen_1_label_alarm, "未设置闹钟");
    lv_obj_center(ui->screen_1_label_alarm);
    lv_obj_set_style_text_font(ui->screen_1_label_alarm, &font_alipuhui20, 0);

    // 创建一个容器来放置闹钟设置组件
    ui->screen_1_cont_alarm = lv_obj_create(ui->screen_1);
    lv_obj_set_size(ui->screen_1_cont_alarm, 260, 160);
    lv_obj_align(ui->screen_1_cont_alarm, LV_ALIGN_CENTER, 0, 20);  // 将y偏移从0改为20,使容器向下移动
    lv_obj_set_style_bg_color(ui->screen_1_cont_alarm, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_pad_all(ui->screen_1_cont_alarm, 10, LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(ui->screen_1_cont_alarm, LV_SCROLLBAR_MODE_OFF);  // 禁用滚动条
    lv_obj_clear_flag(ui->screen_1_cont_alarm, LV_OBJ_FLAG_SCROLLABLE); // 禁用滚动

    // 创建小时滚动条
    ui->screen_1_roller_hour = lv_roller_create(ui->screen_1_cont_alarm);
    lv_obj_set_width(ui->screen_1_roller_hour, 50);
    lv_roller_set_options(ui->screen_1_roller_hour,
                        "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n"
                        "12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23",
                        LV_ROLLER_MODE_NORMAL);
    lv_obj_align(ui->screen_1_roller_hour, LV_ALIGN_LEFT_MID, 20, 0);
    lv_obj_set_style_text_font(ui->screen_1_roller_hour, &lv_font_montserrat_20, LV_PART_MAIN);
    lv_roller_set_visible_row_count(ui->screen_1_roller_hour, 3);  // 设置可见行数

    // 创建分钟滚动条
    ui->screen_1_roller_min = lv_roller_create(ui->screen_1_cont_alarm);
    lv_obj_set_width(ui->screen_1_roller_min, 50);
    lv_roller_set_options(ui->screen_1_roller_min,
                        "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n"
                        "10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n"
                        "20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n"
                        "30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n"
                        "40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n"
                        "50\n51\n52\n53\n54\n55\n56\n57\n58\n59",
                        LV_ROLLER_MODE_NORMAL);
    lv_obj_align(ui->screen_1_roller_min, LV_ALIGN_LEFT_MID, 90, 0);
    lv_obj_set_style_text_font(ui->screen_1_roller_min, &lv_font_montserrat_20, LV_PART_MAIN);
    lv_roller_set_visible_row_count(ui->screen_1_roller_min, 3);  // 设置可见行数

    // 添加冒号标签
    lv_obj_t * label_colon = lv_label_create(ui->screen_1_cont_alarm);
    lv_label_set_text(label_colon, ":");
    lv_obj_align(label_colon, LV_ALIGN_LEFT_MID, 75, 0);
    lv_obj_set_style_text_font(label_colon, &lv_font_montserrat_20, 0);

    // 创建确认按钮
    ui->screen_1_btn_confirm = lv_btn_create(ui->screen_1_cont_alarm);
    lv_obj_set_size(ui->screen_1_btn_confirm, 80, 40);
    lv_obj_align(ui->screen_1_btn_confirm, LV_ALIGN_LEFT_MID, 160, 0);
    ui->screen_1_label_confirm = lv_label_create(ui->screen_1_btn_confirm);
    lv_label_set_text(ui->screen_1_label_confirm, "确认");
    lv_obj_center(ui->screen_1_label_confirm);
    lv_obj_set_style_text_font(ui->screen_1_label_confirm, &font_alipuhui20, 0);

    // 添加按钮点击事件回调
    lv_obj_add_event_cb(ui->screen_1_btn_confirm, btn_confirm_event_cb, LV_EVENT_CLICKED, ui);

    //Update current screen layout.
    lv_obj_update_layout(ui->screen_1);

    //Init events for screen.
    events_init_screen_1(ui);
}
