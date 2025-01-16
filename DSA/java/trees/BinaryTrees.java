package trees;

class TreeNode
{
    protected int data;
    protected TreeNode right;
    protected TreeNode left;

    TreeNode (int data)
    {
        this.right = null;
        this.left = null;
        this.data = data;
    }

    public int getData()
    {
        return data;
    }

    public TreeNode getRight()
    {
        return right;
    }

    public TreeNode getLeft()
    {
        return left;
    }

    public void setLeft(Node data)
    {
        this.left = data;
    }

    public void setRight(TreeNode data)
    {
        this.right = data;
    }

    public void setData(int data)
    {
        this.data = data;
    }
}

public class BinaryTrees extends TreeNode
{
    protected TreeNode root;
    BinaryTrees()
    {
        root = null;
    }

    public boolean isEmpty()
    {
        return root == null;
    }

    public void insert(int data)
    {
        root = insert(root, data);
    }

    private TreeNode insert(TreeNode node, int data)
    {
        if (node == null)
        {
            node = new TreeNode(data);
        }
        else
        {
            if (node.getData() >= data)
            {
                node.left = insert(node.left, data);
            }
            else
            {
                node.right = insert(node.right, data);
            }
        }

        return node;
    }


}