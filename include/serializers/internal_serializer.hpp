#ifndef MULTIGEN_SERIALIZERS_INTERNAL_SERIALIZER_HPP
#define MULTIGEN_SERIALIZERS_INTERNAL_SERIALIZER_HPP

#include "base_serializer.hpp"

namespace multigen {
    class internal_serializer : public base_serializer {
    public:
        bool serialize(const std::stringstream& writer, const std::shared_ptr<metadata_container>& metadata_container) override {
        }
    };
}

#endif