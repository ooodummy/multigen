#include "multigen.hpp"

namespace multigen {
    bool process_and_serialize(const std::shared_ptr<base_backend>& backend, const std::shared_ptr<base_processor>& processor, const std::shared_ptr<base_serializer>& serializer, const std::filesystem::path& output_directory) {
        if (!processor || !serializer)
            return false;

        const auto all_containers = backend->all_metadata_containers();
        if (all_containers.empty()) {
            printf("[!] No metadata containers found\n");
            return false;
        }

        if (!processor->initialize(all_containers)) {
            printf("[!] Processor initialization failed\n");
            return false;
        }

        if (!processor->serialize(serializer)) {
            printf("[!] Processor serialization failed\n");
            return false;
        }

        if (!processor->write(output_directory)) {
            printf("[!] Processor write failed\n");
            return false;
        }

        return true;
    }
}