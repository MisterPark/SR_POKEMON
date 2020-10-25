#include "stdafx.h"
#include "Quaternion.h"

PKH::Quaternion::Quaternion() :D3DXQUATERNION()
{
}

PKH::Quaternion::Quaternion(const FLOAT* r) :D3DXQUATERNION(r)
{
}

PKH::Quaternion::Quaternion(FLOAT fx, FLOAT fy, FLOAT fz, FLOAT fw) : D3DXQUATERNION(fx,fy,fz,fw)
{
}

PKH::Quaternion::Quaternion(const D3DXQUATERNION& r) :D3DXQUATERNION(r)
{
}

PKH::Quaternion::~Quaternion()
{
}

Vector3 PKH::Quaternion::ToEulerAngles(const Quaternion& q1)
{
    float sqw = q1.w * q1.w;
    float sqx = q1.x * q1.x;
    float sqy = q1.y * q1.y;
    float sqz = q1.z * q1.z;
    float unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
    float test = q1.x * q1.w - q1.y * q1.z;
    Vector3 v;

    if (test > 0.4995f * unit)  // singularity at north pole // ���ݱ�
    {
        v.y = 2.f * atan2f(q1.y, q1.x);
        v.x = D3DX_PI / 2;
        v.z = 0;
        return v;
    }

    if (test < -0.4995f * unit)  // singularity at south pole // �Ϲݱ�
    {
        v.y = -2.f * atan2f(q1.y, q1.x);
        v.x = -D3DX_PI / 2;
        v.z = 0;

        return v;
    }

    Quaternion q(q1.w, q1.z, q1.x, q1.y);

    v.y = atan2f(2.f * q.x * q.w + 2.f * q.y * q.z, 1 - 2.f * (q.z * q.z + q.w * q.w));     // Yaw
    v.x = -asinf(2.f * (q.x * q.z - q.w * q.y));                             // Pitch
    v.z = -atan2f(2.f * q.x * q.y + 2.f * q.z * q.w, 1 - 2.f * (q.y * q.y + q.z * q.z));      // Roll
    
    // �������� ������ �� (���� ������ �������� ����)
    // pitch �� ���̳ʽ� ��ȣ�� �ٲ�
    // roll �� ���̳ʽ� ��ȣ�� �ٲ�

    return v;
}
