//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
//开源频道@BY520A
#include "draw.h"

#include "My_font/zh_Font.h"
#include "My_font/fontawesome-brands.h"
#include "My_font/fontawesome-regular.h"
#include "My_font/fontawesome-solid.h"
#include "My_font/gui_icon.h"
   
#include "My_icon/pic_ZhenAiKun_png.h"
#include "My_Custom/imgui_settings.h"
#include "imgui_freetype.h"
#include "My_font2/Fonts.h"
#include "blur.hpp"

static int slider_int[25];

static bool checkboxBool[60] = {0};
static float color_edit[10][4];

static int keybind[10];
static int combo[10];

static int iTabs = 0;
static int iSubTabs = 0;



bool permeate_record = false;
bool permeate_record_ini = false;
struct Last_ImRect LastCoordinate = {0, 0, 0, 0};


std::unique_ptr<AndroidImgui> graphics;
ANativeWindow *window = NULL; 
android::ANativeWindowCreator::DisplayInfo displayInfo;// 屏幕信息
ImGuiWindow *g_window = NULL;// 窗口信息
int abs_ScreenX = 0, abs_ScreenY = 0;// 绝对屏幕X _ Y
int native_window_screen_x = 0, native_window_screen_y = 0;

TextureInfo Aekun_image{};

ImFont* zh_font = NULL;
ImFont* icon_font_0 = NULL;
ImFont* icon_font_1 = NULL;
ImFont* icon_font_2 = NULL;


void Trinage_background()
{

    //ImVec2 screen_size = { (float)GetSystemMetrics(SM_CXSCREEN), (float)GetSystemMetrics(SM_CYSCREEN) };
    ImVec2 screen_size = ImVec2( displayInfo.width, displayInfo.height );

    static ImVec2 partile_pos[100];
    static ImVec2 partile_target_pos[100];
    static float partile_speed[100];
    static float partile_size[100];
    static float partile_radius[100];
    static float partile_rotate[100];

    for (int i = 1; i < 50; i++)
    {
        if (partile_pos[i].x == 0 || partile_pos[i].y == 0)
        {
            partile_pos[i].x = rand() % (int)screen_size.x + 1;
            partile_pos[i].y = screen_size.y + 30;
            partile_speed[i] = 70 + rand() % 135;
            partile_radius[i] = 2 + rand() % 10;
            partile_size[i] = 15 + rand() % 40;

            partile_target_pos[i].x = rand() % (int)screen_size.x;
            partile_target_pos[i].y = -50;
        }

        partile_pos[i].y -= ImGui::GetIO().DeltaTime * partile_speed[i];
        partile_rotate[i] -= ImGui::GetIO().DeltaTime;

        if (partile_pos[i].y < 10)
        {
            partile_pos[i].x = 0;
            partile_pos[i].y = 0;
            partile_rotate[i] = 0;
        }

        ImRotateStart();
        ImGui::GetWindowDrawList()->AddShadowRect(partile_pos[i] - ImVec2(partile_size[i], partile_size[i]), partile_pos[i] + ImVec2(partile_size[i], partile_size[i]), ImColor(0.f, 0.f, 0.f, 0.5f), 15.f, ImVec2(0,0), ImDrawFlags_ShadowCutOutShapeBackground, 15.f);
        ImGui::GetWindowDrawList()->AddRectFilled(partile_pos[i] - ImVec2(partile_size[i], partile_size[i]), partile_pos[i] + ImVec2(partile_size[i], partile_size[i]), GetColorWithAlpha(main_color, 0.3f), 5.f);
        ImRotateEnd(partile_rotate[i]);
    }
}

bool M_Android_LoadFont(float SizePixels) {
    ImGuiIO &io = ImGui::GetIO();
    
    //ImFontConfig config; //oppo字体部分
    //config.FontDataOwnedByAtlas = false;
    //config.SizePixels = SizePixels;
    //config.OversampleH = 1;
    //::zh_font = io.Fonts->AddFontFromMemoryTTF((void *)OPPOSans_H, OPPOSans_H_size, 0.0f, &config, io.Fonts->GetGlyphRangesChineseFull());    
    ////io.Fonts->AddFontDefault(&config);

	static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 3.0;
    icons_config.OversampleV = 3.0;		
    icons_config.SizePixels = SizePixels;
    //icons_config.GlyphOffset.y += 7.0f; // 通过 GlyphOffset 调整单个字形偏移量，向下偏移 size 像素
	::icon_font_0 = io.Fonts->AddFontFromMemoryCompressedTTF((const void *)&font_awesome_brands_compressed_data, sizeof(font_awesome_brands_compressed_data), 0.0f, &icons_config, icons_ranges);
	::icon_font_1 = io.Fonts->AddFontFromMemoryCompressedTTF((const void *)&font_awesome_regular_compressed_data, sizeof(font_awesome_regular_compressed_data), 0.0f, &icons_config, icons_ranges);
	::icon_font_2 = io.Fonts->AddFontFromMemoryCompressedTTF((const void *)&font_awesome_solid_compressed_data, sizeof(font_awesome_solid_compressed_data), 0.0f, &icons_config, icons_ranges);

    io.Fonts->AddFontDefault();
    return zh_font != nullptr;
}
void init_My_drawdata() {
    //ImGui::StyleColorsLight(); //白色
    //ImGui::My_Android_LoadSystemFont(25.0f); //(加载系统字体 安卓15完美适配)
    //M_Android_LoadFont(25.0f); //加载字体(还有图标)
    //ImGui::GetStyle().ScaleAllSizes(3.25f);
    ::Aekun_image = graphics->LoadTextureFromMemory((void *)picture_ZhenAiKun_PNG_H, sizeof(picture_ZhenAiKun_PNG_H));


    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImFontConfig config;

    ImFontConfig config2;
    config.MergeMode = false; // ������ ����� ����� ����������� ��������

    config2.FontBuilderFlags = ImGuiFreeTypeBuilderFlags::ImGuiFreeTypeBuilderFlags_Bold; // ������������ ����� ������ ���������

    config.FontBuilderFlags = ImGuiFreeTypeBuilderFlags::ImGuiFreeTypeBuilderFlags_LightHinting; // ������������ ����� ������ ���������
    config.OversampleH = 25; // ��������� �������������� ������������� �����������
    config.OversampleV = 25; // ��������� ������������ ������������� �����������
    config.PixelSnapH = true; // ��������� ����� �� �������� ��������

    io.Fonts->AddFontFromMemoryTTF(&NunitoMedium, sizeof NunitoMedium, 21, &config, io.Fonts->GetGlyphRangesCyrillic());

    medium_font = io.Fonts->AddFontFromMemoryTTF(&NunitoMedium, sizeof NunitoMedium, 18, &config, io.Fonts->GetGlyphRangesCyrillic());

    small_font = io.Fonts->AddFontFromMemoryTTF(&NunitoMedium, sizeof NunitoMedium, 17, &config, io.Fonts->GetGlyphRangesCyrillic());

    icon_font = io.Fonts->AddFontFromMemoryTTF(&icomoon, sizeof icomoon, 18, &config, io.Fonts->GetGlyphRangesCyrillic());

    icon_big_font = io.Fonts->AddFontFromMemoryTTF(&icomoon, sizeof icomoon, 23, &config, io.Fonts->GetGlyphRangesCyrillic());

    logo_font = io.Fonts->AddFontFromMemoryTTF(&NunitoMedium, sizeof NunitoMedium, 25, &config2, io.Fonts->GetGlyphRangesCyrillic());

    small_icon_font = io.Fonts->AddFontFromMemoryTTF(&NunitoMedium, sizeof NunitoMedium, 15, &config, io.Fonts->GetGlyphRangesCyrillic());

    arrow_icons = io.Fonts->AddFontFromMemoryTTF(&arrowicon, sizeof arrowicon, 18, &config, io.Fonts->GetGlyphRangesCyrillic());

    ImGui::StyleColorsDark();

    //ImGui_ImplWin32_Init(hwnd);
    //ImGui_ImplDX9_Init(g_pd3dDevice);

    ImVec4 clear_color = ImVec4(0.01f, 0.01f, 0.01f, 1.00f);

    ImGuiStyle& s = ImGui::GetStyle();

    s.FramePadding = ImVec2(10, 10);
    s.ItemSpacing = ImVec2(10, 5);
    s.FrameRounding = 5.f;
    s.WindowRounding = 15.f;
    s.WindowBorderSize = 0.f;
    s.PopupBorderSize = 0.f;
    s.WindowPadding = ImVec2(0, 0);
    s.ChildBorderSize = 0.0001f;
    s.Colors[ImGuiCol_WindowBg] = winbg_color;
    s.Colors[ImGuiCol_Border] = ImVec4(0.f, 0.f, 0.f, 0.f);
    s.WindowShadowSize = 0;
    s.PopupRounding = 5.f;
    s.PopupBorderSize = 1.3f;
    s.ScrollbarSize = 4.f;
    s.ScrollbarRounding = 10.f;

}


void screen_config() {
    ::displayInfo = android::ANativeWindowCreator::GetDisplayInfo();
}

void drawBegin() {
    if (::permeate_record_ini) {
        LastCoordinate.Pos_x = ::g_window->Pos.x;
        LastCoordinate.Pos_y = ::g_window->Pos.y;
        LastCoordinate.Size_x = ::g_window->Size.x;
        LastCoordinate.Size_y = ::g_window->Size.y;

        graphics->Shutdown();
        android::ANativeWindowCreator::Destroy(::window);
        ::window = android::ANativeWindowCreator::Create("test_sysGui", native_window_screen_x, native_window_screen_y, permeate_record);
        graphics->Init_Render(::window, native_window_screen_x, native_window_screen_y);
        ::init_My_drawdata(); //初始化绘制数据
    } 


    static uint32_t orientation = -1;
    screen_config();
    if (orientation != displayInfo.orientation) {
        orientation = displayInfo.orientation;
        Touch::setOrientation(displayInfo.orientation);
        if (g_window != NULL) {
            g_window->Pos.x = 100;
            g_window->Pos.y = 125;        
        }        
        //cout << " width:" << displayInfo.width << " height:" << displayInfo.height << " orientation:" << displayInfo.orientation << endl;
    }
}


void Layout_tick_UI(bool *main_thread_flag) {
    static bool show_draw_Line = false;
    static bool show_demo_window = false;
    static bool show_another_window = false;

    ImGuiStyle& s = ImGui::GetStyle();

    ImGui::SetNextWindowSize(ImVec2(1050, 700));
    ImGui::Begin("General", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoBringToFrontOnFocus);
    {
        anim_speed = ImGui::GetIO().DeltaTime * 12.f;

        auto draw = ImGui::GetWindowDrawList();
        const auto& p = ImGui::GetWindowPos();

        blur::add_blur(ImGui::GetBackgroundDrawList(), p, ImVec2(p.x + 1050, p.y + 700), 1.f);

        draw->AddRectFilled(p + ImVec2(0, 55), p + ImVec2(1050, 700), winbg_color, s.WindowRounding, ImDrawFlags_RoundCornersBottom);

        Trinage_background();

        ImGui::PushClipRect(p + ImVec2(0, 55), p + ImVec2(187, 700), true);
        blur::add_blur(ImGui::GetWindowDrawList(), p, ImVec2(p.x + 1050, p.y + 700), 1.f);
        ImGui::PopClipRect();

        ImGui::PushClipRect(p, p + ImVec2(1050, 55), true);
        blur::add_blur(ImGui::GetWindowDrawList(), p, ImVec2(p.x + 1050, p.y + 700), 1.f);
        ImGui::PopClipRect();

        draw->AddRectFilled(p + ImVec2(0, 55), p + ImVec2(187, 700), ImColor(13, 14, 16, 229), s.WindowRounding, ImDrawFlags_RoundCornersBottomLeft);

        draw->AddRectFilled(p, p + ImVec2(1050, 55), ImColor(5, 5, 5, 45), s.WindowRounding, ImDrawFlags_RoundCornersTop);
        draw->AddRectFilled(p + ImVec2(0, 52), p + ImVec2(1050, 55), main_color, s.WindowRounding);

        ImGui::PushFont(logo_font);
        draw->AddText(center_text(p, p + ImVec2(1050, 52), "Your Menu"), ImColor(1.f, 1.f, 1.f, 1.f), "Yours Menu");
        ImGui::PopFont();

        ImGui::SetCursorPos(ImVec2(10, 70));
        ImGui::BeginGroup();
        ImGui::TextColored(ImVec4(1.f, 1.f, 1.f, 0.3f), "Aimbot");
        ImGui::Tab("Legitbot", "9", &iTabs, 0);
        ImGui::Tab("Ragebot", "0", &iTabs, 1);
        ImGui::TextColored(ImVec4(1.f, 1.f, 1.f, 0.3f), "Visuals");
        ImGui::Tab("Wallhack", "8", &iTabs, 2);
        ImGui::Tab("Chams", "5", &iTabs, 3);
        ImGui::TextColored(ImVec4(1.f, 1.f, 1.f, 0.3f), "Others");
        ImGui::Tab("Misc", "1", &iTabs, 4);
        ImGui::Tab("Lua API", "2", &iTabs, 5);
        ImGui::EndGroup();

        ImGui::SetCursorPos(ImVec2(197, 72));
        ImGui::BeginGroup();
        {
            ImGui::BeginChild("Frame##1", ImVec2(frame_size.x, 628), true); // 628 = 700 - margins
            {
                ImGui::Checkbox("Enable", &checkboxBool[50]);
                ImGui::SliderInt("FOV", &slider_int[1], 0, 100);
                ImGui::Checkbox("Auto wall", &checkboxBool[51]);
                ImGui::Checkbox("Auto fire", &checkboxBool[52]);
                ImGui::Checkbox("Silent aim", &checkboxBool[53]);
                ImGui::Checkbox("Quick peek", &checkboxBool[54]);
                ImGui::ColorEdit4("Glow color", (float*)color_edit[0], ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);
                ImGui::ColorEdit4("Main color", (float*)&main_color.Value, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);

                const char* bones[] = {
                    "Head", "Neck", "Spine1", "Spine2", "Spine3",
                    "Spine4", "RightClavicle", "RightUpperArm", "RightForearm",
                };

                ImGui::Combo("Bones", &combo[0], bones, IM_ARRAYSIZE(bones));
            }
            ImGui::EndChild();

            ImGui::SameLine();

            ImGui::BeginChild("Frame##2", ImVec2(frame_size.x, 628), true);
            {
                ImGui::Checkbox("Enable", &checkboxBool[0]);
                ImGui::Checkbox("Silent Aim", &checkboxBool[1]);
                ImGui::Checkbox("Target Dead", &checkboxBool[2]);
                ImGui::Checkbox("Magic Bullet", &checkboxBool[3]);
                ImGui::Checkbox("Preview Aimbot FOV", &checkboxBool[4]);
                ImGui::Checkbox("Filled FOV", &checkboxBool[5]);
                Pickerbox("Aimbot FOV", &checkboxBool[10], (float*)color_edit[1]);
                Keybindbox("Keybind", &checkboxBool[11], &keybind[0]);
                ImGui::SliderInt("Smooth flow", &slider_int[0], 0, 100);

                const char* bones[] = {
                    "Head", "Neck", "Spine1", "Spine2", "Spine3",
                    "Spine4", "RightClavicle", "RightUpperArm", "RightForearm",
                };

                ImGui::Combo("Bones Enemy", &combo[2], bones, IM_ARRAYSIZE(bones));
            }
            ImGui::EndChild();
        }
        ImGui::EndGroup();

        foremenu_drawlist = ImGui::GetWindowDrawList();
    }
    ImGui::End();
}