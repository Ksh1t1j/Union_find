#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct ListNode{
    int element;
    int set;
    struct ListNode* next;
};
int n,m;
struct ListNode* CreateNode(){
    struct ListNode* a;
    a= (struct ListNode*)malloc(sizeof(struct ListNode));
    return(a);
}
void SizeUpdate(int Size[n], struct ListNode* T, int s){
    struct ListNode* temp = CreateNode();
    temp=T;
    while(temp!=NULL){
        Size[temp->element]=s;
        temp=temp->next;
    }
}
int Union(struct ListNode* Element[n],struct ListNode* Set[n], int Size[n],int a, int b){
    struct ListNode* temp = CreateNode();
    if(Size[a]<=Size[b]){
        temp=Set[a];
        temp->set=b;
        while(temp->next!=NULL){
            temp=temp->next;
            temp->set=b;
        }
        temp->next=Set[b];
        Set[b]=Set[a];
        Set[a]=NULL;
        Size[b]=Size[a]+Size[b];
    }
    else{
        temp=Set[b];
        temp->set=a;
        while(temp->next!=NULL){
            temp=temp->next;
            temp->set=a;
        }
        temp->next=Set[a];
        Set[a]=Set[b];
        Set[b]=NULL;
        Size[a]=Size[a]+Size[b];
    }
    return 1;
}
int main() {
    scanf("%d",&n);
    scanf("%d",&m);
    struct ListNode* Element[n];
    struct ListNode* Set[n];
    int Size[n];
    for(int i=0;i<n;i++){
        Element[i]=CreateNode();
        Element[i]->element=i;
        Element[i]->set=i;
        Element[i]->next=NULL;
        Size[i]=1;
        Set[i]=Element[i];
    }
    for(int i=0;i<m;i++){
        int opt;
        scanf("%d",&opt);
        if(opt==3){
            int a,b;
            scanf("%d",&a);
            scanf("%d",&b);
            if(Element[a]->set==Element[b]->set)
                printf("1\n");
            else 
                printf("0\n");
        }
        else{
            if(opt==2){
                int a;
                scanf("%d",&a);
                printf("%d\n",Element[a]->set);
            }
            else 
                if(opt==1){
                    int a,b;
                    scanf("%d",&a);
                    scanf("%d",&b);
                    if(Element[a]->set==Element[b]->set)
                        printf("0\n");
                    else 
                        printf("%d\n",Union(Element,Set,Size,Element[a]->set,Element[b]->set));
                }
        }
    }
    return 0;
}
