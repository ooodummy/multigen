#ifndef MULTIGEN_INSPECTOR_METADATA_FIELD_CONTAINER_HPP
#define MULTIGEN_INSPECTOR_METADATA_FIELD_CONTAINER_HPP

#include "metadata_type.hpp"

namespace multigen {
    struct metadata_field_container {
        std::shared_ptr<metadata_type> type;
        std::string name;
        uint64_t offset;
        uint64_t bit_offset;
        uint64_t size;
    };
}

#endif