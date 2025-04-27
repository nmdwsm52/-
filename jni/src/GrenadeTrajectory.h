#ifndef GRENADE_TRAJECTORY_H
#define GRENADE_TRAJECTORY_H

#include <vector>
#include <unordered_map>
#include <chrono>
#include <imgui.h>
/*
我在搞不用管他
*/
// 3D 向量结构体
struct Vec3 {
    float x, y, z;
};

// 轨迹点结构体
struct GrenadePath {
    Vec3 position;   // 手雷位置
    float timeStamp; // 时间戳，用于控制轨迹消失
};

class GrenadeTrajectory {
public:
    // 构造函数，初始化轨迹存活时间
    GrenadeTrajectory(float lifespan = 1.2f) : lifespan(lifespan) {}

    // 更新手雷位置，记录轨迹点
    void Update(Vec3 grenadePos);

    // 绘制手雷轨迹
    void Draw();

    // 获取手雷轨迹点的数量
    size_t GetPathSize() const { return path.size(); }

private:
    float lifespan;  // 手雷轨迹的存活时间
    std::vector<GrenadePath> path;  // 存储手雷轨迹点

    // 获取当前时间戳（单位：秒）
    float GetCurrentTime() const;

    // 清理已经超时的轨迹点
    void CleanUpOldPaths(float currentTime);

    // 世界坐标转屏幕坐标
    ImVec2 WorldToScreen(const Vec3& pos) const;
};

// 存储所有手雷轨迹，以 ObjAddr 为键
static std::unordered_map<uintptr_t, GrenadeTrajectory> grenadeTrajectories;

// 更新并绘制手雷轨迹
inline void UpdateAndDrawGrenade(uintptr_t objAddr, Vec3 grenadePos) {
    // 查找手雷的轨迹对象，如果没有则创建
    auto& grenadeTrajectory = grenadeTrajectories[objAddr];

    // 更新轨迹
    grenadeTrajectory.Update(grenadePos);

    // 绘制轨迹
    grenadeTrajectory.Draw();
}

// 在此函数中更新手雷位置，记录轨迹点
inline void GrenadeTrajectory::Update(Vec3 grenadePos) {
    float currentTime = GetCurrentTime();
    path.push_back({ grenadePos, currentTime });

    // 清理超时的轨迹点
    CleanUpOldPaths(currentTime);
}

// 绘制手雷轨迹
inline void GrenadeTrajectory::Draw() {
    for (size_t i = 0; i < path.size(); ++i) {
        const GrenadePath& point = path[i];

        // 计算屏幕坐标
        ImVec2 screenPos = WorldToScreen(point.position);

        // 绘制轨迹点
        ImGui::GetBackgroundDrawList()->AddCircleFilled(screenPos, 2.5f, IM_COL32(255, 0, 0, 200));

        // 绘制与前一个点的连线（如果不是第一个点）
        if (i > 0) {
            const GrenadePath& prevPoint = path[i - 1];
            ImVec2 prevScreenPos = WorldToScreen(prevPoint.position);
            ImGui::GetBackgroundDrawList()->AddLine(prevScreenPos, screenPos, IM_COL32(255, 255, 255, 255), 2.0f);
        }
    }
}

// 获取当前时间戳（单位：秒）
inline float GrenadeTrajectory::GetCurrentTime() const {
    return static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count()) / 1000.0f;
}

// 清理已经超时的轨迹点
inline void GrenadeTrajectory::CleanUpOldPaths(float currentTime) {
    // 删除已经超过 lifespan 时间的路径点
    while (!path.empty() && (currentTime - path.front().timeStamp) > lifespan) {
        path.erase(path.begin());
    }
}

// 世界坐标转屏幕坐标
inline ImVec2 GrenadeTrajectory::WorldToScreen(const Vec3& pos) const {
    // 假设 ptr 和 screen_x, screen_y 是全局可用的，你可以根据你的具体项目调整
    float camera = ptr.Matrix[3] * pos.x + ptr.Matrix[7] * pos.y + ptr.Matrix[11] * pos.z + ptr.Matrix[15];
    float r_x = (screen_x / 2) + (ptr.Matrix[0] * pos.x + ptr.Matrix[4] * pos.y + ptr.Matrix[8] * pos.z + ptr.Matrix[12]) / camera * (screen_x / 2);
    float r_y = (screen_y / 2) - (ptr.Matrix[1] * pos.x + ptr.Matrix[5] * pos.y + ptr.Matrix[9] * pos.z + ptr.Matrix[13]) / camera * (screen_y / 2);
    return ImVec2(r_x, r_y);
}

#endif // GRENADE_TRAJECTORY_H
