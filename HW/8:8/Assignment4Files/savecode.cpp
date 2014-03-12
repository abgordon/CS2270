//saved code

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
		left_field->insert(targetData);
	}






	

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
	else if (left_field != NULL && right_field == NULL && targetData < data_field)
	{
		cout << "recursing....." << endl;
		left_field->insert(targetData);
	}
	else if (right_field != NULL && left_field == NULL && targetData > data_field)
	{
		cout << "recursing....." << endl;		
		left_field->insert(targetData);
	}

	else if (left_field != NULL && right_field != NULL && targetData > data_field)
	{
		if (right_field->data_field > targetData && left_field->data_field<targetData)
			{
				cout << "replacing node...." << endl;
				Item x = right_field->data_field;
				right_field->data_field = targetData;
				right_field->right_field = new bstNode(x);
			}
		if (right_field->data_field > targetData && left_field->data_field < targetData)
	else if (left_field != NULL && right_field != NULL && targetData < data_field)
	{
		if (right_field->data_field > targetData && left_field->data_field<targetData)
			{
				cout << "replacing node...." << endl;
				Item x = left_field->data_field;
				left_field->data_field = targetData;
				left_field->left_field = new bstNode(x);
			}
	}
}




	// int digits = 0;
	// int number = initialValue;
 //    while (number > 0) {
 //        number = number / 10;
 //        digits++;
 //    }
	// int i =digits-1;
	// bigIntArray = new char [digits];
	// int x = initialValue;
	// char mod;

	// while (x != 0 ){
	// 	int z = x%10;
	// 	char mod = '0' + z;
	// 	bigIntArray[i]=mod;
	// 	i = i-1;
	// 	x=x/10;
	// 	}


template<class Item>
void bstNode<Item>::remove(Item& targetData)
{
	if (this == NULL) {cout << "No nodes to remove!" << endl;}
	else
	{

		if (data_field == targetData && left_field == NULL && right_field == NULL)
		{
			cout << "Deleting root node with no leaves....." << endl;
			data_field = NULL;
			// this = NULL;	
			}

		else if (right_field != NULL && targetData > data_field)
			{
				if (right_field->data_field == targetData && right_field->left_field == NULL && right_field->right_field==NULL)
		{
			cout<<"Deleting right node with no children" << endl;
			right_field->data_field = NULL;
			right_field = NULL; 
		}}


		else if (left_field != NULL && data_field > targetData)
			{		
			if (left_field->data_field == targetData && left_field->left_field == NULL && left_field->right_field==NULL)
		{
			cout<<"Deleting left node with no children" << endl;
			left_field->data_field = NULL;
			left_field = NULL; 
		}}


		else if (left_field != NULL && data_field > targetData)
		{
		if (left_field->data_field == targetData && left_field->left_field != NULL && left_field->right_field == NULL)
		{
			cout<<"replacing left node with its left leaf" << endl;
			bstNode* x = left_field;

			left_field = left_field->left_field;
			delete x;
		}}

		else if (left_field != NULL && data_field > targetData)
		{
		if (left_field->data_field == targetData && left_field->right_field != NULL && left_field->left_field == NULL)
		{
			cout << "replacing left node with its right leaf" << endl;
			bstNode* x = left_field;
			left_field = left_field->right_field;
			delete x;
		}}

		else if (right_field != NULL && targetData > data_field)
		{
		if (right_field->data_field == targetData && right_field->right_field != NULL && right_field->left_field == NULL)
		{
			cout << "replacing right node with its right leaf" << endl;
			bstNode* x = right_field;
			right_field = right_field->right_field;
			delete x;
		}}

		else if (right_field != NULL && targetData > data_field)
		{
			if (right_field->data_field == targetData && right_field->right_field == NULL && right_field->left_field != NULL)
		{
			cout << "replacing right node with its left leaf" << endl;
			bstNode* x = right_field;
			right_field = right_field->left_field;
			delete x;
		}}


		else if (data_field == targetData && left_field != NULL && right_field != NULL && left_field->right_field == NULL)
		{
			cout << "deleting node with 2 children...." << endl;
			int x;
			x = left_field->data_field;
			data_field = x;
			left_field= left_field->left_field;
		}

		else if (data_field == targetData && left_field != NULL && right_field != NULL)
		{
			cout << "deleting node with 2 children...." << endl;
			int x;
			x = left_field->return_max();
			data_field = x;
			left_field->remove_address();
		}

		else if (targetData < data_field){cout << "recursing left..." << endl;left_field->remove(targetData);}
		else if (targetData > data_field){cout << "recursing right..." << endl;right_field->remove(targetData);}

