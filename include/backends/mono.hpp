#ifndef MULTIGEN_BACKENDS_MONO_HPP
#define MULTIGEN_BACKENDS_MONO_HPP

#include "base_backend.hpp"

namespace multigen {
    // How can we automatically associate PDB things like Unity::Object to UnityEngine::Object when dumping?
    class mono_metadata_static_field : public base_metadata_field {

    };
}

#endif