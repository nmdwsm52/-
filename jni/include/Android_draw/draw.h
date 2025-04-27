
#ifndef NATIVESURFACE_DRAW_H
#define NATIVESURFACE_DRAW_H

#include <timer.h>
#include <sys/stat.h>
#include "结构体.h"
#include "native_surface/ANativeWindowCreator.h"
#include <imgui_internal.h>
#include "imgui_impl_android.h"
#include "imgui_impl_vulkan.h"
#include "Android_vulkan/VulkanGraphics.h"
// #include "Android_draw/其他图片/自瞄关.h"
// #include "Android_draw/其他图片/自瞄开.h"
// namespace
using namespace std;
using namespace std::chrono_literals;
struct Screen {
    float ScreenX;
    float ScreenY;
};

extern VulkanGraphics VK;
extern ANativeWindow *native_window;

extern int init_screen_x, init_screen_y;
extern int Orientation;
extern int screen_x, screen_y;
extern android::ANativeWindowCreator::DisplayInfo displayInfo;

extern int init_vulkan(int _screen_x, int _screen_y, bool log = false);
void screen_config();
void ImGui_init();
void shutdown();
void OffScreen(Vec2 Obj, float camear, ImColor color, float Radius);
void VK_Begin();
void VK_End();


#endif //NATIVESURFACE_DRAW_H
