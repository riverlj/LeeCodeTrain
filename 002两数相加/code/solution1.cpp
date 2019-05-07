#include <math.h>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int listNodeLength(ListNode *list) {
    if (list == NULL)
    {
        return 0;
    }
    
    int size = 0;
    ListNode *tmpPoint = list;
    while(tmpPoint != NULL) {
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
        
        int max = l1Length;
        ListNode *maxListNode = l1;
        int min = l2Length;
        ListNode *minListNode = l2;
        if (l1Length<l2Length)
        {
            max = l2Length;
            maxListNode = l2;
            
            min = l1Length;
            minListNode = l1;
        }
        
        ListNode *minTail = minListNode;
        ListNode *maxTail = maxListNode;
        while (maxTail != NULL) {
            if (minTail -> next == NULL) {
                minTail->next = new ListNode(0);
            }
            maxTail = maxTail -> next;
            minTail = minTail->next;
        }
        
        int temp = 0;
        ListNode* l1temp = minListNode;
        ListNode* l2temp = maxListNode;
        ListNode *result = NULL;
        ListNode *resultTail = NULL;
        for (int i = 0; i < max; ++i)
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
        }
        
        if (temp > 0) {
            resultTail->next = new ListNode(temp);
        }
        return result;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
   
    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    Solution *s = new Solution();
    ListNode *list = s->addTwoNumbers(l1, l2);
    return 0;
}
