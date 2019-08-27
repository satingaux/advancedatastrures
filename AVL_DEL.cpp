#include<bits/stdc++.h>
using namespace std;
struct avl{
	int v;
	struct avl *l,*r;
	int h;
};
int height(struct avl* root){
	if(root==NULL)	return 0;
	return root->h;
}
int getBALANCE(struct avl* root){
	if(root==NULL)	return 0;
	return	height(root->l) - height(root->r);
}
struct avl* create(int val){
	struct avl* node=(struct avl*)malloc(sizeof(struct avl));
	node->v=val;
	node->l=NULL;
	node->r=NULL;
	node->h=1;
	return node;
}

struct avl* rightRot(struct avl* x){
	struct avl* y=x->l;
	
//	cout<<"!!!";
	struct avl* T1=y->r;
	
//	cout<<"!!!";
	y->r=x;
	x->l=T1;
	
	y->h=max(height(y->l), height(y->r))+1;
	x->h=max(height(x->l), height(x->r))+1;
	
	return y;
}

struct avl* leftRot(struct avl* x){
	struct avl* y=x->r;
	struct avl* T1=y->l;
	
	y->l=x;
	x->r=T1;
	
	y->h=max(height(y->l), height(y->r))+1;
	x->h=max(height(x->l), height(x->r))+1;
	
	return y;
}

struct avl* deletion(struct avl* root, int val){
	if(root==NULL)	return root;
	if(root->v <val)	root->r=deletion(root->r,val);
	else if(root->v>val)	root->l=deletion(root->l,val);
	else{
		if(root->l==NULL && root->r==NULL){
			root=NULL;
		}
		else if(root->l!=NULL&&root->r==NULL){
			root= root->l;
			cout<<"!!!!!!!!\n";
		}
		else if(root->l==NULL&&root->r!=NULL){
			root= root->r;
		}
		else{
			struct avl* t=root->r;
			while(t->l!=NULL)	t=t->l;
			root->v=t->v;
			root->r=deletion(root->r, t->v);
		}
		if(root==NULL)	return root;
		
		root->h=1+max(height(root->l),height(root->r));
	//	cout<<"@@@@@@@";
		int getBalance=getBALANCE(root);
		
//		cout<<"\n@@@@@@@"<<getBalance<<"\n";
		if(getBalance>1 && root->l->v > val){
			return rightRot(root);
		}
		if(getBalance>1 && root->l->v < val){
			root->l=leftRot(root->l);
			return rightRot(root);
		}
		if(getBalance <-1 && root->r->v < val){
			return leftRot(root);
		}
		if(getBalance <-1 && root->r->v > val){
//			cout<<"\n@@@@@@@";
			root->r=rightRot(root->r);
//			cout<<"\n####";
			return leftRot(root);
		}
		return root;
		
	}
}
struct avl* insert(struct avl* root, int val){
	if(root==NULL)	return create(val);
	if(root->v	<  val)	root->r=insert(root->r,val);
	else if(root->v	>  val)	root->l=insert(root->l,val);
//	else return root;
	
	root->h=1+max(height(root->l),height(root->r));
//	cout<<"@@@@@@@";
	int getBalance=getBALANCE(root);
	
	cout<<"\n@@@@@@@"<<getBalance<<"\n";
	if(getBalance>1 && root->l->v > val){
		return rightRot(root);
	}
	if(getBalance>1 && root->l->v < val){
		root->l=leftRot(root->l);
		return rightRot(root);
	}
	if(getBalance <-1 && root->r->v < val){
		return leftRot(root);
	}
	if(getBalance <-1 && root->r->v > val){
//		cout<<"\n@@@@@@@";
		root->r=rightRot(root->r);
//		cout<<"\n####";
		return leftRot(root);
	}
	return root;
}

void preOrder(struct avl* node){
	if(node!=NULL){
		cout<<"->"<<node->v;
		preOrder(node->l);
		preOrder(node->r);
	}
}
void inOrder(struct avl* node){
	if(node!=NULL){
		inOrder(node->l);
		cout<<"->"<<node->v;
		inOrder(node->r);
	}
}
int main(){
	    struct avl* root=NULL;
	    root = insert(root, 10);  
	    preOrder(root); 
	    root = insert(root, 20);  
	    preOrder(root);
	    root = insert(root, 30); 
	    preOrder(root); 
	    root = insert(root, 40); 
	    preOrder(root); 
	    root = insert(root, 50);
	    preOrder(root);  
	    root = insert(root, 25);
	    root=deletion(root,50);
	    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    		inOrder(root);  
      
    return 0;    
	    
	    
}
