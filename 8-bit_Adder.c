#include <stdio.h>


/*定义两种NPN三极管*/
	/*collecter待定*/ 
int transistor_type1(int x, int y) 
{
	return x*y;
}
	/*collecter默认为1,即SimpleGate*/
int transistor_type2(int z)
{
	return z;
}


/*定义Not*/
int Not(int a)
{
	return !a;
}

/*定义AndGate*/
int AndGate(int AndGate1Base, int AndGate2Base)
{
	int AndGate2Collecter = transistor_type2(AndGate1Base);
	int AndGate2Emitter = transistor_type1(AndGate2Collecter, AndGate2Base);
	return AndGate2Emitter;
}

/*定义OrGate*/
int OrGate(int OrGate1Base, int OrGate2Base)
{
	int OrGate1Emitter = transistor_type2(OrGate1Base);
	int OrGate2Emitter = transistor_type2(OrGate2Base);
	int not_a = Not(OrGate1Emitter);
	int not_b = Not(OrGate2Emitter);
	int and_out = AndGate(not_a, not_b);
	return Not(and_out);
}

/*定义XOrGate*/
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


/*定义Half Adder*/
int HalfAdderSum(int HalfAdderInput1, int HalfAdderInput2)
{
	int HalfAdderSum = XOrGate(HalfAdderInput1, HalfAdderInput2);
	return HalfAdderSum;
}

int HalfAdderCarry(int HalfAdderInput1, int HalfAdderInput2)
{
	int HalfAdderCarry = AndGate(HalfAdderInput1, HalfAdderInput2);
	return HalfAdderCarry;
}

/*定义Full Adder*/
int FullAdderSum(int FullAdderInput1, int FullAdderInput2, int FullAdderCarryInput)
{
	int XOrGate1Input1 = FullAdderInput2;
	int XOrGate1Input2 = FullAdderInput1;
	int XOrGate2Input1 = FullAdderCarryInput;
	int XOrGate2Input2 = XOrGate(XOrGate1Input1, XOrGate1Input2);
	int FullAdderSum = XOrGate(XOrGate2Input1, XOrGate2Input2);
	return FullAdderSum;
}
int FullAdderCarry(int FullAdderInput1, int FullAdderInput2, int FullAdderCarryInput)
{
	int AndGate1Input1 = FullAdderCarryInput;
	int XOrGate1Input1 = FullAdderInput2;
	int XOrGate1Input2 = FullAdderInput1;
	int AndGate1Input2 = XOrGate(XOrGate1Input1, XOrGate1Input2);
	int OrGateInput1 = AndGate(AndGate1Input1, AndGate1Input2);
	int AndGate2Input1 = FullAdderInput2;
	int AndGate2Input2 = FullAdderInput1;
	int OrGateInput2 = AndGate(AndGate2Input1, AndGate2Input2);
	int FullAdderCarry = OrGate(OrGateInput1, OrGateInput2);
	return FullAdderCarry;
}

/*定义8-bit Adder*/
int eight_bit_AdderOutput1(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder6CarryInput = FullAdderCarry(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int FullAdder5CarryInput = FullAdderCarry(FullAdder6Input1, FullAdder6Input2, FullAdder6CarryInput);
	int FullAdder4CarryInput = FullAdderCarry(FullAdder5Input1, FullAdder5Input2, FullAdder5CarryInput);
	int FullAdder3CarryInput = FullAdderCarry(FullAdder4Input1, FullAdder4Input2, FullAdder4CarryInput);
	int FullAdder2CarryInput = FullAdderCarry(FullAdder3Input1, FullAdder3Input2, FullAdder3CarryInput);
	int FullAdder1CarryInput = FullAdderCarry(FullAdder2Input1, FullAdder2Input2, FullAdder2CarryInput);
	int FullAdder1Carry = FullAdderCarry(FullAdder1Input1, FullAdder1Input2, FullAdder1CarryInput);
	int eight_bit_AdderOutput1 = FullAdder1Carry;
	return eight_bit_AdderOutput1;
}
int eight_bit_AdderOutput2(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder6CarryInput = FullAdderCarry(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int FullAdder5CarryInput = FullAdderCarry(FullAdder6Input1, FullAdder6Input2, FullAdder6CarryInput);
	int FullAdder4CarryInput = FullAdderCarry(FullAdder5Input1, FullAdder5Input2, FullAdder5CarryInput);
	int FullAdder3CarryInput = FullAdderCarry(FullAdder4Input1, FullAdder4Input2, FullAdder4CarryInput);
	int FullAdder2CarryInput = FullAdderCarry(FullAdder3Input1, FullAdder3Input2, FullAdder3CarryInput);
	int FullAdder1CarryInput = FullAdderCarry(FullAdder2Input1, FullAdder2Input2, FullAdder2CarryInput);
	int FullAdder1Sum = FullAdderSum(FullAdder1Input1, FullAdder1Input2, FullAdder1CarryInput);
	int eight_bit_AdderOutput2 = FullAdder1Sum;
	return eight_bit_AdderOutput2;
}
int eight_bit_AdderOutput3(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder6CarryInput = FullAdderCarry(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int FullAdder5CarryInput = FullAdderCarry(FullAdder6Input1, FullAdder6Input2, FullAdder6CarryInput);
	int FullAdder4CarryInput = FullAdderCarry(FullAdder5Input1, FullAdder5Input2, FullAdder5CarryInput);
	int FullAdder3CarryInput = FullAdderCarry(FullAdder4Input1, FullAdder4Input2, FullAdder4CarryInput);
	int FullAdder2CarryInput = FullAdderCarry(FullAdder3Input1, FullAdder3Input2, FullAdder3CarryInput);
	int FullAdder2Sum = FullAdderSum(FullAdder2Input1, FullAdder2Input2, FullAdder2CarryInput);
	int eight_bit_AdderOutput3 = FullAdder2Sum;
	return eight_bit_AdderOutput3;
}
int eight_bit_AdderOutput4(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder6CarryInput = FullAdderCarry(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int FullAdder5CarryInput = FullAdderCarry(FullAdder6Input1, FullAdder6Input2, FullAdder6CarryInput);
	int FullAdder4CarryInput = FullAdderCarry(FullAdder5Input1, FullAdder5Input2, FullAdder5CarryInput);
	int FullAdder3CarryInput = FullAdderCarry(FullAdder4Input1, FullAdder4Input2, FullAdder4CarryInput);
	int FullAdder3Sum = FullAdderSum(FullAdder3Input1, FullAdder3Input2, FullAdder3CarryInput);
	int eight_bit_AdderOutput4 = FullAdder3Sum;
	return eight_bit_AdderOutput4;
}
int eight_bit_AdderOutput5(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder6CarryInput = FullAdderCarry(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int FullAdder5CarryInput = FullAdderCarry(FullAdder6Input1, FullAdder6Input2, FullAdder6CarryInput);
	int FullAdder4CarryInput = FullAdderCarry(FullAdder5Input1, FullAdder5Input2, FullAdder5CarryInput);
	int FullAdder4Sum = FullAdderSum(FullAdder4Input1, FullAdder4Input2, FullAdder4CarryInput);
	int eight_bit_AdderOutput5 = FullAdder4Sum;
	return eight_bit_AdderOutput5;
}
int eight_bit_AdderOutput6(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder6CarryInput = FullAdderCarry(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int FullAdder5CarryInput = FullAdderCarry(FullAdder6Input1, FullAdder6Input2, FullAdder6CarryInput);
	int FullAdder5Sum = FullAdderSum(FullAdder5Input1, FullAdder5Input2, FullAdder5CarryInput);
	int eight_bit_AdderOutput6 = FullAdder5Sum;
	return eight_bit_AdderOutput6;
}
int eight_bit_AdderOutput7(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder6CarryInput = FullAdderCarry(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int FullAdder6Sum = FullAdderSum(FullAdder6Input1, FullAdder6Input2, FullAdder6CarryInput);
	int eight_bit_AdderOutput7 = FullAdder6Sum;
	return eight_bit_AdderOutput7;
}
int eight_bit_AdderOutput8(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder7CarryInput = HalfAdderCarry(FullAdder8Input1, FullAdder8Input2);
	int FullAdder7Sum = FullAdderSum(FullAdder7Input1, FullAdder7Input2, FullAdder7CarryInput);
	int eight_bit_AdderOutput8 = FullAdder7Sum;
	return eight_bit_AdderOutput8;
}
int eight_bit_AdderOutput9(int FullAdder1Input1, int FullAdder2Input1, int FullAdder3Input1, int FullAdder4Input1, int FullAdder5Input1, int FullAdder6Input1, int FullAdder7Input1, int FullAdder8Input1, int FullAdder1Input2, int FullAdder2Input2, int FullAdder3Input2, int FullAdder4Input2, int FullAdder5Input2, int FullAdder6Input2, int FullAdder7Input2, int FullAdder8Input2)
{
	int FullAdder8Sum = HalfAdderSum(FullAdder8Input1, FullAdder8Input2);
	int eight_bit_AdderOutput9 = FullAdder8Sum;
	return eight_bit_AdderOutput9;
}




/*调试代码*/
int num1, num2, result;
int main(void)
{
    printf("输入第一个8bit数:");
    scanf("%d", &num1);
    int FullAdder8Input1 = num1%10;
    num1 /= 10;
    int FullAdder7Input1 = num1%10;
    num1 /= 10;
    int FullAdder6Input1 = num1%10;
    num1 /= 10;
    int FullAdder5Input1 = num1%10;
    num1 /= 10;
    int FullAdder4Input1 = num1%10;
    num1 /= 10;
    int FullAdder3Input1 = num1%10;
    num1 /= 10;
    int FullAdder2Input1 = num1%10;
    num1 /= 10;
    int FullAdder1Input1 = num1;
    
    printf("输入第二个8bit数:");
    scanf("%d", &num2);
    int FullAdder8Input2 = num2%10;
    num2 /= 10;
    int FullAdder7Input2 = num2%10;
    num2 /= 10;
    int FullAdder6Input2 = num2%10;
    num2 /= 10;
    int FullAdder5Input2 = num2%10;
    num2 /= 10;
    int FullAdder4Input2 = num2%10;
    num2 /= 10;
    int FullAdder3Input2 = num2%10;
    num2 /= 10;
    int FullAdder2Input2 = num2%10;
    num2 /= 10;
    int FullAdder1Input2 = num2;
    
    
	result = eight_bit_AdderOutput9(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2) + eight_bit_AdderOutput8(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*10 + eight_bit_AdderOutput7(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*100 + eight_bit_AdderOutput6(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*1000 + eight_bit_AdderOutput5(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*10000 + eight_bit_AdderOutput4(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*100000 + eight_bit_AdderOutput3(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*1000000 + eight_bit_AdderOutput2(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*10000000 + eight_bit_AdderOutput1(FullAdder1Input1, FullAdder2Input1, FullAdder3Input1, FullAdder4Input1, FullAdder5Input1, FullAdder6Input1, FullAdder7Input1, FullAdder8Input1, FullAdder1Input2, FullAdder2Input2, FullAdder3Input2, FullAdder4Input2, FullAdder5Input2, FullAdder6Input2, FullAdder7Input2, FullAdder8Input2)*100000000;
    printf("result=%d", result);
    return 0;
}
