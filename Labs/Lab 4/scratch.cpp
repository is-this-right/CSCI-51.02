bool get_bit(int num, int position)
{
	bool bit = num & (1 << position);
	return bit;
}
#include <iostream>
using namespace std;

int countBits( int number) 
{     
    
    // log function in base 2 
    // take only integer part 
    return (int)log2(number)+1; 
} 

int int_size(int num){
    return sizeof(num) * CHAR_BIT;
}


int main(void){
    bool q0;
    bool qn = 0;
    int accumulator = 0;
    int counter = 0;
    int multiplicand = 5;
    int multiplicand_inv = -multiplicand;
    int multiplier = 2;
    while (counter != 32){
        q0 = get_bit(multiplier, 0);
        if (!(q0 xor qn)){
            multiplier >>= 1;
        } else {
            if (q0 == 0){
                accumulator += multiplicand;
            } else {
                accumulator += multiplicand_inv;
            }
            multiplier >>= 1;
            accumulator >>= 1;
        }
        counter += 1;
    }
    cout << accumulator;
}