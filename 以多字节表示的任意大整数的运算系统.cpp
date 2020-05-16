#include<iostream>
#include<math.h>
#include <iomanip>
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
    int value[10000];
    int part;
	int length;
	int symbol;
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
//栈内元素个数 
int StackCount(ChStack &H){
	int a; 
	a=H.top-H.base;
	return a;
}







int GetTop1(Integer I)
{                                      
    int s,i,n=1;
	i=I.length%8;
	if(i==0)i=8;
	for(;i>1;i--){
		n=n*10;
	}
	s=I.value[I.part-1]/n;
	return s;
}

int GetTop2(Integer I)
{                                        
    int s,i,n=1;
    if(I.length>1){
    	i=I.length%8;
	    if(i>1&&i<8){
	    	for(;i>2;i--){
		        n=n*10;
	        }
	        s=I.value[I.part-1]/n;
	        return s;
		}
	    else if(i==0){
	    	return (I.value[I.part-1]/1000000);
		}
		else {
			return (I.value[I.part-1]*10+I.value[I.part-2]/10000000);
		}
	}
    else {
    	return (I.value[I.part-1]);
	}
}


void Put(Integer I)
{
	if(I.symbol==-1)cout<<"-";
	if(I.length>1){
		cout<<I.value[I.part-1];
		I.part--;
	
		while(I.part>0){
			cout<<setfill('0')<<setw(8)<<I.value[I.part-1];
			I.part--;
		}
		cout<<endl;
	}
	else{
		cout<<I.value[I.part-1];
		I.part--;
		cout<<endl;
	}
	
}


Status IntegerEmpty(Integer I){
	if(I.part>0)return 1;          
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
//栈内元素个数 
int StackCount(SqStack &S){
	int a; 
	a=S.top-S.base;
	return a;
}







Integer assignment(Integer I,char csi[]){
	int A,C=0,n=1,j=1;
	I.part=0;
	for(int i=I.length-1;i>=0;i--){
		if(j==8){
			A=csi[i]-'0';
			C=C+A*n;
			n=n*10;
			I.value[I.part]=C;C=0;n=1;j=1;I.part++;
		}
		else{
			A=csi[i]-'0';
			C=C+A*n;
			n=n*10;
			j++;
		}
	}
	if(j>1){
		I.value[I.part]=C;
		I.part++;
	}
	return I;
}







void Add(SqStack &S){
	Integer a,b,c;
	int n=1,l,i=0,carry=0;
	Pop(S,b);
	Pop(S,a);
	c.part=0;
	if(a.symbol==b.symbol){
	    c.symbol=a.symbol;
    while(i<a.part&&i<b.part){
    	c.value[c.part]=a.value[i]+b.value[i]+carry;
    	carry=0;
    	if(c.value[c.part]>99999999){
    		c.value[c.part]=c.value[c.part]-100000000;
    		carry=1;
		}
		c.part++;
		i++;
	}
	while(i<a.part){
    	c.value[c.part]=(a.value[i]+carry);
    	carry=0;
    	if(c.value[c.part]>99999999){
    		c.value[c.part]=c.value[c.part]-100000000;
    		carry=1;
		}
		c.part++;
		i++;
	}
	while(i<b.part){
    	c.value[c.part]=b.value[i]+carry;
    	carry=0;
    	if(c.value[c.part]>99999999){
    		c.value[c.part]=c.value[c.part]-100000000;
    		carry=1;
		}
		c.part++;
		i++;
	}
	if(carry==1){
    	c.value[c.part]=1;
    	carry=0;
    	c.part++;
    }
    l=0;
    for(i=0;i<8;i++){
    	if(c.value[c.part-1]==0)l++;
    	if(c.value[c.part-1]/n>0){
    		l++;
		}
		n=n*10;
	}
	c.length=l+8*(c.part-1);
	Push(S,c);
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
	Integer a,aa,b,bb,c,d;
	int n=1,l=0,i=0,carry=0;
	Pop(S,bb);
	Pop(S,aa);
	a=aa;
	b=bb;
	c.part=0;
	c.symbol=1;
	if(a.symbol==b.symbol){
		if(a.symbol==-1){
			d=a;a=b;b=d;
		}
        if(a.length<b.length){
        	d=a;a=b;b=d;
        	c.symbol=-1;
		}
		if(a.length==b.length&&a.value[a.part-1]<b.value[b.part-1]){
			d=a;a=b;b=d;
			c.symbol=-1;
		}
    while(i<b.part){
    	c.value[c.part]=a.value[i]-b.value[i]+carry;
    	carry=0;
    	if(c.value[c.part]<0){
    		c.value[c.part]=c.value[c.part]+100000000;
    		carry=-1;
		}
		c.part++;
		i++;
	}
	while(i<a.part){
    	c.value[c.part]=a.value[i]+carry;
    	carry=0;
    	if(c.value[c.part]<0){
    		c.value[c.part]=c.value[c.part]+100000000;
    		carry=-1;
		}
		c.part++;
		i++;
	}

	if(carry==-1){
		Push(S,bb);
		Push(S,aa);
		Reduce(S);
		Pop(S,c);
		c.symbol=-1;
		Push(S,c);
	}
	while(c.value[c.part-1]==0){
		c.part--;
	}
	for(i=0;i<8;i++){
		if(c.value[c.part-1]==0)l++;
    	if(c.value[c.part-1]/n>0){
    		l++;
		}
		n=n*10;
	}
	c.length=l+8*(c.part-1);
	Push(S,c);
	
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
	int j,i=0,carry=0;
	long long A,B,C;
	Pop(S,b);
	Pop(S,a);
	if(a.symbol==b.symbol){
		c.symbol=1;
	}
	else {
		c.symbol=-1;
	} 
	d.symbol=1;d.length=0;d.part=0;
	while(i<b.part){
		B=b.value[i];
		aa=a;
		j=0;
		while(j<aa.part){
			A=aa.value[j];
			C=A*B+carry;
			carry=C/100000000;
			d.value[d.part]=C%100000000;
			d.part++;
			j++;
		}
		if(carry>0){
			d.value[d.part]=carry;
			carry=0;
			d.part++;
		}
		int n=1,l=0;
		for(j=0;j<8;j++){
			if(d.value[d.part-1]==0)l++;
    	    if(d.value[d.part-1]/n>0){
    		    l++;
		    }
		    n=n*10;
    	}
	    d.length=l+8*(d.part-1);
		Push(SS,d);
		if(i>0)Add(SS);
		
		i++;
		d.part=0;
		for(j=i;j>0;j--){
			d.value[d.part]=0;
			d.part++;
		}
	}
	Pop(SS,d);
	d.symbol=c.symbol;
	c=d;
	Push(S,d);
	
} 




void Except(SqStack &S){
	SqStack S1,S2;
	InitStack(S1);
	InitStack(S2);
	Integer a,b,bb,c,d,g;
	int length,symbol=1;
	int A,B,C,X,j,n,q=0;
	Pop(S,bb);
	Pop(S,a);
	if(a.symbol==bb.symbol){
		symbol=1;
	}
	else {
		symbol=-1;
	}
	c=a;b=bb;
	c.symbol=1;
	b.symbol=1;
	length=c.length;
	while(length>=b.length&&b.value[b.part-1]!=0){
		int y=0,u=0,i=-1;
		while(i==-1){
			Push(S1,c);
			Push(S1,b);
			if(u==1){
				A=GetTop2(c);
		    	B=GetTop1(b);
			}
			else if(b.length>1){
				A=GetTop2(c);
			    B=GetTop2(b);
			}
			else{
				A=GetTop1(c);
				B=GetTop1(b);
			}
			C=A/B-y;
			X=length-b.length-u;
			n=X/8;
			j=X%8;
			if(C!=0){
				g.part=0;g.symbol=1;
				for(;n>0;n--){
					g.value[g.part]=0;
					g.part++;
				}
				if(j==0){
					g.value[g.part]=C;
					g.part++;
				}
				else {
					n=1;
					for(;j>0;j--){
						n=n*10;
					}
					g.value[g.part]=C*n;
					g.part++;
				}
				n=1;
				int l=0;
				for(j=0;j<8;j++){
					if(g.value[g.part-1]==0)l++;
    				if(g.value[g.part-1]/n>0){
    					l++;
					}
					n=n*10;
				}
				g.length=l+8*(c.part-1);
				Push(S1,g);
				Ride(S1);
				Reduce(S1);
				Pop(S1,d);
				i=d.symbol;
				if(i==-1){
					y++;
				}
			}
			else {
				if(length==b.length){
					d=c;
					g.part=1;
					g.value[g.part-1]=0;
					d.length=1;
					d.symbol=1;
					i=1;
				}
				u++;
			}
			
		}
		c=d;
		length=c.length;
		if(length==b.length&&u>0)length--;
		if(c.value[c.part-1]==0)length=0;
		Push(S2,g);q++;
		if(q>1)Add(S2);
		 
	}
	if(q==0){
		d.value[d.part]=0;
		d.part++;
		d.length=1;
		d.symbol=1;
		Push(S2,d);
	}
	  
	Pop(S2,d);
	d.symbol=symbol;
	Push(S,d);
	cout<<endl; 
	
	cout<<"含有除法式子："<< endl;
	cout<<"被除数：";
	Put(a); 
	cout<<"除数：";
	Put(bb); 
	 
	cout<<"商：";
	Put(d); 
	cout<<"余数：";
	Put(c); 
	
	if(b.value[b.part-1]==0){
		cout<<endl;
		cout<<"!!!!由于分母为零,计算式不正确,结果返回0"<<endl; 
	}
	
} 




void count(SqStack &S,ChStack &H){
	char x;
	Pop(H,x);                              //变量赋值
    switch(x){
	    case '+':Add(S);break;
		case '-':Add(S);break;
		case '*':Ride(S);break; 
		case '/':Except(S);break;
	}
}






int main(){
	
	int h=0;//

	cout<<"*****************************************************************"<<endl;
	cout<<"**             以多字节表示的任意大整数的运算系统              **"<<endl;
	cout<<"*****************************************************************"<<endl;
	cout<<"**注意：1.本系统适用于带括号的加减乘除的混合计算。             **"<<endl;
	cout<<"**                                                             **"<<endl;
	cout<<"**      2.只能输入数字字符及“+、-、*、/、（、）、#”字符。    **"<<endl;
	cout<<"**                                                             **"<<endl;
    cout<<"*****************************************************************"<<endl;
	cout<<"**欢迎您的使用，请在下面输入需要计算的式子                     **"<<endl;
	cout<<"*****************************************************************"<<endl;
	
	while(h!=1){	
	int l=0,n=0,q=0,t=0,o=0;
	char e;
	ChStack H;
	Integer I;
	SqStack S;
	InitStack(H);
	InitStack(S);
	char csi[1000000]; 
	
	I.length=0;
	I.symbol=1;
	char ch;
	

	cout<<"**请输入一个公式(以#结尾): "<<endl;
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
	    	case '9':csi[I.length]=ch;I.length++;o=1;q=1;break;
	    	case '(':GetTop(H,e);
			    if(e=='-'){
					I.symbol=1;
				    t=1;                            //在输入‘（’时，前一个符号为‘-’的情况下，将数值符号标记q置0，括号符号标记t置1
				}
				n=3;o=0;
		        Push(H,ch);
		        break;
	    	case '+':if(q==1){I=assignment(I,csi);Push(S,I);}
	    	    I.length=0;I.symbol=1;q=0;
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
	    	case '-':if(o==0) {csi[I.length]='0';I.length++;q=1;}
			    o=1;
			    if(q==1){I=assignment(I,csi);Push(S,I);}
			    I.length=0;I.symbol=-1;q=0;
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
	    	case '*':if(q==1){I=assignment(I,csi);Push(S,I);}
	    	    I.length=0;I.symbol=1;q=0;
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
	    	case '/':if(q==1){I=assignment(I,csi);Push(S,I);}
	    	    I.length=0;I.symbol=1;q=0;
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
	    	case ')':if(q==1){I=assignment(I,csi);Push(S,I);}
	    	    I.length=0;I.symbol=1;q=0;
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
				I.length=0;I.symbol=1;q=0;
				break;
	    	
	    	default:l=1;break;
		}
		cin>>ch;
	}
	if(q==1){I=assignment(I,csi);Push(S,I);I.length=0;I.symbol=1;q=0;}
	
    while(StackEmpty(H)){
		count(S,H);                                     //剩余式子的计算
	}
		
	cout<<endl; 
	if(l==0){
		cout<<"算式结果："<<endl;
	    Pop(S,I);
	    Put(I);
	}
	else{
		cout<<"请输入正确的式子！"<<endl; 
		l=0;
	}
	cout<<endl;
	
}//

	return 0;
}
