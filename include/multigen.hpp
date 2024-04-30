#ifndef MULTIGEN_MULTIGEN_HPP
#define MULTIGEN_MULTIGEN_HPP

#include "backends/il2cpp.hpp"
#include "backends/mono.hpp"
#include "backends/ue5.hpp"

#include "memory/win32_memory.hpp"

#include "processors/default_processor.hpp"
#include "processors/sdk_processor.hpp"

#include "dependency_resolver.hpp"

#include "pdb.hpp"

namespace multigen {
    bool process_and_serialize(const std::shared_ptr<base_backend>& backend, const std::shared_ptr<base_processor>& processor, const std::shared_ptr<base_serializer>& serializer, const std::filesystem::path& output_directory);
}

#endif