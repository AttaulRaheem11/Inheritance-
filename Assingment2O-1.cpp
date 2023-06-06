#include<iostream>
using namespace std;

class Time{
	private:
		int hour;
		int min;
		int sec;
		char mode;
		
		public:
		
		Time() : hour(0),min(0),sec(0),mode('0'){
		
			cout<<"Hello from Default Constructor"<<endl;	
			
		}	
		
		Time(int h,int m,int s,char mod){
			hour = h;
			min = m;
			sec = s;
			mode = mod;
		
			if (h < 1 && h > 12){
			
				cout<<"enter in range 1-12: "<<h<<endl;
		}
			if(m < 0 && m > 50){
			
				cout<<"enter in range 0-59: "<<m<<endl;
		}
			if(s < 0 && s > 59){
			
				cout<<"enter in range 0-59: "<<s<<endl;
		}
			if(mod != 'A' && mod != 'P'){
			
				cout<<"entere valid mode: "<<mod<<endl;
		}
			else{
				
			cout<<"Hello from Perameterized Constructor"<<endl;
			cout<<hour<<":"<<min<<":"<<sec<<"-"<<mode<<endl;
		}
}
	
		
		Time(int h1,int m1,int s1){
				
				hour = h1;
				min = m1;
				sec = s1;
	 
				
			if (h1 < 1 && h1 > 12){
			
				cout<<"enter in range 1-12: "<<h1<<endl;
		}
			if(m1 < 0 && m1 > 50){
			
				cout<<"enter in range 0-59: "<<m1<<endl;
		}
			if(s1 < 0 && s1 > 59){
			
				cout<<"enter in range 0-59: "<<s1<<endl;
		}
			else{
				
				cout<<"Hello from Perameterized Constructor"<<endl;	
				cout<<hour<<":"<<min<<":"<<sec<<endl;
		}
	}
	
		Time(const Time& obj){
			hour = obj.hour;
			min  = obj.min;
			sec  = obj.sec;
	
		cout<<"Hello from Copy Constructor"<<endl;
			cout<<hour<<":"<<min<<":"<<sec<<endl;
		}
		
		void set_Hour(int h2){
			hour = h2;
		}
			
		int get_Hour(){
			return hour;
		}
		
		void set_Minutes(int m2){
			min = m2;
		}
		
		int get_Minutes(){
			return min;
		}
		
		void set_Seconds(int s2){
			sec = s2;
		}
		
		int get_Seconds(){
			return sec;
		}
		
		void set_Mode(char mod1){
			mode = mod1;
		}
		
		int get_Mode(){
			return mode;
		}
		void display_Time(){
			cout<<"The Time is: "<<hour<<":"<<min<<":"<<sec<<"-"<<mode<<endl;
		}
		
		int convert_to_Seconds(int hour,int min,int sec){
			int total_sec = (hour * 3600) + (min * 60) + sec;
			cout<<total_sec<<endl;
			
		}
		
		float convert_to_Minutes(int hour,int min,int sec){
			float total_min = (hour * 60) + min + (sec / 60.0);
			cout<<total_min<<endl;
		}
		
		float convert_to_hours(int hour,int min,int sec){
			float total_hour = hour + (min / 60.0) + (sec / 3600.0);
			cout<<total_hour<<endl;
		}
		
		int convert_to_24Hours(){
			
			int formate_24hour;
			cout<<"Time in 24 hours Formate"<<endl;
			cin>>formate_24hour;
			int formate_12hour = 12;
		
			if(formate_24hour <= formate_12hour){
				
					for (int i=1; i<=formate_24hour;i++){
						formate_12hour++;
				}
				 	return formate_12hour;
			}
			else{
				cout<<"Value( "<<formate_24hour<<" )is not in range"<<endl;
			}
		}
		
		void incrementseconds(int seconds){
			sec += seconds;
			if (sec >= 60){
				sec -=60;
				min++;
			}
			if (min >= 60){
				min -= 60;
				hour++;
			}
			if (hour > 12){
				hour -= 12;
				if (mode == 'A')
				mode = 'P';
				else mode ='A';
				
			}
			cout<<"New Time with Seconds: "<<hour<<":"<<min<<":"<<sec<<"-"<<mode<<endl;
		}
		
		void incrementminutes(int minuts){
				min += minuts;
				if (min >= 60){
				min -= 60;
				hour++;
			}
			if (hour > 12){
				hour -= 12;
				if (mode == 'A')
				mode = 'P';
				else mode ='A';
				
			}
			cout<<"New Time with Minuts: "<<hour<<":"<<min<<":"<<sec<<"-"<<mode<<endl;
			
		}
};

int main()
{
	Time t1(11,34,33,'D'),t2(3,45,55),t3(t2);
	t1.set_Hour(12);
	cout<<t1.get_Hour();
	t1.set_Minutes(59);
	cout<<t1.get_Minutes();
	t1.set_Seconds(30);
	cout<<t1.get_Seconds();
	t1.set_Mode('A');
	cout<<t1.get_Mode();
	t1.display_Time();
	t1.incrementseconds(31);
	t1.incrementminutes(12);
	t2.convert_to_Seconds(3,34,54);
	t2.convert_to_Minutes(3,34,54);
	t2.convert_to_hours(3,34,54);
	cout<<t2.convert_to_24Hours();
}

