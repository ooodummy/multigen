#ifndef MULTIGEN_BACKEND_BASE_BACKEND_HPP
#define MULTIGEN_BACKEND_BASE_BACKEND_HPP

#include <string>

namespace multigen {
    class base_metadata {
        std::string name;
    };

    class base_metadata_class : public base_metadata {
        // A token can all uniquely define with Mono classes
        // with IL2CPP we can just use the offset to the class instance

        // Because different backends do things such as JIT or can just be statically analyzed, each backend will have
        // functions to generate each thing such as class, field, method, etc.
    };

    class base_metadata_field : public base_metadata {

    };

    class base_metadata_method : public base_metadata {

    };

    // Defines the backend for the target game we are dumping an SDK for
    class base_backend {

    };
}

#endif