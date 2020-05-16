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



//����˳��ջ�ĳ�ʼ��
Status InitStack(ChStack &H)
{                                        // ����һ����ջ H 
	H.base = new CElemType[MAXSIZE];	 //Ϊ˳��ջ����һ���������ΪMAXSIZE������ռ�
	if(!H.base)
		exit (OVERFLOW);    	         //�洢����ʧ��
	H.top = H.base;
	H.stacksize = MAXSIZE;
	return OK;
}
//����˳��ջ����ջ
Status Push(ChStack &H,CElemType e)
{                                        // ����Ԫ��eΪ�µ�ջ��Ԫ��
	if(H.top-H.base==H.stacksize)
		return ERROR;	                 //ջ��
	*(H.top++) = e;	                     //Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//����˳��ջ�ĳ�ջ
Status Pop(ChStack &H,CElemType &e)
{                                        // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(H.base == H.top)
		return ERROR;                    //ջ��
	e = *(--H.top);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//ȡ����˳��ջ��ջ��Ԫ��
Status GetTop(ChStack H,CElemType &e)
{                                        // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(H.top == H.base){
		e='0';
		return ERROR;
	}
	e = *(H.top-1);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//����ջ��
Status StackEmpty(ChStack &H){
	if(H.top-H.base>0)return 1;          //ջ���շ���1
		else return 0;
}
//ջ��Ԫ�ظ��� 
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









//����˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S)
{                                        // ����һ����ջ S 
	S.base = new Integer[MAXSIZE];	 //Ϊ˳��ջ����һ���������ΪMAXSIZE������ռ�
	if(!S.base)
		exit (OVERFLOW);    	         //�洢����ʧ��
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//����˳��ջ����ջ
Status Push(SqStack &S,Integer e)
{                                        // ����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base==S.stacksize)
		return ERROR;	                 //ջ��
	*(S.top++) = e;	                     //Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//����˳��ջ�ĳ�ջ
Status Pop(SqStack &S,Integer &e)
{                                        // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.base == S.top)
		return ERROR;                    //ջ��
	e = *(--S.top);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//ȡ����˳��ջ��ջ��Ԫ��
Status GetTop(SqStack S,Integer &e)
{                                        // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top == S.base)
		return ERROR;
	e = *(S.top-1);                      //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//����ջ��
Status StackEmpty(SqStack &S){
	if(S.top-S.base>0)return 1;          //ջ���շ���1
		else return 0;
}
//ջ��Ԫ�ظ��� 
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
	
	cout<<"���г���ʽ�ӣ�"<< endl;
	cout<<"��������";
	Put(a); 
	cout<<"������";
	Put(bb); 
	 
	cout<<"�̣�";
	Put(d); 
	cout<<"������";
	Put(c); 
	
	if(b.value[b.part-1]==0){
		cout<<endl;
		cout<<"!!!!���ڷ�ĸΪ��,����ʽ����ȷ,�������0"<<endl; 
	}
	
} 




void count(SqStack &S,ChStack &H){
	char x;
	Pop(H,x);                              //������ֵ
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
	cout<<"**             �Զ��ֽڱ�ʾ�����������������ϵͳ              **"<<endl;
	cout<<"*****************************************************************"<<endl;
	cout<<"**ע�⣺1.��ϵͳ�����ڴ����ŵļӼ��˳��Ļ�ϼ��㡣             **"<<endl;
	cout<<"**                                                             **"<<endl;
	cout<<"**      2.ֻ�����������ַ�����+��-��*��/����������#���ַ���    **"<<endl;
	cout<<"**                                                             **"<<endl;
    cout<<"*****************************************************************"<<endl;
	cout<<"**��ӭ����ʹ�ã���������������Ҫ�����ʽ��                     **"<<endl;
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
	

	cout<<"**������һ����ʽ(��#��β): "<<endl;
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
				    t=1;                            //�����롮����ʱ��ǰһ������Ϊ��-��������£�����ֵ���ű��q��0�����ŷ��ű��t��1
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
				}                                  //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				break;                         //ѹ�����ջ����������˳������Ϊ1������˳���ǵ�ֵ��3����ʱ����4��
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
				}                                    //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				break;                           //ѹ�����ջ����������˳������Ϊ1������˳���ǵ�ֵ��3����ʱ����4������ֵ���ű����1
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
				}                                     //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				break;                            //ѹ�����ջ����������˳������Ϊ2������˳���ǵ�ֵ��3����ʱ����5��
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
				}                                     //�ڲ�ͬ����˳����ֵ������²�ȡ�Ĳ�ͬ���㷽��
				break;                            //ѹ�����ջ����������˳������Ϊ2������˳���ǵ�ֵ��3����ʱ����5��
	    	case ')':if(q==1){I=assignment(I,csi);Push(S,I);}
	    	    I.length=0;I.symbol=1;q=0;
			    GetTop(H,e);
				while(e!='('){
					count(S,H);
					GetTop(H,e);
				}                                      //����������ʽ�ӵ�ֵ
				Pop(H,e);                              //ȥ������ջ�еġ�����
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
			    }                                          //������ǰ�ķ����жϣ��ظ�����ǰ����˳���ǵ�ֵ                                     
				
				if(t==1){
					Pop(S,I);
					I.symbol=-I.symbol;
					t=0;
					Push(S,I);                         //�����ŷ��ű�ǵ�ֵ�ж��������ż�����������
				}
				I.length=0;I.symbol=1;q=0;
				break;
	    	
	    	default:l=1;break;
		}
		cin>>ch;
	}
	if(q==1){I=assignment(I,csi);Push(S,I);I.length=0;I.symbol=1;q=0;}
	
    while(StackEmpty(H)){
		count(S,H);                                     //ʣ��ʽ�ӵļ���
	}
		
	cout<<endl; 
	if(l==0){
		cout<<"��ʽ�����"<<endl;
	    Pop(S,I);
	    Put(I);
	}
	else{
		cout<<"��������ȷ��ʽ�ӣ�"<<endl; 
		l=0;
	}
	cout<<endl;
	
}//

	return 0;
}
