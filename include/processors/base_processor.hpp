#ifndef MULTIGEN_PROCESSORS_BASE_PROCESSOR_HPP
#define MULTIGEN_PROCESSORS_BASE_PROCESSOR_HPP

#include <iostream>
#include <filesystem>

namespace multigen {
    class base_processor {
    public:
        virtual bool initialize() = 0;
        virtual bool serialize() = 0;
        virtual bool write(std::fs) = 0;
    };
}

#endif