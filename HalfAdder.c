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

/*输入限制*/
int binary_input(const char* prompt) {
    int val;
    do {
        printf("%s (请输入 0 或 1): ", prompt);
        scanf("%d", &val);
        
        // 如果输入的不是 0 或 1，提示错误并重新循环
        if (val != 0 && val != 1) {
            printf("  输入无效！只能输入 0 或 1，请重新输入。\n");
        }
    } while (val != 0 && val != 1);
    
    return val;
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




/*调试代码*/
int main(void)
{
    int HalfAdderInput1 = binary_input("HalfAdderInput1");
    int HalfAdderInput2 = binary_input("HalfAdderInput2");
    
    printf("HalfAdderSum: %d\n", HalfAdderSum(HalfAdderInput1, HalfAdderInput2));
    printf("HalfAdderCarry: %d\n", HalfAdderCarry(HalfAdderInput1, HalfAdderInput2));
    return 0;
}
