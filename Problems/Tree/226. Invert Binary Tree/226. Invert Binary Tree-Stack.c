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
 * @file    226. Invert Binary Tree-Stack.c
 * @brief   使用陣列實作堆疊 (Stack implementation using array)
 * @author  BY Huang
 * @date    2025-03-02
 * @version 1.0
 * 
 * @details
 * 本程式提供了一個基於陣列的堆疊 (Stack) 實作，包括：
 * - 入棧 (push)
 * - 出棧 (pop)
 * - 檢查堆疊是否為空 (isEmpty)
 * - 深度優先搜索(Depth-First Search)
 */
//---------------------------------------------

struct stack{
    struct TreeNode* node;
    struct stack* next;
};
void push(struct stack **stackPtr,struct TreeNode* root)
{
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->node=root;
    s->next=*stackPtr;
    *stackPtr=s;
}
void pop(struct stack **stackPtr)
{
    struct stack* tmp=*stackPtr;
    *stackPtr=(*stackPtr)->next;
    free(tmp);
}
int isEmpty(struct stack *stackPtr)
{
    if(stackPtr==0)
        return 1;
    return 0;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==0)
        return 0;

    struct stack *stackPtr=(struct stack *)malloc(sizeof(struct stack ));
    stackPtr->node=root;
    stackPtr->next=0;

    while(isEmpty(stackPtr)==0)
    {
        struct TreeNode* top = stackPtr->node;
        pop(&stackPtr);
        struct TreeNode*tmp=top->left;
        top->left=top->right;
        top->right=tmp;
        
        if(top->left!=0)
            push(&stackPtr,top->left);
 
        if(top->right!=0)
            push(&stackPtr,top->right);
    }
    return root;
}