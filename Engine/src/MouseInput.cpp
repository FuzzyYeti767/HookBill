#include "MouseInput.h"

namespace HookBill
{
    void MouseInput::Init(float screenWidth, float screenHeight)
    {
        lastX = screenWidth / 2.0f;
        lastY = screenHeight / 2.0f;
        firstUpdate = true;
    }

    void MouseInput::Update(float currentX, float currentY)
    {
        if (firstUpdate)
        {
            lastX = currentX;
            lastY = currentY;
            firstUpdate = false;
        }

        deltaX = currentX - lastX;
        deltaY = currentY - lastY;

        lastX = currentX;
        lastY = currentY;
    }

    float MouseInput::GetDeltaX()
    {
        return deltaX;
    }

    float MouseInput::GetDeltaY()
    {
        return deltaY;
    }

    void MouseInput::ResetDelta()
    {
        deltaX = 0.0f;
        deltaY = 0.0f;
    }


}
