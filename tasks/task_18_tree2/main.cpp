#include <iostream>
#include <vector>
#include <memory>

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<std::unique_ptr<TreeNode>> children;

public:
    TreeNode(int val): value(val) {
    }

    TreeNode* AddChild(int child_value) {
        auto node = std::make_unique<TreeNode>(child_value);
        TreeNode* ptr = node.get();
        node->root = this;
        children.push_back(std::move(node));
        return ptr;
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << " ";
        }
        std::cout << "- " << value << "\n";
        for (const auto& child : children) {
            child->Print(depth + 1);
        }
    }
};