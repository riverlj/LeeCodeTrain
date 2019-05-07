#include <math.h>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int listNodeLength(ListNode *list) {
    if (list == NULL || list->next == NULL)
    {
        return 0;
    }
    
    int size = 0;
    ListNode *tmpPoint = list;
    while(tmpPoint->next != NULL) {
        size++;
        tmpPoint = tmpPoint->next;
    }
    return size;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Length = listNodeLength(l1);
        int l2Length = listNodeLength(l2);

        int min = l1Length;
        if (l1Length>l2Length)
        {
            min = l2Length;   
        }

        int temp = 0;
        ListNode* l1temp = l1;
        ListNode* l2temp = l2;
        ListNode *result = NULL;
        ListNode *resultTail = NULL;
        for (int i = 0; i < min; ++i)
        {
            int sum = l1temp->val + l2temp->val + temp;
            temp = sum/10;
            int val = sum%10;
            ListNode *node = new ListNode(val);
            if (result == NULL)
            {
                result = node;
                resultTail = result;
            } 
            else 
            {
                resultTail->next = node;
                resultTail = node;
            }

            l1temp = l1temp->next;
            l2temp = l2temp->next;

            if (i == min - 1)
            {
                if(temp > 0) 
                {
                    if (l1Length == l2Length)
                    {
                        resultTail->next = new ListNode(temp);
                    } 
                    else if(l1Length > l2Length) 
                    {
                        node = new ListNode(l1temp->val + temp);
                        resultTail->next = node;
                        resultTail = node;
                        l1temp = l1temp->next;
                        resultTail->next = l1temp;

                    }
                    else if(l1Length < l2Length)
                    {

                        node = new ListNode(l2temp->val + temp);
                        resultTail->next = node;
                        resultTail = node;
                        l2temp = l2temp->next;
                        resultTail->next = l2temp;
                    }

                } else {
                    if (min == l1Length)
                    {
                        resultTail->next = l2temp;
                    }
                    else
                    {
                        resultTail->next = l1temp;
                    }
                }
            }

        }

        return result;
        
    }
    
};

int main()
{
    ListNode *l1 = new ListNode(9);
    ListNode *tmp = l1;
    for (int i=0; i<10; i++) {
        ListNode *list = new ListNode(9);
        tmp->next = list;
        tmp = list;
    }
    
    ListNode *l2 = new ListNode(9);
    tmp = l2;
    for (int i=0; i<10; i++) {
        ListNode *list = new ListNode(9);
        tmp->next = list;
        tmp = list;
    }
    Solution *s = new Solution();
    ListNode *list = s->addTwoNumbers(l1, l2);
    
    
    return 0;
}
