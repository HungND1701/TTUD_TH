#include<iostream>
#include<map>
#include<queue>
using namespace std;

int soPhoneSai=0;
int number_total_calls=0;
map<string,int> number_calls_from;
map<string,int> time_calls;
queue<string>truy_van;
queue<string>phone_numbs;


bool checkPhone(string s){
	if(s.length() != 10) return false;
	for(int i = 0; i <s.length();i++){
		if(s[i]<'0'&&s[i]>'9') return false;
		 
	}
	return true;
}

int demthoigian(string from, string to){
	int start_time = 3600*((from[0]-'0')*10+(from[1]-'0')) + 60*((from[3]-'0')*10+(from[4]-'0'))+((from[6]-'0')*10+(from[7]-'0'));
	int end_time = 3600*((to[0]-'0')*10+(to[1]-'0')) + 60*((to[3]-'0')*10+(to[4]-'0'))+((to[6]-'0')*10+(to[7]-'0'));
	return end_time - start_time;
}
int main(){
	string word ; 
	do{	
		string phone1;
		string phone2;
		string date1;
		string hour1;
		string hour2;
		
		cin >> word;
		if(word == "#") continue;
		else{
			cin >> phone1 >> phone2>>date1>>hour1>>hour2;
			if(!(checkPhone(phone1)&&checkPhone(phone2))) soPhoneSai++;
			
			number_total_calls+=1;
			
			auto find = number_calls_from.find(phone1);
			
			if(find == number_calls_from.end()){
				number_calls_from.insert({phone1, 1});
				int time = demthoigian(hour1,hour2);
				time_calls.insert({phone1,time});
			}else{
				find->second = find->second +1;
				time_calls[phone1] += demthoigian(hour1,hour2);
			}
		}
	}while(word!="#");
	
	
	string hoi;
	string phone;
	do{
		cin >> hoi;
		if(hoi=="#") continue;
		else{
			
			truy_van.push(hoi);
			if(hoi == "?number_calls_from") {
				cin >> phone;
				phone_numbs.push(phone);
			}
			if(hoi == "?count_time_calls_from"){
				cin >> phone;
				phone_numbs.push(phone);
			}
		}
	}while(hoi!="#");
	
	while(!truy_van.empty()){
		string hoi = truy_van.front();
		truy_van.pop();
		string phone;
		if(hoi == "?check_phone_number" ) cout <<(soPhoneSai == 0 ? "1":"")<<endl;
		if(hoi == "?number_calls_from") {
			phone = phone_numbs.front();
			phone_numbs.pop();
			cout<< number_calls_from[phone] <<endl;
		}
		if(hoi == "?number_total_calls"){
			cout << number_total_calls <<endl;
		}
		if(hoi == "?count_time_calls_from"){
			phone = phone_numbs.front();
			phone_numbs.pop();
			cout << time_calls[phone] <<endl;
		}
	}
	return 0;
}