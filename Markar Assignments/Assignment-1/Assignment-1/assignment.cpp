#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

class BST
{

private:
	node *root;

public:
	BST()
	{
		root = NULL;
	}

	bool check_left(node *temp)
	{
		if (temp->left == NULL)
		{
			return true;
		}
		else
			return false;
	}

	bool check_right(node *temp)
	{
		if (temp->right == NULL)
			return true;
		else
			return false;
	}

	bool is_greater(int val, int val_1)
	{
		if (val > val_1)
			return true;
		else
			return false;
	}

	node *Create(int data)
	{
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	void Insertion(node *temp, int data)
	{
		if (root == NULL)
		{
			root = Create(data);
			return;
		}
		if (is_greater(temp->data, data))
		{
			if (check_left(temp))
			{
				temp->left = Create(data);
				return;
			}
			else
				Insertion(temp->left, data);
		}
		else
		{
			if (check_right(temp))
			{

				temp->right = Create(data);
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else
				Insertion(temp->right, data);
		}
	}

	node *Get_Root()
	{
		return root;
	}

	void print(node *temp)
	{
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}

	// ***************Part A*******************

	int count_nodes(node *iter, int val, int count = 0)
	{
		//   YOUR CODE HERE /////
		if (iter == NULL)
			return 0;

		if (iter->data == val)
			count++;

		if (count)
		{
			if (iter->left)
				count = count_nodes(iter->left, val, count + 1);
			if (iter->right)
				count = count_nodes(iter->right, val, count + 1);
			return count;
		}

		count += count_nodes(iter->left, val);
		count += count_nodes(iter->right, val);
		return count;
	}

	// ****************Part-B********************
	int left_most_node(node *root_iter)
	{
		// YOUR CODE HERE
		if (root_iter == NULL)
			return 0;

		int leftHeight = 0;
		int rightHeight = 0;

		leftHeight += left_most_node(root_iter->left);

		if ((!root_iter->left && !root_iter->right) && root_iter != Get_Root())
			return 1;

		if (root_iter->right)
		{
			if (root_iter->right->right || root_iter->right->left)
				rightHeight += left_most_node(root_iter->right);
		}

		if ((leftHeight || rightHeight) && root_iter != Get_Root())
			return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;

		else
			return (leftHeight > rightHeight) ? leftHeight : rightHeight;
	}

	// **********************PART-C********************
	int getLeafData(node *root_iter)
	{
		if ((!root_iter->left && !root_iter->right) && root_iter != Get_Root())
			return root_iter->data;
		else
			return 0;
	}

	int right_leaves(node *root_iter)
	{
		// YOUR CODE HERE
		if (root_iter == NULL)
			return 0;

		int sum = 0;

		sum += getLeafData(root_iter);
		sum += right_leaves(root_iter->right);
		if (root_iter->left)
		{
			if (root_iter->left->left || root_iter->left->right)
				sum += right_leaves(root_iter->left);
		}
		return sum;
	}

	// *********************PART-D******************
	int left_diff(node *root_iter)
	{
		return root_iter->data - root_iter->left->data;
	}

	int right_diff(node *root_iter)
	{
		return root_iter->right->data - root_iter->data;
	}

	int get_lowest_diff(int diff, int returnedDiff)
	{
		if ((returnedDiff && diff > returnedDiff) || !diff)
			diff = returnedDiff;
		return diff;
	}

	int min_diff(node *root_iter, int diff = 0)
	{
		// YOUR CODE HERE
		if (root_iter == NULL)
			return 0;

		int returnedDiff = 0;

		if (root_iter->left)
			returnedDiff = min_diff(root_iter->left, left_diff(root_iter));

		diff = get_lowest_diff(diff, returnedDiff);

		if (root_iter->right)
			returnedDiff = min_diff(root_iter->right, right_diff(root_iter));

		diff = get_lowest_diff(diff, returnedDiff);
		return diff;
	}
};

int main()
{
	BST bst;
	bst.Insertion(bst.Get_Root(), 10);
	bst.Insertion(bst.Get_Root(), 4);
	bst.Insertion(bst.Get_Root(), 12);
	bst.Insertion(bst.Get_Root(), 24);
	bst.Insertion(bst.Get_Root(), 13);
	bst.Insertion(bst.Get_Root(), 1);
	bst.Insertion(bst.Get_Root(), 8);
	bst.Insertion(bst.Get_Root(), 9);
	bst.print(bst.Get_Root());
	//cout << endl;
	// cout << bst.count_nodes(bst.Get_Root(), 12) << endl;
	cout << bst.left_most_node(bst.Get_Root()) << endl;
	// cout << bst.right_leaves(bst.Get_Root()) << endl;
	// cout << bst.min_diff(bst.Get_Root()) << endl;
}