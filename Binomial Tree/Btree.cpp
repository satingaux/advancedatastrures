#include<bits/stdc++.h> 
using namespace std; 
  
struct Btree 
{ 
    int v, d; 
    Btree *c, *s, *p; 
}; 
Btree* create(int val){
	Btree *t=new Btree;
	t->c=t->p=t->s=NULL;
	t->v=val;
	t->d=0;
	return t;
}
list<Btree*>	ADJUST(list<Btree*> hp){
	if(hp.size()<=1){
		cout<<"heap size one";
		return hp;
	}
	cout<<"heap size two";
	list<Btree*> ::iterator it1,it2,it3;
	it1=it2=it3=hp.begin();
	if(hp.size()==2){
		it2=it1,it2++,it3=hp.end();
	}else{
		it2++;it3=it2;it3++;
	}
	while(it1!=hp.end()){
		if(it2==hp.end())	it1++;
		else if((*it1)->d < (*it2)->d){
			it1++,it2++;
			if(it3!=hp.end())	it3++;
		}
		else if((it3!=hp.end())&& (*it1)->d == (*it2)->d && (*it2)->d==(*it3)->d){
			it1++;
			it2++;
			it3++;
		}	
		else if((*it1)->d	==	(*it2)->d){
//			cout<<"#";
			if((*it1)->v	>	(*it2)->v){
				swap(it1,it2);
			}
			(*it2)->p=*it1;
			(*it2)->s=(*it1)->c;
			(*it1)->c=*it2;
			(*it1)->d++;
			
			hp.erase(it2);
			if(it3!=hp.end())	it3++;
		}
	}
	return hp;
} 
list<Btree*> UNION(list<Btree*> l1,	list<Btree*> l2){
	list<Btree*> Ulist;
	list<Btree*>:: iterator itr1=l1.begin();
	list<Btree*>:: iterator itr2=l2.begin();
	while(itr1!=l1.end() && itr2!=l2.end()){
//		cout<<"#";
		if((*itr1)->d	<= (*itr2)->d){
			Ulist.push_back(*itr1);
			itr1++;
		}else{
			Ulist.push_back(*itr2);
			itr2++;
		}
	}
	while(itr1!=l1.end()){
		Ulist.push_back(*itr1);
		*itr1++;
	}
	while(itr2!=l2.end()){
		Ulist.push_back(*itr2);
		*itr2++;
	}
	return Ulist;
}
list<Btree*> insert(list<Btree*>	hp,int val ){
	Btree *t=create(val);
	list<Btree*> tlist;
	tlist.push_back(t);
	cout<<"~~";
	tlist=UNION(hp,tlist);
	cout<<"#";
	return ADJUST(tlist);
}
void printTree(Btree *h) 
{ 
    while (h) 
    { 
        cout << h->v << " "; 
        printTree(h->c); 
        h = h->s; 
    } 
} 
void printHeap(list<Btree*> hp) 
{ 
	cout<<"**";
    list<Btree*> ::iterator it; 
    cout<<"$";
    it = hp.begin(); 
    while (it != hp.end()) 
    { 
    cout<"asdfasdf";
        printTree(*it); 
        it++; 
    } 
}
int main(){
	
    list<Btree*> hp; 
  
    hp = insert(hp,10); 
    cout<<"/";
    hp = insert(hp,20); 
    cout<<"!";
    hp = insert(hp,30); 
    cout<<"&";
//  	cout<<*hp->v;
//cout<<hp.begin()->v;
    printHeap(hp);
	return 0;
}
  
