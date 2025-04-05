
#include "ShaderWatcher.h"

void ShaderWatcher::Watch(const std::string& name,
    const std::filesystem::path& vert,
    const std::filesystem::path& frag)
{
    paths[name] = { vert, frag };
    last_times[name] = {
        std::filesystem::last_write_time(vert),
        std::filesystem::last_write_time(frag)
    };
}

std::vector<std::string> ShaderWatcher::PollChangedShaders()
{
    std::vector<std::string> changed;

    for (const auto& [name, path_pair] : paths) {
        auto cur_vert = std::filesystem::last_write_time(path_pair.first);
        auto cur_frag = std::filesystem::last_write_time(path_pair.second);
        auto& last = last_times[name];

        if (cur_vert != last.vertex_time || cur_frag != last.fragment_time) {
            changed.push_back(name);
            last = { cur_vert, cur_frag };
        }
    }

    return changed;
}
