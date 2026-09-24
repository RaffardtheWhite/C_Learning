#include <stdio.h>
int transistor_type1(int, int);
int transistor_type2(int);
int Not(int);
int AndGate(int, int);
int OrGate(int, int);
int XOrGate(int, int);
//int HalfAdder(int, int, int, int);
int FullAdder(int, int, int, int*, int*);



int num1=0, num2=0, carry=0, result = 0;
int num_1=0,num_2=0, cnt=0, temp=0, checker=2, is_illegal=0;
int A[8]={0}, B[8]={0}, S[8]={0};
int main(void)
{

	
	printf("please type in the first 8_bit binary number:");
    scanf("%d", &num1);
    num_1 = num1 ;
    /*check*/
	if (num1 < 0){
    	printf("this is an Adder!\n");
    	goto out;
	} else if (num1 > 0){
		int checker = num1;
		
		while (num_1) { 
			cnt++; num_1 /= 10; 
		} 
		if (cnt > 8){
			is_illegal = 1;
		}
		while (checker > 0){
			int digit = checker % 10;
			if (digit != 0 && digit != 1){
				is_illegal = 1;
				break;
			}
			checker /= 10;
		}
	}
	if (is_illegal == 1){
		printf("this is a illegal number!\n");
		goto out;
	}
	
	printf("please type in the second 8_bit binary number:");
    scanf("%d", &num2);
    num_2 = num2;
    /*check*/
	if (num2 < 0){
    	printf("this is an Adder!\n");
    	goto out;
	} else if (num2 > 0){
		int checker = num2;
		cnt = 0; 
		while (num_2) { 
			cnt++; num_2 /= 10; 
		} 
		if (cnt > 8){
			is_illegal = 1;
		}
		while (checker > 0){
			int digit = checker % 10;
			if (digit != 0 && digit != 1){
				is_illegal = 1;
				break;
			}
			checker /= 10;
		}
	}
	if (is_illegal == 1){
		printf("this is a illegal number!\n");
		goto out;
	}
    
    
    temp = num1;
    for (int i = 0; i < 8; i++) {
        A[i] = temp % 10;  
        temp /= 10;         
    }
    for (int i = 0; i < 4; i++) {
        int tmp = A[i];
        A[i] = A[7 - i];
        A[7 - i] = tmp;
  	}
    
    temp = num2;
    for (int i = 0; i < 8; i++) {
        B[i] = temp % 10;  
        temp /= 10;         
    }
    for (int i = 0; i < 4; i++) {
        int tmp = B[i];
        B[i] = B[7 - i];
        B[7 - i] = tmp;
	}
    
    for (int i = 0; i < 8; i++) {
        FullAdder(A[i], B[i], carry, &S[i], &carry);
	}
	
	
    printf("result = %d", carry);
    for (int i = 7; i >= 0; i--) {
        printf("%d", S[i]);
    }
out:
    return 0;
}





/*NPN*/
	/*type1*/ 
int transistor_type1(int x, int y) 
{
	return x*y;
}
	/*type2*/ 
int transistor_type2(int z)
{
	return z;
}


/*Not*/
int Not(int a)
{
	return !a;
}


/*AndGate*/
int AndGate(int AndGate1Base, int AndGate2Base)
{
	int AndGate2Collecter = transistor_type2(AndGate1Base);
	int AndGate2Emitter = transistor_type1(AndGate2Collecter, AndGate2Base);
	return AndGate2Emitter;
}


/*OrGate*/
int OrGate(int OrGate1Base, int OrGate2Base)
{
	int OrGate1Emitter = transistor_type2(OrGate1Base);
	int OrGate2Emitter = transistor_type2(OrGate2Base);
	int not_a = Not(OrGate1Emitter);
	int not_b = Not(OrGate2Emitter);
	int and_out = AndGate(not_a, not_b);
	return Not(and_out);
}


/*XOrGate*/
int XOrGate(int XOrGateInput1, int XOrGateInput2)
{
	int AndGate1Collecter = XOrGateInput1;
	int AndGate1Base = Not(XOrGateInput2);
	int AndGate2Collecter = XOrGateInput2;
	int AndGate2Base = Not(XOrGateInput1);
	int AndGate1Emitter = AndGate(AndGate1Collecter, AndGate1Base);
	int AndGate2Emitter = AndGate(AndGate2Collecter, AndGate2Base);
	int OrGateEmitter = OrGate(AndGate1Emitter, AndGate2Emitter);
	return OrGateEmitter;
}


/*Half Adder*/
//int HalfAdder(int HalfAdderInput1, int HalfAdderInput2, int *HalfAdderSum, int *HalfAdderCarry)
//{
//	*HalfAdderSum = XOrGate(HalfAdderInput1, HalfAdderInput2);
//	*HalfAdderCarry = AndGate(HalfAdderInput1, HalfAdderInput2);
//	return 0;
//}


/*Full Adder*/
int FullAdder(int FullAdderInput1, int FullAdderInput2, int FullAdderCarryInput, int *FullAdderSum, int *FullAdderCarry)
{
	int XOrGate1Input1 = FullAdderInput2;
	int XOrGate1Input2 = FullAdderInput1;
	int XOrGate2Input1 = FullAdderCarryInput;
	int XOrGate2Input2 = XOrGate(XOrGate1Input1, XOrGate1Input2);
	
	int AndGate1Input1 = FullAdderCarryInput;
	int AndGate1Input2 = XOrGate(XOrGate1Input1, XOrGate1Input2);
	int OrGateInput1 = AndGate(AndGate1Input1, AndGate1Input2);
	int AndGate2Input1 = FullAdderInput2;
	int AndGate2Input2 = FullAdderInput1;
	int OrGateInput2 = AndGate(AndGate2Input1, AndGate2Input2);
	
		
	*FullAdderSum = XOrGate(XOrGate2Input1, XOrGate2Input2);
	*FullAdderCarry = OrGate(OrGateInput1, OrGateInput2);
	return 0;
}

