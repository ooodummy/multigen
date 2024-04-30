#ifndef MULTIGEN_INSPECTOR_METADATA_METHOD_CONTAINER_HPP
#define MULTIGEN_INSPECTOR_METADATA_METHOD_CONTAINER_HPP

#include "metadata_type.hpp"

namespace multigen {
    enum class method_flags {
        method_default,
        method_static,
        method_virtual
    };

    struct method_parameter {
        std::shared_ptr<metadata_type> type;
        std::string name;
    };

    // Because different backends do things such as JIT or can just be statically analyzed, each backend will have
    // functions to generate each thing such as class, field, method, etc.

    struct metadata_method_container {
        std::string name;
        method_flags flags;

        // TODO: Can't just do function offset for all game engines
        // A token can all uniquely define with Mono classes
        // with IL2CPP we can just use the offset to the class instance

        std::shared_ptr<metadata_type> return_type;
        std::vector<method_parameter> parameters;
    };
}

#endif