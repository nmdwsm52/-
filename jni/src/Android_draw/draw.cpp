
#include <draw.h>
#include <array>
#include "font2.h"
#include "font.h"
VulkanGraphics VK;
ANativeWindow *native_window;
Screen full_screen;
int Orientation = 0;
int screen_x = 0, screen_y = 0;
int init_screen_x = 0, init_screen_y = 0;
android::ANativeWindowCreator::DisplayInfo displayInfo;

string exec(string command) {
char buffer[128];
string result = "";
FILE* pipe = popen(command.c_str(), "r");
if (!pipe) {
return "popen failed!";
}
while (!feof(pipe)) {
if (fgets(buffer, 128, pipe) != nullptr)
result += buffer;
}
pclose(pipe);
return result;
}


int init_vulkan(int _screen_x, int _screen_y, bool flp) {
native_window = android::ANativeWindowCreator::Create("Ssage", _screen_x, _screen_y, flp);;
ANativeWindow_acquire(native_window);
VK.Create(native_window, _screen_x, _screen_y);
return 1;
}


void screen_config() {
displayInfo = android::ANativeWindowCreator::GetDisplayInfo();
screen_x = displayInfo.width;
screen_y = displayInfo.height;
Orientation = displayInfo.orientation;
}



void ImGui_init() {
IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImGuiIO& io = ImGui::GetIO();
io.IniFilename = NULL;
 
ImGui_ImplAndroid_Init(native_window);
VK.Setup();  //初始化vk数据
io.Fonts->AddFontFromMemoryTTF((void *) font_data, font_size, 35.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
io.Fonts->AddFontFromMemoryTTF((void *)font2_data, font2_size, 35.0f, NULL, NULL);
}


void VK_Begin() {
screen_config();
ImGui_ImplVulkan_NewFrame(); //开始新的vk帧
ImGui_ImplAndroid_NewFrame(screen_x, screen_y);
ImGui::NewFrame();
}

void VK_End() {
ImGui::Render();
VK.Render(ImGui::GetDrawData());  //使用vk进行渲染
}


void shutdown(){
ImGui_ImplVulkan_Shutdown();
ImGui_ImplAndroid_Shutdown(); 
ImGui::DestroyContext();
VK.PrepareShutdown();
VK.Cleanup();
ANativeWindow_release(native_window);
android::ANativeWindowCreator::Destroy(native_window);
}

void OffScreen(Vec2 Obj, float camear, ImColor color, float Radius) {
ImRect screen_rect = {0.0f, 0.0f, screen_x, screen_y};
auto screen_center = screen_rect.GetCenter();
auto angle = atan2(screen_center.y - Obj.y, screen_center.x - Obj.x);
angle += camear > 0 ? M_PI : 0.0f;
Vec2 arrow_center {
screen_center.x + Radius * cosf(angle),
screen_center.y + Radius * sinf(angle)
};
std::array<ImVec2, 4>points {
ImVec2(-22.0f, -8.6f),
ImVec2(0.0f, 0.0f),
ImVec2(-22.0f, 8.6f),
ImVec2(-18.0f, 0.0f)
};
for (auto & point : points) {
auto x = point.x * 1.155f;
auto y = point.y * 1.155f;
point.x = arrow_center.x + x * cosf(angle) - y * sinf(angle);
point.y = arrow_center.y + x * sinf(angle) + y * cosf(angle);
}
float alpha = 1.0f;
if (camear > 0) {
constexpr float nearThreshold = 200 * 200;
ImVec2 screen_outer_diff = {
Obj.x < 0 ? abs(Obj.x) : (Obj.x > screen_rect.Max.x ? Obj.x - screen_rect.Max.x : 0.0f),
Obj.y < 0 ? abs(Obj.y) : (Obj.y > screen_rect.Max.y ? Obj.y - screen_rect.Max.y : 0.0f),
};
float distance = static_cast<float>(pow(screen_outer_diff.x, 2) + pow(screen_outer_diff.y, 2));
alpha = camear < 0 ? 1.0f : (distance / nearThreshold);
}
ImColor arrowColor = color;
arrowColor.Value.w = std::min(alpha, 1.0f);
ImGui::GetBackgroundDrawList()->AddTriangleFilled(points[0], points[1], points[3], arrowColor);
ImGui::GetBackgroundDrawList()->AddTriangleFilled(points[2], points[1], points[3], arrowColor);
ImGui::GetBackgroundDrawList()->AddQuad(points[0], points[1], points[2], points[3], ImColor(0.0f, 0.0f, 0.0f, alpha), 1.335f);
}
