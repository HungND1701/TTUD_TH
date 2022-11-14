#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct date{
	string year;
	string month;
	string day;
};

struct hour{
	string hh;
	string mm;
	string ss;
};
int soPhoneSai = 0;
int number_total_calls = 0;
vector<string>from_number;
vector<string>to_number;
vector<string>date_phone;
vector<string>from_time;
vector<string>to_time;
queue<string>truy_van;
queue<string>phone_numbs;
bool checkPhone(string s){
	if(s.length() != 10) return false;
	for(int i = 0; i <s.length();i++){
		if(s[i]<'0'&&s[i]>'9') return false;
		 
	}
	return true;
}
int demthoigian(int i){
	int start_time = 3600*((from_time.at(i)[0]-'0')*10+(from_time.at(i)[1]-'0')) + 60*((from_time.at(i)[3]-'0')*10+(from_time.at(i)[4]-'0'))+((from_time.at(i)[6]-'0')*10+(from_time.at(i)[7]-'0'));
	int end_time = 3600*((to_time.at(i)[0]-'0')*10+(to_time.at(i)[1]-'0')) + 60*((to_time.at(i)[3]-'0')*10+(to_time.at(i)[4]-'0'))+((to_time.at(i)[6]-'0')*10+(to_time.at(i)[7]-'0'));
	return end_time - start_time;
}
void timeCall(string phone){
	int giay = 0;
	for(int i = 0 ; i< from_number.size();i++){
		if(from_number.at(i)==phone) giay+=demthoigian(i);
	}
	cout << giay <<endl;
}
bool pushList(){
	string word;
	cin >> word;
	string phone1;
	string phone2;
	string date1;
	string hour1;
	string hour2;
	
	if(word=="#") return false;
	else {
		cin >> phone1 >> phone2 >>date1 >> hour1 >> hour2;
		from_number.push_back(phone1);
		
		to_number.push_back(phone2);
		
		date_phone.push_back(date1);
		
		from_time.push_back(hour1);
		
		to_time.push_back(hour2);
		if(checkPhone(phone1)||checkPhone(phone2)) soPhoneSai++;
		number_total_calls++;
	}
	return true;
}
void number_calls_from(string phone){
	int number_calls = 0;
	for(int i = 0 ; i< from_number.size();i++){
		if(from_number.at(i)==phone) number_calls++;
	}
	cout << number_calls << endl;
}

void getData(){
	bool test = true;
	
	while(test!=false){
		test = pushList();
	} 
}
void docTruyVan(){
	string hoi;
	string phone;
	do{
		cin >> hoi;
		if(hoi=="#") continue;
		else{
			
			truy_van.push(hoi);
//			if(hoi == "?check_phone_number" ) cout << (soPhoneSai != 0 ? "1":"")<<endl;
			if(hoi == "?number_calls_from") {
				cin >> phone;
				phone_numbs.push(phone);
			}
//			if(hoi == "?number_total_calls"){
//				cout << number_total_calls <<endl;
//			}
			if(hoi == "?count_time_calls_from"){
				cin >> phone;
				phone_numbs.push(phone);
			}
		}
	}while(hoi!="#");
}
void output(){
	while(!truy_van.empty()){
		string hoi = truy_van.front();
		truy_van.pop();
		string phone;
		if(hoi == "?check_phone_number" ) cout <<(soPhoneSai != 0 ? "1":"")<<endl;
		if(hoi == "?number_calls_from") {
			phone = phone_numbs.front();
			phone_numbs.pop();
			number_calls_from(phone);
		}
		if(hoi == "?number_total_calls"){
			cout << number_total_calls <<endl;
		}
		if(hoi == "?count_time_calls_from"){
			phone = phone_numbs.front();
			phone_numbs.pop();
			timeCall(phone);
		}
	}
}
int main(){
	getData();
	docTruyVan();
	output();
	return 0;
}