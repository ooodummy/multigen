#ifndef MULTIGEN_SERIALIZERS_BASE_SERIALIZER_HPP
#define MULTIGEN_SERIALIZERS_BASE_SERIALIZER_HPP

#include "inspector/metadata_container.hpp"

namespace multigen {
    class base_serializer {
    public:
        virtual ~base_serializer() = default;

        virtual bool serialize(const std::stringstream& writer, const std::shared_ptr<metadata_container>& metadata_container) = 0;
    };
}

#endif