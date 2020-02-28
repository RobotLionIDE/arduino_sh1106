/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CS_MOS_LIBS_ARDUINO_ADAFRUIT_SH1106_SRC_MGOS_ARDUINO_SH1106_H_
#define CS_MOS_LIBS_ARDUINO_ADAFRUIT_SH1106_SRC_MGOS_ARDUINO_SH1106_H_

class Adafruit_SH1106;
class TwoWire;

bool mgos_arduino_sh1106_init(void);

/*
 * Create and return an Adafruit_SH1106 instance for I2C.
 * - w   - display width
 * - h   - display height
 * - i2c - i2c channel
 */
Adafruit_SH1106 *mgos_sh1106_create_i2c(int w, int h, TwoWire& i2c);

/*
 * Close Adafruit_SH1106 indstance.
 */
void mgos_sh1106_close(Adafruit_SH1106 *ssd);

/*
 * Initialize the display. `vccstate` is a VCC state, one of those:
 * - `SH1106_EXTERNALVCC`
 * - `SH1106_SWITCHCAPVCC`
 * `i2caddr` is an I2C address (ignored if `create_spi` was used).
 * If `reset` is true, then the display controller will be reset.
 * Example:
 * ```javascript
 * mySH1106 = mgos_sh1106_create_i2c(12, MGOS_SH1106_RES_96_16);
 * mgos_sh1106_begin(mySH1106, SH1106_EXTERNALVCC, 0x42, true);
 * ```
 */
void mgos_sh1106_begin(Adafruit_SH1106 *ssd, int vccstate, int i2caddr);

/*
 * Send an arbitrary command `cmd`, which must be a number from 0 to 255.
 */
void mgos_sh1106_command(Adafruit_SH1106 *ssd, int c);

/*
 * Clear display.
 */
void mgos_sh1106_clear_display(Adafruit_SH1106 *ssd);

/*
 * Set invert mode: 0 - don't invert; 1 - invert.
 */
void mgos_sh1106_invert_display(Adafruit_SH1106 *ssd, int i);

/*
 * Put image data to the display.
 */
void mgos_sh1106_display(Adafruit_SH1106 *ssd);

/*
 * Activate a right handed scroll for rows `start` through `stop`.
 */
//void mgos_sh1106_start_scroll_right(Adafruit_SH1106 *ssd, int start,
//                                    int stop);

/*
 * Activate a left handed scroll for rows `start` through `stop`.
 */
//void mgos_sh1106_start_scroll_left(Adafruit_SH1106 *ssd, int start, int stop);

/*
 * Activate a diagonal scroll for rows `start` through `stop`.
 */
//void mgos_sh1106_start_scroll_diag_right(Adafruit_SH1106 *ssd, int start,
//                                          int stop);

/*
 * Activate a diagonal scroll for rows `start` through `stop`.
 */
//void mgos_sh1106_start_scroll_diag_left(Adafruit_SH1106 *ssd, int start,
//                                         int stop);

/*
 * Stop scroll.
 */
//void mgos_sh1106_stop_scroll(Adafruit_SH1106 *ssd);

/*
 * Set dim mode:
 * dim is 1: display is dimmed;
 * dim is 0: display is normal.
 */
//void mgos_sh1106_dim(Adafruit_SH1106 *ssd, int dim);

/*
 * Set a single pixel at `x`, `y` to have the given `color`, the color being
 * one of the following: `BLACK`, `WHITE`, `INVERSE`.
 */
void mgos_sh1106_draw_pixel(Adafruit_SH1106 *ssd, int x, int y, int color);

/*
 * Draw a vertical line with height `h`, starting at `x`, `y`, with color
 * `color` (`BLACK`, `WHITE` or `INVERSE`)
 */
void mgos_sh1106_draw_fast_vline(Adafruit_SH1106 *ssd, int x, int y, int h,
                                  int color);

/*
 * Draw a horizontal line with width `w`, starting at `x`, `y`, with color
 * `color` (`BLACK`, `WHITE` or `INVERSE`)
 */
void mgos_sh1106_draw_fast_hline(Adafruit_SH1106 *ssd, int x, int y, int w,
                                  int color);

/*
 * Adafruit_GFX
 */
int mgos_sh1106_make_xy_pair(int x, int y);

void mgos_sh1106_draw_circle(Adafruit_SH1106 *ssd, int x0y0, int r,
                              int color);

void mgos_sh1106_draw_circle_helper(Adafruit_SH1106 *ssd, int x0y0, int r,
                                     int cornername, int color);

void mgos_sh1106_fill_circle(Adafruit_SH1106 *ssd, int x0y0, int r,
                              int color);

void mgos_sh1106_fill_circle_helper(Adafruit_SH1106 *ssd, int x0y0, int r,
                                     int cornername, int delta, int color);

void mgos_sh1106_draw_triangle(Adafruit_SH1106 *ssd, int x0y0, int x1y1,
                                int x2y2, int color);

void mgos_sh1106_fill_triangle(Adafruit_SH1106 *ssd, int x0y0, int x1y1,
                                int x2y2, int color);

void mgos_sh1106_draw_round_rect(Adafruit_SH1106 *ssd, int x0y0, int w, int h,
                                  int radius, int color);

void mgos_sh1106_fill_round_rect(Adafruit_SH1106 *ssd, int x0y0, int w, int h,
                                  int radius, int color);

void mgos_sh1106_draw_char(Adafruit_SH1106 *ssd, int xy, int c, int color,
                            int bg, int size);

void mgos_sh1106_set_cursor(Adafruit_SH1106 *ssd, int x, int y);

void mgos_sh1106_set_text_color(Adafruit_SH1106 *ssd, int c);
void mgos_sh1106_set_text_color_bg(Adafruit_SH1106 *ssd, int c, int bg);
void mgos_sh1106_set_text_size(Adafruit_SH1106 *ssd, int s);
void mgos_sh1106_set_text_wrap(Adafruit_SH1106 *ssd, boolean w);

int mgos_sh1106_write(Adafruit_SH1106 *ssd, const char *buffer, int size);

int mgos_sh1106_height(Adafruit_SH1106 *ssd);
int mgos_sh1106_width(Adafruit_SH1106 *ssd);

int mgos_sh1106_get_rotation(Adafruit_SH1106 *ssd);
void mgos_sh1106_set_rotation(Adafruit_SH1106 *ssd, int rotation);

/*
 * get current cursor position (get rotation safe maximum values, using: width()
 * for x, height() for y)
 */
int mgos_sh1106_get_cursor_x(Adafruit_SH1106 *ssd);
int mgos_sh1106_get_cursor_y(Adafruit_SH1106 *ssd);

#endif /* CS_MOS_LIBS_ARDUINO_ADAFRUIT_SH1106_SRC_MGOS_ARDUINO_SH1106_H_ */
