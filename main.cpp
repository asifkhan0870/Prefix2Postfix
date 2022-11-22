#include<bits/stdc++.h>
using namespace std;

#define max_size 100

class Stack{
     
   int tp;

   public: 

   vector<string>arr;

   Stack(){
     tp=-1;
     arr=vector<string>(max_size,"");
   }

   bool push(string s){
      
      if(tp>=max_size-1){
        cout<<"stack overflow"<<endl;
        return false;
      }
      else{
        arr[++tp]=s;
        return true;
      }
   }

   bool pop(){
      
      if(tp==-1){
        cout<<"stack underflow"<<endl;
         return "";
      }
      else{
         
         tp--;
         return true;
        
      }
   }

   string top(){
       
       if(tp<0){
            cout<<"stack underflow"<<endl;
            return "";
       }
       else{

        return arr[tp];

       }
   }


};

string PrefixToPostfix(string prefix){

    // stack<string>st;

    Stack st;
     

    for(int i=prefix.size()-1;i>=0;i--){

        if(prefix[i]=='*' or prefix[i]=='/' or prefix[i]=='+' or prefix[i]=='-'){

            // remove two operands

            string s1=st.top();
            st.pop();

            string s2=st.top();
            st.pop();

            string temp=s1+s2+prefix[i];
            
           
                st.push(temp);


        }
        else {

            string temp;
            temp+=prefix[i];
            st.push(temp);
        }
    }

    return st.top();
}

int main(){

   
   string str;
   cin>>str;

   cout<<PrefixToPostfix(str)<<endl;

    return 0;
}