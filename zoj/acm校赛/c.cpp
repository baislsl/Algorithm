#include <bits/stdc++.h>
using namespace std;

int month[][12] = { 
					{31,28,31,30,31,30,31,31,30,31,30,31},
				 	{31,29,31,30,31,30,31,31,30,31,30,31}
				  };

int count9(int yy, int mm, int dd) {
	int cnt = 0;
	while(yy!=0) {
		if(yy%10 == 9)
			cnt ++;
		yy /= 10;
	}
	while(mm!=0) {
		if(mm%10 == 9)
			cnt ++;
		mm /= 10;
	}
	while(dd!=0) {
		if(dd%10 == 9)
			cnt ++;
		dd /= 10;
	}
	return cnt;
}
	
void nextday(int *yy, int *mm, int *dd) {
	int leap = ((*yy)%4==0&&(*yy)%100)||(*yy)%400==0;
	if((*dd) + 1 > month[leap][(*mm)-1]) {
		(*dd) = 1;
		if((*mm)+1 > 12) {
			(*mm) = 1;
			(*yy) += 1;
		} else {
			(*mm) += 1;
		}
	} else {
		(*dd) += 1;
	}
}
	  
int main() {
	
	int repeat;
	int yy,mm,dd;
	int y1,m1,d1;
	int y2,m2,d2;
	int count;
	scanf("%d", &repeat);
	while(repeat--) {
		count = 0;
		scanf("%d %d %d", &y1, &m1, &d1);
		scanf("%d %d %d", &y2, &m2, &d2);
		yy = y1; mm = m1; dd = d1;
		do{
			count += count9(yy, mm, dd);
			nextday(&yy, &mm, &dd);
		}while(yy!=y2&&mm!=m2&&dd!=d2);
		printf("%d\n", count);
	}	
	return 0;
}
