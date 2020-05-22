//Question 1 - Problem 1 on page 826

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

void reverseNodes(LNPtr& head)
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

  cout << "Question 1 Output:" << endl;
/*
  LNPtr head = new ListNode(5, nullptr); //3
  head = new ListNode(7, head); //2
  head = new ListNode(9,head); //1
  head = new ListNode(4,head); //0

  //Original order 4,9,7,5
  //Now prints 5,7,9,4

  reverseNodes(head);
*/
//
  LNPtr head1 = new ListNode(7, nullptr); //3
  head1 = new ListNode(1, head1); //2
  head1 = new ListNode(12,head1); //1
  head1 = new ListNode(8,head1); //0

  //Original order 8,12,1,7
  //Now prints 7,1,12,8

  reverseNodes(head1);
//

  return 0;
}
