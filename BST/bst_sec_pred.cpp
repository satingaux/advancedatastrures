#include<bits/stdc++.h>
using namespace std;

struct bst{
	int v;struct bst*l,*r,*p;
};
struct bst* create(struct bst* n, int val){
	struct bst* node=(struct bst*) malloc(sizeof(struct bst));
	node->v=val;node->l=NULL;node->r=NULL;
	node->p=NULL;
	return node;
}
struct bst* insert(struct bst* n, int val){
	if(n==NULL)	return create(n,val);
	else if(n->v<val){
		n->r=insert(n->r,val);
		n->r->p=n;
	}	
	else{
		n->l=insert(n->l,val);
		n->l->p=n;
	} 
	return n;
}
void inorder(struct bst* n){
	if(n){
		inorder(n->l);
		cout<<"->->"<<n->p->v;
		inorder(n->r);
	}
}
struct bst* search(struct bst* rt, int val){
	if(rt->v==val|| rt==NULL)	return rt;
	else if(rt->v<val)	search(rt->r,val);
	else if(rt->v>val)	search(rt->l,val);
}
struct bst* successer(struct bst* rt, int val){
	struct bst* node=search(rt, val);
	
	if(node==NULL)	return node;
	if(node->r!=NULL)	return node->r;
	else{
		struct bst* parent=node->p;
		while(parent->l!=node){
			node=parent;
			parent=node->p;
		}
		return parent;
	}
}
struct bst* predecessor(struct bst* rt, int val){
	struct bst* node=search(rt, val);
	
	if(node==NULL)	return node;
	if(node->l!=NULL)	return node->l;
	else{
		struct bst* parent=node->p;
		while(parent->r!=node){
			node=parent;
			parent=node->p;
		}
		return parent;
	}
}
int main(){
	struct bst* rt=create(rt,10);
	rt->p=rt;
	
	insert(rt,5);
	insert(rt,15);
	insert(rt,3);
	insert(rt,7);
	insert(rt,2);
	insert(rt,4);
	insert(rt,1);
	
//	inorder(rt->p);
	cout<<successer(rt,10)->v;
//	rt=insert(rt,5);
//	cout<<"$$$$$$$";
	return 0;
}
