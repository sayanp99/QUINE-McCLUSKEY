#include<bits/stdc++.h>
using namespace std;
//class that contains all the functions
class QM
{
public:

int VARIABLES;
string dontcares;

QM(int a)
{
   VARIABLES=a;
   dontcares.append(a,'-');
}

//converts decimal to binary
string decimalToBinary(int n)
{
   if ( n == 0 )
       return n+"";
   if ( n % 2 == 0 )
       return decimalToBinary(n / 2) + "0";
   else
       return decimalToBinary(n / 2) + "1";
}

//takes in variables and produces the corresponding alphabets
vector<string> getVars()
{
   vector<string> v;
   string letters[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
   for(int i=0;i<this->VARIABLES;i++)
    v.push_back(letters[i]);
   return v;
}

//converts into 4 bits
string fourbit(string bin)
{
   int max=VARIABLES-bin.length();
   for(int i=0; i<max; i++)
       bin="0"+bin;
   return bin;
}

//complements the changing bit


//checks whether the hamming distance is 1 or not
bool isGreyCode(string a,string b)
{
   int flag=0;
   for(int i=0;i<a.length();i++)
   {
       if(a[i]!=b[i])
        flag++;
   }
   return (flag==1);
}

//checks whether a string is present in a vector or not
bool stInVector(vector<string> a,string b)
{
   for(int i=0;i<a.size();i++)
     if(a[i].compare(b)==0)
      return true;
    return false;
}

//reduces the expression
vector<string> reduce(vector<string> minterms)
{
      vector<string> newminterms;

      int max=minterms.size();
      int* checked = new int[max];
      for(int i=0;i<max;i++)
      {
          for(int j=i;j<max;j++)
          {
               if(isGreyCode(minterms[i],minterms[j]))
               {
                  checked[i]=1;
                  checked[j]=1;
                  if(!stInVector(newminterms,complement(minterms[i],minterms[j])))
                     newminterms.push_back(complement(minterms[i],minterms[j]));
               }
          }
      }

      for(int i=0;i<max;i++)
      {
          if(checked[i]!=1 && ! stInVector(newminterms,minterms[i]))
           newminterms.push_back(minterms[i]);
      }

       delete[] checked;
   
       return newminterms;
}

//changes binary to alphabets
string binaryToAlphabet(string a)
{
   string temp="";
   vector<string> vars=this->getVars();
   if(a==dontcares)
     return "1";

   for(int i=0;i<a.length();i++)
   {
     if(a[i]!='-')
     {
        if(a[i]=='0')
         temp=temp+vars[i]+"\'";
        else
         temp=temp+vars[i];
     }
   }
   return temp;
}

//checks whether the vectors are equal or not
bool vectorsAreEqual(vector<string> a,vector<string> b)
{
   if(a.size()!=b.size())
      return false;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}

};


int main ()
{
   char check='y';
   while(check=='y')
   {
      int no,roll,nom;
      cout<<endl<<"Enter the number of variables:"<<endl;
      cin>>no;
      if(no > 26 || no < 1)
      {
          cout << "Invalid number of variables (1-26)" << endl;
          continue;
      }
      QM q(no);

	cout<<"\nEnter last two digit of  your roll number as an argument of srand() function: \n";
	cin>>roll;
	srand(roll);
	int power=pow(2,no);
	nom=rand()%power;
    vector<int> temp1;
	for(long long int i=0;i<nom;i++)
		temp1.push_back(rand()%power);
	sort(temp1.begin(), temp1.end());
   	vector<int>::iterator ip,it; 
	ip = unique(temp1.begin(), temp1.end()); 
    temp1.resize(distance(temp1.begin(), ip));
    cout<<"\nThe random minterms generated are :\n";
	for (it = temp1.begin(); it != temp1.end(); it++) 
        cout << *it << " ";
    
	cout<<endl<<endl;
	    
    string temp="";    
	for (int i=0; i<temp1.size(); i++)  
       {
		 temp += to_string(temp1[i]);
		 if(i!=temp1.size()-1)
    		temp += ",";
    	}
   	 
      vector<string> minterms;
      istringstream f(temp);
      string s;
      while (getline(f, s, ','))
      {
         int t=atoi(s.data());
         minterms.push_back(q.fourbit(q.decimalToBinary(t)));
      }

      sort(minterms.begin(),minterms.end());

      do
      {
         minterms=q.reduce(minterms);
         sort(minterms.begin(),minterms.end());
      }while(!q.vectorsAreEqual(minterms,q.reduce(minterms)));


      int i;
      cout << "The reduced boolean expression in SOP form:" << endl;
      for (i=0;i<minterms.size()-1; i++)
          cout <<q.binaryToAlphabet(minterms[i])<<"+";
      cout<<q.binaryToAlphabet(minterms[i])<<endl;
	
      cout<<"\nWould you like to enter another expression? (y/n)"<<endl;
      cin>>check;
   }
   cout<<endl<<"---END---"<<endl;
}
