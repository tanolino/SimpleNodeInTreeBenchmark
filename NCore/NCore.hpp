#pragma once

namespace NCore {
    namespace DynamicNodes {
        struct Node
        {
            glm::mat4 LocalTransform = glm::identity<glm::mat4>();
            glm::mat4 GlobalTransform = glm::identity<glm::mat4>();
            std::vector<Node> Children;

            void UpdateGlobalTransformRecursive(const glm::mat4& ParentTransform);
            size_t RecusrsiveCountNodes() const;
        };
    }

    namespace MemoryOrientedDesign {
        struct Tree
        {
            std::vector<glm::mat4> LocalTransforms;
            std::vector<glm::mat4> GlobalTransforms;
            std::vector<int> Parents; // -1 has no parent

            void UpdateGlobalTransforms();
        };
    }
}