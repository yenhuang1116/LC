/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//---------------------------------------------
/**
 * @file    226. Invert Binary Tree-Queue.c
 * @brief   使用佇列 (Queue implementation)
 * @author  BY Huang
 * @date    2025-03-02
 * @version 1.0
 * 
 * @details
 * 本程式提供了一個基於鏈結串列(Linked List)的佇列 (Queue) 實作，包括：
 * - 入佇列 (enqueue)
 * - 出佇列 (dequeue)
 * - 檢查佇列是否為空 (isEmpty)
 * - #廣度優先搜尋(Breadth-First Search)
 * - #Queue-Linked List
 */
//---------------------------------------------

struct queue{
    struct TreeNode* node;
    struct queue* next;
};
int isEmpty(struct queue **queuePtr)
{
    if(*queuePtr==0)
        return 1;
    return 0;
}
void enqueue(struct queue **queuePtr,struct TreeNode* root)
{
    struct queue *new=(struct queue *)malloc(sizeof(struct queue));
    new->node=root;
    new->next=0;
    if(*queuePtr==0)
        *queuePtr=new;
    else{
        struct queue *curr=*queuePtr;
        while(curr->next!=0)
            curr=curr->next;
        curr->next=new;
    }
}
struct TreeNode* dequeue(struct queue **queuePtr)
{
    struct TreeNode* ret=(*queuePtr)->node;
    struct queue* tmp=*queuePtr;
    *queuePtr=(*queuePtr)->next;
    free(tmp);
    return ret;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==0)
        return 0;

    struct queue *queuePtr=(struct queue*)malloc(sizeof(struct queue));
    queuePtr->node=root;
    queuePtr->next=0;

    while(isEmpty(&queuePtr)==0)
    {
        struct TreeNode* front = dequeue(&queuePtr);
        struct TreeNode*tmp=front->left;
        front->left=front->right;
        front->right=tmp;
        
        if(front->left!=0)
            enqueue(&queuePtr,front->left);
 
        if(front->right!=0)
            enqueue(&queuePtr,front->right);
    }
    return root;
}