#include "catch_amalgamated.hpp"

#include <NCore.hpp>

namespace {
    constexpr const int GEN_9864101_CHILDREN{ 10 };

    constexpr const int SAME_NODE_SEED{ GEN_9864101_CHILDREN };
}

TEST_CASE("Matrix Multiply", "[basics]") {

    auto mat{ glm::identity<glm::mat4>() };
    std::vector<glm::mat4> tMatList((size_t)1000, mat);
    BENCHMARK("Multiply 1000 Matrices") {
        for (const auto& tMat : tMatList) {
            mat = mat * tMat;
        }
        return mat;
    };
}

NCore::DynamicNodes::Node
RecursiveGenerateNodes(int children)
{
    using NCore::DynamicNodes::Node;
    Node result;
    if (children >= 0)
    {
        Node child = RecursiveGenerateNodes(children - 1);
        result.Children.resize(children, child);
    }
    return result;
};

TEST_CASE("Dynamic Nodes Global Matrix Update", "[tree]") {
    using NCore::DynamicNodes::Node;

    Node root;
    
    root = RecursiveGenerateNodes(SAME_NODE_SEED);

    const size_t childs = root.RecusrsiveCountNodes();
    CAPTURE(childs);

    BENCHMARK("Update") {
        root.UpdateGlobalTransformRecursive(
            glm::identity<glm::mat4>());
        return;
    };
    return;
}

void
RecursiveBuildTree(NCore::MemoryOrientedDesign::Tree& tree , int parent, int children)
{
    const int me = (int)tree.Parents.size();
    tree.Parents.push_back(parent);
    for (int i{ 0 }; i < children; ++i)
    {
        RecursiveBuildTree(tree, me, children - 1);
    }
}

TEST_CASE("Memory Aligned Global Matrix Update", "[tree]") {
    using NCore::MemoryOrientedDesign::Tree;

    Tree tree;

    tree.Parents.clear();
    RecursiveBuildTree(tree, -1, SAME_NODE_SEED);
    tree.LocalTransforms.resize(tree.Parents.size(), glm::identity<glm::mat4>());
    tree.GlobalTransforms.resize(tree.Parents.size(), glm::identity<glm::mat4>());

    const size_t childs = tree.Parents.size();
    CAPTURE(childs);

    BENCHMARK("Update") {
        tree.UpdateGlobalTransforms();
        return;
    };
    return;
}