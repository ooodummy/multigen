#ifndef MULTIGEN_BACKEND_BASE_BACKEND_HPP
#define MULTIGEN_BACKEND_BASE_BACKEND_HPP

namespace multigen {
    class base_class {
        // How should generics/templating be handled?
        std::string name;

        // Because different backends do things such as JIT or can just be statically analyzed, each backend will have
        // functions to generate each thing such as class, field, method, etc.
    };

    // Defines the backend for the target game we are dumping an SDK for
    class base_backend {

    };
}

#endif