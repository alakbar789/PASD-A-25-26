#include <iostream>
using namespace std;

typedef struct node *alamatnode;
typedef struct node {
    char INFO;
    alamatnode RIGHT;
    alamatnode LEFT;
} NODE;

typedef struct {
    NODE* root;
} TREE;

void BuatTree(char C, TREE *T) {
    NODE *Baru;
    Baru = new NODE;
    Baru -> INFO = C;
    Baru -> RIGHT = NULL;
    Baru -> LEFT = NULL;
    (*T).root = Baru;
}

void TambahKanan(char C, NODE *root) {
    if(root -> RIGHT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru -> INFO = C;
        Baru -> RIGHT = NULL;
        Baru -> LEFT = NULL;
        root -> RIGHT = Baru;
    }
    else
        cout << "Sub Tree Kanan telah diisi" << endl;
}

void TambahKiri(char C, NODE *root) {
    if(root -> LEFT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru -> INFO = C;
        Baru -> RIGHT = NULL;
        Baru -> LEFT = NULL;
        root -> LEFT = Baru;
    }
    else
        cout << "Sub Tree Kiri telah diisi" << endl;
}

void CopyTree(NODE *root1, NODE **root2) {
    if(root1 != NULL) {
        (*root2) = new NODE;
        (*root2) -> INFO = root1 -> INFO;
        (*root2) -> LEFT = NULL;
        (*root2) -> RIGHT = NULL;
        if(root1 -> LEFT != NULL) {
            CopyTree(root1 -> LEFT, &(*root2) -> LEFT);
        }
        if(root1 -> RIGHT != NULL) {
            CopyTree(root1 -> RIGHT, &(*root2) -> RIGHT);
        }
    } else {
        *root2 = NULL;
    }
}

void CetakTreePreOrder(NODE *root) {
    if(root != NULL) {
        cout << root->INFO << endl;
        CetakTreePreOrder(root->LEFT);
        CetakTreePreOrder(root->RIGHT);
    }
}

void CetakTreeInOrder(NODE *root) {
    if(root != NULL) {
        CetakTreeInOrder(root->LEFT);
        cout << root->INFO << endl;
        CetakTreeInOrder(root->RIGHT);
    }
}

void CetakTreePostOrder(NODE *root) {
    if(root != NULL) {
        CetakTreePostOrder(root->LEFT);
        CetakTreePostOrder(root->RIGHT);
        cout << root->INFO << endl;
    }
}

void HapusTree(NODE *root) {
    if(root != NULL) {
        HapusTree(root->LEFT);
        HapusTree(root->RIGHT);
        delete root;
    }
}

bool isEqual(NODE *root1, NODE *root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 != NULL && root2 != NULL) {
        return (root1->INFO == root2->INFO) &&
               isEqual(root1->LEFT, root2->LEFT) &&
               isEqual(root1->RIGHT, root2->RIGHT);
    }
    return false;
}

int main() {
    TREE T;
    BuatTree('R', &T);
    TambahKiri('S', T.root);
    TambahKanan('U', T.root);
    TambahKiri('V', T.root -> LEFT);
    TambahKanan('W', T.root -> LEFT);
    TambahKiri('Y', T.root -> RIGHT);
    TambahKanan('Z', T.root -> RIGHT);

    TREE T2;
    T2.root = NULL;
    CopyTree(T.root, &T2.root);
    if(T2.root -> LEFT != NULL) T2.root -> LEFT -> INFO = 'X'; 

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~     PREORDER     ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakTreePreOrder(T.root);
    cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~     INORDER      ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakTreeInOrder(T.root);
    cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~    POSTORDER     ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakTreePostOrder(T.root);
    cout << endl;

    if (isEqual(T.root, T2.root)) {
        cout << "TREE yang sama" << endl;
    } else {
        cout << "TREE yang tidak sama" << endl;
    }
    cout << endl;

    if(T.root -> LEFT != NULL) {
        HapusTree(T.root -> LEFT -> LEFT);
        HapusTree(T.root -> LEFT -> RIGHT);
        T.root -> LEFT -> LEFT = NULL;
        T.root -> LEFT -> RIGHT = NULL;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   PREORDER Setelah Dihapus    " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakTreePreOrder(T.root);
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    HapusTree(T.root);
    HapusTree(T2.root);

    return 0;
}