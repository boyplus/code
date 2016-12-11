#include <iostream> //for cin, cout, getline
#include <algorithm> //for any_of
#include <iterator> //for begin, end
#include <string> //for string
using namespace std;
int main()
{
   int flag = 0;
   char vowel[]={'a','e','i','o','y'};
   string input;
   getline(cin, input);
   for(char ch : input){
       if(any_of(begin(vowel),end(vowel),[&](char v){return v == ch;})) flag ^= 1;
       if(flag == 0) cout << ch;
   }
   return 0;
}
