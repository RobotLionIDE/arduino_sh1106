let Adafruit_SH1106 = {
    _ci2c: ffi('void *mgos_sh1106_create_i2c(int, int)'),
    _begin: ffi('void *mgos_sh1106_begin(void *, int, int)'),
    _cd: ffi('void *mgos_sh1106_clear_display(void *)'),
    _sts: ffi('void *mgos_sh1106_set_text_size(void *, int)'),
    _stc: ffi('void *mgos_sh1106_set_text_color(void *, int)'),
    _sc: ffi('void *mgos_sh1106_set_cursor(void *, int, int)'),
    _d: ffi('void *mgos_sh1106_display(void *)'),
    _w: ffi('int mgos_sh1106_write(void *, char *, int)'),
    _stw: ffi('void mgos_sh1106_set_text_wrap(void *, int)'),
    
  RES_96_16: 0,
  RES_128_32: 1,
  RES_128_64: 2,

  EXTERNALVCC: 1,
  SWITCHCAPVCC: 2,

  // ## **`Colors`**
  // - `Adafruit_SSD1306.BLACK`
  // - `Adafruit_SSD1306.WHITE`
  // - `Adafruit_SSD1306.INVERSE`
  BLACK: 0,
  WHITE: 1,
  INVERSE: 2,


create_i2c: function(h, w) {
    let obj = Object.create(Adafruit_SH1106._proto);
    // Initialize Adafruit_SH1106 library for I2C.
    // Return value: handle opaque pointer.
    // We set the reset pin and
    // Resolution: 0 - RES_96_16, 1 - RES_128_32, 2 - RES_128_64.
    obj.ssd = Adafruit_SH1106._ci2c(h, w);
    return obj;
  },
  
  
//////////////////////////////////////////////////////////////////////////////////////////
  _proto: {
    // ## **`mySH1106.close()`**
    // Close Adafruit_SH1106 instance. Return value: none.
    close: function() {
      return Adafruit_SH1106._close(this.ssd);
    },

    // ## **`mySH1106.begin(vccst, i2caddr, reset)`**
    // Initialize the display. `vccst` is a VCC state, one of those:
    // - `Adafruit_SH1106.EXTERNALVCC`
    // - `Adafruit_SH1106.SWITCHCAPVCC`
    // `i2caddr` is an I2C address (ignored if `create_spi` was used). `reset`
    // is a boolean; if true, then the display controller will be reset.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.begin(Adafruit_SH1106.EXTERNALVCC, 0x42, true);
    // ```
    begin: function(vccst, addr) {
      return Adafruit_SH1106._begin(this.ssd, vccst, addr);
    },

    // ## **`mySH1106.SH1106_command(cmd)`**
    // Send an arbitrary command `cmd`, which must be a number from 0 to 255.
    // Return value: none.
    SH1106_command: function(cmd) {
      return Adafruit_SH1106._cmd(this.ssd, cmd);
    },

    // ## **`mySH1106.clearDisplay()`**
    // Clear display. Return value: none.
    clearDisplay: function() {
      return Adafruit_SH1106._cd(this.ssd);
    },

    // ## **`mySH1106.invertDisplay(i)`**
    // Set invert mode: 0 - don't invert; 1 - invert. Return value: none.
    invertDisplay: function(i) {
      return Adafruit_SH1106._id(this.ssd, i);
    },

    // ## **`mySH1106.display()`**
    // Put image data to the display. Return value: none.
    display: function() {
      return Adafruit_SH1106._d(this.ssd);
    },

    // ## **`mySH1106.startScrollRight()`**
    // Activate a right handed scroll for rows from `start` to `stop`.
    // Return value: none.
    startScrollRight: function(start, stop) {
      return Adafruit_SH1106._ssr(this.ssd, start, stop);
    },

    // ## **`mySH1106.startScrollLeft()`**
    // Activate a left handed scroll for rows from `start` to `stop`.
    // Return value: none.
    startScrollLeft: function(start, stop) {
      return Adafruit_SH1106._ssl(this.ssd, start, stop);
    },

    // ## **`mySH1106.startScrollDiagRight()`**
    // Activate a diagonal scroll for rows from `start` to `stop`.
    // Return value: none.
    startScrollDiagRight: function(start, stop) {
      return Adafruit_SH1106._ssdr(this.ssd, start, stop);
    },

    // ## **`mySH1106.startScrollDiagLeft()`**
    // Activate a diagonal scroll for rows from `start` to `stop`.
    // Return value: none.
    startScrollDiagLeft: function(start, stop) {
      return Adafruit_SH1106._ssdl(this.ssd, start, stop);
    },

    // ## **`mySH1106.stopScroll()`**
    // Stop scrolling. Return value: none.
    stopScroll: function() {
      return Adafruit_SH1106._ss(this.ssd);
    },

    // ## **`mySH1106.dim(dim)`**
    // Set dim mode:
    // `dim` is 1: display is dimmed;
    // `dim` is 0: display is normal.
    // Return value: none.
    dim: function(dim) {
      return Adafruit_SH1106._dim(this.ssd, dim);
    },

    // ## **`mySH1106.drawPixel(x, y, color)`**
    // Set a single pixel with coords `x`, `y` to have the given `color`. See
    // available colors above.
    // Return value: none.
    drawPixel: function(x, y, color) {
      return Adafruit_SH1106._dp(this.ssd, x, y, color);
    },

    // ## **`mySH1106.drawFastVLine(x, y, h, color)`**
    // Draw a vertical line with height `h` starting from `x`, `y`, with color
    // `color`. See available colors above.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.drawFastVLine(10, 5, 15, Adafruit_SH1106.WHITE);
    // ```
    drawFastVLine: function(x, y, h, color) {
      return Adafruit_SH1106._dfvl(this.ssd, x, y, h, color);
    },

    // ## **`mySH1106.drawFastHLine(x, y, w, color)`**
    // Draw a horizontal line of width `w` starting from `x`, `y`, with color
    // `color`. See available colors above.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.drawFastHLine(10, 10, 20, Adafruit_SH1106.WHITE);
    // ```
    drawFastHLine: function(x, y, w, color) {
      return Adafruit_SH1106._dfhl(this.ssd, x, y, w, color);
    },

    // ## **`mySH1106.drawCircle(x, y, r, color)`**
    // Draw a circle with the radius `r`, centered at from `x`, `y`, with color
    // `color`. See available colors above.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.drawCircle(10, 10, 20, 10, 3, Adafruit_SH1106.WHITE);
    // ```
    drawCircle: function(x0, y0, r, color) {
      return Adafruit_SH1106._dc(this.ssd, Adafruit_SH1106._pair(x0, y0), r, color);
    },

    drawCircleHelper: function(x0, y0, r, cornername, color) {
      return Adafruit_SH1106._dchl(this.ssd, Adafruit_SH1106._pair(x0, y0), r, cornername, color);
    },

    // ## **`mySH1106.fillCircle(x, y, r, color)`**
    // Draw a filled circle with the radius `r`, centered at from `x`, `y`,
    // with color `color`. See available colors above.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.fillCircle(10, 10, 5, Adafruit_SH1106.WHITE);
    // ```
    fillCircle: function(x0, y0, r, color) {
      return Adafruit_SH1106._fc(this.ssd, Adafruit_SH1106._pair(x0, y0), r, color);
    },

    fillCircleHelper: function(x0, y0, r, cornername, delta, color) {
      return Adafruit_SH1106._fch(this.ssd, Adafruit_SH1106._pair(x0, y0), r, cornername, delta, color);
    },

    // ## **`mySH1106.drawTriangle(x0, y0, x1, y1, x2, y2, color)`**
    // Draw a triangle at the given coordinates, with color `color`. See
    // available colors above.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.drawTriangle(10, 0, 20, 20, 0, 20, Adafruit_SH1106.WHITE);
    // ```
    drawTriangle: function(x0, y0, x1, y1, x2, y2, color) {
      return Adafruit_SH1106._dt(this.ssd, Adafruit_SH1106._pair(x0, y0), Adafruit_SH1106._pair(x1, y1), Adafruit_SH1106._pair(x2, y2), color);
    },

    fillTriangle: function(x0, y0, x1, y1, x2, y2, color) {
      return Adafruit_SH1106._ft(this.ssd, Adafruit_SH1106._pair(x0, y0), Adafruit_SH1106._pair(x1, y1), Adafruit_SH1106._pair(x2, y2), color);
    },

    // ## **`mySH1106.drawRoundRect(x0, y0, w, h, radius, color)`**
    // Draw a rectangle with round corners; `x0`, `y0` are the coords of the
    // left-top corner, `w` is width, `h` is height, `radius` is the corners
    // radius, with color `color`. See available colors above.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.drawRoundRect(10, 10, 20, 10, 3, Adafruit_SH1106.WHITE);
    // ```
    drawRoundRect: function(x0, y0, w, h, radius, color) {
      return Adafruit_SH1106._drr(this.ssd, Adafruit_SH1106._pair(x0, y0), w, h, radius, color);
    },

    // ## **`mySH1106.drawRoundRect(x0, y0, w, h, radius, color)`**
    // Draw a filled rectangle with round corners; `x0`, `y0` are the coords of
    // the left-top corner, `w` is width, `h` is height, `radius` is the
    // corners radius, with color `color`. See available colors above.
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.fillRoundRect(10, 10, 20, 10, 3, Adafruit_SH1106.WHITE);
    // ```
    fillRoundRect: function(x0, y0, w, h, radius, color) {
      return Adafruit_SH1106._frr(this.ssd, Adafruit_SH1106._pair(x0, y0), w, h, radius, color);
    },

    // ## **`mySH1106.drawChar(x, y, c, color, bg, size)`**
    // Draw a character `c` starting at the point `x`, `y`, with the color
    // `color` (see available colors above). If `bg` is different from `color`,
    // then the background is filled with `bg`; otherwise bacground is left
    // intact.
    //
    // There is only one font (to save space) and it's meant to be 5x8 pixels,
    // but an optional `size` parameter which scales the font by this factor (e.g.
    // size=2 will render the text at 10x16 pixels per character).
    // Return value: none.
    // Example:
    // ```javascript
    // mySH1106.drawChar(10, 10, 'a',
    //                    Adafruit_SH1106.WHITE, Adafruit_SH1106.WHITE, 1);
    // ```
    drawChar: function(x, y, c, color, bg, size) {
      size = size || 1;
      return Adafruit_SH1106._dch(this.ssd, Adafruit_SH1106._pair(x, y), c.at(0), color, bg, size);
    },

    // ## **`mySH1106.setCursor(x, y)`**
    // Set text cursor for the following calls to `mySH1106.write()`.
    // See example for `write()` below.
    // Return value: none.
    setCursor: function(x, y) {
      return Adafruit_SH1106._sc(this.ssd, x, y);
    },

    // ## **`mySH1106.setTextColor(color)`**
    // Set text color for the following calls to `mySH1106.write()`. See
    // available colors above.
    // See example for `write()` below.
    // Return value: none.
    setTextColor: function(color) {
      return Adafruit_SH1106._stc(this.ssd, color);
    },

    // ## **`mySH1106.setTextColorBg(color, bg)`**
    // Set text color and background color for the following calls to
    // `mySH1106.write()`. If `bg` is equal to the `color`, then the
    // background will be left intact while drawing characters.
    // See example for `write()` below.
    // Return value: none.
    setTextColorBg: function(color, bg) {
      return Adafruit_SH1106._stcb(this.ssd, color, bg);
    },

    // ## **`mySH1106.setTextSize(size)`**
    // Set text color for the following calls to `mySH1106.write()`. There is
    // only one font (to save space) and it's meant to be 5x8 pixels, but an
    // optional `size` parameter which scales the font by this factor (e.g.
    // size=2 will render the text at 10x16 pixels per character).
    // See example for `write()` below.
    // Return value: none.
    setTextSize: function(size) {
      return Adafruit_SH1106._sts(this.ssd, size);
    },

    // ## **`mySH1106.setTextWrap(wrap)`**
    // Set text wrap mode (true or false) for the following calls to
    // `mySH1106.write()`.
    // See example for `write()` below.
    // Return value: none.
    setTextWrap: function(w) {
      return Adafruit_SH1106._stw(this.ssd, w);
    },

    // ## **`mySH1106.write(str)`**
    // Write given string `str` using the parameters set before (`setCursor()`,
    // `setTextColor()`, `setTextColorBg()`, `setTextSize()`, `setTextWrap()`)
    // Return value: 1.
    // Example:
    // ```javascript
    // mySH1106.setCursor(10, 10);
    // mySH1106.setTextColor(Adafruit_SH1106.WHITE);
    // mySH1106.setTextSize(2);
    // mySH1106.setTextWrap(true);
    // mySH1106.write("Hello world!");
    // ```
    write: function(str) {
      return Adafruit_SH1106._w(this.ssd, str, str.length);
    },

    // ## **`mySH1106.height()`**
    // Return display height in pixels.
    height: function() {
      return Adafruit_SH1106._ht(this.ssd);
    },

    // ## **`mySH1106.width()`**
    // Return display width in pixels.
    width: function() {
      return Adafruit_SH1106._wh(this.ssd);
    },

    // ## **`mySH1106.setRotation(rot)`**
    // Set display rotation:
    // - 0: no rotation
    // - 1: rotated at 90 degrees
    // - 2: rotated at 180 degrees
    // - 3: rotated at 270 degrees
    setRotation: function(rot) {
      return Adafruit_SH1106._sr(this.ssd, rot);
    },

    // ## **`mySH1106.getRotation()`**
    // Return rotation previously set with `setRotation()`
    getRotation: function() {
      return Adafruit_SH1106._gr(this.ssd);
    },

    // ## **`mySH1106.getCursorX()`**
    // Return cursor X coordinate, previously set with `setCursor()`.
    getCursorX: function() {
      return Adafruit_SH1106._gcx(this.ssd);
    },

    // ## **`mySH1106.getCursorY()`**
    // Return cursor Y coordinate, previously set with `setCursor()`.
    getCursorY: function() {
      return Adafruit_SH1106._gcy(this.ssd);
    },
  },

  
  
}
