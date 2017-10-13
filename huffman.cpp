#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char* argv[]){

srand(time(0));
    priority_queue<int,vector<int>,greater<int> > q;
    //for( int i = 0; i != 10; ++i ) q.push(rand()%10);
    q.push(10); q.push(20); q.push(30); q.push(5); q.push(15);
    cout << "Min-heap, popped one by one: ";
    while( ! q.empty() ) {
        cout << q.top() << ' ';  // 0 3 3 3 4 5 5 6 8 9
        q.pop();
    }
    cout << endl;
   

  
  /*
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end(), greater<int>());
  std::cout << "initial min heap   : " << v.front() << '\n';

  for(unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  cout << endl;

  std::sort_heap (v.begin(), v.end(),greater<int>());

  for(unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  cout << endl;
  
  std::pop_heap (v.begin(),v.end(),greater<int>());
  v.pop_back();
  std::cout << "min heap after pop : " << v.front() << '\n';

  for(unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  cout << endl;

  
  v.push_back(99); std::push_heap (v.begin(),v.end(), greater<int>());
  std::cout << "max heap after push: " << v.front() << '\n';

  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';
 
  */



  return 0; 
}
