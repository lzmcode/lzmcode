#include <stdio.h>
#include <string.h>

/*�������32bytes�ڴ�*/
/*pc: program counter, ���������������������ʱ�ĵ�ַָ�� */
unsigned char pc;
/*accu: accumulator, ���ۼ���*/
unsigned char accu;

/*ÿ�ζ�ȡ��һ�У�byte��*/
char line[9];

/*���������һ���ֽڵ�ֵ*/
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

/*��ֵ�����ɶ����Ʊ����ַ�����׼����ӡ*/
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

/*���У������ۼ�����ֵ*/
unsigned char Run()
{
    /*�ֱ��ǵ�ǰָ�ָ���루����λ������ַ������λ��*/
    unsigned char instruction, code, addr;
    /*��ʼ��*/
    pc=0;
    accu=0;    
    
    /*����ѭ��*/
    while(1)
    {
        /*ȡָ*/
        instruction = memory[pc++];
        /*һ��pcԽ���ڴ���ޣ��ͻ��˵�0��û���������WA�������䵼��AC��*/
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
