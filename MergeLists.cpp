//Question 2 - Problem 2 on page 826

#include <iostream>
using namespace std;

class ListNode
{
public:
  ListNode(int theNum, ListNode *theLink);
  int getNum() const {return num;}
  ListNode* getLink() const {return link;}
  void setLink(ListNode *theLink) {link = theLink;}
private:
  int num;
  ListNode *link;
};
typedef ListNode* LNPtr;

ListNode::ListNode(int theNum, ListNode *theLink):num(theNum), link(theLink)
{
  //intentionally empty
}

LNPtr mergeLists(LNPtr& head1, LNPtr& head2)
{
  LNPtr newHead = nullptr;
  LNPtr iterator1 = head1;
  LNPtr iterator2 = head2;

  if (iterator1->getNum() > iterator2->getNum()) {
    newHead = new ListNode(iterator2->getNum(), nullptr);
    iterator2 = iterator2->getLink();
  }
  else
  {
    newHead = new ListNode(iterator1->getNum(), nullptr);
    iterator1 = iterator1->getLink();
  }

  while (iterator1 != NULL && iterator2 != NULL) {
    if (iterator1->getNum() > iterator2->getNum()) {
      newHead = new ListNode(iterator2->getNum(), newHead);
      iterator2 = iterator2->getLink();
    }
    else
    {
      newHead = new ListNode(iterator1->getNum(), newHead);
      iterator1 = iterator1->getLink();
    }
  }

  if (iterator1 != NULL) {
    newHead = new ListNode(iterator1->getNum(), newHead);
    iterator1 = iterator1->getLink();
  }
  if (iterator2 != NULL) {
    newHead = new ListNode(iterator2->getNum(), newHead);
    iterator2 = iterator2->getLink();
  }

  head1 = nullptr;
  head2 = nullptr;

  return newHead;
}

void reverseNodes(LNPtr& head) //used from previous file
{
  LNPtr iterator = head;
  LNPtr next = head;
  LNPtr prev = NULL;
  int count = 0;
  while(iterator != NULL) {
    next = next->getLink();
    iterator->setLink(prev);
    prev = iterator;
    iterator = next;
  }
  head = prev;
  for (iterator = head; iterator != NULL; iterator = iterator->getLink()) {
    cout << iterator->getNum() << endl;
  }
}


int main()
{
  cout << "Question 2 Output:\n" << endl;

  LNPtr head1 = new ListNode(12, nullptr); //3
  head1 = new ListNode(7, head1); //2
  head1 = new ListNode(4,head1); //1
  head1 = new ListNode(2,head1); //0

  LNPtr head2 = new ListNode(10, nullptr); //3
  head2 = new ListNode(6, head2); //2
  head2 = new ListNode(5,head2); //1
  head2 = new ListNode(1,head2); //0

  LNPtr head3 = new ListNode(11, nullptr); //3
  head3 = new ListNode(9, head3); //2
  head3 = new ListNode(8,head3); //1
  head3 = new ListNode(3,head3); //0

  //LNPtr merged1 = mergeLists(head1, head2); //example 1
  LNPtr merged2 = mergeLists(head3, head1); //example 2

  //reverseNodes(merged1); //print example 1
  reverseNodes(merged2); //print example 2

  return 0;
}
