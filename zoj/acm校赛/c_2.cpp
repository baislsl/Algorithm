#include<bits/stdc++.h>

using namespace std;

int count9[10000];

int monthc[][12] = { 
					{31,28,31,30,31,30,31,31,30,31,30,31},
				 	{31,29,31,30,31,30,31,31,30,31,30,31}
				  };

void init(){
	for(int i=0;i<10000;i++){
		int k = i;
		while(k!=0){
			if(k%10 == 9) count9[i]++;
			k /= 10;
		}
	}
}

bool isp(int y){
	return (y % 4 == 0 && y%100 != 0 ) || y %400 == 0;
}

int count99(int i){
	int res = 0;
	while(i !=0 ){
		if(i%9==0) res++;
		i /= 10;
	}
	return res;
}

int day(int &y, int &m, int &d){
	int res = count9[y] + count9[m] + count9[d];
	int leap = ((y)%4==0&&(y)%100)||(y)%400==0;
	if((d) + 1 > monthc[leap][(m)-1]) {
		(d) = 1;
		if((m)+1 > 12) {
			(m) = 1;
			(y) += 1;
		} else {
			(m) += 1;
		}
	} else {
		(d) += 1;
	}
	return res;
	
}

int month(int &y, int &m){
	int mul = count9[y] + count9[m], res = 0;
	int leap = ((y)%4==0&&(y)%100)||(y)%400==0;
	int datNum = monthc[leap][(m)-1];
	int day9 = 3;
	if(m==2 && !leap) day9 -= 1;
	m++;
	if(m == 13){
		m = 1;
		y++;
	}
	

	
	return mul*datNum + day9;
	
}


int year(int &y){
	int year = count9[y];
	
	int leap = ((y)%4==0&&(y)%100)||(y)%400==0;
	int m_d = leap + 3*11 + 2 + 30;
	y++;
	
	return year*(leap ? 366 : 365) + m_d;

}


int main(){
	int y1, m1, y2,m2, d1,d2;
	int repeat;
	init();
	scanf("%d", &repeat);
	while(repeat--){
		scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);
		
		int cnt = 0;
		cnt += count9[y2] + count9[m2] + count9[d2];
		
		while(d1 != 1){
			cnt += day(y1 , m1 , d1);
		};
		
		while(d2 != 1){
			cnt -= day(y2 , m2 , d2);
		};

		
		while(m1 != 1 ){
			cnt += month(y1, m1);
		};
		
		while(m2 != 1 ){
			cnt -= month(y2, m2);
		};
		
		
		while(y1 != y2){
			cnt += year(y1);
		};

		printf("%d\n", cnt);
		
	}
}




