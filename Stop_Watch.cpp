#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include <iostream>
using namespace std;

class stopWatch{
	int Seconds;
	int Minutes;
	int Hours;
public:	
	stopWatch():Seconds(0),Minutes(0),Hours(0){}

	void IncrementTime(int,int,int);
	void printTime();

};
void stopWatch::IncrementTime(int hRange=0, int mRange=0, int sRange=0){
	while(true){
		for(int i=0; i<60; i++){
			Seconds++;
			if(Seconds>59){
				Minutes++;
				Seconds = 0;
				if(Minutes>59){
					Hours++;
					Minutes = 0;
				}
			}
			if(Hours==hRange&&Minutes==mRange&&Seconds==sRange){
					cout << "Time Up! ----------------------";
					printTime();
					//int c = getchar();	//using getchar() to achieve system("pause") in Linux
					system("pause");
					}else{
						system("cls");
						printTime();
						}
		}
	}
}	//End of IncrementTime();

void stopWatch::printTime(){
	cout << "\n \n \n \n ";
	
	cout << "\t \t \t";
	cout << "H" << " : ";
	cout << "M" << " : ";
	cout << "S\n" ;
	cout << "\t \t \t";
	cout << Hours << " : ";
	cout << Minutes << " : ";
	cout << Seconds ;
	cout << "\n \n \n \n ";;
			
	sleep(1);
}	//End of printTime();


int main(){
	stopWatch time;
	// passed parameters (hours, minutes,seconds,mSecond)
	time.IncrementTime(0,0,15);	
	
	return 0;
}
