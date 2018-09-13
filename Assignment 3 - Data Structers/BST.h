

typedef int tree_type;

typedef struct Tnode {
	tree_type key;
	struct Tnode *left;
	struct Tnode *right;
	struct Tnode *root;
}Tnode;



Tnode* CreateTreeNode(tree_type value);
Tnode* CreateBST();
Tnode* insertBST(Tnode *root, tree_type value);
void Ex1(Tnode **root);

void InOrder(Tnode *root);
void Ex2(Tnode *root);


void printByLevel(Tnode *root);
void Ex3(Tnode *root);

void FreeBST(Tnode *root);
void Ex4(Tnode **root);