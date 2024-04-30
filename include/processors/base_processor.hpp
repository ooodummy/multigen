#ifndef MULTIGEN_PROCESSORS_BASE_PROCESSOR_HPP
#define MULTIGEN_PROCESSORS_BASE_PROCESSOR_HPP

#include "inspector/metadata_container.hpp"
#include "serializers/base_serializer.hpp"

#include <filesystem>

namespace multigen {
    class base_processor {
    public:
        virtual ~base_processor() = default;

        virtual bool initialize(const std::vector<std::shared_ptr<metadata_container>>& metadata_containers) = 0;
        virtual bool serialize(const std::shared_ptr<base_serializer>& serializer) = 0;
        virtual bool write(std::filesystem::path output_directory) = 0;
    };
}

#endif