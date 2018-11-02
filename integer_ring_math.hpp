#ifndef IRM_PJ
#define IRM_PJ

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//inverse of a in integer ring of m
int gcd(int a, int b){
	// Everything divides 0  
    if (a == 0){
    	return b; 
    }
    if (b == 0){
    	return a; 
    }

    // base case 
    if (a == b){
    	return a; 
    }
   
    // a is greater 
    if (a > b){
        return gcd(a-b, b); 
    }
    return gcd(a, b-a); 
}

int phi(int m){
	int result = 1; 
    for (int i = 2; i < m; i++){
        if (gcd(i, m) == 1){
            result++; 
        }
    }
    return result; 
}

void ab_mod_c(int a, int b, int c){
	int x = a;
	for(int i = 1; i < b; i++){
		x = (x * a) % c;
		cout << i << " - " << x << endl;
	}
	cout << "Answer = " << x << endl;
}

void calc(int d){
	int x = 0;
	for(int i = 0; i <= d; i++){
		x = ((3643 * i) + 2212) % 9811;
		if(x == 0){
			cout << "The answer is: " << i << endl;
		}
	}
}

class Integer_Ring{
private:
	int base;
	vector<int> ring;

public:
	Integer_Ring(){}

	Integer_Ring(int m){
		base = m;
		ring = create_integer_ring_coprime();
	}

	vector<int> get_ring(){
		return ring;
	}

	int get_base(){
		return base;
	}

	vector<int> find_generators(){
		vector<int> result;
		int order = cardinality();
		for(int a : ring){
			if(find_order(a) == order){
				result.push_back(a);
			}
		}
		return result;
	}

	int cardinality(){
		return ring.size();
	}

	vector<int> create_integer_ring_coprime(){
		vector<int> result;
		for(int i = 0; i < base; i++){
			if(gcd(i, base) == 1){
				result.push_back(i);
			}
		}
		return result;
	}

	int find_order(int a){
		int x = a;
		int b = base - 1;
		for(int i = 1; i < b; i++){
			if(x == 1){
				return i;
			}
			x = (x * a) % base;
		}
	}

	int inverse_in_ring(int a){
		a = a % base; 
    	for (int x = 1; x < base; x++){
    		if ((a * x) % base == 1){
    			return x;
    		}
   		}
	}

};

#endif
