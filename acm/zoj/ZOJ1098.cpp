#include <stdio.h>
#include <string.h>

/*计算机的32bytes内存*/
unsigned char memory[32];
/*pc: program counter, 程序计数器，即程序运行时的地址指针 */
unsigned char pc;
/*accu: accumulator, 即累加器*/
unsigned char accu;

/*每次读取的一行（byte）*/
char line[9];

/*解析读入的一行字节的值*/
unsigned char ParseFromLine(char* s)
{
    unsigned char result = 0;
    int base = 128;
    while(*s)
    {
        result += (*s-'0')*base;
        base = (base>>1);
        s++;
    }
    return result;
}

/*把值解析成二进制表达的字符串，准备打印*/
void ParseToLine(unsigned char number, char* buf)
{
    int i=7;
    memset(buf, '0', 8);
    buf[8]=0;/* NULL terminated */
    while(number)
    {
        buf[i--] = (number % 2 ) + '0';
        number = (number>>1);
    }
}

/*运行，返回累加器的值*/
unsigned char Run()
{
    /*分别是当前指令，指令码（高三位），地址（低五位）*/
    unsigned char instruction, code, addr;
    /*初始化*/
    pc=0;
    accu=0;    
    
    /*运行循环*/
    while(1)
    {
        /*取指*/
        instruction = memory[pc++];
        /*一旦pc越过内存界限，就回退到0。没有这个语句会WA，这个语句导致AC！*/
        if(pc>=32) pc=0;
        code = (instruction >> 5);
        addr = (instruction & 0x1f);
        
        switch(code)
        {
            /* 000xxxxx   STA x   store the value of the accu into memory byte x */
            case 0:
                memory[addr] = accu;
                break;
            /* 001xxxxx   LDA x   load the value of memory byte x into the accu */
            case 1:
                accu = memory[addr];
                break;
            /* 010xxxxx   BEQ x   if the value of the accu is 0 load the value x into the pc */
            case 2:
                if(accu == 0) pc=addr;
                break;
            /* 011-----   NOP     no operation */
            case 3:
                break;
            /* 100-----   DEC     subtract 1 from the accu */
            case 4:
                accu--;
                break;
            /* 101-----   INC     add 1 to the accu */
            case 5:
                accu++;
                break;
            /* 110xxxxx   JMP x   load the value x into the pc */
            case 6:
                pc=addr;
                break;
            /* 111-----   HLT     terminate program */
            case 7:
                return accu;
                break;
        }
    }
    return accu;
}

int main()
{
    int i=0;
    unsigned char result;
    while(scanf("%s",line)!=EOF)
    {
        memory[0]=ParseFromLine(line);
        for(i=1;i<32;i++)
        {
            scanf("%s",line);
            memory[i]=ParseFromLine(line);
        }
        result = Run();
        ParseToLine(result, line);
        printf("%s\n", line);
    }
    return 0;
}
