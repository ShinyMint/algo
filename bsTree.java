class Node {
    Node node;
    int key;
    Node left = null;
    Node right = null;

    public Node(int key) {
        this.key = key;
    }

    public Node(Node left, int key, Node right) {
        this.left = left;
        this.key = key;
        this.right = right;
    }

    public Node getNode() {
        return node;
    }
}

public class bsTree {

    public static Node insertBST(Node T, int newKey) {
        Node p = T;
        Node q = null;
        while (p != null) {
            if (newKey == p.key)//if newKey is a root of the BST
                return T;
            q = p;
            if (newKey < p.key)
                p = p.left;
            else
                p = p.right;
        }

        Node newNode = new Node(newKey);
        newNode.getNode();
        newNode.key = newKey;
        newNode.right = null;
        newNode.left = null;
        if (T == null)
            T = newNode;
        else if (newKey < q.key)
            q.left = newNode;
        else
            q.right = newNode;
        return T;
    }

    public static int height(Node T){
        if (T == null)
            return 0;
        else {
            int h1 = height(T.left);
            int h2 = height(T.right);
            if (h1 > h2) {
                h1++;
                return h1;
            }
            else{
                h2++;
                return h2;
            }
        }
    }

    public static int noNodes(Node T) {
        if (T == null)
            return 0;
        else {
            int num = 0;
            num += noNodes(T.left);
            num += noNodes(T.right);
            return num;
        }
    }

    public static Node maxNode(Node T) {
        if(T.right == null)
            return T;
        else
            return maxNode(T.right);
    }

    public static Node minNode(Node T) {
        if(T.left == null)
            return T;
        else
            return minNode(T.left);
    }

    public static Node searchBST(Node T, int searchKey) {
        Node p = T;
        if (p == null)
            return null;
        else if (p.key == searchKey)
            return p;
        else if (p.key < searchKey)
            return searchBST(p.right, searchKey);
        else
            return searchBST(p.left, searchKey);
    }

    public static Node searchParentBST(Node T, int searchKey, Node p) {
        Node q = null;
        p = T;
        while (p != null) {
            if (searchKey == p.key)
                return q;
            q = p;
            if (searchKey < p.key)
                p = p.left;
            else
                p = p.right;
        }
        return q;
    }

    public static Node deleteBST(Node T, int deleteKey) {
        Node p = searchBST(T,deleteKey);
        Node q = searchParentBST(T, deleteKey, p);
        Node r = null;
        String flag = null;

        if (p == null)
            return T;
        if (q == null) {
            T = null;
            return T;
        }
        if (p.left == null && p.right == null) { //|l-r| = 0
            if (q.left == p)
                q.left = null;
            else
                q.right = null;
        }
        else if (p.left == null || p.right == null) { //|l-r| = 1
            if (p.left != null) {
                if (q.left == p)
                    q.left = p.left;
                else
                    q.right = p.left;
            }
            else {
                if (q.left == p)
                    q.left = p.right;
                else
                    q.right = p.right;
            }
        }
        else if (p.left != null && p.right != null) { //|l-r| = 2
            if (height(p.left) > height(p.right)) {
                r = maxNode(p.left);
                flag = "LEFT";
            }
            else if (height(p.left) < height(p.right)) {
                r = minNode(p.right);
                flag = "RIGHT";
            }
            else if(height(p.left) == height(p.right)) {
                if (noNodes(p.left) >= noNodes(p.right)) {
                    r = maxNode(p.left);
                    flag = "LEFT";
                }
                else if (noNodes(p.left) < noNodes(p.right)) {
                    r = minNode(p.right);
                    flag = "RIGHT";
                }
            }
            p.key = r.key;
            if (flag == "LEFT")
                deleteBST(p.left, r.key);
            else
                deleteBST(p.right, r.key);
        }
        return T;
    }

    public static void inorderBST(Node T) {
        if (T != null) {
            inorderBST(T.left);
            System.out.print(T.key + " ");
            inorderBST(T.right);
        }
    }

    public static void main(String[] args) {

        Node T = null;

        //1st insert
        T = insertBST(T, 25); inorderBST(T);
        System.out.println();
        T = insertBST(T, 500); inorderBST(T);
        System.out.println();
        T = insertBST(T, 33); inorderBST(T);
        System.out.println();
        T = insertBST(T, 49); inorderBST(T);
        System.out.println();
        T = insertBST(T, 17); inorderBST(T);
        System.out.println();
        T = insertBST(T, 403); inorderBST(T);
        System.out.println();
        T = insertBST(T, 29); inorderBST(T);
        System.out.println();
        T = insertBST(T, 105); inorderBST(T);
        System.out.println();
        T = insertBST(T, 39); inorderBST(T);
        System.out.println();
        T = insertBST(T, 66); inorderBST(T);
        System.out.println();
        T = insertBST(T, 305); inorderBST(T);
        System.out.println();
        T = insertBST(T, 44); inorderBST(T);
        System.out.println();
        T = insertBST(T, 19); inorderBST(T);
        System.out.println();
        T = insertBST(T, 441); inorderBST(T);
        System.out.println();
        T = insertBST(T, 390); inorderBST(T);
        System.out.println();
        T = insertBST(T, 12); inorderBST(T);
        System.out.println();
        T = insertBST(T, 81); inorderBST(T);
        System.out.println();
        T = insertBST(T, 50); inorderBST(T);
        System.out.println();
        T = insertBST(T, 100); inorderBST(T);
        System.out.println();
        T = insertBST(T, 999); inorderBST(T);
        System.out.println();

        //1st delete
        T = deleteBST(T, 999); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 100); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 50); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 81); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 12); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 390); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 441); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 19); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 44); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 305); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 66); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 39); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 105); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 29); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 403); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 17); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 49); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 33); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 500); inorderBST(T);
        System.out.println();
        T = deleteBST(T, 25); inorderBST(T);
        System.out.println();
    }
}
