/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 *
 * Arduino Adafruit_SH1106 library API wrapper
 */

#include "Adafruit_SH1106.h"

Adafruit_SH1106 *mgos_sh1106_create_i2c(int w, int h, TwoWire& i2c) {
  return new Adafruit_SH1106(w, h, i2c);
}

void mgos_sh1106_close(Adafruit_SH1106 *ssd) {
  if (ssd != nullptr) {
    delete ssd;
    ssd = nullptr;
  }
}

void mgos_sh1106_begin(Adafruit_SH1106 *ssd, int vccstate, int i2caddr) {
  if (ssd == nullptr) return;
  ssd->begin(vccstate, i2caddr);
}

void mgos_sh1106_command(Adafruit_SH1106 *ssd, int c) {
  if (ssd == nullptr) return;
  ssd->SH1106_command(c);
}

void mgos_sh1106_clear_display(Adafruit_SH1106 *ssd) {
  if (ssd == nullptr) return;
  ssd->clearDisplay();
}

void mgos_sh1106_invert_display(Adafruit_SH1106 *ssd, int i) {
  if (ssd == nullptr) return;
  ssd->invertDisplay(i);
}

void mgos_sh1106_display(Adafruit_SH1106 *ssd) {
  if (ssd == nullptr) return;
  ssd->display();
}

// void mgos_sh1106_start_scroll_right(Adafruit_SH1106 *ssd, int start,
//                                      int stop) {
//   if (ssd == nullptr) return;
//   ssd->startscrollright(start, stop);
// }

// void mgos_sh1106_start_scroll_left(Adafruit_SH1106 *ssd, int start,
//                                     int stop) {
//   if (ssd == nullptr) return;
//   ssd->startscrollleft(start, stop);
// }

// void mgos_sh1106_start_scroll_diag_right(Adafruit_SH1106 *ssd, int start,
//                                           int stop) {
//   if (ssd == nullptr) return;
//   ssd->startscrolldiagright(start, stop);
// }

// void mgos_sh1106_start_scroll_diag_left(Adafruit_SH1106 *ssd, int start,
//                                          int stop) {
//   if (ssd == nullptr) return;
//   ssd->startscrolldiagleft(start, stop);
// }

// void mgos_sh1106_stop_scroll(Adafruit_SH1106 *ssd) {
//   if (ssd == nullptr) return;
//   ssd->stopscroll();
// }

// void mgos_sh1106_dim(Adafruit_SH1106 *ssd, int dim) {
//   if (ssd == nullptr) return;
//   ssd->dim(dim);
// }

void mgos_sh1106_draw_pixel(Adafruit_SH1106 *ssd, int x, int y, int color) {
  if (ssd == nullptr) return;
  ssd->drawPixel(x, y, color);
}

void mgos_sh1106_draw_fast_vline(Adafruit_SH1106 *ssd, int x, int y, int h,
                                  int color) {
  if (ssd == nullptr) return;
  ssd->drawFastVLine(x, y, h, color);
}

void mgos_sh1106_draw_fast_hline(Adafruit_SH1106 *ssd, int x, int y, int w,
                                  int color) {
  if (ssd == nullptr) return;
  ssd->drawFastHLine(x, y, w, color);
}

// Adafruit_GFX
int mgos_sh1106_make_xy_pair(int x, int y) {
  return ((int) x << 16) + y;
}

void mgos_sh1106_draw_circle(Adafruit_SH1106 *ssd, int x0y0, int r,
                              int color) {
  if (ssd == nullptr) return;
  ssd->drawCircle((x0y0 >> 16), x0y0, r, color);
}

void mgos_sh1106_draw_circle_helper(Adafruit_SH1106 *ssd, int x0y0, int r,
                                     int cornername, int color) {
  if (ssd == nullptr) return;
  ssd->drawCircleHelper((x0y0 >> 16), x0y0, r, cornername, color);
}

void mgos_sh1106_fill_circle(Adafruit_SH1106 *ssd, int x0y0, int r,
                              int color) {
  if (ssd == nullptr) return;
  ssd->fillCircle((x0y0 >> 16), x0y0, r, color);
}

void mgos_sh1106_fill_circle_helper(Adafruit_SH1106 *ssd, int x0y0, int r,
                                     int cornername, int delta, int color) {
  if (ssd == nullptr) return;
  ssd->fillCircleHelper((x0y0 >> 16), x0y0, r, cornername, delta, color);
}

void mgos_sh1106_draw_triangle(Adafruit_SH1106 *ssd, int x0y0, int x1y1,
                                int x2y2, int color) {
  if (ssd == nullptr) return;
  ssd->drawTriangle((x0y0 >> 16), x0y0, (x1y1 >> 16), x1y1, (x2y2 >> 16), x2y2,
                    color);
}

void mgos_sh1106_fill_triangle(Adafruit_SH1106 *ssd, int x0y0, int x1y1,
                                int x2y2, int color) {
  if (ssd == nullptr) return;
  ssd->fillTriangle((x0y0 >> 16), x0y0, (x1y1 >> 16), x1y1, (x2y2 >> 16), x2y2,
                    color);
}

void mgos_sh1106_draw_round_rect(Adafruit_SH1106 *ssd, int x0y0, int w, int h,
                                  int radius, int color) {
  if (ssd == nullptr) return;
  ssd->drawRoundRect((x0y0 >> 16), x0y0, w, h, radius, color);
}

void mgos_sh1106_fill_round_rect(Adafruit_SH1106 *ssd, int x0y0, int w, int h,
                                  int radius, int color) {
  if (ssd == nullptr) return;
  ssd->fillRoundRect((x0y0 >> 16), x0y0, w, h, radius, color);
}

void mgos_sh1106_draw_char(Adafruit_SH1106 *ssd, int xy, int c, int color,
                            int bg, int size) {
  if (ssd == nullptr) return;
  ssd->drawChar((xy >> 16), xy, c, color, bg, size);
}

void mgos_sh1106_set_cursor(Adafruit_SH1106 *ssd, int x, int y) {
  if (ssd == nullptr) return;
  ssd->setCursor(x, y);
}

void mgos_sh1106_set_text_color(Adafruit_SH1106 *ssd, int c) {
  if (ssd == nullptr) return;
  ssd->setTextColor(c);
}

void mgos_sh1106_set_text_color_bg(Adafruit_SH1106 *ssd, int c, int bg) {
  if (ssd == nullptr) return;
  ssd->setTextColor(c, bg);
}

void mgos_sh1106_set_text_size(Adafruit_SH1106 *ssd, int s) {
  if (ssd == nullptr) return;
  ssd->setTextSize(s);
}

void mgos_sh1106_set_text_wrap(Adafruit_SH1106 *ssd, boolean w) {
  if (ssd == nullptr) return;
  ssd->setTextWrap(w);
}

int mgos_sh1106_write(Adafruit_SH1106 *ssd, const char *buffer, int size) {
  if (ssd == nullptr) return 0;
  return ssd->Print::write(buffer, size);
}

int mgos_sh1106_height(Adafruit_SH1106 *ssd) {
  if (ssd == nullptr) return 0;
  return ssd->height();
}

int mgos_sh1106_width(Adafruit_SH1106 *ssd) {
  if (ssd == nullptr) return 0;
  return ssd->width();
}

int mgos_sh1106_get_rotation(Adafruit_SH1106 *ssd) {
  if (ssd == nullptr) return 0;
  return ssd->getRotation();
}

void mgos_sh1106_set_rotation(Adafruit_SH1106 *ssd, int rotation) {
  if (ssd == nullptr) return;
  ssd->setRotation(rotation);
}

// get current cursor position (get rotation safe maximum values, using: width()
// for x, height() for y)
int mgos_sh1106_get_cursor_x(Adafruit_SH1106 *ssd) {
  if (ssd == nullptr) return 0;
  return ssd->getCursorX();
}

int mgos_sh1106_get_cursor_y(Adafruit_SH1106 *ssd) {
  if (ssd == nullptr) return 0;
  return ssd->getCursorY();
}

bool mgos_arduino_sh1106_init(void){
    return true;
}
