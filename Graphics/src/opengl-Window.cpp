
#include"opengl-window.h"
#include<iostream>
// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;


int HookBill_opengl::create_window(std::string windowname)
{
    // glfw: initialize and configure
    // ------------------------------
    if (!glfwInit())
    {
        std::cout << "GLFW Initialization failed!" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);


    // glfw window creation
    // --------------------
    window_ptr = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,windowname.c_str(), nullptr, nullptr);
    //glfwSetWindowTitle(window_ptr, ""); // 창 제목 제거
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
    glViewport(0,0, SCR_WIDTH,SCR_HEIGHT);
    
    return 0;
}


void HookBill_opengl::update_window()
{
    glfwPollEvents();

    //glfwSwapBuffers(window_ptr);

   
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



void HookBill_opengl::InitializeFrameBuffer(int width, int height)
{
   
    // FBO 생성
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    // 텍스처 생성 (프레임버퍼의 렌더링 결과를 담을 텍스처)
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // 깊이 버퍼 생성
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rbo);

    // 텍스처를 프레임버퍼에 연결
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

  

}