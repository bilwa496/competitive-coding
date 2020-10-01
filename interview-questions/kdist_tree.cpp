/*
Company : JPMC[Quant Trader]
Problem Statement: Given a target node. Print all nodes at k distance from the target node
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(node* root, int k)
{
	if (root == NULL or k < 0)
		return;
	if (k == 0)
	{
		cout << root->data << endl;
		return;
	}
	solve(root->left, k - 1);
	solve(root->right, k - 1);
}
/*function returns distance of root from target node.
returns -1 if target node absent
*/
int calculate(node* root , node*target, int k)
{
	if (root == NULL)
		return -1;
	if (root == target)
	{
		solve(root, k);
		return 0;
	}
	ll left = calculate(root->left, target, k);
	if (left != -1)
	{
		if (left + 1 == k)
			cout << root->data << endl;
		else
			solve(root->right, k - left - 2);//right child is at a distance of two from left child
		return left + 1;
	}
	ll right = calculate(root->right, target, k);
	if (right != -1)
	{
		if (right + 1 == k)
			cout << root->data << endl;
		else
			solve(root->left, k - right - 2);
		return left + 1;
	}
	return -1;
}
/*
We have 2 kind of nodes:
1. nodes in the subtree rooted with target node[Traverse down the tree][Easy]
2. other nodes, maybe ancestor of target of a node in some other subtree
 and at a distance of k.[Hard]
 Approach:
 for nodes not lying in the subtree use the follwoing approach:
 1. For every ancestor we find distance from target node[=d]
 now we fo to other subtree[left if target was in right subtree and vice versa]
 2. Find all nodes at a distance of k-d from the ancestor


*/