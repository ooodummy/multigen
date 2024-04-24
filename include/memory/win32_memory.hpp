#ifndef MULTIGEN_MEMORY_WIN32_MEMORY_HPP
#define MULTIGEN_MEMORY_WIN32_MEMORY_HPP

#include "base_memory.hpp"

namespace multigen {
    class win32_memory : public base_memory {
    public:
        bool attach(uint32_t pid) override{
            process_handle_ = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
            return process_handle_ != nullptr;
        }

        // Unnecessary but whatever
        void detach() override {
            CloseHandle(process_handle_);
        }

        bool read(uint64_t address, void* buffer, size_t size) override {
            SIZE_T bytes_read;
            ReadProcessMemory(process_handle_, (LPCVOID) address, buffer, size, &bytes_read);
            return bytes_read == size;
        }

        bool write(uint64_t address, void* buffer, size_t size) override {
            SIZE_T bytes_written;
            WriteProcessMemory(process_handle_, (LPVOID) address, buffer, size, &bytes_written);
            return bytes_written == size;
        }

    private:
        HANDLE process_handle_{};
    };
}

#endif