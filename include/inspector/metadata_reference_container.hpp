#ifndef MULTIGEN_INSPECTOR_METADATA_REFERENCE_CONTAINER_HPP
#define MULTIGEN_INSPECTOR_METADATA_REFERENCE_CONTAINER_HPP

#include "metadata_type.hpp"

namespace multigen {
    enum class reference_type {
        reference_field,
        reference_method,
        reference_inheritance,
        reference_interface,
        reference_generic,
        reference_template_type
    };

    class metadata_reference_container {
    public:
        std::string full_name;
        std::shared_ptr<metadata_type> type_def;
        reference_type type;
    };
}

#endif