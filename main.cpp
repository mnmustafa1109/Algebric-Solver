#include<iostream>
#include<cmath>

using namespace std;

int ex_pow(string s){

    // Find position of ':' using find()
    int pos ;

    pos = s.find("x^");

    // Copy substring after pos
    string sub = s.substr(pos + 2);

    return stoi(sub);
}

int ex_coef(string s){

    // Find position of ':' using find()
    int pos ;

    pos = s.find("x^");

    // Copy substring before pos
    string sub = s.substr(0 , pos);

    return stoi(sub);
}

int find_degree(string s){

    char checkCharacter = 'x';
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] ==  checkCharacter)
        {
            ++ count;
        }
    }

    return count;

}


string del(string s){

    // Find position of ':' using find()
    int pos = 0 ;

    pos = s.find("+");
    if (pos<0 || pos>s.find("-")) {
      pos = s.find("-");
    }

    string sub = s.substr(pos);


    return sub;
}

char get_sign(string s){
  return s.at(0);
}

int main () {

  string equ ;
  std::cout << "Enter an equation like 3x^45+9x^3-6x^21" << '\n';
  std::cin >> equ;

  int deg = find_degree(equ) ;

  for (size_t i = 0; i < deg; i++) {

    std::cout << "co: "<< ex_coef(equ) << '\n';
    std::cout << "pow: "<<ex_pow(equ)<< '\n';
    if( i!=deg-1){
      equ = del(equ);
      std::cout << "sign " << get_sign(equ) << '\n';
      equ.erase(0,1);
    }
  }

  return 0;

}
