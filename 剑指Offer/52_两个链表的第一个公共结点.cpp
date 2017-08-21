struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution_1 {
    int getListLength(ListNode* pHead){
        if(!pHead) return 0;
        int len = 0;
        ListNode* pNode = pHead;
        while(pNode){
            ++len;
            pNode = pNode->next;
        }
        return len;
    }
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2) return 0;
        int len1 = getListLength(pHead1);
        int len2 = getListLength(pHead2);
        // 假定pHead1是长的链表，如果不是，后面的判断会处理
        ListNode* longList = pHead1;
        ListNode* shortList = pHead2;
        int listDif = len1 - len2;
        if(len1 < len2){
            longList = pHead2;
            shortList = pHead1;
            listDif = len2 - len1;
        }
        // 长的链表先走多的那几步
        while(listDif--)
            longList = longList->next;
        // 不必判断longList或者shortList是否为空，如果为空则两个相等同样退出循环
        while(longList && longList != shortList) {
            longList = longList->next;
            shortList = shortList->next;
        }
        return longList; // 返回相等时的节点，此时longList=shortList
    }
};

// 走你来时走过的路，那么我们会在交叉路口突然的相遇。好浪漫的解法！
class Solution_2 {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* pNode1 = pHead1;
        ListNode* pNode2 = pHead2;
        // 只需判断是否相等，如果没有公共点会一起走到空节点，则相等返回空节点
        while(pNode1 != pNode2){
            // 如果不为空继续走，否则续上另一个链表
            pNode1 = (pNode1 ? pNode1->next : pHead2);
            pNode2 = (pNode2 ? pNode2->next : pHead1);
        }
        return pNode1;
    }
};
