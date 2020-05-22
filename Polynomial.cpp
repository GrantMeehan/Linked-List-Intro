//Question 3 - Problem 3 on page 826

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class PolyNode
{
public:
  PolyNode();
  PolyNode(int theCoefficient, PolyNode *theLink);
  PolyNode(int thePower, int theCoefficient, PolyNode *theLink);
  PolyNode(PolyNode& newPolyNode);
  ~PolyNode();
  int getPower() const {return power;} //inline
  int getCoefficient() const {return coefficient;} //inline
  PolyNode* getLink() const {return link;} //inline
  void setLink(PolyNode *theLink) {link = theLink;} //inline
  void output();
  double evaluate(int xValue);
private:
  int power, coefficient;
  PolyNode *link;
};
typedef PolyNode* PNPtr;

PolyNode::PolyNode():power(0), coefficient(0), link(nullptr)
{
  //intentionally empty
}
PolyNode::PolyNode(int theCoefficient, PolyNode *theLink):power(0), coefficient(theCoefficient), link(theLink)
{
  //intentionally empty
}
PolyNode::PolyNode(int thePower, int theCoefficient, PolyNode *theLink):
                  power(thePower), coefficient(theCoefficient), link(theLink)
{
  //intentionally empty
}
PolyNode::PolyNode(PolyNode& newPolyNode)
{
  power = newPolyNode.power;
  coefficient = newPolyNode.coefficient;
  link = newPolyNode.link;
}
PolyNode::~PolyNode()
{
  delete link;
  link = nullptr;
}
void PolyNode::output()
{
  PNPtr iterator = nullptr;

  for (iterator = this; iterator != NULL; iterator = iterator->getLink()) {
    if (iterator -> getPower() > 0) {
      cout << iterator->getCoefficient() << "x^" << iterator->getPower() << endl;
    }
    else
      cout << iterator->getCoefficient() << endl;
  }
}
double PolyNode::evaluate(int xValue)
{
  return (pow(xValue, this->getPower())*this->getCoefficient());
}

//isNumber(string s), is by: Rohit Thapliyal
//https://www.geeksforgeeks.org/program-check-input-integer-string/
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int main()
{
  cout << "Question 3 Output:\n" << endl;

  string polynomial;

  PNPtr head = nullptr;

  cout << "- Enter polynomial with variable x, one term per line." << endl;
  cout << "- No need to add + signs." << endl;
  cout << "- Will be assumed each term is positive unless - sign added at front of term." << endl;
  cout <<"- Enter positive constant last to signal all terms entered (Enter 0 if no constant)." << endl;
  cout << endl;

  cout << "Input: " << endl;

  bool input = true;
  while(input){

    cin >> polynomial;

    if(isNumber(polynomial))
    {
      head = new PolyNode(stoi(polynomial),head);

      input = false;
    }
    else
    {
      int xLoc;
      int powLoc;
      string coefficient;
      string power;

      //finds coefficient
      for (int i = 0; i < polynomial.length(); i++)
      {
        if (polynomial[i] == 'x')
        {
          xLoc = i;
          break;
        }
      }
      for (int i = 0; i < xLoc; i++) {
        coefficient += polynomial[i];
      }

      //finds power
      for (int i = 0; i < polynomial.length(); i++)
      {
        if (polynomial[i] == '^')
        {
          powLoc = i;
          break;
        }
      }
      for (int i = powLoc + 1; i < polynomial.length(); i++) {
        power += polynomial[i];
      }

      head = new PolyNode(stoi(power),stoi(coefficient),head);

      input = true;
    }
  }

  cout << "Polynomial entered: " << endl;
  head->output();

  cout << endl;

  double enteredX;
  cout << "Evaluate this polynomial with what x value?: ";
  cin >> enteredX;

  PNPtr iterator = head;
  double total = 0;
  while(iterator != NULL)
  {
    total += iterator->evaluate(enteredX);

    iterator = iterator->getLink();
  }
  cout << "Evaluated at x = " << enteredX << " -> " << total;



  return 0;
}
