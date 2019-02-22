//
//  TreeDataStructure.cpp
//  Algorithms
//
//  Created by Sandip Pal on 9/16/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#include "TreeDataStructure.hpp"
#include <queue>
#include <iostream>

using namespace std;

void BinTreeNode::doBFS(BinTreeNode *t){

	if( t == NULL) return;
	queue <BinTreeNode * > bfsq;
	bfsq.push(t);

	while(!bfsq.empty()){
		BinTreeNode * p;
		p = bfsq.front();
		cout << p->val  << endl;
		if(p->left) bfsq.push(p->left);
		if(p->right) bfsq.push(p->right);
		bfsq.pop();

	}



}

void BinTreeNode::doInorder(BinTreeNode *t){

	if(t == NULL) return;
	doInorder(t->left);
	cout << t->val << endl ;
	doInorder(t->right);

}

void BinTreeNode::addBinSearchTreeElems(BinTreeNode *head, int val){

	if(val > head->val){
		if(head->right != NULL){
			addBinSearchTreeElems(head->right, val);
		}
		else{

			head->right = new BinTreeNode(val);
		}
	}
	else{
		if(head->left != NULL){
			addBinSearchTreeElems(head->left, val);
		}
		else{

			head->left = new BinTreeNode(val);
		}
	}

}

void BinTreeNode::doInorderKSmall(BinTreeNode*head, int k , int &now){

	if(head == NULL) return;
	if(now >= k) return;

	doInorderKSmall(head->left, k , now);
	if(now >= k) return;
	now++ ;
	if(now == k){
		cout << "Our Val:  "<<head->val << endl ;
		return;
	}
	cout << head->val << endl ;
	doInorderKSmall(head->right, k , now);


}
