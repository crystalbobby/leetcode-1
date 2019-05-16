#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



void init_tree(struct TreeNode ** T)
{
    *T = NULL;
}

bool tree_is_empty(struct TreeNode **T)
{
    return false;
}

int tree_depth(struct TreeNode **T)
{
    return 0;
}

int find_node(struct TreeNode **T, int data)
{
    return 0;
}

void pre_order(struct TreeNode **T)
{

}

/**
 * @brief 左 -> 根 -> 右
 * 
 * @param T 
 */
void mid_order(struct TreeNode * T)
{
    if(T != NULL)
    {
        mid_order(T->left);
        printf("%d\t", T->val);
        mid_order(T->right);
    }
}

void post_order(struct TreeNode ** T)
{
    
}

struct TreeNode * insert_tree(struct TreeNode * T, int data)
{
    if(T == NULL)       // 如果树是空, 创建结点并插入
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            printf("out of memory!\n");
        else
        {
            T->left = NULL;
            T->right = NULL;
            T->val = data;
        }
    }
    else if(data > T->val)
        T->right = insert_tree(T->right, data);
    else if(data < T->val)
        T->left = insert_tree(T->left, data);
    
    return T;
}

/**
 * @brief 获得树的高度(根到一片树叶的最长路径)
 * 
 * @param T 
 * @return int 
 */
#define max(a,b) (((a) > (b)) ? (a) : (b))
int get_tree_height(struct TreeNode * T)
{
    return T == NULL ? 0 : max(get_tree_height(T -> left), get_tree_height(T -> right)) + 1;
    // int left_h, right_h;
    // if(T == NULL)
    //     return 0;
    // else
    // {
    //     left_h = get_tree_height(T->left);
    //     right_h = get_tree_height(T->right);

    //     return (right_h > left_h) ? right_h+1 : left_h+1;
    // }
}

int main()
{
    struct TreeNode * tree;
    int a[] = {1, 3, 8, 2, 5, 6 ,7};
    init_tree(&tree);

    for (size_t i = 0; i < sizeof(a)/4; i++)
    {
        tree = insert_tree(tree, a[i]);
    }
    mid_order(tree);
    printf("\ntree height = %d\n", get_tree_height(tree));
    return 0;
}