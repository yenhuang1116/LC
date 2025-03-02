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