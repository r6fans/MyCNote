// 栈的实现
typedef char datatype;
typedef struct{
    datatype data[128];
    int top;    //顺序栈栈顶位置
}SeqStack;

SeqStack* init(){
    SeqStack *SS;
    SS = (SeqStack *)malloc(sizeof(SeqStack));
    SS -> top = -1;
    return SS;
}

void push(datatype data, SeqStack *SS){
    SS->data[++SS->top]=data;
}

datatype pop(SeqStack *SS){
    if(SS->top == -1){
        return -1;
    }
    return SS->data[SS->top];
}

int empty(SeqStack *SS){
    if(SS->top == -1){
        return 0;
    }
    return -1;
}


//数制转换(求余法)
// 10进制-》b进制
void Conversion(int num, int b){
    SeqStack *stack = init();
    while(num){
        push(num%b, stack);
        num = num / b;
    }
    while(!empty(stack)){
        printf("%d", pop(stack))
    }
}