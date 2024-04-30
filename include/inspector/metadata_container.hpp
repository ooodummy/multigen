#ifndef MULTIGEN_INSPECTOR_METADATA_CONTAINER_HPP
#define MULTIGEN_INSPECTOR_METADATA_CONTAINER_HPP

#include "metadata_field_container.hpp"
#include "metadata_method_container.hpp"
#include "metadata_reference_container.hpp"

namespace multigen {
    // Basically "class"
    class metadata_container {
    public:
        std::shared_ptr<metadata_reference_container> base_type() {
            for (auto& ref : references) {
                if (ref->type == reference_type::reference_inheritance) {
                    return ref;
                }
            }

            return nullptr;
        }

        std::vector<std::shared_ptr<metadata_reference_container>> interfaces() {
            std::vector<std::shared_ptr<metadata_reference_container>> interfaces;

            for (auto& ref : references) {
                if (ref->type == reference_type::reference_interface) {
                    interfaces.push_back(ref);
                }
            }

            return interfaces;
        }

        std::shared_ptr<metadata_type> type;

        std::vector<std::shared_ptr<metadata_reference_container>> references;

        std::vector<std::shared_ptr<metadata_field_container>> fields;
        std::vector<std::shared_ptr<metadata_method_container>> methods;

        uint64_t size;
    };
}

#endif