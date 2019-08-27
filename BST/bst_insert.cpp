#include<bits/stdc++.h>
using namespace std;

struct bst{
	int v;struct bst*l,*r;
};
struct bst* create(struct bst* n, int val){
	struct bst* node=(struct bst*) malloc(sizeof(struct bst));
	node->v=val;node->l=NULL;node->r=NULL;
	return node;
}
struct bst* insert(struct bst* n, int val){
	cout<"ssssssss";
	if(n==NULL)	return create(n,val);
	else if(n->v<val)	n->r=insert(n->r,val);
	else n->l=insert(n->l,val);
	return n;
}
void inorder(struct bst* n){
	if(n){
		inorder(n->l);
		cout<<"->->"<<n->v;
		inorder(n->r);
	}
}
void preorder(struct bst* n){
	if(n){
		cout<<"->->"<<n->v;
		preorder(n->l);
		preorder(n->r);
	}
}	
int main(){
	struct bst* root=NULL;
//	insert(rt,77);
//	insert(rt,2);
	root = insert(root, 10);  
 	root = insert(root, 20);  
  	root = insert(root, 30);  
    	root = insert(root, 40);  
   	root = insert(root, 50);  
    	root = insert(root, 25);  
	preorder(root);

	return 0;
}
