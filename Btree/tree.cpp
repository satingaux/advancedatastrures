#include<bits/stdc++.h>
using namespace std;
#define MAX 4
#define MIN 2


struct BtreeNode{
	int val[MAX+1], count;
	BtreeNode* link[MAX+1];
};

BtreeNode* root;

BtreeNode * createNode(int val, BtreeNode *child){
	BtreeNode* node = (BtreeNode* ) malloc(sizeof( struct BtreeNode*));
	node->val[1]=val;
	node->count=1;
	node->link[0]=root;
	node->link[1]=child;
	return node;
}

void addValToNode(int val, int pos, BtreeNode* node, BtreeNode* child){
	int j=node->count;
	while(j>pos){
		node->val[j+1]=node->val[j];
		node->link[j+1]=node->link[j];
		j--;
	}
	node->val[j+1]=val;
	node->link[j+1]=child;
	node->count++;
}

///SPLIT FUNCTION
void splitNode (int val, int *pval, int pos, struct BtreeNode *node, struct BtreeNode *child, struct BtreeNode **newNode) {
        int median, j;
		cout<<"pos"<<pos<<"\n";
        if (pos > MIN)
                median = MIN + 1;
        else
                median = MIN;

        *newNode = (struct BtreeNode *)malloc(sizeof(struct BtreeNode));
        j = median + 1;
        while (j <= MAX) {
        		cout<<"\nNEW NODE val while loop"<<node->val[j]<<"\n";
                (*newNode)->val[j - median] = node->val[j];
                (*newNode)->link[j - median] = node->link[j];
                j++;
        }
        node->count = median;
        (*newNode)->count = MAX - median;
		
        if (pos <= MIN) {
                addValToNode(val, pos, node, child);
        } else {
                addValToNode(val, pos - median, *newNode, child);
        }
        *pval = node->val[node->count];
        (*newNode)->link[0] = node->link[node->count];
        node->count--;
  }


int setValNode(int val, int *pval, BtreeNode* node, BtreeNode **child){
	int pos;
 	if(!node){
		*pval=val;
		*child=NULL;
		return 1;
	}
	
	if(val<node->val[1]){
		pos=0;
	}else{
		for(pos=node->count; (val<node->val[pos] && pos>1); pos--);
		if(val==node->val[pos]){
			cout<<"DUPLICATE FOUND!!!\n";
			return 0;
		}
	}
	if(setValNode(val, pval, node->link[pos], child)){
		if(node->count<MAX){
			cout<<"ADD VAL TO NODE called\n";
			addValToNode(*pval, pos, node, *child);
		}else{
			cout<<"TO BE SPLIT\n";
			splitNode(*pval, pval, pos, node, *child, child);
			return 1;	
		}
	}
	return 0;
}

void insertNode(int val){
	int flag,i;
	BtreeNode* child;
	flag=setValNode(val, &i, root, &child);
	if(flag){
		root=createNode(i,child);	
	}
}

void traversal(BtreeNode *myNode) {
        int i;
        if (myNode) {
                for (i = 0; i < myNode->count; i++) {
                        traversal(myNode->link[i]);
                        printf("%d *", myNode->val[i +1]);
                }
                cout<<"  Node count: "<<myNode->count;
                cout<<"\n";
                traversal(myNode->link[i]);
        }
  }
int main(){
	 int val, ch;
        while (1) {
                printf("\n\n1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Traversal\n");
                printf("5. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter your input:");
                                scanf("%d", &val);
                                insertNode(val);
                                traversal(root);
                                break;
                        case 2:
                                printf("Enter the element to delete:");
                                scanf("%d", &val);
//                                deletion(val, root);
                                break;
                        case 3:
                                printf("Enter the element to search:");
                                scanf("%d", &val);
//                                searching(val, &ch, root);
                                break;
                        case 4:
                                traversal(root);
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("U have entered wrong option!!\n");
                                break;
                }
                printf("\n");
        }
}









//  /* sets the value val in the node */
//  int setValueInNode(int val, int *pval,
//     struct btreeNode *node, struct btreeNode **child) {
//
//        int pos;
//        if (!node) {
//                *pval = val;
//                *child = NULL;
//                return 1;
//        }
//
//        if (val < node->val[1]) {
//                pos = 0;
//        } else {
//                for (pos = node->count;
//                        (val < node->val[pos] && pos > 1); pos--);
//                if (val == node->val[pos]) {
//                        printf("Duplicates not allowed\n");
//                        return 0;
//                }
//        }
//        if (setValueInNode(val, pval, node->link[pos], child)) {
//                if (node->count < MAX) {
//                        addValToNode(*pval, pos, node, *child);
//                } else {
//                        splitNode(*pval, pval, pos, node, *child, child);
//                        return 1;
//                }
//        }
//        return 0;
//  }
//
//  /* insert val in B-Tree */
//  void insertion(int val) {
//        int flag, i;
//        struct btreeNode *child;
//
//        flag = setValueInNode(val, &i, root, &child);
//        if (flag)
//                root = createNode(i, child);
//  }
//
//  /* copy successor for the value to be deleted */
//  void copySuccessor(struct btreeNode *myNode, int pos) {
//        struct btreeNode *dummy;
//        dummy = myNode->link[pos];
//
//        for (;dummy->link[0] != NULL;)
//                dummy = dummy->link[0];
//        myNode->val[pos] = dummy->val[1];
//
//  }
//
//  /* removes the value from the given node and rearrange values */
//  void removeVal(struct btreeNode *myNode, int pos) {
//        int i = pos + 1;
//        while (i <= myNode->count) {
//                myNode->val[i - 1] = myNode->val[i];
//                myNode->link[i - 1] = myNode->link[i];
//                i++;
//        }
//        myNode->count--;
//  }
//
//  /* shifts value from parent to right child */
//  void doRightShift(struct btreeNode *myNode, int pos) {
//        struct btreeNode *x = myNode->link[pos];
//        int j = x->count;
//
//        while (j > 0) {
//                x->val[j + 1] = x->val[j];
//                x->link[j + 1] = x->link[j];
//        }
//        x->val[1] = myNode->val[pos];
//        x->link[1] = x->link[0];
//        x->count++;
//
//        x = myNode->link[pos - 1];
//        myNode->val[pos] = x->val[x->count];
//        myNode->link[pos] = x->link[x->count];
//        x->count--;
//        return;
//  }
//
//  /* shifts value from parent to left child */
//  void doLeftShift(struct btreeNode *myNode, int pos) {
//        int j = 1;
//        struct btreeNode *x = myNode->link[pos - 1];
//
//        x->count++;
//        x->val[x->count] = myNode->val[pos];
//        x->link[x->count] = myNode->link[pos]->link[0];
//
//        x = myNode->link[pos];
//        myNode->val[pos] = x->val[1];
//        x->link[0] = x->link[1];
//        x->count--;
//
//        while (j <= x->count) {
//                x->val[j] = x->val[j + 1];
//                x->link[j] = x->link[j + 1];
//                j++;
//        }
//        return;
//  }
//
//  /* merge nodes */
//  void mergeNodes(struct btreeNode *myNode, int pos) {
//        int j = 1;
//        struct btreeNode *x1 = myNode->link[pos], *x2 = myNode->link[pos - 1];
//
//        x2->count++;
//        x2->val[x2->count] = myNode->val[pos];
//        x2->link[x2->count] = myNode->link[0];
//
//        while (j <= x1->count) {
//                x2->count++;
//                x2->val[x2->count] = x1->val[j];
//                x2->link[x2->count] = x1->link[j];
//                j++;
//        }
//
//        j = pos;
//        while (j < myNode->count) {
//                myNode->val[j] = myNode->val[j + 1];
//                myNode->link[j] = myNode->link[j + 1];
//                j++;
//        }
//        myNode->count--;
//        free(x1);
//  }

