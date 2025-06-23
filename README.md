# HookBill

**HookBill** is a modular C++ game engine designed for learning, experimentation, and prototyping.  
It leverages modern C++17/20 features and popular open-source libraries including GLFW, GLM, ImGui, EnTT, and spdlog.

---

## 🚀 Features

- Modular architecture (Engine, Graphics, Game, Physics, Math)
- ECS-based game logic powered by [EnTT](https://github.com/skypjack/entt)
- OpenGL-based rendering with shader hot-reload and texture management
- Input and window handling via [GLFW](https://www.glfw.org/)
- Real-time UI debugging using [ImGui](https://github.com/ocornut/imgui)
- High-performance logging with [spdlog](https://github.com/gabime/spdlog)
- Designed for scalability and clean code structure

---

## 📁 Project Structure

```
HookBill/
├── Engine/       # Core engine systems (rendering, input, timing)
├── Graphics/     # Rendering pipeline, abstraction layers
├── Math/         # Math utilities (vectors, matrices)
├── Physics/      # Physics system (under development)
├── Game/         # Game logic and main entry point
├── assets/       # Shaders, textures, and game resources
├── extern/       # External libraries (GLFW, GLM, ImGui, EnTT, spdlog)
```

---

## 🛠 Build Instructions

### Requirements
- Visual Studio 2019 or later (Windows)
- OpenGL-compatible GPU
- C++17 or later support

### Steps
1. Clone the repository with submodules:
   ```bash
   git clone --recursive https://github.com/yourname/HookBill.git
   ```
2. Open `HookBill.sln` in Visual Studio.
3. Set the `Game` project as the startup project.
4. Build and run.

---

## 📸 Screenshots

*Coming soon...*

---

## 📄 License

This project is licensed under the MIT License.  
See the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Contributors

- Your Name (you@example.com)
- Other contributors...
