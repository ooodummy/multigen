#ifndef MULTIGEN_MEMORY_BASE_MEMORY_HPP
#define MULTIGEN_MEMORY_BASE_MEMORY_HPP

#include <cstdint>
#include <Windows.h>

namespace multigen {
    // Different memory connectors will need to be used in the event we cannot read/write memory due to anticheat and
    // framework data like classes not being initialized unless we are in game
    class base_memory {
    public:
        ~base_memory() {
            detach();
        }

        virtual bool attach(uint32_t pid) = 0;
        virtual void detach() { }; // Not all memory connectors will need to detach
        virtual bool read(uint64_t address, void* buffer, size_t size) = 0;
        virtual bool write(uint64_t address, void* buffer, size_t size) = 0;

        template <typename T>
        T read(uint64_t address) {
            T buffer;
            read(address, &buffer, sizeof(T));
            return buffer;
        }

        template <typename T>
        void write(uint64_t address, T value) {
            write(address, &value, sizeof(T));
        }
    };
}

#endif