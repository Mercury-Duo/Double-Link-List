#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* front;
	struct Node* next;
}LNode,* LPNode;
 LPNode CreatNode() {
	 LPNode HeadNode = (LPNode)malloc(sizeof(LNode));
	 HeadNode->data = 0;
	 HeadNode->front = NULL;
	 HeadNode->next = NULL;
	 return HeadNode;
}
 LPNode CreatNewNode(int data) {
	 LPNode NewNode = (LPNode)malloc(sizeof(LNode));
	 NewNode->data = data;
	 NewNode->front = NULL;
	 NewNode->next = NULL;
	 return NewNode;
 }
 void InsertNode(LPNode HeadNode, int data) {//插入
	 LPNode NewNode = CreatNewNode(data);
	 if (HeadNode->next == NULL) {
		 HeadNode->next = NewNode;
		 NewNode->front = HeadNode;
		 return;
	 }
	 NewNode->next = HeadNode->next;
	 HeadNode->next->front = NewNode;
	 NewNode->front = HeadNode;
     HeadNode->next =NewNode;
 }
 void PrintList(LPNode HeadNode) {
	 LPNode pointNode = HeadNode->next;
	 while (pointNode) {
		 printf("%4d", pointNode->data);
		 pointNode = pointNode->next;
	 }
 }
 int main() {
	 LPNode myNode = CreatNode();
	 InsertNode(myNode, 6);
	 InsertNode(myNode, 1);
	 InsertNode(myNode, 2);
	 InsertNode(myNode, 3);
	 InsertNode(myNode, 4);
	 InsertNode(myNode, 5);
	 PrintList(myNode);
 }