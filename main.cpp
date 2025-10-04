#include "minuitwrp/minui.h"
#include "minuitwrp/resources.hpp"
#include "minuitwrp/graphics.h"
#include "minuitwrp/graphics_fbdev.h"
#include "minuitwrp/events.h"
#include <unistd.h>
#include <string>

int main() {
    // Initialize graphics
    gr_init();

    // Clear the screen to black
    gr_color(0, 0, 0, 255);
    gr_clear();

    // Set draw color to white
    gr_color(255, 255, 255, 255);

    // Choose a font from TWRes
    SetFont("roboto_regular");

    std::string text = "Hello, world from minuitwrp!";

    // Get surface dimensions
    int w = gr_fb_width();
    int h = gr_fb_height();

    // Compute a roughly centered position
    int text_w = gr_measure(text.c_str());
    int x = (w - text_w) / 2;
    int y = h / 2;

    // Draw text
    gr_text(x, y, text.c_str(), false);

    // Flip buffer to display
    gr_flip();
    vibrate(500);

    // Wait a bit
    sleep(5);

    // Shut down graphics cleanly
    gr_exit();

    return 0;
}
