
#include"opengl-window.h"
#include<iostream>
// settings
const unsigned int SCR_WIDTH = 1800;
const unsigned int SCR_HEIGHT = 1600;


int HookBill_opengl::create_window(std::string windowname)
{
    // glfw: initialize and configure
    // ------------------------------
    if (!glfwInit())
    {
        std::cout << "GLFW Initialization failed!" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    // glfw window creation
    // --------------------
    window_ptr = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,windowname.c_str(), nullptr, nullptr);
    if (window_ptr == nullptr)
    {
        std::cout << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window_ptr);
    glfwSwapInterval(1); // Enable V-Sync

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD!" << std::endl;
        return -1;
    }

    
    return 0;
}


void HookBill_opengl::update_window()
{
    glfwSwapBuffers(window_ptr);

    glfwPollEvents();
}

bool HookBill_opengl::ShouldCloseWindow()
{
    if (window_ptr == nullptr)
    {
        std::cout << "sex " << '\n';
    }
    return glfwWindowShouldClose(window_ptr);
}

void HookBill_opengl::set_window_user_pointer(void* user_data)
{
    if (window_ptr)
    {
        glfwSetWindowUserPointer(window_ptr, user_data);
    }
}



void HookBill_opengl::shutdown_window()
{

    glfwTerminate();
}



