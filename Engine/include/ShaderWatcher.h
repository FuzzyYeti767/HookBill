
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>

class ShaderWatcher {
public:
    void Watch(const std::string& shader_name,
        const std::filesystem::path& vertex_path,
        const std::filesystem::path& fragment_path);

    std::vector<std::string> PollChangedShaders();

private:
    struct FileTime {
        std::filesystem::file_time_type vertex_time;
        std::filesystem::file_time_type fragment_time;
    };

    std::unordered_map<std::string, std::pair<std::filesystem::path, std::filesystem::path>> paths;
    std::unordered_map<std::string, FileTime> last_times;
};

