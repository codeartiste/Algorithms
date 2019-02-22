//
//  TreeDataStructure.hpp
//  Algorithms
//
//  Created by Sandip Pal on 9/16/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#ifndef TreeDataStructure_hpp
#define TreeDataStructure_hpp

#include <stdio.h>

class BinTreeNode{
public:
    int val;
    BinTreeNode   *left;
    BinTreeNode   *right;
    BinTreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    static void doBFS(BinTreeNode *);
    static void doInorder(BinTreeNode *);
    static void addBinSearchTreeElems(BinTreeNode*head, int val);
    static void doInorderKSmall(BinTreeNode *head, int k , int &now);
    
};

#endif /* TreeDataStructure_hpp */
