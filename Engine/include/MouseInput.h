#pragma once
namespace HookBill
{
    class MouseInput
    {
    public:
        static void Init(float screenWidth, float screenHeight);
        static void Update(float currentX, float currentY);
        static float GetDeltaX();
        static float GetDeltaY();
        static void ResetDelta();

    private:
        static inline float lastX = 0.0f;
        static inline float lastY = 0.0f;
        static inline float deltaX = 0.0f;
        static inline float deltaY = 0.0f;
        static inline bool firstUpdate = true;
    };
}
