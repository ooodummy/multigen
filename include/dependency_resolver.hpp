#ifndef MULTIGEN_DEPENDENCY_RESOLVER_HPP
#define MULTIGEN_DEPENDENCY_RESOLVER_HPP

namespace multigen {
    // Will be based on Kahn's algorithm (https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)
    // We will need to take a look into doing a multithreaded approach for this because when we have 28k+ metadata
    // containers dependency resolving can take a while
    // https://stackoverflow.com/questions/61415979/a-parallel-version-of-kahns-algorithm
}

#endif