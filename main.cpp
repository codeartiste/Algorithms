//
//  main.cpp
//  GraphAlgo
//
//  Created by Sandip Pal on 8/11/18.
//  Copyright © 2018 Sandip Pal. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "GraphStructure.hpp"
#include "ProblemHeaders.hpp"
#include "Permutations.hpp"
#include "RecursionDynamicProgs.hpp"
#include "SortingAlgorithms.hpp"
#include "TreeDataStructure.hpp"
#include "Backtracking.h"
#include "StackAlgorithm.h"
#include "BinarySearch.h"
#include "ArrayAlgo.hpp"
#include "PriorityQueue.hpp"


void test_graph1(){
    
    std::cout << "Hello, Graphs!\n";
    GraphAdjacencyList *pAdj = new GraphAdjacencyList(13);
    pAdj->AddEdge(0, 1);
    pAdj->AddEdge(1, 2);
    pAdj->AddEdge(2, 3);
    pAdj->AddEdge(2, 5);
    pAdj->AddEdge(5, 6);
    pAdj->AddEdge(5, 7);
    pAdj->AddEdge(3, 4);
    pAdj->AddEdge(3, 7);
    //pAdj->AddEdge(7, 0);
    pAdj->AddEdge(7, 12);
    pAdj->AddEdge(7, 11);
    pAdj->AddEdge(7, 8);
    pAdj->AddEdge(8, 9);
    pAdj->AddEdge(9, 10);
    pAdj->AddEdge(8, 11);
    pAdj->AddEdge(11, 12);
    
    //pAdj->PrintBFS(5);
    
    /* pAdj->AddEdge(0, 2);
     pAdj->AddEdge(0, 1);
     pAdj->AddEdge(1, 3);
     pAdj->AddEdge(1, 4);
     pAdj->AddEdge(3, 4);*/
    
    cout << "Union Find cyclic = " << pAdj->isCyclicUnionFind() << endl;
    //pAdj->PrintDFS(7);
    
    //pAdj->SearchPath(1, 7);
    
    delete [] pAdj;
    cout <<endl ;
    
}

void test_Dynamic1(){
    RecurDynamicProg nRP;
    int n = 8;
    int *memo;
    memo = new int[n + 1];
    for (int i = 0; i <= n; i++) {
    memo[i] = -1;
    }

    cout << "Num ways to climb = "
    << nRP.getChildNumWaysToClimb(n, memo) << endl;
    
}

void test_permu(){
    Permutations p("ABC");
    //p->doPermuteAndPrint();
    char str[] = "ABC";
    p.permute(str, 0, strlen(str) -1 );
    
}
void test_stack1(){
    StackAlgorithm st;
    cout <<st.CheckValidParenthesis("((aaa{ccc})){}") << endl ;
    //string *cor = st.MakeValidParenthesis("{{[[{{{)((()))");
    //cout << *cor;

    st.MakeValidParenthesis("{{[[{{{)((()))");
    cout << endl ;
    st.MakeValidParenthesis("()())()");
    cout << endl ;
    
}

void test_stack2(){
 
    StackAlgorithm st;
    string exp = "()())()";
    st.RemoveInvalidParenthesis(exp);
    
}

void test_reccurDynamic1(){
    
    
     /*RecurDynamicProg *nRP = new RecurDynamicProg();
     
     int ways = nRP->CalcWaystoWriteBrackets(10 , 10);
     cout << "Ways:   " << ways <<endl;
      */
    
     RecurDynamicProg *nRP = new RecurDynamicProg();
     int n = 3;
     vector<string> strset;
     char *str = new char[n+11];
     int ways = nRP->CalcWaystoWriteBrackets(n , n, str, 0, strset);
     delete [] str;
    for(std::vector<string>::iterator it = strset.begin(); it != strset.end(); ++it) {
        cout << *it  << endl;
    }
     cout << "Ways:   " << ways <<endl;
    
    /*SortAlgorithms *pSort = new SortAlgorithms();
     int arr[] = {8, 7, 26, 3, 9, 4, 12, 5};
     pSort->myMergeSort(arr, sizeof(arr)/sizeof(int));
     for(int i = 0 ; i < sizeof(arr)/sizeof(int); i++){
     cout << arr[i] << ",    " ;
     }*/
    /*int r = 4;
     i
     int *arr[r];
     for (int i=0; i<r; i++)
     arr[i] = (int *)malloc(c * sizeof(int));
     char grid[4][5] ={{'1', '1', '1', '1', 0}, {'1', '1', '0', '1', 0}, {'1', '1', '0', '0', 0}, {'0', '0', '0', '0', 0} };
     Solution *s = new Solution;
     s->numIslands((char**)grid, 4, 5);*/
}


void test_arralgo1(){
    ArrayAlgo alg;
    vector<int> a{1, 3, 3, 5, 5, 8, 10};
    vector<int> b{1, 3, 4, 6, 8, 8, 9, 10};
    vector<int> out;
    out = alg.Aunion(a, b);
    
    for (std::vector<int>::iterator it = out.begin() ; it != out.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    
    
    out = alg.Aintersect(a,b);
    
    for (std::vector<int>::iterator it = out.begin() ; it != out.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
   
    
}

void test_PriorityQ(){

    PriorityQueue pq(0);
    pq.insert(20);
    pq.insert(10);
    pq.insert(11);
    pq.insert(5);
    pq.insert(8);
    pq.insert(21);
    pq.insert(2);
    cout<< endl << pq.findMinimum() << endl <<endl << endl;
    ;    pq.print();
    
    
}

int main(int argc, const char * argv[]) {
	// insert code here...
    //test_stack1();
    //test_stack2();
    //test_reccurDynamic1();
    //test_permu();
    //test_arralgo1();
    test_PriorityQ();

	 

	

    
    /*
    Solution3Sum *s1 = new Solution3Sum();
    vector<int> nums = {-1,0,1,2,-1,-4};
    s1->threeSum(nums);
    
*/
	/*
    RecurDynamicProg *nRP = new RecurDynamicProg();
    int n = 4;
    vector<string> strset;
    char *str = new char[n+11];
    int ways = nRP->CalcWaystoWriteBrackets(n , n, str, 0, strset);
    delete [] str;
    cout << "Ways:   " << ways <<endl;  */
    
/*    BinTreeNode * head  = NULL;
    BinTreeNode * curr  = NULL;
    head = new BinTreeNode(3);
    curr = head;
    curr->left = new BinTreeNode(1);
    curr->right = new BinTreeNode(2);
    curr = curr->left;
    curr->left = new BinTreeNode(5);
    curr->right = new BinTreeNode(7);
    curr = curr->right;
    curr->left = new BinTreeNode(18);
    
    curr = head->right;
    curr->left = new BinTreeNode(8);
    curr->right = new BinTreeNode(4);
    curr = curr->right;
    curr->left = new BinTreeNode(9);
    curr->right = new BinTreeNode(12);
    BinTreeNode::doBFS(head);*/
    
	/*MathProbs mp;
	cout << mp.getSqrt(22, 0.0001);*/

    /*
	    BinTreeNode * head  = NULL;
	    BinTreeNode * curr  = NULL;
	    head = new BinTreeNode(12);

	    BinTreeNode::addBinSearchTreeElems(head, 5);
	    BinTreeNode::addBinSearchTreeElems(head, 7);
	    BinTreeNode::addBinSearchTreeElems(head, 15);
	    BinTreeNode::addBinSearchTreeElems(head, 18);
	    BinTreeNode::addBinSearchTreeElems(head, 11);
	    BinTreeNode::addBinSearchTreeElems(head, 3);
	    BinTreeNode::addBinSearchTreeElems(head, 21);
	    BinTreeNode::addBinSearchTreeElems(head, 9);
	    BinTreeNode::addBinSearchTreeElems(head, 1);
	    BinTreeNode::addBinSearchTreeElems(head, 14);
	    BinTreeNode::addBinSearchTreeElems(head, 17);
	    BinTreeNode::addBinSearchTreeElems(head, 19);
	    BinTreeNode::addBinSearchTreeElems(head, 25);
	    BinTreeNode::addBinSearchTreeElems(head, 28);

	    BinTreeNode::doInorder(head);

	    cout << "==============" << endl ;
	    int now = 0;
	    BinTreeNode::doInorderKSmall(head, 7, now);*/
    
   /* SortAlgorithms sort ;
    int arr[] = {8, 7, 26, 3, 9, 4, 12, 5};
    sort.myQsort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0 ; i < sizeof(arr)/sizeof(int); i++){
        cout << arr[i] << "   " ;
    }
    
    */
/*
	Backtracking bt;
	vector <int> arr = {1, 1, 2, 5, 6, 7, 10};
	vector <vector <int>> res;

	res = bt.solveCombinationSum(arr, 8);
	// Print all combinations stored in res.
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i].size() > 0)
		{
			cout << " ( ";
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << ")";
		}
	}
	*/

	

	/*BinarySearch bsrch;

	vector<int> myrSArr;
	myrSArr.push_back(8);
	myrSArr.push_back(9);
	myrSArr.push_back(10);
	myrSArr.push_back(2);
	myrSArr.push_back(3);
	myrSArr.push_back(4);
	myrSArr.push_back(5);
	myrSArr.push_back(6);
	myrSArr.push_back(7);

	bsrch.doBinaryRotatedSearch(myrSArr, 4);
	 */
/*
	GraphAdjacencyList *pAdj = new GraphAdjacencyList(5);
		 pAdj->AddEdge(0, 1);
		 pAdj->AddEdge(1, 2);
		 pAdj->AddEdge(2, 3);
		 pAdj->AddEdge(3, 4);
		 pAdj->AddEdge(4, 2);

		 bool iscyl = pAdj->isUCyclic();
		 cout << "IsUCyclic = " << iscyl << endl;

*/

	/*RecurDynamicProg *nRP = new RecurDynamicProg();
	nRP->CalcWaystoWriteSumofPerfectSquares(100);*/
/*
	GraphAdjacencyList *pAdj = new GraphAdjacencyList(13);
	 pAdj->AddEdge(0, 1, 7);
	 pAdj->AddEdge(0, 2, 2);
	 pAdj->AddEdge(0, 3, 3);
	 pAdj->AddEdge(1, 2, 3);
	 pAdj->AddEdge(1, 4, 4);
	 pAdj->AddEdge(2, 4, 4);
	 pAdj->AddEdge(2, 8, 1);
	 pAdj->AddEdge(4, 6, 5);
	 pAdj->AddEdge(8, 6, 3);
	 pAdj->AddEdge(8, 7, 2);
	 pAdj->AddEdge(7, 5, 2);
	 pAdj->AddEdge(5, 11, 5);
	 pAdj->AddEdge(11, 9, 4);
	 pAdj->AddEdge(11, 10, 4);
	 pAdj->AddEdge(10, 9, 6);
	 pAdj->AddEdge(9, 12, 4);
	 pAdj->AddEdge(10, 12, 4);
	 pAdj->AddEdge(12, 3, 2);
    
    pAdj->getDijstrasPath(0, 5) ;
 */

	return 0;
}
