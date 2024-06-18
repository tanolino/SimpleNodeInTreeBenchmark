#include "NCore.hpp"

namespace NCore::DynamicNodes {

void
Node::UpdateGlobalTransformRecursive(const glm::mat4& ParentTransform)
{
    GlobalTransform = ParentTransform * LocalTransform;
    for (auto& child : Children)
        child.UpdateGlobalTransformRecursive(GlobalTransform);
}
size_t
Node::RecusrsiveCountNodes() const
{
    size_t res = 1;
    for (const auto c : Children)
        res += c.RecusrsiveCountNodes();
    return res;
}

} // NCore::DynamicNodes

namespace NCore::MemoryOrientedDesign {

void
Tree::UpdateGlobalTransforms()
{
    const int end = (int)std::min(GlobalTransforms.size(),
        std::min(Parents.size(), LocalTransforms.size()));

    for (size_t id{ 0 }; id < end; ++id)
    {
        const int parentId{ Parents[id] };
        if (parentId < 0)
        {
            GlobalTransforms[id] = LocalTransforms[id];
        }
        else if (parentId < end) [[likely]]
        {
            GlobalTransforms[id] = GlobalTransforms[parentId] * LocalTransforms[id];
        }
        else
        {
            GlobalTransforms[id] = glm::identity<glm::mat4>();
        }
    }
}

}