typedef int poly_type;

typedef struct node {
   poly_type coef;
   poly_type exp;
   struct node *next;
   struct node *prev;
}Node;

typedef struct PolyS {
	Node *head;
	Node *tail;
}PolyStruct;

typedef PolyStruct *Polynomial;

void initPoly(Polynomial *lst);

int isEmpty(Polynomial *lst);

int length(Polynomial *lst);

Node* allocItem(poly_type coef,poly_type exp);

Node* getLinkByIndex(Polynomial *lst, int idx);

int insertFirst(Polynomial *lst, Node *item);

int insertLast(Polynomial *lst, Node *item);

int deleteFirst(Polynomial *lst);

int deleteLast(Polynomial *lst);

int deleteLink(Polynomial *lst, Node *link);

int insertAfter(Polynomial *lst, Node *item, Node *link);

int insertBefore(Polynomial *lst, Node *item, Node *link);


