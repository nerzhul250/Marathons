#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;

bool parseExpression(string &s,int &index);
bool parseOperator(string &s,int &index);

bool parseOperator(string &s,int &index){
	if(index==s.size())return false;
	if(s[index]=='*' ||s[index]=='+' ||s[index]=='-' ||s[index]=='/' ||s[index]=='%'){
		index++;
		return parseExpression(s,index);	
	}else if(s[index]==')'){
		return false;
	}else{
		return true;
	}
}
bool parseExpression(string &s,int &index){
	if(s[index]=='('){
		index++;
		if(parseExpression(s,index))return true;
		if(s[index]!=')')return true;
		index++;
		return parseOperator(s,index);
	}else if(s[index]>='a' && s[index]<='z'){
		index++;
		return parseOperator(s,index);
	}else{
		return true;
	}
}

bool esOper(string &s, int index){
	return s[index]=='*' ||s[index]=='+' ||s[index]=='-' ||s[index]=='/' ||s[index]=='%';
}
bool esLet(string &s,int index){
	return s[index]>='a'&&s[index]<='z';
}
bool error(string &s){
	int index=0;
	//cout << s <<endl;
	//return parseExpression(s,index);
	int sum=0;
	fore(i,0,s.size()){
		if(s[i]=='('){
			sum++;
		}else if(s[i]==')'){
			sum--;
		}
		if(sum<0){
			return true;
		}
		if(s[i]=='('){
			if(i+1==s.size()||esOper(s,i+1) || s[i+1]==')'){
				return true;
			}
		}
		if(s[i]==')'){
			if(s[i+1]=='(' || esLet(s,i+1)){
				return true;
			}
		}
		if(esOper(s,i)){
			if(i+1==s.size() || s[i+1]==')' || esOper(s,i+1)){
				return true;
			}
		}
		if(esLet(s,i)){
			if(s[i+1]=='(' || esLet(s,i+1)){
				return true;
			}
		}
	}
	return sum!=0;
}

bool ambiguous(string &s){
	//cout << s << endl;
	vector<ii> parenPair;
	stack<int> parenStack;
	fore(i,0,s.size()){
		if(s[i]=='('){
			parenStack.push(i);
		}else if(s[i]==')'){
			parenPair.pb(ii(parenStack.top(),i));
			parenStack.pop();
		}
	}
	fore(i,0,parenPair.size()){
		int l=parenPair[i].ff;
		int r=parenPair[i].ss;
		int sum=0;
		int cnt=0;
		fore(j,l+1,r){
			//cout <<i<<" "<<j<<endl;
			if(s[j]=='('){
				sum++;
			}else if(s[j]==')'){
				sum--;
			}
			if(sum==0 && (s[j]=='*' ||s[j]=='+' ||s[j]=='-' ||s[j]=='/' ||s[j]=='%')){
				cnt++;
			}
		}
		if(cnt>=2){
			return true;
		}
	}
	return false;
}
int main(){FIN;
	string aux="";
	getline(cin,aux);
	string s="";
	fore(i,0,aux.size())if(aux[i]!=' ')s+=aux[i];
	if(error(s)){
		cout << "error\n";
	}else{
		string ipt="("+s+")";
		bool proper=!ambiguous(ipt);
		if(proper){
			vector<ii> parenPair;
			stack<int> parenStack;
			fore(i,0,s.size()){
				if(s[i]=='('){
					parenStack.push(i);
				}else if(s[i]==')'){
					parenPair.pb(ii(parenStack.top(),i));
					parenStack.pop();
				}
			}
			fore(i,0,parenPair.size()){
				int l=parenPair[i].ff;
				int r=parenPair[i].ss;
				string newStr=s;
				newStr[l]=' ';
				newStr[r]=' ';
				string toAdd="";
				fore(j,0,newStr.size()){
					if(newStr[j]!=' ')toAdd+=newStr[j];
				}
				toAdd="("+toAdd+")";
				if(!ambiguous(toAdd)){
					proper=false;
					break;
				}
			}
		}
		if(proper){
			cout <<"proper\n";
		}else{
			cout <<"improper\n";
		}
	}
    return 0;
}
