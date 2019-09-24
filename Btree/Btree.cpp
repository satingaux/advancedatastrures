#include<bits/stdc++.h>
using namespace std;
#define MAX 4
#define MIN 2

//http://see-programming.blogspot.com/2013/05/insertion-deletion-and-traversal-in-b.html

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
		//	splitNode(*pval, pval, pos, node, *child, child);
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
                        printf("%d ", myNode->val[i + 1]);
                }
                traversal(myNode->link[i]);
        }
  }
int main(){
	 int val, ch;
        while (1) {
                printf("1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Traversal\n");
                printf("5. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter your input:");
                                scanf("%d", &val);
                                insertNode(val);
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
