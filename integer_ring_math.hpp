#ifndef IRM_PJ
#define IRM_PJ

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//inverse of a in integer ring of m

int inverse_in_ring(int a, int m){
	a = a % m; 
    for (int x=1; x<m; x++){
    	if ((a*x) % m == 1){
    		return x;
    	}
    }
}

int find_order(int a, int m){
	int x = a;
	int b = m - 1;
	for(int i = 1; i < b; i++){
		if(x == 1){
			return i;
		}
		x = (x * a) % m;
	}
}

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

vector<int> create_integer_ring_coprime(int m){
	vector<int> result;
	for(int i = 0; i < m; i++){
		if(gcd(i, m) == 1){
			result.push_back(i);
		}
	}
	return result;
}
int cardinality(vector<int> ring){
	return ring.size();
}

vector<int> find_generators(vector<int> ring, int m){
	vector<int> result;
	int order = cardinality(ring);
	for(int a : ring){
		if(find_order(a, m) == order){
			result.push_back(a);
		}
	}
	return result;
}

class Integer_Ring{
private:
	int base;
	vector<int> ring;

public:
	Integer_Ring(){}
	Integer_Ring(int m){
		base = m;
		ring = create_integer_ring_coprime(base);
	}

	vector<int> get_ring(){
		return ring;
	}

	int get_base(){
		return base;
	}
};

#endif
