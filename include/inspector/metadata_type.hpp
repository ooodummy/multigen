#ifndef MULTIGEN_INSPECTOR_METADATA_TYPE_HPP
#define MULTIGEN_INSPECTOR_METADATA_TYPE_HPP

#include <memory>
#include <string>
#include <vector>

namespace multigen {
    enum class element_type {
        type_default, // (int, float, double, bool, etc.)
        type_struct,
        type_class,
        type_enum,
        type_function,
        type_field
    };

    // Should be type_def
    class metadata_type {
    public:
        element_type type;
        std::string type_name;
        std::string extended_type;
        std::string name_space;
        bool reference = false; // only used for function parameters
        std::vector<std::shared_ptr<metadata_type>> sub_types;
    };

    struct enum_member {
        std::string name;
        uint64_t value;
    };

    struct metadata_enum {
        std::string type; // Will only ever be a primitive type
        std::string name;
        std::vector<enum_member> members;
    };
}

#endif