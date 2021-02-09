// Tags: Tree Design Amazon
// Time: O(n)
// Space: O(n)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        // convert stream to string
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in {data};
        return deserializeHelper(in);
    }
private:
    // preorder traversal (push entries into stack)
    void serializeHelper(TreeNode* root, ostringstream &out) {
        if (root) {
            out << root->val << ' '; // add space
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        } else {
            out << "# "; // add space
            }
        }
    // preorder traversal (pop stack entries from bottom side, same order)
    TreeNode *deserializeHelper(istringstream &in){
        string val {};
        in >> val;

        if (val == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};
/*
Encode in preorder fashion using insertion operator.
Similary using extraction operation we can retrieve back
the values in the same order.
*/
