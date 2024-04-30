#ifndef MULTIGEN_BACKEND_BASE_BACKEND_HPP
#define MULTIGEN_BACKEND_BASE_BACKEND_HPP

#include "inspector/metadata_container.hpp"

#include <filesystem>
#include <string>
#include <vector>
#include <memory>

// It's gonna be hell optimizing this
namespace multigen {
    // Defines the backend for the target game we are dumping an SDK for
    class base_backend {
    public:
        virtual ~base_backend() = default;

        virtual std::vector<std::shared_ptr<metadata_container>> all_metadata_containers() = 0;
    };
}

#endif
