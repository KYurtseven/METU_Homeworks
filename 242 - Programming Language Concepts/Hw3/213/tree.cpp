#ifndef TREE_H__
#define TREE_H__

#include <list>
#include <iostream>
#include <cmath>
#include <functional> //less<T> <-> operator<
#include <queue>
#include <stack>
//you can #include <queue> and #include <stack> but no other STL

using std::list;
using std::cout;
using std::endl;
using std::less;
					  //function object used for comparison, default value is less
template <typename Comparable, typename Comparator=less<Comparable> >
class Tree
{
public:
  Tree( );	//construct an empty tree
  Tree( const list<Comparable> & ); //construct complete BST with min height based on list vals
  ~Tree( ); //release all dynamically allocated memory
  
  void construct( const list<Comparable> & ); //release own sources and get values from list

  const Comparable * findMin( ) const; //pointer to element that is minimal wrt Comparator, implemented
  const Comparable * findMax( ) const; //pointer to element that is maximal wrt Comparator, implemented

  const Comparable * getAddress( const Comparable & ) const; //find pointer to element with given values

  bool contains( const Comparable * ) const; //does this element with data exists in tree, implemented
  bool isEmpty( ) const; //is the tree empty, implemented
    
  void insert( const Comparable * ); //insert if dereferenced argument's data is not present, update heights of those affected
  void remove( const Comparable * ); //delete if dereferenced argument's data is present, update heights of those affected
  /* DO NOT FORGET TO CHECK BALANCE AND REBALANCE TREE IF NOT BALANCED AFTER INSERTION AND DELETION */

  size_t getSize( ) const; //accessor to size, implemented
  int getHeight( ) const; //accessor  to height, implemented
  bool isBalanced( ) const; //accessor to balanced, implemented

  void print( ) const; //inorder print of dereferenced pointers held in nodes, implemented

  friend class MusicList; //MusicList class can access private parts of Tree

private:
  struct TreeNode  //scope Tree::TreeNode, thus is only public to Tree structure, no non-friend outsiders can see
  {
    const Comparable * element; //adress of the item
    TreeNode * left; //pointer to the root of left subtree
    TreeNode * right; //pointer to the root of right subtree
    TreeNode * parent; //pointer to parent node, pay attention to this!
    size_t height; //height >= 0

    //constructor
    TreeNode( const Comparable * el,
              TreeNode * l, TreeNode * r, 
              TreeNode * p )
      : element( el ), 
        left( l ), right( r ),
        parent( p )
    {
    }
    //you should separately set height values, no constructor is defined for them
  };

  TreeNode * root; //designated root
 
  /* isLessThan( const Comparable & lhs, const Comparable & rhs )
   * returns true if lhs<rhs and false otherwise */
  Comparator isLessThan;
  
  size_t size; //number of nodes
  bool balanced;

  /* uncopiable */
  Tree( const Tree & ); //disabled, provide no implementation
  Tree & operator=( const Tree & ); //disabled, provide no implementation

  /* private utility functions */
  TreeNode * findMin( TreeNode * ) const; //recursively find min in (leftward) subtrees
  TreeNode * findMax( TreeNode * ) const; //recursively find max in (rightward) subtrees
  bool contains( const Comparable *, TreeNode * ) const; //recursively search for an item
  
  bool isLeaf( TreeNode * ) const; //isLeaf
  bool isFull( TreeNode * ) const; //isFull
  void print( TreeNode * ) const; //recursive print
  void destruction_helper( TreeNode *);
  int middleList(int n);
  size_t setHeight( TreeNode * );
  TreeNode * construction_helper(const list<Comparable> & );
  void parent_helper(TreeNode *);

  //define and use more as you may need

  template <typename T>  //templated max
  T max( T x, T y ) { return x > y ? x : y; }
}; //Do not modify method prototypes and data member names

//Below this point you should begin implementing the missing parts
template <typename Comparable, typename Comparator>
Tree<Comparable,Comparator>::Tree( )
{
	root = NULL;
	balanced = true;
	size = 0;

}
//Complete the body of the constructor



template <typename Comparable, typename Comparator>
Tree<Comparable,Comparator>::Tree( const list<Comparable> & data )
{
	int size_list = data.size();
	int mid = middleList(size_list);
	typename list<int>::const_iterator it = data.begin();
	for(int i = 0; i < mid-1 ; i++ ){ it++;}
	list<int> list1, list2;
	list1.assign(data.begin(), it);
	typename list<int>::const_iterator iter1 = list1.begin();
	while (iter1 != list1.end()){
	    cout << *iter1 << endl;
	    iter1++;
	}
	it++;
	list2.assign(it, data.end());
	typename list<int>::const_iterator iter2 = list2.begin();
		while (iter2 != list2.end()){
		    cout << *iter2 << endl;
		    iter2++;
		}
	it--;
	TreeNode * new_node = new TreeNode(&(*it),construction_helper(list1),construction_helper(list2),NULL);
	typename list<int>::const_iterator iter3 = data.begin();
		cout<< "once" << endl;
		while (iter3 != data.end()){
		    cout << *iter3 << endl;
		    iter3++;
		}
	root = new_node;
	typename list<int>::const_iterator iter4 = data.begin();
		cout<< "sonra" << endl;
		while (iter4 != data.end()){
		    cout << *iter4 << endl;
		    iter4++;
		}
	new_node->height = setHeight(root);
	parent_helper(root);
}
//Complete the body of the constructor

template <typename Comparable, typename Comparator>
void
Tree<Comparable,Comparator>::construct( const list<Comparable> & data )
{
  //Implement
}

template <typename Comparable, typename Comparator>
Tree<Comparable,Comparator>::~Tree( )
{
	destruction_helper(root);
}

template <typename Comparable, typename Comparator>
void
Tree<Comparable,Comparator>::insert( const Comparable * data )
{
  //Implement
}

template <typename Comparable, typename Comparator>
void
Tree<Comparable,Comparator>::remove( const Comparable * data )
{
  //Implement
}

template <typename Comparable, typename Comparator>
const Comparable *
Tree<Comparable,Comparator>::findMin( ) const
{
  if( isEmpty( ) )
    return NULL;
  
  return findMin( root )->element; //call in to recursive utility function
}

template <typename Comparable, typename Comparator>
const Comparable *
Tree<Comparable,Comparator>::findMax( ) const
{
  if( isEmpty( ) )
    return NULL;
  
  return findMax( root )->element;
}

template <typename Comparable, typename Comparator>
const Comparable *
Tree<Comparable,Comparator>::getAddress( const Comparable & item ) const
{ 
  //Implement
}

template <typename Comparable, typename Comparator>
bool
Tree<Comparable,Comparator>::contains( const Comparable * item ) const
{  
  return contains( item, root );
}

template <typename Comparable, typename Comparator>
size_t
Tree<Comparable,Comparator>::getSize( ) const
{
  return size;
}

template <typename Comparable, typename Comparator>
int
Tree<Comparable,Comparator>::getHeight( ) const
{
  if( isEmpty( ) )
    return -1;  //convention: empty tree has height -1
  else
    return root->height; //>= 0
}

template <typename Comparable, typename Comparator>
bool
Tree<Comparable,Comparator>::isEmpty( ) const
{
  return ( root == NULL );
}

template <typename Comparable, typename Comparator>
void
Tree<Comparable,Comparator>::print( ) const
{
  print( root );
  cout << endl;  
}

template <typename Comparable, typename Comparator>
bool
Tree<Comparable,Comparator>::isBalanced( ) const
{
  return balanced;
}

/* private utility functions 
 * define and use as many as you deem required
 * some are provided for the already implemented 
 * part of the public interface
 */
template <typename Comparable, typename Comparator>
typename Tree<Comparable,Comparator>::TreeNode *
Tree<Comparable,Comparator>::findMin( TreeNode * t ) const
{
  if( t == NULL )
    return NULL;

  if( t->left == NULL )
    return t;

  return findMin( t->left );
}

template <typename Comparable, typename Comparator>
typename Tree<Comparable,Comparator>::TreeNode *
Tree<Comparable,Comparator>::findMax( TreeNode * t ) const
{
  if( t != NULL )
    while( t->right != NULL )
      t = t->right;
  return t;
}

template <typename Comparable, typename Comparator>
bool
Tree<Comparable,Comparator>::contains( const Comparable * item, 
                                           TreeNode * t ) const
{
  if( t == NULL )
    return false;
  else if( isLessThan( *item, *(t->element) ) )
    return contains( item, t->left );
  else if( isLessThan( *(t->element), *item ) )
    return contains( item, t->right );
  else
    return true;
}

template <typename Comparable, typename Comparator>
bool
Tree<Comparable,Comparator>::isLeaf( TreeNode * t ) const
{
  return ( ( t->left == NULL ) && ( t->right == NULL ) );
}

template <typename Comparable, typename Comparator>
bool
Tree<Comparable,Comparator>::isFull( TreeNode * t ) const
{
  return ( ( t->left != NULL ) && ( t->right != NULL ) );
}

template <typename Comparable, typename Comparator>
void
Tree<Comparable,Comparator>::print( TreeNode * t ) const
{
  if( t->left != NULL )
  {
    cout << '[';
    print( t->left );
  }
  else if( t->left == NULL && t->right != NULL )
  {
    cout << "[";
  }

  if( t != NULL )
  {
    if( isLeaf( t ) )
    {
      cout << '(' << *( t->element ) << ')';
    }
    else if( !isLeaf( t ) )
    {
      cout << *( t->element );
    }
  }

  if( t->right != NULL )
  {
    print( t->right );
    cout << ']';
  }
  else if( t->left != NULL && t->right == NULL )
  {
    cout << "]";
  }
}

template <typename Comparable, typename Comparator>
void Tree<Comparable,Comparator>::destruction_helper(TreeNode * t)
{
	if ( t != NULL)
	{
		destruction_helper(t->right);
		destruction_helper(t->left);
		delete t;
	}
}

template <typename Comparable, typename Comparator>
int Tree<Comparable,Comparator>::middleList(int n)
{
  int mid;

  if(n > 0)
  {
    int a = floor(log2(n));
    int kalan = n - pow(2,a) + 1 ;
    int kalan_max = pow(2,a);

    if( kalan > kalan_max/2 )
    {
      mid = pow(2,a)/2 + kalan_max/2;
    }
    else
    {
      mid = pow(2,a)/2 + kalan;
    }
    return mid;
  }
  else
  {
	  return 0;
  }
}

template <typename Comparable, typename Comparator>
size_t Tree<Comparable,Comparator>::setHeight( TreeNode* t )
{
	return max(t->left->height , t->right->height ) +1 ;
}

template <typename Comparable, typename Comparator>
typename Tree<Comparable,Comparator>::TreeNode *
Tree<Comparable,Comparator>::construction_helper( const list<Comparable> & data )
{

	int size_list = data.size();
	int mid = middleList(size_list);


	if(data.size() == 0){ return NULL;}

	else if ( data.size() == 1 )
	{
		typename list<int>::const_iterator it = data.begin();
		TreeNode * new_node = new TreeNode(&(*it),NULL,NULL,NULL);
		new_node->height = 0;
		return new_node;
	}

	else
	{
		typename list<int>::const_iterator it = data.begin();
		for(int i = 0; i < mid-1 ; i++ ){ it++;}
		list<int> list1, list2;
		list1.assign(data.begin(), it);
		it++;

		/*
		 * typename list<int>::const_iterator iter1 = list1.begin();
			while (iter1 != list1.end()){
			    cout << *iter1 << endl;
			    iter1++;}*/
		list2.assign(it, data.end());
		it--;
		/*typename list<int>::const_iterator iter2 = list2.begin();
			while (iter2 != list2.end()){
			    cout << *iter2 << endl;
			    iter2++;}*/
		TreeNode* new_node = new TreeNode(&(*it),NULL,NULL, NULL);

		new_node->left = construction_helper(list1);
		new_node->right = construction_helper(list2);

		new_node->height = setHeight(new_node);
		return new_node;
	}
}

template <typename Comparable, typename Comparator>
void Tree<Comparable,Comparator>::parent_helper(TreeNode* t)
{
	if(t == NULL)
	{
		return;
	}
	if ( t->left )
	{
		t->left->parent = t;
		parent_helper(t->left);
	}
	if (t->right)
	{
		t->right->parent = t;
		parent_helper(t->right);
	}
}

#endif
