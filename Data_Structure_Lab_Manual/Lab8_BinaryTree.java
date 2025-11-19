import java.util.Scanner;

class TreeNode {
    int data;
    TreeNode left, right;
    TreeNode(int d) { data = d; }
}

public class Lab8_BinaryTree {

    TreeNode root;

    TreeNode insert(TreeNode node, int val) {
        if (node == null) return new TreeNode(val);
        if (val < node.data) node.left = insert(node.left, val);
        else node.right = insert(node.right, val);
        return node;
    }

    void inorder(TreeNode n) {
        if (n != null) {
            inorder(n.left);
            System.out.print(n.data + " ");
            inorder(n.right);
        }
    }

    void preorder(TreeNode n) {
        if (n != null) {
            System.out.print(n.data + " ");
            preorder(n.left);
            preorder(n.right);
        }
    }

    void postorder(TreeNode n) {
        if (n != null) {
            postorder(n.left);
            postorder(n.right);
            System.out.print(n.data + " ");
        }
    }

    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Lab8_BinaryTree bt = new Lab8_BinaryTree();

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter values:");
        for (int i = 0; i < n; i++)
            bt.root = bt.insert(bt.root, sc.nextInt());

        System.out.print("Inorder: "); bt.inorder(bt.root); System.out.println();
        System.out.print("Preorder: "); bt.preorder(bt.root); System.out.println();
        System.out.print("Postorder: "); bt.postorder(bt.root); System.out.println();
    }
}

