#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addLists(ListNode *head1, ListNode *head2)
{
    int carry = 0, sum = 0;
    ListNode *resultList = nullptr,
             *resultIter = nullptr;

    while (head1 || head2 || carry)
    {
        int val1 = (head1) ? head1->val : 0;
        int val2 = (head2) ? head2->val : 0;

        sum += val1 + val2 + carry;
        carry = sum / 10;
        sum %= 10;

        if (!resultList)
        {
            resultIter = new ListNode(sum);
            resultList = resultIter;
        }
        else
        {
            resultIter->next = new ListNode(sum);
            resultIter = resultIter->next;
        }

        sum = 0;
        if (head1)
            head1 = head1->next;
        if (head2)
            head2 = head2->next;
    }

    return resultList;
}

int main()
{
    ListNode *head1 =
        new ListNode(9,
                     new ListNode(9,
                                  new ListNode(9,
                                               new ListNode(9,
                                                            new ListNode(9,
                                                                         new ListNode(9,
                                                                                      new ListNode(9)))))));

    ListNode *head2 =
        new ListNode(9,
                     new ListNode(9,
                                  new ListNode(9,
                                               new ListNode(9))));

    ListNode *result = addLists(head1, head2);

    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}