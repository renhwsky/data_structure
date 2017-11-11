/**************************
* Auth: Atlantis 
* Date: 2017-10-17
****************************/
#include <stdio.h>
#include <stdlib.h>

// define Node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}TNode;

//链队列类型定义
typedef struct QueueNode
{
     TNode *data;
     struct QueueNode *next;
}TQueueNode;


typedef struct LinkQueueNode
{
      TQueueNode *front,*rear;
}LKQue;


void InitQueue(LKQue *LQ)//初始化队列
{     
      TQueueNode *p;
      p=(TQueueNode*)malloc(sizeof(TQueueNode));
      LQ->front=p;
      LQ->rear=p;
      LQ->front->next=NULL;
      LQ->front->data=NULL;
      LQ->rear->next=NULL;
      LQ->rear->data=NULL;
}

int EmptyQueue(LKQue *LQ)//判断队列是否为空
{  if(LQ->front==LQ->rear)
      return 1;
   else 
      return 0;
}

void EnQueue(LKQue *LQ,TNode *x)//入队列
{
    TQueueNode *p;
    p=(TQueueNode*)malloc(sizeof(TQueueNode));
    p->data=x;
    p->next=NULL;
    LQ->rear->next=p;
    LQ->rear=p;
}

int OutQueue(LKQue *LQ)//出队列
{
    TQueueNode *s;
    if (EmptyQueue(LQ))
    {
        exit(0);
    }
    else
    {
        s=LQ->front->next;
        LQ->front->next=s->next;
        if(s->next==NULL)
            LQ->rear=LQ->front;
        free(s);
        return 1;
   }
}

TNode* GetHead(LKQue *LQ)//取队列首元素
{
    TQueueNode *p;
    TNode *q;//q->data=-1; 错误在这里没有分配空间就赋值
    if(EmptyQueue(LQ))
        return NULL;
    else 
    {
        p=LQ->front->next;
        LQ->front = LQ->front->next;
        return p->data;
    }
}


void printLevelTree(TNode *T)
{
    if (T == NULL) return;
    LKQue link;
    TNode *temp;
    InitQueue(&link);
    EnQueue(&link, T);
    while(!EmptyQueue(&link))
    {
        temp = GetHead(&link);
        printf("%d\n", temp->data);
        if (temp->left) EnQueue(&link,temp->left);
        if (temp->right) EnQueue(&link,temp->right);
    }
    printf("--------\n");
}





// create a new TNode
TNode *newNode(int data) {
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// add a new data to the tree
TNode *create(TNode *head, int data) {
    if (NULL == head) {
        head = newNode(data);
    }
    else if (data <= head->data) {
        head->left = create(head->left, data);
    }
    else {
        head->right = create(head->right, data);
    }
    return head;
}

// print tree
void printPreTree(TNode *head) {
    if (NULL == head) {
        return;
    }
    printf("%d\n", head->data);
    printPreTree(head->left);
    printPreTree(head->right);
}


printInoTree(TNode *head) {
    if (NULL == head) {
        return;
    }
    printInoTree(head->left);
    printf("%d\n", head->data);
    printInoTree(head->right);
}


printPosTree(TNode *head) {
    if (NULL == head) {
        return;
    }
    printPosTree(head->left);
    printPosTree(head->right);
    printf("%d\n", head->data);
}



/*
delete all the node of the Designated head 
*/
TNode *deleteTree(TNode *head) {
    if (head == NULL) {
        return NULL; 
    }
    
    deleteTree(head->left);
    deleteTree(head->right);
    free(head);
    return NULL;
}

TNode *delete(TNode *head, int data) {
    if (head == NULL) {
        printf("not found!\n");
        return NULL;
    }
    if (head->data == data) {
        head = deleteTree(head);
    }
    else if (head->data < data) {
        head->right = delete(head->right, data);
    }
    else {
        head->left = delete(head->left, data);
    }
    return head;
} 


int height(TNode *head) 
{
   if (head==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int left_height = height(head->left);
       int right_height = height(head->right);
 
       /* use the larger one */
       if (left_height > right_height) 
           return(left_height+1);
       else return(right_height+1);
   }
} 


// main
int main()
{
    printf("Binary Search Tree\n");
    TNode * head = NULL;
    int c,i;
    int data;
    
    head=create(head, 55); 
    for(i=1; i<10; i=i+2) {
        head=create(head, i);
        head=create(head, i+100);
    }
    
    again:
    printf("\n1. Insert Node	2. Delete Node	  3. Search    4.Find height    0.print tree   -1.print LevelTree\n");
    scanf("%d",&c);
    switch(c) {
        case -1:
            printLevelTree(head);
            break;
        case 0:
            printInoTree(head); 
            break; 
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            head = create(head, data);
            break;
        case 2:
            printf("Delete data\n");
            scanf("%d", &data);
            head = delete(head, data);
            break;
        case 4:
            printf("tree height\n");
            printf("%d\n",height(head));
            break;
    	default:
    	    printf("No is choose, Please again!\n");
            return 0;
    }
    goto again;   
 
    return 0;
}

