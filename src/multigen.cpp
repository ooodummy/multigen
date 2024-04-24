#include "multigen.hpp"

int main() {
    const auto memory = std::make_unique<multigen::win32_memory>();

    // What should be done automatically with static analysis and then what should be done using mono/il2cpp dissection?
    // How should the backend be structured?
    std::string target_process = "target_process";

    HWND hwnd = FindWindowA(nullptr, target_process.c_str());
    if (hwnd == nullptr) {
        MessageBoxA(nullptr, "Failed to find process!", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    DWORD pid;
    if (!GetWindowThreadProcessId(hwnd, &pid)) {
        MessageBoxA(nullptr, "Failed to get process id!", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    if (!memory->attach(pid)) {
        MessageBoxA(nullptr, "Failed to attach to process!", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    return 0;
}