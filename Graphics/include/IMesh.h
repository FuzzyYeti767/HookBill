#pragma once
class IMesh
{
public:
    virtual ~IMesh() = default;
    virtual void Draw() const = 0; // 순수 가상 함수
};
