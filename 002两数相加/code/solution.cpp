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
        int sum1 = getListSum(l1);
        int sum2 = getListSum(l2);
        int sum3 = sum1 + sum2;
        
        int sum3Length = 0;
        int tmp = sum3;
        while(tmp > 0) {
            tmp = tmp/10;
            sum3Length++;
        }
        
        ListNode *head = NULL;
        ListNode *tail = nullptr;
        int m = sum3;
        while(sum3Length > 0) {
            int val = m%(10);
            m = m / 10;
            
            ListNode *list = new ListNode(val);
            if (head)
            {
                tail->next = list;
                tail = list;
            } else {
                head = list;
                tail = head;
            }
            sum3Length--;
        }
        return head;
        
    }
    
    int getListSum(ListNode *list) {
        int length = listNodeLength(list);
        
        int sum = 0;
        int index = 0;
        ListNode *tmpPoint = list;
        while(tmpPoint != NULL) {
            sum += pow(10, length-index) * tmpPoint->val;
            tmpPoint = tmpPoint->next;
            index++;
        }
        
        return sum;
        
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
    
    while(list != NULL) {
        list = list->next;
    }
    
    
    return 0;
}
