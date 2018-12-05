#ifndef _TREE_H
#define _TREE_H

#include <iostream>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode {
	friend class Tree<T>;
public:
	TreeNode() :m_data(T()), firstChild(NULL), nextSibling(NULL)
	{}
	TreeNode(T data) :m_data(data), firstChild(NULL), nextSibling(NULL)
	{}
private:
	T m_data;
	TreeNode<T> *firstChild;
	TreeNode<T> *nextSibling;
};

template <typename T>
class Tree {
	typedef TreeNode<T> node_type;
public:
	Tree() = default;
	Tree(T ref) :refval(ref), root(NULL)
	{}
public:
	void init_tree(const char* str);
	void preorder_traverse()const;

	int Size()const;
	int Height()const;
	node_type* Root()const;
	node_type* Find(const T&)const;
	node_type* Parent(node_type *)const;
	bool is_empty()const;
protected:
	void init_tree(node_type *&, const char *&);
	void preorder_traverse(node_type *)const;

	int Size(node_type *)const;
	int Height(node_type *)const;
	node_type* Find(node_type *, const T&)const;
	node_type* Parent(node_type *, node_type *)const;
private:
	node_type *root;
	T refval;
};

//public interface

template <typename T>
void Tree<T>::init_tree(const char* str)
{
	init_tree(root, str);
}

template <typename T>
void Tree<T>::preorder_traverse()const
{
	preorder_traverse(root);
}

template <typename T>
int Tree<T>::Size()const
{
	return Size(root);
}

template <typename T>
int Tree<T>::Height()const
{
	return Height(root);
}

template <typename T>
TreeNode<T>* Tree<T>::Root()const
{
	return root;
}

template <typename T>
TreeNode<T>* Tree<T>::Find(const T& val)const
{
	return Find(root, val);
}

template <typename T>
TreeNode<T>* Tree<T>::Parent(node_type *cur)const
{
	return Parent(root, cur);
}

template <typename T>
bool Tree<T>::is_empty()const
{
	return root == NULL;
}

//protected interface

template <typename T>
void Tree<T>::init_tree(node_type *&t, const char *&str)
{
	if (*str == refval) {
		t = NULL;
		return;
	}
	else {
		t = new node_type(*str);
		init_tree(t->firstChild, ++str);
		init_tree(t->nextSibling, ++str);
	}
}

template <typename T>
void Tree<T>::preorder_traverse(node_type *t)const
{
	if (t == NULL)
		return;

	cout << t->m_data << " ";
	preorder_traverse(t->firstChild);
	preorder_traverse(t->nextSibling);
}


template <typename T>
int Tree<T>::Size(node_type *t)const
{
	if (t == NULL)
		return 0;
	else
		return 1 + Size(t->firstChild) + Size(t->nextSibling);
}

template <typename T>
int Tree<T>::Height(node_type *t)const
{
	if (t == NULL)
		return 0;
	if (t->firstChild == NULL)
		return 1;

	int m_current;
	int max = 0;

	auto tmp = t->firstChild;
	while (tmp != NULL) {
		m_current = Height(tmp);
		if (m_current > max)
			max = m_current;

		tmp = tmp->nextSibling;
	}

	return max + 1;
}

template <typename T>
TreeNode<T>* Tree<T>::Find(node_type *t, const T& val)const
{
	if (t == NULL)
		return NULL;
	if (t->m_data == val)
		return t;

	auto tmp = Find(t->firstChild, val);
	if (tmp == NULL)
		tmp = Find(t->nextSibling, val);

	return tmp;
}

template <typename T>
TreeNode<T>* Tree<T>::Parent(node_type *t, node_type *cur)const
{
	if (t == NULL || cur == NULL || t == cur)
		return NULL;
	if (t->firstChild == cur)
		return t;

	auto p = t->firstChild;
	while (p != NULL && p != cur) {
		auto tmp = Parent(p, cur);
		if (tmp != NULL)
			return tmp;

		p = p->nextSibling;
	}

	if (p != NULL && p == cur)
		return t;
	else
		return NULL;
}

#endif
