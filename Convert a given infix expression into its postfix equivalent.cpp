//Program to convert infix operation to postfix.
#include<iostream>
#include<stack>
using namespace std;

bool arith_operators(char p)
{
	if(p=='+'||p=='-'||p=='*'||p=='/'||p=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

  int assign(char p) 
{     if(p == '^') 
      return 3; 
      else if(p == '*' || p == '/') 
      return 2; 
      else if(p== '+' || p == '-') 
      return 1; 
       else
       return -1;  
} 

string In_to_Post(stack<char> s, string inf)
{
	string post;
	for(int i=0;i<inf.length();i++)
	{   
		if((inf[i] >= 'a' && inf[i] <= 'z')
		||(inf[i] >= 'A' && inf[i] <= 'Z'))
		{
			post+=inf[i];
		}
		else if(inf[i] == '(')
		{
			s.push(inf[i]);
		}
		else if(inf[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				post+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(arith_operators(inf[i]))
		{
			if(s.empty())
			{
				s.push(inf[i]);
			}
			else
			{
				if(assign(inf[i])>assign(s.top()))
				{
					s.push(inf[i]);
				}	
				else if((assign(inf[i])==assign(s.top()))&&(inf[i]=='^'))
				{
					s.push(inf[i]);
				}
				else
				{
					while((!s.empty())&&( assign(inf[i])<=assign(s.top())))
					{
						post+=s.top();
						s.pop();
					}
					s.push(inf[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		post+=s.top();
		s.pop();
	}
	
	return post;
}

int main() 
{  

  	string infix_exp, postfix_exp;
  	cout<<"Enter a Infix Expression:"<<endl;
  	cin>>infix_exp;
  	stack <char> stack;
	cout<<"Enter INFIX: "<<infix_exp<<endl;
  	postfix_exp = In_to_Post(stack, infix_exp);
  	cout<<endl<<"POSTFIX of the entered INFIX: "<<postfix_exp;
	  
	return 0;
}
