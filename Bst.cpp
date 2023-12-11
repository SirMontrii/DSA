//Binary search tree
#include <iostream>
using namespace std;
template <class T>
class Bst;

template<class T>
class bstnode{
	T ele;
	bstnode * left;
	bstnode * right;
	bstnode * parent;
	
	public:
		bstnode(T e = "",bstnode * l = 0, bstnode * r = 0, bstnode * p = 0){
			ele = e;
			left = l;
			right = r;
			parent = p;
		}
		
		~bstnode(){
		}
	
	friend class Bst<T>;	
};

template <class T>
class Bst{
	bstnode<T> * root;
	int size;
	
	public:
		Bst(){
			root = 0;
			size = 0;
		}
		
		void insert(T e){
			bstnode<T> * p = new bstnode<T>(e);
			if(root == 0){
				root  = p;
				size++;
				return;
			}else{
				size++;
				bstnode<T> * q = root;
				bstnode<T> * r;
				while(q!=0){
					if(e < q->ele){
						r = q;
						q = q->left;
					}else if(e > q->ele){
						r = q;
						q = q->right;
					}
				}
				if(e < r->ele){
					r->left = p;
				}else if(e > r->ele){
					r->right = p;
				}
			}
		}
		
		bstnode<T> * Root(){
			return root;
		}
		
		bstnode<T>* search(T e){
			bstnode<T> * p = root;
			while(p!=0){
				if(p->ele==e){
					return p;
				}else if(e<p->ele){
					p = p->left;
				}else{
					p = p->right;
				}
			}
			return 0;
		}
		
		//preorder traversal
		void preT(bstnode<T> * p){
			if(p!=0){
				cout<<p->ele<<"  ";
				preT(p->left);
				preT(p->right);		
			}
		}
		
		//inorder traversal
		void inT(bstnode<T> * p){
			if(p!=0){
				inT(p->left);
				cout<<p->ele<<"  ";
				inT(p->right);
			}
		}
		
		//postorder traversal
		void postT(bstnode<T> * p){
			if(p!=0){
				postT(p->left);
				postT(p->right);
				cout<<p->ele<<"  ";
			}
		}
		
		//function to calculate height
		int height(bstnode<T> * p){
			if(p==0){
				return 0;
			}
			int lheight = height(p->left);
			int rheight = height(p->right);
			if(lheight>rheight){
				return (1+lheight);
			}else{
				return (1+rheight);
			}
		}
		
		//function to delete a node by merging
		void delbyMer(T e){
			bstnode<T> * temp,* todel = root;
			while(todel!=0 && todel->ele!=e){
				temp = todel;
				if(e < todel->ele){
					todel = todel->left;
				}else{
					todel = todel->right;
				}
			}
			if(todel!=0){
				//if the node has not any child node
				if(todel->left==0 && todel->right==0){
					if(todel==root){
						root = 0;
					}else{
						if(todel->ele < temp->ele){
							temp->left = 0;
						}else{
							temp->right = 0;
						}
					}
				}
				
				//if the node has only left child node
				else if(todel->right==0){
					if(todel==root){
						root = 0;
					}else{
						if(todel->ele < temp->ele){
							temp->left = todel->left;
						}else{
							temp->right = todel->left;
						}
					}
					
				}
				
				//if the node has only right child node
				else if(todel->left==0){
					if(todel==root){
						root = 0;
					}else{
						if(todel->ele < temp->ele){
							temp->left = todel->right;
						}else{
							temp->right = todel->right;
						}
					}
				}
				
				//if the node has both child node
				else{
					bstnode<T> * leftmax = todel->left;
					//finding the maximum element of left subtree
					while(leftmax->right!=0){
						leftmax = leftmax->right;
					}
					leftmax->right = todel->right;
					if(todel==root){
						root = todel->left;
					}else{
						if(todel->ele < temp->ele){
							temp->left = todel->left;
						}else{
							temp->right = todel->left;
						}
					}
				}
				//now deleting the node
				delete todel;
			}
			else{
				cout<<"\nNode is not present\n";
			}
		}
		
		void delAll(bstnode<T> * p){
			if(p!=0){
				delAll(p->left);
				delAll(p->right);
				if(p==root){
					root = 0;
				}
				delete p;
			}
		}
		
		~Bst(){
			delAll(root);
		}
};

int main(){
	Bst<int> ob;
	cout<<"BINARY SEARCH TREE\n";
	int ch;
	do{
		cout<<"\n1. Insert\n";
		cout<<"2. Preorder traversal\n";
		cout<<"3. Inorder traversal\n";
		cout<<"4. Postorder traversal\n";
		cout<<"5. Search a node\n";
		cout<<"6. Height of tree\n";
		cout<<"7. Delete a node\n";
		cout<<"8. Delete all nodes\n";
		cout<<"0. Exit\n";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:{
				int ele;
				cout<<"\nEnter an integer : ";
				cin>>ele;
				ob.insert(ele);
				break;
			}
			case 2:{
				ob.preT(ob.Root());
				cout<<endl;
				break;
			}
			case 3:{
				ob.inT(ob.Root());
				cout<<endl;
				break;
			}
			case 4:{
				ob.postT(ob.Root());
				cout<<endl;
				break;
			}
			case 5:{
				int node;
				cout<<"\nEnter an integer to search : ";
				cin>>node;
				if(ob.search(node)!=0){
					cout<<node<<" is present\n";
				}else{
					cout<<node<<" is not present\n";
				}
				break;
			}
			case 6:{
				cout<<"Height of the tree is : "<<ob.height(ob.Root())<<endl;
				break;
			}
			case 7:{
				int node;
				cout<<"\nWhich node do you want to delete : ";
				cin>>node;
				ob.delbyMer(node);
				break;
			}
			case 8:{
				ob.delAll(ob.Root());
				break;
			}
			case 0:{
				break;
			}
			default:{
				cout<<"\nError : Invalid choice\n";
				break;
			}
		}
	}while(ch!=0);
	return 0;
}
