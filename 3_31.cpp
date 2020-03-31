#include<iostream>
#include<math.h>
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;
typedef char CElemType;


typedef struct{
	CElemType *base;
	CElemType *top;
	int stacksize;
}ChStack;


typedef struct{
	char *first;
	char *last;
	int length;
	int symbol;
	int order;
}Integer;


typedef struct{
	Integer *base;
	Integer *top;
	int stacksize;
}SqStack;


void Reduce(SqStack &S);



//符号顺序栈的初始化
Status InitStack(ChStack &H)
{                                        // 构造一个空栈 H 
	H.base = new CElemType[MAXSIZE];	 //为顺序栈分配一个最大容量为MAXSIZE的数组空间
	if(!H.base)
		exit (OVERFLOW);    	         //存储分配失败
	H.top = H.base;
	H.stacksize = MAXSIZE;
	return OK;
}
//符号顺序栈的入栈
Status Push(ChStack &H,CElemType e)
{                                        // 插入元素e为新的栈顶元素
	if(H.top-H.base==H.stacksize)
		return ERROR;	                 //栈满
	*(H.top++) = e;	                     //元素e压入栈顶，栈顶指针加1
	return OK;
}
//符号顺序栈的出栈
Status Pop(ChStack &H,CElemType &e)
{                                        // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(H.base == H.top)
		return ERROR;                    //栈空
	e = *(--H.top);                      //栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//取符号顺序栈的栈顶元素
Status GetTop(ChStack H,CElemType &e)
{                                        // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(H.top == H.base){
		e='0';
		return ERROR;
	}
	e = *(H.top-1);                      //栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//符号栈空
Status StackEmpty(ChStack &H){
	if(H.top-H.base>0)return 1;          //栈不空返回1
		else return 0;
}








//取符号顺序栈的栈顶元素
int GetTop1(Integer I)
{                                        // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    int s,s1,s2;
    if(I.last==I.first){
    	cout<<"发现错误!";
    	return 0;
	}
	s=int(*(I.first)-'0');
	
	return s;
}

int GetTop2(Integer I)
{                                        // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    int s,s1,s2;
    if(I.last==I.first){
    	cout<<"发现错误!";
    	return 0;
	}
	if(I.length>1){
		s1=int(*(I.first)-'0');
	    s2=int(*(I.first+I.order)-'0');
	    s=s1*10+s2;
	}
	else {
		s=int(*(I.first)-'0');
	}
	
	return s;
}


void Put(Integer I)
{
	char *p;
	p=I.first;
	while(p!=I.last){
		cout<<*p;
		p=p+I.order;
	}
	cout<<endl;
}


Status StackEmpty(Integer I){
	if(I.first!=I.last)return 1;          //栈不空返回1
		else return 0;
}









//数据顺序栈的初始化
Status InitStack(SqStack &S)
{                                        // 构造一个空栈 S 
	S.base = new Integer[MAXSIZE];	 //为顺序栈分配一个最大容量为MAXSIZE的数组空间
	if(!S.base)
		exit (OVERFLOW);    	         //存储分配失败
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//数据顺序栈的入栈
Status Push(SqStack &S,Integer e)
{                                        // 插入元素e为新的栈顶元素
	if(S.top-S.base==S.stacksize)
		return ERROR;	                 //栈满
	*(S.top++) = e;	                     //元素e压入栈顶，栈顶指针加1
	return OK;
}
//数据顺序栈的出栈
Status Pop(SqStack &S,Integer &e)
{                                        // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.base == S.top)
		return ERROR;                    //栈空
	e = *(--S.top);                      //栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//取数据顺序栈的栈顶元素
Status GetTop(SqStack S,Integer &e)
{                                        // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top == S.base)
		return ERROR;
	e = *(S.top-1);                      //栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//数据栈空
Status StackEmpty(SqStack &S){
	if(S.top-S.base>0)return 1;          //栈不空返回1
		else return 0;
}









void copy(SqStack &S,Integer &e){
	Integer a,c,d;
	c=e;
	GetTop(S,a);
	if(a.order==1){
		d.first=d.last=a.last+1;
	}
	else {
		d.first=d.last=a.first+1;
	}
	d.length=0;d.order=1;
	d.symbol=c.symbol;
	while(StackEmpty(c)){
		*(d.last)=*(c.first);
		d.length++;
		d.last++;c.first=c.first+c.order;
	}
	Push(S,d);
}


void cover(SqStack &S,Integer &e){
	Integer a,c,d;
	c=e;
	Pop(S,a);
	if(a.order==1){
		d.first=d.last=a.first;
	}
	else {
		d.first=d.last=a.last;
	}
	d.length=0;d.order=1;
	d.symbol=c.symbol;
	while(StackEmpty(c)){
		*(d.last)=*(c.first);
		d.length++;
		d.last++;c.first=c.first+c.order;
	}
	Push(S,d);
}








void Add(SqStack &S){
	Integer a,b,c,d;
	int size,carry=0;
	Pop(S,b);
	Pop(S,a);
	if(a.symbol==b.symbol){
	d.symbol=a.symbol;
	if(a.length>b.length){size=a.length+2;}
	else {size=b.length+2;}
	char cc[size];
	c.first=c.last=cc;
	c.length=0;
	c.order=-1;
	while(StackEmpty(a)&&StackEmpty(b)){
		a.last=a.last-a.order;
	    b.last=b.last-b.order;
		c.first=c.first+1;
		switch(*(a.last)){
			case '0':if(carry==0){
			    *(c.first)=*(b.last);carry=0;
			}
			else {
				*(c.first)=*(b.last)+1;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break; 
			case '1':if(carry==0){
			    *(c.first)=*(b.last)+1;carry=0;
			}
			else {
				*(c.first)=*(b.last)+2;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break; 
			case '2':if(carry==0){
			    *(c.first)=*(b.last)+2;carry=0;
			}
			else {
				*(c.first)=*(b.last)+3;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break;
			case '3':if(carry==0){
			    *(c.first)=*(b.last)+3;carry=0;
			}
			else {
				*(c.first)=*(b.last)+4;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break; 
			case '4':if(carry==0){
			    *(c.first)=*(b.last)+4;carry=0;
			}
			else {
				*(c.first)=*(b.last)+5;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break; 
			case '5':if(carry==0){
			    *(c.first)=*(b.last)+5;carry=0;
			}
			else {
				*(c.first)=*(b.last)+6;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}break;
			case '6':if(carry==0){
			    *(c.first)=*(b.last)+6;carry=0;
			}
			else {
				*(c.first)=*(b.last)+7;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break; 
			case '7':if(carry==0){
			    *(c.first)=*(b.last)+7;carry=0;
			}
			else {
				*(c.first)=*(b.last)+8;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break;
			case '8':if(carry==0){
			    *(c.first)=*(b.last)+8;carry=0;
			}
			else {
				*(c.first)=*(b.last)+9;carry=0;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break;
			case '9':if(carry==0){
			    *(c.first)=*(b.last)+9;carry=0;
			}
			else {
				*(c.first)=*(b.last);carry=1;
			}
			if(*(c.first)>'9'){
				*(c.first)=*(c.first)-10;
				carry=1;
			}
			break;
		}
		c.length++;
	}
	
	
	while(StackEmpty(a)){
		c.first++;
		a.last=a.last-a.order;
		if(carry==0){*(c.first)=*(a.last);carry=0;}
		else {
			if(*(a.last)<'9'){*(c.first)=*(a.last)+1;carry=0;}
			else {*(c.first)=*(a.last)-9;carry=1;}
		}
		c.length++;
	}
	while(StackEmpty(b)){
		c.first++;
		b.last=b.last-b.order;
		if(carry==0){*(c.first)=*(b.last);carry=0;}
		else {
			if(*(b.last)<'9'){*(c.first)=*(b.last)+1;carry=0;}
			else {*(c.first)=*(b.last)-9;carry=1;}
		}
		c.length++;
	}
	if(carry==1){
		c.first++;
		*(c.first)='1';
		c.length++;
		carry=0;
	}
	
	
	GetTop(S,a);
	if(a.order==1){
		d.first=d.last=a.last+1;
	}
	else {
		d.first=d.last=a.first+1;
	}
	d.length=0;d.order=1;
	
	while(*(c.first)=='0'&&c.length>1){
	    c.length--;
	  	c.first=c.first+c.order;
	}  
	
	while(StackEmpty(c)){
		*(d.last)=*(c.first);
		d.length++;
		d.last++;c.first=c.first+c.order;
	}
	Push(S,d);
    }
    else if(a.symbol==-1){
    	a.symbol=1;
    	Push(S,b);
    	Push(S,a);
    	Reduce(S);
	}
	else {
		b.symbol=1;
		Push(S,a);
		Push(S,b);
		Reduce(S);
	}
}





void Reduce(SqStack &S){
	Integer aa,bb,a,b,c,d;
	int carry=0;
	d.symbol=1;
	Pop(S,bb);
	Pop(S,aa);
	a=aa;
	b=bb;
	if(a.symbol==b.symbol){
		if(a.symbol==-1){
			c=a;a=b;b=c;
		}
        if(a.length<b.length){
        	c=a;a=b;b=c;
        	d.symbol=-1;
		}
		if(a.length==b.length&&GetTop2(a)<GetTop2(b)){
			c=a;a=b;b=c;
			d.symbol=-1;
		}
	    char m,cc[a.length];
	    c.first=c.last=cc;
	    c.length=0;
	    c.order=-1;
	    while(StackEmpty(b)){
		a.last=a.last-a.order;
	    b.last=b.last-b.order;
		c.first=c.first+1;
		switch(*(b.last)){
			case '0':if(carry==0){
			    *(c.first)=*(a.last);carry=0;
			}
			else {
				*(c.first)=*(a.last)-1;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break; 
			case '1':if(carry==0){
			    *(c.first)=*(a.last)-1;carry=0;
			}
			else {
				*(c.first)=*(a.last)-2;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '2':if(carry==0){
			    *(c.first)=*(a.last)-2;carry=0;
			}
			else {
				*(c.first)=*(a.last)-3;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '3':if(carry==0){
			    *(c.first)=*(a.last)-3;carry=0;
			}
			else {
				*(c.first)=*(a.last)-4;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '4':if(carry==0){
			    *(c.first)=*(a.last)-4;carry=0;
			}
			else {
				*(c.first)=*(a.last)-5;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '5':if(carry==0){
			    *(c.first)=*(a.last)-5;carry=0;
			}
			else {
				*(c.first)=*(a.last)-6;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '6':if(carry==0){
			    *(c.first)=*(a.last)-6;carry=0;
			}
			else {
				*(c.first)=*(a.last)-7;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '7':if(carry==0){
			    *(c.first)=*(a.last)-7;carry=0;
			}
			else {
				*(c.first)=*(a.last)-8;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '8':if(carry==0){
			    *(c.first)=*(a.last)-8;carry=0;
			}
			else {
				*(c.first)=*(a.last)-9;carry=0;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
			case '9':if(carry==0){
			    *(c.first)=*(a.last)-9;carry=0;
			}
			else {
				*(c.first)=*(a.last);carry=-1;
			}
			if(*(c.first)<'0'){
				*(c.first)=*(c.first)+10;
				carry=-1;
			}
			break;
		}
		c.length++;
	}
	
	while(StackEmpty(a)){
		c.first++;
		a.last=a.last-a.order;
		if(carry==0){*(c.first)=*(a.last);carry=0;}
		else {
			if(*(a.last)>'0'){*(c.first)=*(a.last)-1;carry=0;}
			else {*(c.first)=*(a.last)+9;carry=-1;}
		}
		c.length++;
	}
	
	if(carry==-1){
		Push(S,bb);
		Push(S,aa);
		Reduce(S);
		Pop(S,d);
		d.symbol=-1;
		Push(S,d);
	}
	else {
		GetTop(S,a);
	    if(a.order==1){
		    d.first=d.last=a.last+1;
	    }
	    else {
		    d.first=d.last=a.first+1;
	    }
	    d.length=0;d.order=1;
	    while(*(c.first)=='0'&&c.length>1){
	    	c.length--;
	    	c.first=c.first+c.order;
		}
	    while(StackEmpty(c)){
		    *(d.last)=*(c.first);
		    d.length++;
		    d.last++;c.first=c.first+c.order;
	    }    
	    Push(S,d);
	}    
	
	}
    else {
    	b.symbol=a.symbol;
    	Push(S,a);
    	Push(S,b);
    	Add(S);
	}
	
} 




void Ride(SqStack &S) {
	SqStack SS;
	InitStack(SS);
	Integer a,aa,b,c,d;
	int A,B,C,j,i=0;
	int size,carry=0;
	Pop(S,b);
	Pop(S,a);
	aa=a;
	if(a.symbol==b.symbol){
		d.symbol=1;
	}
	else {
		d.symbol=-1;
	} 
	size=a.length+b.length+2;
	size=size*b.length;
	char cc[size+2];
	c.first=c.last=cc;
	c.length=0;
	c.order=-1;
	c.symbol=1;
	while(StackEmpty(b)){
		a=aa;
	    b.last=b.last-b.order;
	    B=int(*(b.last)-'0');
		while(StackEmpty(a)){
			a.last=a.last-a.order;
			c.first=c.first+1;
			A=int(*(a.last)-'0');
			C=A*B+carry;
			carry=C/10;
			*(c.first)='0'+C%10;
			c.length++;
		}
		if(carry>0){
			c.first=c.first+1;
			*(c.first)='0'+carry;
			carry=0;
			c.length++;
		}
		Push(SS,c);GetTop(SS,c);c.last=++c.first;c.length=0;c.symbol=1;c.order=-1;i++;
		for(int j=i;j>0;j--){
			c.first=c.first+1;
			*(c.first)='0';
			c.length++;
		}
	}
	
	for(;i>1;i--){
		Add(SS);
	}
	
	Pop(SS,c);
	
	GetTop(S,a);
	if(a.order==1){
		d.first=d.last=a.last+1;
	}
	else {
		d.first=d.last=a.first+1;
	}
	d.length=0;d.order=1;
	while(StackEmpty(c)){
		*(d.last)=*(c.first);
		d.length++;
		d.last++;c.first=c.first+c.order;
	}    
	Push(S,d);
	
} 




void Except(SqStack &S){
	SqStack S1,S2,S3,S4;
	InitStack(S1);
	InitStack(S2);
	InitStack(S3);
	InitStack(S4);
	Integer a,aa,b,bb,c,d,e,f;
	int A,B,C,i,j;
	int size;
	Pop(S,b);
	Pop(S,f);
	a=f;
	if(a.symbol==b.symbol){
		d.symbol=1;
	}
	else {
		d.symbol=-1;
	} 
	size=a.length+b.length+4;
	char c1[size],c2[size],c3[size],c4[size];
	c.first=c.last=c4;
	c.length=0;
	c.order=1;
	c.symbol=1;
	aa=bb=e=c;
	aa.first=aa.last=c1;
	bb.first=bb.last=c2;
	e.first=e.last=c3;
	*(e.last)='0';e.length=1;e.last++;
	Push(S1,aa);Push(S2,bb);Push(S3,e);Push(S4,c);
	while(StackEmpty(a)){
		*(aa.last)=*(a.first);
		aa.length++;
		aa.last++;
		a.first=a.first+a.order;
		if(aa.length>=b.length){
			i=-1;j=0;
			while(i==-1){
				Push(S1,aa);
			    copy(S3,aa);copy(S3,b);
			    A=GetTop2(aa);B=GetTop2(b);
			    C=A/B-j;
			    *(e.first)='0'+C;
			    Push(S3,e);
			    Ride(S3);
			    Reduce(S3);
			    Pop(S3,bb);
			    i=bb.symbol;
			}
			*(c.last)='0'+C;
			c.length++;
			c.last++;
			if(bb.length==1&&*(bb.first)=='0'){
				bb.last=bb.first;
				bb.length=0;
			}
			cover(S1,bb);
			Pop(S1,aa);
		}
		else {
			*(c.last)='0';
			c.length++;
			c.last++;
		}
			
	}
	
	cout<<endl; 
	cout<<"含有除法式子："<< endl;
	cout<<"被除数：";
	Put(f); 
	cout<<"除数：";
	Put(b); 
	 
	
	GetTop(S,a);
	if(a.order==1){
		d.first=d.last=a.last+1;
	}
	else {
		d.first=d.last=a.first+1;
	}
	d.length=0;d.order=1;
	
	while(*(c.first)=='0'&&c.length>1){
	    	c.length--;
	    	c.first=c.first+c.order;
		}
	while(StackEmpty(c)){
		*(d.last)=*(c.first);
		d.length++;
		d.last++;c.first=c.first+c.order;
	}
	
	cout<<"商：";
	Put(d); 
	cout<<"余数：";
	Put(aa);
	    
	Push(S,d);
} 




void count(SqStack &S,ChStack &H){
	char x;
	Pop(H,x);                              //变量赋值
    switch(x){
	    case '+': 
		case '-':Add(S);break;
		case '*':Ride(S);break; 
		case '/':Except(S);break;
	}
}






int main(){
	
	int h=0;//
	while(h!=1){//
	
	int n=0,q=0,t=0,o=0;
	char e;
	int MaxNum=10,MaxLen=100;
	ChStack H;
	Integer I;
	SqStack S;
	InitStack(H);
	InitStack(S);
	char csi[MaxNum*MaxLen];
	I.first=I.last=csi;
	I.length=0;
	I.symbol=1;
	I.order=1;
	char ch;
	cin>>ch;
	while(ch!='#'){
		switch(ch){
		    case '0':
		    case '1':
		    case '2':
		    case '3':
		    case '4':
		    case '5':
		    case '6':
		    case '7':
	    	case '8':
	    	case '9':*(I.last)=ch;I.last++;I.length++;o=1;q=1;break;
	    	case '(':GetTop(H,e);
			    if(e=='-'){
					I.symbol=1;
				    t=1;                            //在输入‘（’时，前一个符号为‘-’的情况下，将数值符号标记q置0，括号符号标记t置1
				}
				n=3;o=0;
		        Push(H,ch);
		        break;
	    	case '+':if(q==1){Push(S,I);}
	    	    GetTop(S,I);I.first=++I.last;I.length=0;I.symbol=1;I.order=1;q=0;
	    	    o=1;
	    	    if(n<1){
					Push(H,ch);
					n=1;break;
				}
				else if(n>=1&&n<3){
					count(S,H);
					Push(H,ch);
					n=1;break;
				}
				else if(n==3){
					Push(H,ch);
					n=4;break;
				}
				else if(n>=4){
					count(S,H);
					Push(H,ch);
					n=4;break;
				}                                  //在不同计算顺序标记值的情况下采取的不同计算方案
				break;                         //压入符号栈，并将计算顺序标记置为1（计算顺序标记的值在3以上时，置4）
	    	case '-':if(o==0) {*(I.last)='0';I.last++;I.length++;q=1;}
			    o=1;
			    if(q==1){Push(S,I);}
			    GetTop(S,I);I.first=++I.last;I.length=0;I.symbol=-1;I.order=1;q=0;
	    	    if(n<1){
					Push(H,ch);
					n=1;break;
				}
				else if(n>=1&&n<3){
					count(S,H);
					Push(H,ch);
					n=1;break;
				}
				else if(n==3){
					Push(H,ch);
					n=4;break;
				}
				else if(n>=4){
					count(S,H);
					Push(H,ch);
					n=4;break;
				}                                    //在不同计算顺序标记值的情况下采取的不同计算方案
				break;                           //压入符号栈，并将计算顺序标记置为1（计算顺序标记的值在3以上时，置4），数值符号标记置1
	    	case '*':if(q==1){Push(S,I);}
	    	    GetTop(S,I);I.first=++I.last;I.length=0;I.symbol=1;I.order=1;q=0;
	    	    o=1;
	    	    if(n<=1){
					Push(H,ch);
					n=2;break;
				}
				else if(n>=2&&n<3){
					count(S,H);
					Push(H,ch);
					n=2;break;
				}
				else if(n==3||n==4){
					Push(H,ch);
					n=5;break;
				}
				else if(n=5){
					count(S,H);
					Push(H,ch);
					n=5;break;
				}                                     //在不同计算顺序标记值的情况下采取的不同计算方案
				break;                            //压入符号栈，并将计算顺序标记置为2（计算顺序标记的值在3以上时，置5）
	    	case '/':if(q==1){Push(S,I);}
	    	    GetTop(S,I);I.first=++I.last;I.length=0;I.symbol=1;I.order=1;q=0;
	    	    o=1;
				if(n<=1){
					Push(H,ch);
					n=2;break;
				}
				else if(n>=2&&n<3){
					count(S,H);
					Push(H,ch);
					n=2;break;
				}
				else if(n==3||n==4){
					Push(H,ch);
					n=5;break;
				}
				else if(n=5){
					count(S,H);
					Push(H,ch);
					n=5;break;
				}                                     //在不同计算顺序标记值的情况下采取的不同计算方案
				break;                            //压入符号栈，并将计算顺序标记置为2（计算顺序标记的值在3以上时，置5）
	    	case ')':if(q==1){Push(S,I);}
	    	    GetTop(S,I);I.first=++I.last;I.length=0;I.symbol=1;I.order=1;q=0;
			    GetTop(H,e);
				while(e!='('){
					count(S,H);
					GetTop(H,e);
				}                                      //计算括号中式子的值
				Pop(H,e);                              //去除符号栈中的‘（’
				GetTop(H,e);
				switch(e){
				    case '0':
					    n=0;break;
				    case '+':
				    case '-':
					    n=1;break;
				   	case '*':
				    case '/':
					    n=2;break;
					default:n=0;break;
			    }                                          //由括号前的符号判断，回复括号前计算顺序标记的值                                     
				
				if(t==1){
					Pop(S,I);
					I.symbol=-I.symbol;
					t=0;
					Push(S,I);                         //由括号符号标记的值判断整个括号计算结果的正负
				}
				GetTop(S,I);I.first=++I.last;I.length=0;I.symbol=1;I.order=1;q=0;
				break;
	    	
	    	case '!':h=1;break;//
	    	
	    	default:break;
		}
		cin>>ch;
	}
	if(q==1){Push(S,I);GetTop(S,I);I.first=++I.last;I.length=0;I.symbol=1;I.order=1;q=0;}
	//Push(S,I);
	/*while(StackEmpty(S)){
		Pop(S,I);
		Put(I);
		int g=GetTop2(I);
		cout<<g<<endl;
	}
	
	while(StackEmpty(H)){
		Pop(H,ch);
		cout<<ch<<endl;
	}*/
	while(StackEmpty(H)){
		count(S,H);                                     //剩余式子的计算
		/*Put(I);
		cout<<I.length<<endl;
		cout<<I.order<<endl;
		cout<<I.symbol<<endl;*/
	}
	Pop(S,I);
	if(I.symbol==-1){
		cout<<"-";
	}
	cout<<endl; 
	cout<<"算式结果："<<endl;
	Put(I);
	
}//

	return 0;
}
