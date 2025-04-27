#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#define PI 3.141592653589793238
typedef char UTF8;
typedef unsigned short UTF16;

struct Vec2 {
float x;
float y;
Vec2() {
this->x = 0;
this->y = 0;
}
Vec2(float x, float y) {
this->x = x;
this->y = y;
}
};

struct Vec3 {
float x;
float y;
float z;
Vec3() {
this->x = 0;
this->y = 0;
this->z = 0;
}
Vec3(float x, float y, float z) {
this->x = x;
this->y = y;
this->z = z;
}
};

struct Vec4 {
float x;
float y;
float z;
float w;
Vec4() {
this->x = 0;
this->y = 0;
this->z = 0;
this->w = 0;
}
Vec4(float x, float y, float z, float w) {
this->x = x;
this->y = y;
this->z = z;
this->w = w;
}
};

struct FMatrix {
float M[4][4];
};

struct Quat {
float x;
float y;
float z;
float w;
};

struct FTransform {
Quat Rotation;
Vec3 Translation;
float chunk;
Vec3 Scale3D;
};

struct BoneStruct {
Vec3 Pos; // 世界坐标 
Vec2 ScreenPos; // 屏幕坐标
bool CanSee; // 可见判断
};






// 计算骨骼
inline Vec3 MarixToVector(FMatrix matrix) {
return Vec3(matrix.M[3][0], matrix.M[3][1], matrix.M[3][2]);
}
// 计算骨骼
inline FMatrix MatrixMulti(FMatrix m1, FMatrix m2) {
FMatrix matrix = FMatrix();
for (int i = 0; i < 4; i++) {
for (int j = 0; j < 4; j++) {
for (int k = 0; k < 4; k++) {
matrix.M[i][j] += m1.M[i][k] * m2.M[k][j];
}
}
}
return matrix;
}
// 计算骨骼
inline FMatrix TransformToMatrix(FTransform transform) {
FMatrix matrix;
matrix.M[3][0] = transform.Translation.x;
matrix.M[3][1] = transform.Translation.y;
matrix.M[3][2] = transform.Translation.z;
float x2 = transform.Rotation.x + transform.Rotation.x;
float y2 = transform.Rotation.y + transform.Rotation.y;
float z2 = transform.Rotation.z + transform.Rotation.z;
float xx2 = transform.Rotation.x * x2;
float yy2 = transform.Rotation.y * y2;
float zz2 = transform.Rotation.z * z2;
matrix.M[0][0] = (1 - (yy2 + zz2)) * transform.Scale3D.x;
matrix.M[1][1] = (1 - (xx2 + zz2)) * transform.Scale3D.y;
matrix.M[2][2] = (1 - (xx2 + yy2)) * transform.Scale3D.z;
float yz2 = transform.Rotation.y * z2;
float wx2 = transform.Rotation.w * x2;
matrix.M[2][1] = (yz2 - wx2) * transform.Scale3D.z;
matrix.M[1][2] = (yz2 + wx2) * transform.Scale3D.y;
float xy2 = transform.Rotation.x * y2;
float wz2 = transform.Rotation.w * z2;
matrix.M[1][0] = (xy2 - wz2) * transform.Scale3D.y;
matrix.M[0][1] = (xy2 + wz2) * transform.Scale3D.x;
float xz2 = transform.Rotation.x * z2;
float wy2 = transform.Rotation.w * y2;
matrix.M[2][0] = (xz2 + wy2) * transform.Scale3D.z;
matrix.M[0][2] = (xz2 - wy2) * transform.Scale3D.x;
matrix.M[0][3] = 0;
matrix.M[1][3] = 0;
matrix.M[2][3] = 0;
matrix.M[3][3] = 1;
return matrix;
}




#endif