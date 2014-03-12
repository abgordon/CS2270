#include <cstddef>
#include <iostream>
#include <queue>
#ifndef BST_H
#define BST_H

using namespace std;
template<class Item>
class bstNode
{
	public:
	//constructor
	bstNode(const Item& init_data, bstNode* init_left=NULL, bstNode* init_right= NULL)
		{
			data_field = init_data;
			left_field = init_left;
			right_field = init_right;
		}
	//helper functions if you need them ..
	//I think I haven't used any of them so far	
	//Item& get_data() {return data_field;}
	void set_data(Item& target) {data_field=target;}
	bstNode*& get_left() {return left_field;}
	bstNode*& get_right() {return right_field;}
	int return_max();
	int return_min();
	void remove_address();
	void remove_address2();
	void print_row();

	//FUNCTIONS YOU IMPLEMENT BELOW
	bool find(Item& targetData);
	void insert(Item& targetData);
	void remove(Item& targetData);
	int size();
	void traverse();
	void destroy_root();



	
	//our private variables (we just have 3)
	private:
		Item data_field; //our data
		bstNode* left_field; //pointer to left child
		bstNode* right_field; //pointer to right child
		int tree_max_value;
		int tree_min_value;
};
//ALL OUR IMPLEMENTATIONS GO IN HERE-- NO .CPP FILE FOR BSTNODE BECUASE IT'S A TEMPLATE CLASS
template<class Item>
bool bstNode<Item>::find(Item& targetData)
{
	if (this == NULL) {cout << "No nodes exist!" << endl; return false;}
	if (data_field == targetData)
	{
		cout << "Data found in " << this << endl;
		return true;
	}


	if (data_field != targetData)
		{
		if (targetData > data_field && right_field == NULL){return false;}
		if (targetData < data_field && left_field == NULL) {return false;}
		if (targetData > data_field && right_field != NULL)
		{

			return right_field->find(targetData);			
		}

		if (targetData < data_field && left_field != NULL)
		{

			return left_field->find(targetData);

		}
	return false;

	}
}
	//check my self, check my children... if I find targetData I return true, else false

template<class Item>
void bstNode<Item>::insert(Item& targetData)
{

	if (left_field == NULL && targetData < data_field)
	{
		cout << "datafield = " << data_field << ", data placed in left node" << endl;
		left_field = new bstNode<Item>(targetData);

	}
	else if (right_field == NULL && targetData > data_field)
	{
		cout << "datafield = " << data_field << ", data placed in right node" << endl;
		right_field = new bstNode<Item>(targetData);

	}
	else if (left_field != NULL && targetData < data_field)
	{
		cout << "recursing....." << endl;
		left_field->insert(targetData);
	}
	else if (right_field != NULL && targetData > data_field)
	{
		cout << "recursing....." << endl;		
		right_field->insert(targetData);
	}


	//go through and find the correct place to insert a new node
	//with this data, remember that you print out the tree in 
	//that specific format after you insert!
}

template<class Item>
void bstNode<Item>::traverse()
{
	if (this == NULL) {cout << "No data to traverse!!" << endl;}
	else 
	{
		if (left_field != NULL)
		{
			left_field->traverse();
		}
		cout << "Current data field: " << this << ":" << data_field << endl;
		if (right_field != NULL)
		{
			right_field->traverse();

		}
	}
	//print out the sequence of data using IN ORDER traversal
}

template<class Item>
void bstNode<Item>::remove(Item& targetData)
{
	if (this == NULL) {cout << "";}
	else
	{

		if (data_field == targetData && left_field == NULL && right_field == NULL)
		{
			cout << "Deleting root node with no leaves....." << endl;
			data_field = NULL;

		}

		if (right_field != NULL)
			{
				if (right_field->data_field == targetData && right_field->left_field == NULL && right_field->right_field==NULL)
		{
			cout<<"Deleting right node with no children" << endl;
			right_field->data_field = NULL;
			right_field = NULL; 
		}
		}


		if (left_field != NULL)
			{		
			if (left_field->data_field == targetData && left_field->left_field == NULL && left_field->right_field==NULL)
		{
			cout<<"Deleting left node with no children" << endl;
			left_field->data_field = NULL;
			left_field = NULL; 
		}
		}


		if (left_field != NULL)
		{
		if (left_field->data_field == targetData && left_field->left_field != NULL && left_field->right_field == NULL)
		{
			cout<<"replacing left node with its left leaf" << endl;
			bstNode* x = left_field;

			left_field = left_field->left_field;
			delete x;
		}
		}

		if (left_field != NULL)
		{
		if (left_field->data_field == targetData && left_field->right_field != NULL && left_field->left_field == NULL)
		{
			cout << "replacing left node with its right leaf" << endl;
			bstNode* x = left_field;
			left_field = left_field->right_field;
			delete x;
		}
		}

		if (right_field != NULL)
		{
		if (right_field->data_field == targetData && right_field->right_field != NULL && right_field->left_field == NULL)
		{
			cout << "replacing right node with its right leaf" << endl;
			bstNode* x = right_field;
			right_field = right_field->right_field;
			delete x;
		}
		}

		if (right_field != NULL)
		{
			if (right_field->data_field == targetData && right_field->right_field == NULL && right_field->left_field != NULL)
		{
			cout << "replacing right node with its left leaf" << endl;
			bstNode* x = right_field;
			right_field = right_field->left_field;
			delete x;
		}
		}


		if (data_field == targetData && left_field != NULL && right_field != NULL && left_field->right_field == NULL)
		{
			cout << "deleting node with 2 children...." << endl;
			int x;
			x = left_field->data_field;
			data_field = x;
			left_field= left_field->left_field;
		}

		if (data_field == targetData && left_field != NULL && right_field != NULL)
		{
			cout << "deleting node with 2 children...." << endl;
			int x;
			x = left_field->return_max();
			data_field = x;
			left_field->remove_address();
		}

		////my 2 new cases
		if (data_field == targetData && left_field == NULL && right_field != NULL && right_field->left_field == NULL)
		{
			cout << "deleting root node with only right child" << endl;
			int x;
			x = right_field->data_field;
			data_field = x;
			right_field= right_field->right_field;
		}

		if (data_field == targetData && right_field == NULL && left_field != NULL && left_field->right_field == NULL)
		{
			cout << "deleting root node with only left child" << endl;
			int x;
			x = left_field->data_field;
			data_field = x;
			left_field= left_field->left_field;
		}

		else if (targetData < data_field){left_field->remove(targetData);}
		else if (targetData > data_field){right_field->remove(targetData);}

	}
	//go through and remove the item and remake the tree
}

//sum=1; if left not nul sum+=size(left)  if right not null sum+=size right
//return 1+size(left_field)+size(right_field)
template<class Item>
int bstNode<Item>::size()
{
	  if (this==NULL) 
	 { 
	  	cout << "No nodes yet" << endl;
	    return 0; 
	 } 
	else 
	{ 
	  int size = 1;
	  if (left_field != NULL) {size += left_field->size();}
	  if (right_field != NULL) {size += right_field->size();}

	  cout << "Size of tree: " << size << endl;
	  return size;
  	} 
  }



template<class Item>
int bstNode<Item>::return_max()
{
	bstNode* temp = this;
	while (temp->right_field != NULL)
		{
			temp = temp->right_field;
			// cout << temp->data_field << endl;
		}
	// cout << "max value = " << temp->data_field << endl;

	return temp->data_field;
	}


template<class Item>
void bstNode<Item>::remove_address()
{
	bstNode* temp = this;

	while (temp->right_field->right_field != NULL)
		{
			temp = temp->right_field;
		}

	temp->right_field= NULL;//}
	}

template<class Item>
void bstNode<Item>::print_row() 
{
  if (this == NULL) {cout << "No data to print!!" << endl;}

  else {
	queue <bstNode*>currentLevel, nextLevel;
	currentLevel.push(this);
	while (currentLevel.empty() == false) {
		bstNode *current_node = currentLevel.front();
	    currentLevel.pop();
	    if (current_node) {
	      cout <<current_node->data_field << " ";
	      if(left_field != NULL) {nextLevel.push(current_node->left_field);}
	      if(right_field != NULL) {nextLevel.push(current_node->right_field);}
	    }
	    if (currentLevel.empty()) {
	      cout << "\n" <<"------------------" << endl;
	      swap(currentLevel, nextLevel);
	    }
	  }
	}
}



#endif














